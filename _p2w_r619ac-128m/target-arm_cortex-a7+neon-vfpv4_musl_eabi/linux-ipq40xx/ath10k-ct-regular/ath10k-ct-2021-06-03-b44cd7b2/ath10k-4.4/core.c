/*
 * Copyright (c) 2005-2011 Atheros Communications Inc.
 * Copyright (c) 2011-2013 Qualcomm Atheros, Inc.
 *
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#include <linux/module.h>
#include <linux/firmware.h>
#include <linux/of.h>
#include <linux/ctype.h>

#include "core.h"
#include "mac.h"
#include "htc.h"
#include "hif.h"
#include "wmi.h"
#include "bmi.h"
#include "debug.h"
#include "htt.h"
#include "testmode.h"
#include "wmi-ops.h"

unsigned int ath10k_debug_mask;
static unsigned int ath10k_cryptmode_param;
static bool uart_print;
static bool skip_otp;
static bool rawmode;

static int _modparam_override_eeprom_regdomain = -1;
module_param_named(override_eeprom_regdomain,
		   _modparam_override_eeprom_regdomain, int, 0444);
MODULE_PARM_DESC(override_eeprom_regdomain, "Override regdomain hardcoded in EEPROM with this value (DANGEROUS).");

module_param_named(debug_mask, ath10k_debug_mask, uint, 0644);
module_param_named(cryptmode, ath10k_cryptmode_param, uint, 0644);
module_param(uart_print, bool, 0644);
module_param(skip_otp, bool, 0644);
module_param(rawmode, bool, 0644);

MODULE_PARM_DESC(debug_mask, "Debugging mask");
MODULE_PARM_DESC(uart_print, "Uart target debugging");
MODULE_PARM_DESC(skip_otp, "Skip otp failure for calibration in testmode");
MODULE_PARM_DESC(cryptmode, "Crypto mode: 0-hardware, 1-software");
MODULE_PARM_DESC(rawmode, "Use raw 802.11 frame datapath");

static const struct ath10k_hw_params ath10k_hw_params_list[] = {
	{
		.id = QCA988X_HW_2_0_VERSION,
		.dev_id = QCA988X_2_0_DEVICE_ID,
		.name = "qca988x hw2.0",
		.patch_load_addr = QCA988X_HW_2_0_PATCH_LOAD_ADDR,
		.uart_pin = 7,
		.has_shifted_cc_wraparound = true,
		.otp_exe_param = 0,
		.channel_counters_freq_hz = 88000,
		.max_probe_resp_desc_thres = 0,
		.hw_4addr_pad = ATH10K_HW_4ADDR_PAD_AFTER,
		.cal_data_len = 2116,
		.fw = {
			.dir = QCA988X_HW_2_0_FW_DIR,
			.fw = QCA988X_HW_2_0_FW_FILE,
			.otp = QCA988X_HW_2_0_OTP_FILE,
			.board = QCA988X_HW_2_0_BOARD_DATA_FILE,
			.board_size = QCA988X_BOARD_DATA_SZ,
			.board_ext_size = QCA988X_BOARD_EXT_DATA_SZ,
		},
	},
	{
		.id = QCA6174_HW_2_1_VERSION,
		.dev_id = QCA6164_2_1_DEVICE_ID,
		.name = "qca6164 hw2.1",
		.patch_load_addr = QCA6174_HW_2_1_PATCH_LOAD_ADDR,
		.uart_pin = 6,
		.otp_exe_param = 0,
		.channel_counters_freq_hz = 88000,
		.max_probe_resp_desc_thres = 0,
		.hw_4addr_pad = ATH10K_HW_4ADDR_PAD_AFTER,
		.fw = {
			.dir = QCA6174_HW_2_1_FW_DIR,
			.fw = QCA6174_HW_2_1_FW_FILE,
			.otp = QCA6174_HW_2_1_OTP_FILE,
			.board = QCA6174_HW_2_1_BOARD_DATA_FILE,
			.board_size = QCA6174_BOARD_DATA_SZ,
			.board_ext_size = QCA6174_BOARD_EXT_DATA_SZ,
		},
	},
	{
		.id = QCA6174_HW_2_1_VERSION,
		.dev_id = QCA6174_2_1_DEVICE_ID,
		.name = "qca6174 hw2.1",
		.patch_load_addr = QCA6174_HW_2_1_PATCH_LOAD_ADDR,
		.uart_pin = 6,
		.otp_exe_param = 0,
		.channel_counters_freq_hz = 88000,
		.max_probe_resp_desc_thres = 0,
		.cal_data_len = 8124,
		.fw = {
			.dir = QCA6174_HW_2_1_FW_DIR,
			.fw = QCA6174_HW_2_1_FW_FILE,
			.otp = QCA6174_HW_2_1_OTP_FILE,
			.board = QCA6174_HW_2_1_BOARD_DATA_FILE,
			.board_size = QCA6174_BOARD_DATA_SZ,
			.board_ext_size = QCA6174_BOARD_EXT_DATA_SZ,
		},
	},
	{
		.id = QCA6174_HW_3_0_VERSION,
		.dev_id = QCA6174_2_1_DEVICE_ID,
		.name = "qca6174 hw3.0",
		.patch_load_addr = QCA6174_HW_3_0_PATCH_LOAD_ADDR,
		.uart_pin = 6,
		.otp_exe_param = 0,
		.channel_counters_freq_hz = 88000,
		.max_probe_resp_desc_thres = 0,
		.hw_4addr_pad = ATH10K_HW_4ADDR_PAD_AFTER,
		.cal_data_len = 8124,
		.fw = {
			.dir = QCA6174_HW_3_0_FW_DIR,
			.fw = QCA6174_HW_3_0_FW_FILE,
			.otp = QCA6174_HW_3_0_OTP_FILE,
			.board = QCA6174_HW_3_0_BOARD_DATA_FILE,
			.board_size = QCA6174_BOARD_DATA_SZ,
			.board_ext_size = QCA6174_BOARD_EXT_DATA_SZ,
		},
	},
	{
		.id = QCA6174_HW_3_2_VERSION,
		.dev_id = QCA6174_2_1_DEVICE_ID,
		.name = "qca6174 hw3.2",
		.patch_load_addr = QCA6174_HW_3_0_PATCH_LOAD_ADDR,
		.uart_pin = 6,
		.otp_exe_param = 0,
		.channel_counters_freq_hz = 88000,
		.max_probe_resp_desc_thres = 0,
		.hw_4addr_pad = ATH10K_HW_4ADDR_PAD_AFTER,
		.cal_data_len = 8124,
		.fw = {
			/* uses same binaries as hw3.0 */
			.dir = QCA6174_HW_3_0_FW_DIR,
			.fw = QCA6174_HW_3_0_FW_FILE,
			.otp = QCA6174_HW_3_0_OTP_FILE,
			.board = QCA6174_HW_3_0_BOARD_DATA_FILE,
			.board_size = QCA6174_BOARD_DATA_SZ,
			.board_ext_size = QCA6174_BOARD_EXT_DATA_SZ,
		},
	},
	{
		.id = QCA99X0_HW_2_0_DEV_VERSION,
		.dev_id = QCA99X0_2_0_DEVICE_ID,
		.name = "qca99x0 hw2.0",
		.patch_load_addr = QCA99X0_HW_2_0_PATCH_LOAD_ADDR,
		.uart_pin = 7,
		.otp_exe_param = 0x00000700,
		.continuous_frag_desc = true,
		.channel_counters_freq_hz = 150000,
		.max_probe_resp_desc_thres = 24,
		.hw_4addr_pad = ATH10K_HW_4ADDR_PAD_BEFORE,
		.num_msdu_desc = 1424,
		.qcache_active_peers = 50,
		.tx_chain_mask = 0xf,
		.rx_chain_mask = 0xf,
		.max_spatial_stream = 4,
		.cal_data_len = 12064,
		.fw = {
			.dir = QCA99X0_HW_2_0_FW_DIR,
			.fw = QCA99X0_HW_2_0_FW_FILE,
			.otp = QCA99X0_HW_2_0_OTP_FILE,
			.board = QCA99X0_HW_2_0_BOARD_DATA_FILE,
			.board_size = QCA99X0_BOARD_DATA_SZ,
			.board_ext_size = QCA99X0_BOARD_EXT_DATA_SZ,
		},
	},
	{
		.id = QCA9377_HW_1_0_DEV_VERSION,
		.dev_id = QCA9377_1_0_DEVICE_ID,
		.name = "qca9377 hw1.0",
		.patch_load_addr = QCA9377_HW_1_0_PATCH_LOAD_ADDR,
		.uart_pin = 6,
		.otp_exe_param = 0,
		.channel_counters_freq_hz = 88000,
		.max_probe_resp_desc_thres = 0,
		.cal_data_len = 8124,
		.fw = {
			.dir = QCA9377_HW_1_0_FW_DIR,
			.fw = QCA9377_HW_1_0_FW_FILE,
			.otp = QCA9377_HW_1_0_OTP_FILE,
			.board = QCA9377_HW_1_0_BOARD_DATA_FILE,
			.board_size = QCA9377_BOARD_DATA_SZ,
			.board_ext_size = QCA9377_BOARD_EXT_DATA_SZ,
		},
	},
	{
		.id = QCA9377_HW_1_1_DEV_VERSION,
		.dev_id = QCA9377_1_0_DEVICE_ID,
		.name = "qca9377 hw1.1",
		.patch_load_addr = QCA9377_HW_1_0_PATCH_LOAD_ADDR,
		.uart_pin = 6,
		.otp_exe_param = 0,
		.channel_counters_freq_hz = 88000,
		.max_probe_resp_desc_thres = 0,
		.cal_data_len = 8124,
		.fw = {
			.dir = QCA9377_HW_1_0_FW_DIR,
			.fw = QCA9377_HW_1_0_FW_FILE,
			.otp = QCA9377_HW_1_0_OTP_FILE,
			.board = QCA9377_HW_1_0_BOARD_DATA_FILE,
			.board_size = QCA9377_BOARD_DATA_SZ,
			.board_ext_size = QCA9377_BOARD_EXT_DATA_SZ,
		},
	},
	{
		.id = QCA4019_HW_1_0_DEV_VERSION,
		.dev_id = 0,
		.name = "qca4019 hw1.0",
		.patch_load_addr = QCA4019_HW_1_0_PATCH_LOAD_ADDR,
		.uart_pin = 7,
		.otp_exe_param = 0x0010000,
		.continuous_frag_desc = true,
		.channel_counters_freq_hz = 125000,
		.max_probe_resp_desc_thres = 24,
		.hw_4addr_pad = ATH10K_HW_4ADDR_PAD_BEFORE,
		.num_msdu_desc = 2500,
		.qcache_active_peers = 35,
		.tx_chain_mask = 0x3,
		.rx_chain_mask = 0x3,
		.max_spatial_stream = 2,
		.cal_data_len = 12064,
		.fw = {
			.dir = QCA4019_HW_1_0_FW_DIR,
			.fw = QCA4019_HW_1_0_FW_FILE,
			.otp = QCA4019_HW_1_0_OTP_FILE,
			.board = QCA4019_HW_1_0_BOARD_DATA_FILE,
			.board_size = QCA4019_BOARD_DATA_SZ,
			.board_ext_size = QCA4019_BOARD_EXT_DATA_SZ,
		},
	},
};

static const char *const ath10k_core_fw_feature_str[] = {
	[ATH10K_FW_FEATURE_EXT_WMI_MGMT_RX] = "wmi-mgmt-rx",
	[ATH10K_FW_FEATURE_WMI_10X] = "wmi-10.x",
	[ATH10K_FW_FEATURE_HAS_WMI_MGMT_TX] = "has-wmi-mgmt-tx",
	[ATH10K_FW_FEATURE_NO_P2P] = "no-p2p",
	[ATH10K_FW_FEATURE_WMI_10_2] = "wmi-10.2",
	[ATH10K_FW_FEATURE_MULTI_VIF_PS_SUPPORT] = "multi-vif-ps",
	[ATH10K_FW_FEATURE_WOWLAN_SUPPORT] = "wowlan",
	[ATH10K_FW_FEATURE_IGNORE_OTP_RESULT] = "ignore-otp",
	[ATH10K_FW_FEATURE_NO_NWIFI_DECAP_4ADDR_PADDING] = "no-4addr-pad",
	[ATH10K_FW_FEATURE_SUPPORTS_SKIP_CLOCK_INIT] = "skip-clock-init",
	[ATH10K_FW_FEATURE_RAW_MODE_SUPPORT] = "raw-mode",
	[ATH10K_FW_FEATURE_SUPPORTS_ADAPTIVE_CCA] = "adaptive-cca",
	[ATH10K_FW_FEATURE_MFP_SUPPORT] = "mfp",
	[ATH10K_FW_FEATURE_PEER_FLOW_CONTROL] = "peer-flow-ctrl",
	[ATH10K_FW_FEATURE_WMI_10X_CT] = "wmi-10.x-CT",
	[ATH10K_FW_FEATURE_CT_RXSWCRYPT] = "rxswcrypt-CT",
	[ATH10K_FW_FEATURE_HAS_TXSTATUS_NOACK] = "txstatus-noack",
	[ATH10K_FW_FEATURE_CT_RATEMASK] = "ratemask-CT",
	[ATH10K_FW_FEATURE_HAS_SAFE_BURST] = "safe-burst",
	[ATH10K_FW_FEATURE_REGDUMP_CT] = "regdump-CT",
	[ATH10K_FW_FEATURE_TXRATE_CT] = "txrate-CT",
	[ATH10K_FW_FEATURE_FLUSH_ALL_CT] = "flush-all-CT",
	[ATH10K_FW_FEATURE_PINGPONG_READ_CT] = "pingpong-CT",
	[ATH10K_FW_FEATURE_SKIP_CH_RES_CT] = "ch-regs-CT",
	[ATH10K_FW_FEATURE_NOP_CT] = "nop-CT",
	[ATH10K_FW_FEATURE_HTT_MGT_CT] = "htt-mgt-CT",
	[ATH10K_FW_FEATURE_SET_SPECIAL_CT] = "set-special-CT",
	[ATH10K_FW_FEATURE_NO_BMISS_CT] = "no-bmiss-CT",
};

static unsigned int ath10k_core_get_fw_feature_str(char *buf,
						   size_t buf_len,
						   enum ath10k_fw_features feat)
{
	/* make sure that ath10k_core_fw_feature_str[] gets updated */
	BUILD_BUG_ON(ARRAY_SIZE(ath10k_core_fw_feature_str) !=
		     ATH10K_FW_FEATURE_COUNT);

	if (feat >= ARRAY_SIZE(ath10k_core_fw_feature_str) ||
	    WARN_ON(!ath10k_core_fw_feature_str[feat])) {
		return scnprintf(buf, buf_len, "bit%d", feat);
	}

	return scnprintf(buf, buf_len, "%s", ath10k_core_fw_feature_str[feat]);
}

void ath10k_core_get_fw_features_str(struct ath10k *ar,
				     char *buf,
				     size_t buf_len)
{
	unsigned int len = 0;
	int i;

	for (i = 0; i < ATH10K_FW_FEATURE_COUNT; i++) {
		if (test_bit(i, ar->fw_features)) {
			if (len > 0)
				len += scnprintf(buf + len, buf_len - len, ",");

			len += ath10k_core_get_fw_feature_str(buf + len,
							      buf_len - len,
							      i);
		}
	}
}

static void ath10k_send_suspend_complete(struct ath10k *ar)
{
	ath10k_dbg(ar, ATH10K_DBG_BOOT, "boot suspend complete\n");

	complete(&ar->target_suspend);
}

static int ath10k_init_configure_target(struct ath10k *ar)
{
	u32 param_host;
	int ret;

	/* tell target which HTC version it is used*/
	ret = ath10k_bmi_write32(ar, hi_app_host_interest,
				 HTC_PROTOCOL_VERSION);
	if (ret) {
		ath10k_err(ar, "settings HTC version failed\n");
		return ret;
	}

	/* Configure HTC credits logic. */
	param_host = (TARGET_HTC_MAX_CONTROL_BUFFERS << 16);
	param_host |= (TARGET_HTC_MAX_PENDING_TXCREDITS_RPTS << 20);

	/* Max tx buffers (tx-credits), CT firmware only.
	 * but normal .487 firmware will just ignore it fine.
	 */
	param_host |= (TARGET_HTC_MAX_TX_CREDITS_CT << 24);

	ret = ath10k_bmi_write32(ar, hi_mbox_io_block_sz,
				 param_host);
	if (ret) {
		ath10k_err(ar, "failed setting HTC mbox-io-block-sz\n");
		return ret;
	}

	/* set the firmware mode to STA/IBSS/AP */
	ret = ath10k_bmi_read32(ar, hi_option_flag, &param_host);
	if (ret) {
		ath10k_err(ar, "setting firmware mode (1/2) failed\n");
		return ret;
	}

	/* TODO following parameters need to be re-visited. */
	/* num_device */
	param_host |= (1 << HI_OPTION_NUM_DEV_SHIFT);
	/* Firmware mode */
	/* FIXME: Why FW_MODE_AP ??.*/
	param_host |= (HI_OPTION_FW_MODE_AP << HI_OPTION_FW_MODE_SHIFT);
	/* mac_addr_method */
	param_host |= (1 << HI_OPTION_MAC_ADDR_METHOD_SHIFT);
	/* firmware_bridge */
	param_host |= (0 << HI_OPTION_FW_BRIDGE_SHIFT);
	/* fwsubmode */
	param_host |= (0 << HI_OPTION_FW_SUBMODE_SHIFT);

	ret = ath10k_bmi_write32(ar, hi_option_flag, param_host);
	if (ret) {
		ath10k_err(ar, "setting firmware mode (2/2) failed\n");
		return ret;
	}

	/* We do all byte-swapping on the host */
	ret = ath10k_bmi_write32(ar, hi_be, 0);
	if (ret) {
		ath10k_err(ar, "setting host CPU BE mode failed\n");
		return ret;
	}

	/* FW descriptor/Data swap flags */
	ret = ath10k_bmi_write32(ar, hi_fw_swap, 0);

	if (ret) {
		ath10k_err(ar, "setting FW data/desc swap flags failed\n");
		return ret;
	}

	/* Some devices have a special sanity check that verifies the PCI
	 * Device ID is written to this host interest var. It is known to be
	 * required to boot QCA6164.
	 */
	ret = ath10k_bmi_write32(ar, hi_hci_uart_pwr_mgmt_params_ext,
				 ar->dev_id);
	if (ret) {
		ath10k_err(ar, "failed to set pwr_mgmt_params: %d\n", ret);
		return ret;
	}

	return 0;
}

static const struct firmware *ath10k_fetch_fw_file(struct ath10k *ar,
						   const char *dir,
						   const char *file)
{
	char filename[100];
	const struct firmware *fw;
	int ret;

	if (file == NULL)
		return ERR_PTR(-ENOENT);

	if (dir == NULL)
		dir = ".";

	snprintf(filename, sizeof(filename), "%s/%s", dir, file);
	ret = request_firmware(&fw, filename, ar->dev);
	if (ret)
		return ERR_PTR(ret);

	return fw;
}

static int ath10k_push_board_ext_data(struct ath10k *ar, const void *data,
				      size_t data_len)
{
	u32 board_data_size = ar->hw_params.fw.board_size;
	u32 board_ext_data_size = ar->hw_params.fw.board_ext_size;
	u32 board_ext_data_addr;
	int ret;

	ret = ath10k_bmi_read32(ar, hi_board_ext_data, &board_ext_data_addr);
	if (ret) {
		ath10k_err(ar, "could not read board ext data addr (%d)\n",
			   ret);
		return ret;
	}

	ath10k_dbg(ar, ATH10K_DBG_BOOT,
		   "boot push board extended data addr 0x%x\n",
		   board_ext_data_addr);

	if (board_ext_data_addr == 0)
		return 0;

	if (data_len != (board_data_size + board_ext_data_size)) {
		ath10k_err(ar, "invalid board (ext) data sizes %zu != %d+%d\n",
			   data_len, board_data_size, board_ext_data_size);
		return -EINVAL;
	}

	ret = ath10k_bmi_write_memory(ar, board_ext_data_addr,
				      data + board_data_size,
				      board_ext_data_size);
	if (ret) {
		ath10k_err(ar, "could not write board ext data (%d)\n", ret);
		return ret;
	}

	ret = ath10k_bmi_write32(ar, hi_board_ext_data_config,
				 (board_ext_data_size << 16) | 1);
	if (ret) {
		ath10k_err(ar, "could not write board ext data bit (%d)\n",
			   ret);
		return ret;
	}

	return 0;
}

static int ath10k_download_board_data(struct ath10k *ar, const void *data,
				      size_t data_len)
{
	u32 board_data_size = ar->hw_params.fw.board_size;
	u32 address;
	int ret;

	ret = ath10k_push_board_ext_data(ar, data, data_len);
	if (ret) {
		ath10k_err(ar, "could not push board ext data (%d)\n", ret);
		goto exit;
	}

	ret = ath10k_bmi_read32(ar, hi_board_data, &address);
	if (ret) {
		ath10k_err(ar, "could not read board data addr (%d)\n", ret);
		goto exit;
	}

	ret = ath10k_bmi_write_memory(ar, address, data,
				      min_t(u32, board_data_size,
					    data_len));
	if (ret) {
		ath10k_err(ar, "could not write board data (%d)\n", ret);
		goto exit;
	}

	ret = ath10k_bmi_write32(ar, hi_board_data_initialized, 1);
	if (ret) {
		ath10k_err(ar, "could not write board data bit (%d)\n", ret);
		goto exit;
	}

exit:
	return ret;
}

static int ath10k_download_cal_file(struct ath10k *ar,
				    const struct firmware *file)
{
	int ret;

	if (!file)
		return -ENOENT;

	if (IS_ERR(file))
		return PTR_ERR(file);

	ret = ath10k_download_board_data(ar, file->data, file->size);
	if (ret) {
		ath10k_err(ar, "failed to download cal_file data: %d\n", ret);
		return ret;
	}

	ath10k_dbg(ar, ATH10K_DBG_BOOT, "boot cal file downloaded\n");

	return 0;
}

static int ath10k_download_cal_dt(struct ath10k *ar, const char *dt_name)
{
	struct device_node *node;
	int data_len;
	void *data;
	int ret;

	node = ar->dev->of_node;
	if (!node)
		/* Device Tree is optional, don't print any warnings if
		 * there's no node for ath10k.
		 */
		return -ENOENT;

	if (!of_get_property(node, dt_name, &data_len)) {
		/* The calibration data node is optional */
		return -ENOENT;
	}

	if (data_len != ar->hw_params.cal_data_len) {
		ath10k_warn(ar, "invalid calibration data length in DT: %d\n",
			    data_len);
		ret = -EMSGSIZE;
		goto out;
	}

	data = kmalloc(data_len, GFP_KERNEL);
	if (!data) {
		ret = -ENOMEM;
		goto out;
	}

	ret = of_property_read_u8_array(node, dt_name, data, data_len);
	if (ret) {
		ath10k_warn(ar, "failed to read calibration data from DT: %d\n",
			    ret);
		goto out_free;
	}

	ret = ath10k_download_board_data(ar, data, data_len);
	if (ret) {
		ath10k_warn(ar, "failed to download calibration data from Device Tree: %d\n",
			    ret);
		goto out_free;
	}

	ret = 0;

out_free:
	kfree(data);

out:
	return ret;
}

static int ath10k_core_get_board_id_from_otp(struct ath10k *ar)
{
	u32 result, address;
	u8 board_id, chip_id;
	int ret;

	address = ar->hw_params.patch_load_addr;

	if (!ar->otp_data || !ar->otp_len) {
		ath10k_warn(ar,
			    "failed to retrieve board id because of invalid otp\n");
		return -ENODATA;
	}

	ath10k_dbg(ar, ATH10K_DBG_BOOT,
		   "boot upload otp to 0x%x len %zd for board id\n",
		   address, ar->otp_len);

	ret = ath10k_bmi_fast_download(ar, address, ar->otp_data, ar->otp_len);
	if (ret) {
		ath10k_err(ar, "could not write otp for board id check: %d\n",
			   ret);
		return ret;
	}

	ret = ath10k_bmi_execute(ar, address, BMI_PARAM_GET_EEPROM_BOARD_ID,
				 &result);
	if (ret) {
		ath10k_err(ar, "could not execute otp for board id check: %d\n",
			   ret);
		return ret;
	}

	board_id = MS(result, ATH10K_BMI_BOARD_ID_FROM_OTP);
	chip_id = MS(result, ATH10K_BMI_CHIP_ID_FROM_OTP);

	ath10k_dbg(ar, ATH10K_DBG_BOOT,
		   "boot get otp board id result 0x%08x board_id %d chip_id %d\n",
		   result, board_id, chip_id);

	if ((result & ATH10K_BMI_BOARD_ID_STATUS_MASK) != 0)
		return -EOPNOTSUPP;

	ar->id.bmi_ids_valid = true;
	ar->id.bmi_board_id = board_id;
	ar->id.bmi_chip_id = chip_id;

	return 0;
}

static int ath10k_download_and_run_otp(struct ath10k *ar)
{
	u32 result, address = ar->hw_params.patch_load_addr;
	u32 bmi_otp_exe_param = ar->hw_params.otp_exe_param;
	int ret;

	ret = ath10k_download_board_data(ar, ar->board_data, ar->board_len);
	if (ret) {
		ath10k_err(ar, "failed to download board data: %d\n", ret);
		return ret;
	}

	/* OTP is optional */

	if (!ar->otp_data || !ar->otp_len) {
		ath10k_warn(ar, "Not running otp, calibration will be incorrect (otp-data %p otp_len %zd)!\n",
			    ar->otp_data, ar->otp_len);
		return 0;
	}

	ath10k_dbg(ar, ATH10K_DBG_BOOT, "boot upload otp to 0x%x len %zd\n",
		   address, ar->otp_len);

	ret = ath10k_bmi_fast_download(ar, address, ar->otp_data, ar->otp_len);
	if (ret) {
		ath10k_err(ar, "could not write otp (%d)\n", ret);
		return ret;
	}

	ret = ath10k_bmi_execute(ar, address, bmi_otp_exe_param, &result);
	if (ret) {
		ath10k_err(ar, "could not execute otp (%d)\n", ret);
		return ret;
	}

	ath10k_dbg(ar, ATH10K_DBG_BOOT, "boot otp execute result %d\n", result);

	if (!(skip_otp || test_bit(ATH10K_FW_FEATURE_IGNORE_OTP_RESULT,
				   ar->fw_features)) &&
	    result != 0) {
		ath10k_err(ar, "otp calibration failed: %d", result);
		return -EINVAL;
	}

	return 0;
}

static int ath10k_download_fw(struct ath10k *ar, enum ath10k_firmware_mode mode)
{
	u32 address, data_len;
	const char *mode_name;
	const void *data;
	int ret;

	address = ar->hw_params.patch_load_addr;

	switch (mode) {
	case ATH10K_FIRMWARE_MODE_NORMAL:
		data = ar->firmware_data;
		data_len = ar->firmware_len;
		mode_name = "normal";
		ret = ath10k_swap_code_seg_configure(ar,
						     ATH10K_SWAP_CODE_SEG_BIN_TYPE_FW);
		if (ret) {
			ath10k_err(ar, "failed to configure fw code swap: %d\n",
				   ret);
			return ret;
		}
		break;
	case ATH10K_FIRMWARE_MODE_UTF:
		data = ar->testmode.utf_firmware_data;
		data_len = ar->testmode.utf_firmware_len;
		mode_name = "utf";
		break;
	default:
		ath10k_err(ar, "unknown firmware mode: %d\n", mode);
		return -EINVAL;
	}

	ath10k_dbg(ar, ATH10K_DBG_BOOT,
		   "boot uploading firmware image %p len %d mode %s\n",
		   data, data_len, mode_name);

	ret = ath10k_bmi_fast_download(ar, address, data, data_len);
	if (ret) {
		ath10k_err(ar, "failed to download %s firmware: %d\n",
			   mode_name, ret);
		return ret;
	}

	return ret;
}

static void ath10k_core_free_board_files(struct ath10k *ar)
{
	if (!IS_ERR(ar->board))
		release_firmware(ar->board);

	ar->board = NULL;
	ar->board_data = NULL;
	ar->board_len = 0;
}

static void ath10k_core_free_firmware_files(struct ath10k *ar)
{
	if (!IS_ERR(ar->otp))
		release_firmware(ar->otp);

	if (!IS_ERR(ar->firmware))
		release_firmware(ar->firmware);

	if (!IS_ERR(ar->cal_file))
		release_firmware(ar->cal_file);

	if (!IS_ERR(ar->fwcfg_file))
		release_firmware(ar->fwcfg_file);
	ar->fwcfg_file = NULL;

	ath10k_swap_code_seg_release(ar);

	ar->otp = NULL;
	ar->otp_data = NULL;
	ar->otp_len = 0;

	ar->firmware = NULL;
	ar->firmware_data = NULL;
	ar->firmware_len = 0;

	ar->cal_file = NULL;
}

static int ath10k_fetch_cal_file(struct ath10k *ar)
{
	char filename[100];

	/* pre-cal-<bus>-<id>.bin */
	scnprintf(filename, sizeof(filename), "pre-cal-%s-%s.bin",
		  ath10k_bus_str(ar->hif.bus), dev_name(ar->dev));

	ar->pre_cal_file = ath10k_fetch_fw_file(ar, ATH10K_FW_DIR, filename);
	if (!IS_ERR(ar->pre_cal_file))
		goto success;

	/* cal-<bus>-<id>.bin */
	scnprintf(filename, sizeof(filename), "cal-%s-%s.bin",
		  ath10k_bus_str(ar->hif.bus), dev_name(ar->dev));

	if (ar->fwcfg.calname[0]) {
		/* Use user-specified file name. */
		strncpy(filename, ar->fwcfg.calname, sizeof(filename));
		filename[sizeof(filename) - 1] = 0;
	} else {
		/* cal-<bus>-<id>.bin */
		scnprintf(filename, sizeof(filename), "cal-%s-%s.bin",
			  ath10k_bus_str(ar->hif.bus), dev_name(ar->dev));
	}

	ar->cal_file = ath10k_fetch_fw_file(ar, ATH10K_FW_DIR, filename);
	if (IS_ERR(ar->cal_file))
		/* calibration file is optional, don't print any warnings */
		return PTR_ERR(ar->cal_file);
success:
	ath10k_dbg(ar, ATH10K_DBG_BOOT, "found calibration file %s/%s\n",
		   ATH10K_FW_DIR, filename);

	return 0;
}

static int ath10k_fetch_fwcfg_file(struct ath10k *ar)
{
	char filename[100];
	const char* buf;
	size_t i = 0;
	char val[100];
	size_t key_idx;
	size_t val_idx;
	char c;
	size_t sz;
	long t;

	ar->fwcfg.flags = 0;

	/* fwcfg-<bus>-<id>.txt */
	/* If this changes, change ath10k_read_fwinfo as well. */
	scnprintf(filename, sizeof(filename), "fwcfg-%s-%s.txt",
		  ath10k_bus_str(ar->hif.bus), dev_name(ar->dev));

	ar->fwcfg_file = ath10k_fetch_fw_file(ar, ATH10K_FW_DIR, filename);
	if (IS_ERR(ar->fwcfg_file)) {
		/* FW config file is optional, don't be scary. */
		ath10k_dbg(ar, ATH10K_DBG_BOOT,
			   "Could not find firmware config file %s/%s, continuing with defaults.\n",
			   ATH10K_FW_DIR, filename);
		return PTR_ERR(ar->fwcfg_file);
	}

	ath10k_dbg(ar, ATH10K_DBG_BOOT, "found firmware config file %s/%s\n",
		   ATH10K_FW_DIR, filename);

	/* Now, attempt to parse results.
	 * Format is key=value
	 */
	buf = (const char*)(ar->fwcfg_file->data);
	while (i < ar->fwcfg_file->size) {
start_again:
		/* First, eat space, or entire line if we have # as first char */
		c = buf[i];
		while (isspace(c)) {
			i++;
			if (i >= ar->fwcfg_file->size)
				goto done;
			c = buf[i];
		}
		/* Eat comment ? */
		if (c == '#') {
			i++;
			while (i < ar->fwcfg_file->size) {
				c = buf[i];
				i++;
				if (c == '\n')
					goto start_again;
			}
			/* Found no newline, must be done. */
			goto done;
		}

		/* If here, we have start of token, store it in 'filename' to save space */
		key_idx = 0;
		while (i < ar->fwcfg_file->size) {
			c = buf[i];
			if (c == '=') {
				i++;
				c = buf[i];
				/* Eat any space after the '=' sign. */
				while (i < ar->fwcfg_file->size) {
					if (!isspace(c)) {
						break;
					}
					i++;
					c = buf[i];
				}
				break;
			}
			if (isspace(c)) {
				i++;
				continue;
			}
			filename[key_idx] = c;
			key_idx++;
			if (key_idx >= sizeof(filename)) {
				/* Too long, bail out. */
				goto done;
			}
			i++;
		}
		filename[key_idx] = 0; /* null terminate */

		/* We have found the key, now find the value */
		val_idx = 0;
		while (i < ar->fwcfg_file->size) {
			c = buf[i];
			if (isspace(c))
				break;
			val[val_idx] = c;
			val_idx++;
			if (val_idx >= sizeof(val)) {
				/* Too long, bail out. */
				goto done;
			}
			i++;
		}
		val[val_idx] = 0; /* null terminate value */

		/* We have key and value now. */
		ath10k_warn(ar, "fwcfg key: %s  val: %s\n",
			    filename, val);

		/* Assign key and values as appropriate */
		if (strcasecmp(filename, "calname") == 0) {
			sz = sizeof(ar->fwcfg.calname);
			strncpy(ar->fwcfg.calname, val, sz);
			ar->fwcfg.calname[sz - 1] = 0; /* ensure null term */
		}
		else if (strcasecmp(filename, "fwname") == 0) {
			sz = sizeof(ar->fwcfg.fwname);
			strncpy(ar->fwcfg.fwname, val, sz);
			ar->fwcfg.fwname[sz - 1] = 0; /* ensure null term */
		}
		else if (strcasecmp(filename, "fwver") == 0) {
			if (kstrtol(val, 0, &t) == 0) {
				ar->fwcfg.fwver = t;
				ar->fwcfg.flags |= ATH10K_FWCFG_FWVER;
			}
		}
		else if (strcasecmp(filename, "vdevs") == 0) {
			if (kstrtol(val, 0, &t) == 0) {
				ar->fwcfg.vdevs = t;
				ar->fwcfg.flags |= ATH10K_FWCFG_VDEVS;
			}
		}
		else if (strcasecmp(filename, "stations") == 0) {
			if (kstrtol(val, 0, &t) == 0) {
				ar->fwcfg.stations = t;
				ar->fwcfg.flags |= ATH10K_FWCFG_STATIONS;
			}
		}
		else if (strcasecmp(filename, "peers") == 0) {
			if (kstrtol(val, 0, &t) == 0) {
				ar->fwcfg.peers = t;
				ar->fwcfg.flags |= ATH10K_FWCFG_PEERS;
			}
		}
		else if (strcasecmp(filename, "nohwcrypt") == 0) {
			if (kstrtol(val, 0, &t) == 0) {
				ar->fwcfg.nohwcrypt = t;
				ar->fwcfg.flags |= ATH10K_FWCFG_NOHWCRYPT;
			}
		}
		else if (strcasecmp(filename, "rate_ctrl_objs") == 0) {
			if (kstrtol(val, 0, &t) == 0) {
				ar->fwcfg.rate_ctrl_objs = t;
				ar->fwcfg.flags |= ATH10K_FWCFG_RATE_CTRL_OBJS;
			}
		}
		else if (strcasecmp(filename, "tx_desc") == 0) {
			if (kstrtol(val, 0, &t) == 0) {
				ar->fwcfg.tx_desc = t;
				ar->fwcfg.flags |= ATH10K_FWCFG_TX_DESC;
			}
		}
		else if (strcasecmp(filename, "max_nss") == 0) {
			if (kstrtol(val, 0, &t) == 0) {
				ar->fwcfg.max_nss = t;
				ar->fwcfg.flags |= ATH10K_FWCFG_MAX_NSS;
			}
		}
		else if (strcasecmp(filename, "tids") == 0) {
			if (kstrtol(val, 0, &t) == 0) {
				ar->fwcfg.num_tids = t;
				ar->fwcfg.flags |= ATH10K_FWCFG_NUM_TIDS;
			}
		}
		else if (strcasecmp(filename, "active_peers") == 0) {
			if (kstrtol(val, 0, &t) == 0) {
				ar->fwcfg.active_peers = t;
				ar->fwcfg.flags |= ATH10K_FWCFG_ACTIVE_PEERS;
			}
		}
		else if (strcasecmp(filename, "skid_limit") == 0) {
			if (kstrtol(val, 0, &t) == 0) {
				ar->fwcfg.skid_limit = t;
				ar->fwcfg.flags |= ATH10K_FWCFG_SKID_LIMIT;
			}
		}
		else if (strcasecmp(filename, "regdom") == 0) {
			if (kstrtol(val, 0, &t) == 0) {
				ar->fwcfg.regdom = t;
				ar->fwcfg.flags |= ATH10K_FWCFG_REGDOM;
			}
		}
		else if (strcasecmp(filename, "bmiss_vdevs") == 0) {
			if (kstrtol(val, 0, &t) == 0) {
				ar->fwcfg.bmiss_vdevs = t;
				ar->fwcfg.flags |= ATH10K_FWCFG_BMISS_VDEVS;
			}
		}
		else {
			ath10k_warn(ar, "Unknown fwcfg key name -:%s:-, val: %s\n",
				    filename, val);
		}
	}
done:
	return 0;
}

static int ath10k_core_fetch_board_data_api_1(struct ath10k *ar)
{
	if (!ar->hw_params.fw.board) {
		ath10k_err(ar, "failed to find board file fw entry\n");
		return -EINVAL;
	}

	ar->board = ath10k_fetch_fw_file(ar,
					 ar->hw_params.fw.dir,
					 ar->hw_params.fw.board);
	if (IS_ERR(ar->board))
		return PTR_ERR(ar->board);

	ar->board_data = ar->board->data;
	ar->board_len = ar->board->size;

	return 0;
}

static int ath10k_core_parse_bd_ie_board(struct ath10k *ar,
					 const void *buf, size_t buf_len,
					 const char *boardname)
{
	const struct ath10k_fw_ie *hdr;
	bool name_match_found;
	int ret, board_ie_id;
	size_t board_ie_len;
	const void *board_ie_data;

	name_match_found = false;

	/* go through ATH10K_BD_IE_BOARD_ elements */
	while (buf_len > sizeof(struct ath10k_fw_ie)) {
		hdr = buf;
		board_ie_id = le32_to_cpu(hdr->id);
		board_ie_len = le32_to_cpu(hdr->len);
		board_ie_data = hdr->data;

		buf_len -= sizeof(*hdr);
		buf += sizeof(*hdr);

		if (buf_len < ALIGN(board_ie_len, 4)) {
			ath10k_err(ar, "invalid ATH10K_BD_IE_BOARD length: %zu < %zu\n",
				   buf_len, ALIGN(board_ie_len, 4));
			ret = -EINVAL;
			goto out;
		}

		switch (board_ie_id) {
		case ATH10K_BD_IE_BOARD_NAME:
			ath10k_dbg_dump(ar, ATH10K_DBG_BOOT, "board name", "",
					board_ie_data, board_ie_len);

			if (board_ie_len != strlen(boardname))
				break;

			ret = memcmp(board_ie_data, boardname, strlen(boardname));
			if (ret)
				break;

			name_match_found = true;
			ath10k_dbg(ar, ATH10K_DBG_BOOT,
				   "boot found match for name '%s'",
				   boardname);
			break;
		case ATH10K_BD_IE_BOARD_DATA:
			if (!name_match_found)
				/* no match found */
				break;

			ath10k_dbg(ar, ATH10K_DBG_BOOT,
				   "boot found board data for '%s'",
				   boardname);

			ar->board_data = board_ie_data;
			ar->board_len = board_ie_len;

			ret = 0;
			goto out;
		default:
			ath10k_warn(ar, "unknown ATH10K_BD_IE_BOARD found: %d\n",
				    board_ie_id);
			break;
		}

		/* jump over the padding */
		board_ie_len = ALIGN(board_ie_len, 4);

		buf_len -= board_ie_len;
		buf += board_ie_len;
	}

	/* no match found */
	ret = -ENOENT;

out:
	return ret;
}

static int ath10k_core_fetch_board_data_api_n(struct ath10k *ar,
					      const char *boardname,
					      const char *filename)
{
	size_t len, magic_len, ie_len;
	struct ath10k_fw_ie *hdr;
	const u8 *data;
	int ret, ie_id;

	ar->board = ath10k_fetch_fw_file(ar, ar->hw_params.fw.dir, filename);
	if (IS_ERR(ar->board))
		return PTR_ERR(ar->board);

	data = ar->board->data;
	len = ar->board->size;

	/* magic has extra null byte padded */
	magic_len = strlen(ATH10K_BOARD_MAGIC) + 1;
	if (len < magic_len) {
		ath10k_err(ar, "failed to find magic value in %s/%s, file too short: %zu\n",
			   ar->hw_params.fw.dir, filename, len);
		ret = -EINVAL;
		goto err;
	}

	if (memcmp(data, ATH10K_BOARD_MAGIC, magic_len)) {
		ath10k_err(ar, "found invalid board magic\n");
		ret = -EINVAL;
		goto err;
	}

	/* magic is padded to 4 bytes */
	magic_len = ALIGN(magic_len, 4);
	if (len < magic_len) {
		ath10k_err(ar, "failed: %s/%s too small to contain board data, len: %zu\n",
			   ar->hw_params.fw.dir, filename, len);
		ret = -EINVAL;
		goto err;
	}

	data += magic_len;
	len -= magic_len;

	while (len > sizeof(struct ath10k_fw_ie)) {
		hdr = (struct ath10k_fw_ie *)data;
		ie_id = le32_to_cpu(hdr->id);
		ie_len = le32_to_cpu(hdr->len);

		len -= sizeof(*hdr);
		data = hdr->data;

		if (len < ALIGN(ie_len, 4)) {
			ath10k_err(ar, "invalid length for board ie_id %d ie_len %zu len %zu\n",
				   ie_id, ie_len, len);
			ret = -EINVAL;
			goto err;
		}

		switch (ie_id) {
		case ATH10K_BD_IE_BOARD:
			ret = ath10k_core_parse_bd_ie_board(ar, data, ie_len,
							    boardname);
			if (ret == -ENOENT)
				/* no match found, continue */
				break;
			else if (ret)
				/* there was an error, bail out */
				goto err;

			/* board data found */
			goto out;
		}

		/* jump over the padding */
		ie_len = ALIGN(ie_len, 4);

		len -= ie_len;
		data += ie_len;
	}

out:
	if (!ar->board_data || !ar->board_len) {
		ath10k_err(ar,
			   "failed to fetch board data for %s from %s/%s\n",
			   boardname, ar->hw_params.fw.dir, filename);
		ret = -ENODATA;
		goto err;
	}

	return 0;

err:
	ath10k_core_free_board_files(ar);
	return ret;
}

static int ath10k_core_create_board_name(struct ath10k *ar, char *name,
					 size_t name_len)
{
	if (ar->id.bmi_ids_valid) {
		scnprintf(name, name_len,
			  "bus=%s,bmi-chip-id=%d,bmi-board-id=%d",
			  ath10k_bus_str(ar->hif.bus),
			  ar->id.bmi_chip_id,
			  ar->id.bmi_board_id);
		goto out;
	}

	scnprintf(name, name_len,
		  "bus=%s,vendor=%04x,device=%04x,subsystem-vendor=%04x,subsystem-device=%04x",
		  ath10k_bus_str(ar->hif.bus),
		  ar->id.vendor, ar->id.device,
		  ar->id.subsystem_vendor, ar->id.subsystem_device);

out:
	ath10k_dbg(ar, ATH10K_DBG_BOOT, "boot using board name '%s'\n", name);

	return 0;
}

static int ath10k_core_fetch_board_file(struct ath10k *ar)
{
	char boardname[100];
	int ret;

	ret = ath10k_core_create_board_name(ar, boardname, sizeof(boardname));
	if (ret) {
		ath10k_err(ar, "failed to create board name: %d", ret);
		return ret;
	}

	ar->bd_api = 2;
	ret = ath10k_core_fetch_board_data_api_n(ar, boardname,
						 ATH10K_BOARD_API2_FILE);
	if (!ret)
		goto success;

	ar->bd_api = 1;
	ret = ath10k_core_fetch_board_data_api_1(ar);
	if (ret) {
		ath10k_err(ar, "failed to fetch board data\n");
		return ret;
	}

success:
	ath10k_dbg(ar, ATH10K_DBG_BOOT, "using board api %d\n", ar->bd_api);
	return 0;
}

static int ath10k_core_fetch_firmware_api_1(struct ath10k *ar)
{
	int ret = 0;

	if (ar->hw_params.fw.fw == NULL) {
		ath10k_err(ar, "firmware file not defined\n");
		return -EINVAL;
	}

	ar->firmware = ath10k_fetch_fw_file(ar,
					    ar->hw_params.fw.dir,
					    ar->hw_params.fw.fw);
	if (IS_ERR(ar->firmware)) {
		ret = PTR_ERR(ar->firmware);
		ath10k_err(ar, "could not fetch firmware (%d)\n", ret);
		goto err;
	}

	ar->firmware_data = ar->firmware->data;
	ar->firmware_len = ar->firmware->size;

	/* OTP may be undefined. If so, don't fetch it at all */
	if (ar->hw_params.fw.otp == NULL)
		return 0;

	ar->otp = ath10k_fetch_fw_file(ar,
				       ar->hw_params.fw.dir,
				       ar->hw_params.fw.otp);
	if (IS_ERR(ar->otp)) {
		ret = PTR_ERR(ar->otp);
		ath10k_err(ar, "could not fetch otp (%d)\n", ret);
		goto err;
	}

	ar->otp_data = ar->otp->data;
	ar->otp_len = ar->otp->size;

	/* Save firmware name so we can display it later. */
	strncpy(ar->current_fwname, ar->hw_params.fw.fw,
		sizeof(ar->current_fwname));
	ar->current_fwname[sizeof(ar->current_fwname) - 1] = 0;

	return 0;

err:
	ath10k_core_free_firmware_files(ar);
	return ret;
}

struct ath10k_bss_rom_ie {
	__le32 ram_addr;
	__le32 ram_len;
	__le32 rom_addr;
	__le32 rom_len;
} __packed;

static int ath10k_core_fetch_firmware_api_n(struct ath10k *ar, const char *name)
{
	size_t magic_len, len, ie_len;
	int ie_id, i, index, bit, ret;
	struct ath10k_fw_ie *hdr;
	const u8 *data;
	__le32 *timestamp, *version;
	struct ath10k_bss_rom_ie *bss;

	/* first fetch the firmware file (firmware-*.bin) */
	ar->firmware = ath10k_fetch_fw_file(ar, ar->hw_params.fw.dir, name);
	if (IS_ERR(ar->firmware)) {
		ath10k_err(ar, "could not fetch firmware file '%s/%s': %ld\n",
			   ar->hw_params.fw.dir, name, PTR_ERR(ar->firmware));
		return PTR_ERR(ar->firmware);
	}

	data = ar->firmware->data;
	len = ar->firmware->size;

	/* magic also includes the null byte, check that as well */
	magic_len = strlen(ATH10K_FIRMWARE_MAGIC) + 1;

	if (len < magic_len) {
		ath10k_err(ar, "firmware file '%s/%s' too small to contain magic: %zu\n",
			   ar->hw_params.fw.dir, name, len);
		ret = -EINVAL;
		goto err;
	}

	if (memcmp(data, ATH10K_FIRMWARE_MAGIC, magic_len) != 0) {
		ath10k_err(ar, "invalid firmware magic\n");
		ret = -EINVAL;
		goto err;
	}

	/* jump over the padding */
	magic_len = ALIGN(magic_len, 4);

	len -= magic_len;
	data += magic_len;

	/* loop elements */
	while (len > sizeof(struct ath10k_fw_ie)) {
		hdr = (struct ath10k_fw_ie *)data;

		ie_id = le32_to_cpu(hdr->id);
		ie_len = le32_to_cpu(hdr->len);

		len -= sizeof(*hdr);
		data += sizeof(*hdr);

		if (len < ie_len) {
			ath10k_err(ar, "invalid length for FW IE %d (%zu < %zu)\n",
				   ie_id, len, ie_len);
			ret = -EINVAL;
			goto err;
		}

		switch (ie_id) {
		case ATH10K_FW_IE_FW_VERSION:
			if (ie_len > sizeof(ar->hw->wiphy->fw_version) - 1)
				break;

			memcpy(ar->hw->wiphy->fw_version, data, ie_len);
			ar->hw->wiphy->fw_version[ie_len] = '\0';

			ath10k_dbg(ar, ATH10K_DBG_BOOT,
				   "found fw version %s\n",
				    ar->hw->wiphy->fw_version);
			break;
		case ATH10K_FW_IE_TIMESTAMP:
			if (ie_len != sizeof(u32))
				break;

			timestamp = (__le32 *)data;

			ath10k_dbg(ar, ATH10K_DBG_BOOT, "found fw timestamp %d\n",
				   le32_to_cpup(timestamp));
			break;
		case ATH10K_FW_IE_FEATURES:
			ath10k_dbg(ar, ATH10K_DBG_BOOT,
				   "found firmware features ie (%zd B)\n",
				   ie_len);

			for (i = 0; i < ATH10K_FW_FEATURE_COUNT; i++) {
				index = i / 8;
				bit = i % 8;

				if (index == ie_len)
					break;

				if (data[index] & (1 << bit)) {
					ath10k_dbg(ar, ATH10K_DBG_BOOT,
						   "Enabling feature bit: %i\n",
						   i);
					__set_bit(i, ar->fw_features);
				}
			}

			ath10k_dbg_dump(ar, ATH10K_DBG_BOOT, "features", "",
					ar->fw_features,
					sizeof(ar->fw_features));
			break;
		case ATH10K_FW_IE_FW_IMAGE:
			ath10k_dbg(ar, ATH10K_DBG_BOOT,
				   "found fw image ie (%zd B)\n",
				   ie_len);

			ar->firmware_data = data;
			ar->firmware_len = ie_len;

			break;
		case ATH10K_FW_IE_OTP_IMAGE:
			ath10k_dbg(ar, ATH10K_DBG_BOOT,
				   "found otp image ie (%zd B)\n",
				   ie_len);

			ar->otp_data = data;
			ar->otp_len = ie_len;

			break;
		case ATH10K_FW_IE_WMI_OP_VERSION:
			/* Upstream stole the ID CT firmware was using, so add
			 * hack-around to deal with backwards-compat. --Ben
			 */
			if (ie_len >= sizeof(*bss))
				goto fw_ie_bss_info_ct;

			if (ie_len != sizeof(u32))
				break;

			version = (__le32 *)data;

			ar->wmi.op_version = le32_to_cpup(version);

			ath10k_dbg(ar, ATH10K_DBG_BOOT, "found fw ie wmi op version %d\n",
				   ar->wmi.op_version);
			break;
		case ATH10K_FW_IE_HTT_OP_VERSION:
			if (ie_len != sizeof(u32))
				break;

			version = (__le32 *)data;

			ar->htt.op_version = le32_to_cpup(version);

			ath10k_dbg(ar, ATH10K_DBG_BOOT, "found fw ie htt op version %d\n",
				   ar->htt.op_version);
			break;
		case ATH10K_FW_IE_FW_CODE_SWAP_IMAGE:
			ath10k_dbg(ar, ATH10K_DBG_BOOT,
				   "found fw code swap image ie (%zd B)\n",
				   ie_len);
			ar->swap.firmware_codeswap_data = data;
			ar->swap.firmware_codeswap_len = ie_len;
			break;
		case ATH10K_FW_IE_BSS_INFO_CT:
fw_ie_bss_info_ct:
			if (ie_len < sizeof(*bss)) {
				ath10k_warn(ar, "invalid ie len for bss-info (%zd)\n",
					    ie_len);
				break;
			}
			bss = (struct ath10k_bss_rom_ie *)(data);

			ar->fw.ram_bss_addr = le32_to_cpu(bss->ram_addr);
			ar->fw.ram_bss_len = le32_to_cpu(bss->ram_len);
			ath10k_dbg(ar, ATH10K_DBG_BOOT,
				   "found RAM BSS addr 0x%x length %d\n",
				   ar->fw.ram_bss_addr, ar->fw.ram_bss_len);

			if (ar->fw.ram_bss_len > ATH10K_RAM_BSS_BUF_LEN) {
				ath10k_warn(ar, "too long firmware RAM BSS length: %d\n",
					    ar->fw.ram_bss_len);
				ar->fw.ram_bss_len = 0;
			}

			ar->fw.rom_bss_addr = le32_to_cpu(bss->rom_addr);
			ar->fw.rom_bss_len = le32_to_cpu(bss->rom_len);
			ath10k_dbg(ar, ATH10K_DBG_BOOT,
				   "found ROM BSS addr 0x%x length %d\n",
				   ar->fw.rom_bss_addr, ar->fw.rom_bss_len);

			if (ar->fw.rom_bss_len > ATH10K_ROM_BSS_BUF_LEN) {
				ath10k_warn(ar, "too long firmware ROM BSS length: %d\n",
					    ar->fw.rom_bss_len);
				ar->fw.rom_bss_len = 0;
			}

			break;
		default:
			ath10k_warn(ar, "Unknown FW IE: %u\n",
				    le32_to_cpu(hdr->id));
			break;
		}

		/* jump over the padding */
		ie_len = ALIGN(ie_len, 4);

		len -= ie_len;
		data += ie_len;
	}

	/* Only CT firmware has BSS stuff, so we can use this to fix up
	 * flags for backwards and forwards compat with older/newer CT firmware.
	 * (upstream stole some bits it was using)
	 */
	if (ar->fw.rom_bss_addr) {
		if (test_bit(5, ar->fw_features))
			__set_bit(ATH10K_FW_FEATURE_WMI_10X_CT, ar->fw_features);

		if (test_bit(6, ar->fw_features))
			__set_bit(ATH10K_FW_FEATURE_CT_RXSWCRYPT, ar->fw_features);
	}


	if (!ar->firmware_data || !ar->firmware_len) {
		ath10k_warn(ar, "No ATH10K_FW_IE_FW_IMAGE found from '%s/%s', skipping\n",
			    ar->hw_params.fw.dir, name);
		ret = -ENOMEDIUM;
		goto err;
	}

	/* Save firmware name so we can display it later. */
	strncpy(ar->current_fwname, name, sizeof(ar->current_fwname));
	ar->current_fwname[sizeof(ar->current_fwname) - 1] = 0;

	return 0;

err:
	ath10k_core_free_firmware_files(ar);
	return ret;
}

static int ath10k_core_fetch_firmware_files(struct ath10k *ar)
{
	int ret;

	/* First, see if we have a special config file for this firmware. */
	ath10k_fetch_fwcfg_file(ar);

	/* calibration file is optional, don't check for any errors */
	ath10k_fetch_cal_file(ar);

	/* Check for user-specified firmware name. */
	if (ar->fwcfg.fwname[0] && (ar->fwcfg.flags & ATH10K_FWCFG_FWVER)) {
		ar->fw_api = ar->fwcfg.fwver;
		ath10k_dbg(ar, ATH10K_DBG_BOOT,
			   "trying user-specified fw %s api %d\n",
			   ar->fwcfg.fwname, ar->fw_api);

		ret = ath10k_core_fetch_firmware_api_n(ar, ar->fwcfg.fwname);
		if (ret == 0)
			goto success;
	}

	ar->fw_api = 5;
	ath10k_dbg(ar, ATH10K_DBG_BOOT, "trying fw api %d\n", ar->fw_api);

	ret = ath10k_core_fetch_firmware_api_n(ar, ATH10K_FW_API5_FILE);
	if (ret == 0)
		goto success;

	ar->fw_api = 4;
	ath10k_dbg(ar, ATH10K_DBG_BOOT, "trying fw api %d\n", ar->fw_api);

	ret = ath10k_core_fetch_firmware_api_n(ar, ATH10K_FW_API4_FILE);
	if (ret == 0)
		goto success;

	ar->fw_api = 3;
	ath10k_dbg(ar, ATH10K_DBG_BOOT, "trying fw api %d\n", ar->fw_api);

	ret = ath10k_core_fetch_firmware_api_n(ar, ATH10K_FW_API3_FILE);
	if (ret == 0)
		goto success;

	ar->fw_api = 2;
	ath10k_dbg(ar, ATH10K_DBG_BOOT, "trying fw api %d\n", ar->fw_api);

	ret = ath10k_core_fetch_firmware_api_n(ar, ATH10K_FW_API2_FILE);
	if (ret == 0)
		goto success;

	ar->fw_api = 1;
	ath10k_dbg(ar, ATH10K_DBG_BOOT, "trying fw api %d\n", ar->fw_api);

	ret = ath10k_core_fetch_firmware_api_1(ar);
	if (ret)
		return ret;

success:
	ath10k_dbg(ar, ATH10K_DBG_BOOT, "using fw api %d: %s/%s\n",
		   ar->fw_api, ar->hw_params.fw.dir, ar->current_fwname);

	return 0;
}

static int ath10k_core_pre_cal_download(struct ath10k *ar)
{
	int ret;

	ret = ath10k_download_cal_file(ar, ar->pre_cal_file);
	if (ret == 0) {
		ar->cal_mode = ATH10K_PRE_CAL_MODE_FILE;
		goto success;
	}

	ath10k_dbg(ar, ATH10K_DBG_BOOT,
		   "boot did not find a pre calibration file, try DT next: %d\n",
		   ret);

	ret = ath10k_download_cal_dt(ar, "qcom,ath10k-pre-calibration-data");
	if (ret) {
		ath10k_dbg(ar, ATH10K_DBG_BOOT,
			   "unable to load pre cal data from DT: %d\n", ret);
		return ret;
	}
	ar->cal_mode = ATH10K_PRE_CAL_MODE_DT;

success:
	ath10k_dbg(ar, ATH10K_DBG_BOOT, "boot using calibration mode %s\n",
		   ath10k_cal_mode_str(ar->cal_mode));

	return 0;
}

static int ath10k_core_pre_cal_config(struct ath10k *ar)
{
	int ret;

	ret = ath10k_core_pre_cal_download(ar);
	if (ret) {
		ath10k_dbg(ar, ATH10K_DBG_BOOT,
			   "failed to load pre cal data: %d\n", ret);
		return ret;
	}

	ret = ath10k_core_get_board_id_from_otp(ar);
	if (ret) {
		ath10k_err(ar, "failed to get board id: %d\n", ret);
		return ret;
	}

	ret = ath10k_download_and_run_otp(ar);
	if (ret) {
		ath10k_err(ar, "failed to run otp: %d\n", ret);
		return ret;
	}

	ath10k_dbg(ar, ATH10K_DBG_BOOT,
		   "pre cal configuration done successfully\n");

	return 0;
}

static int ath10k_download_cal_data(struct ath10k *ar)
{
	int ret;

	ret = ath10k_core_pre_cal_config(ar);
	if (ret == 0)
		return 0;

	ath10k_dbg(ar, ATH10K_DBG_BOOT,
		   "pre cal download procedure failed, try cal file: %d\n",
		   ret);

	ret = ath10k_download_cal_file(ar, ar->cal_file);
	if (ret == 0) {
		ar->cal_mode = ATH10K_CAL_MODE_FILE;
		goto done;
	}

	ath10k_dbg(ar, ATH10K_DBG_BOOT,
		   "boot did not find a calibration file, try DT next: %d\n",
		   ret);

	ret = ath10k_download_cal_dt(ar, "qcom,ath10k-calibration-data");
	if (ret == 0) {
		ar->cal_mode = ATH10K_CAL_MODE_DT;
		goto done;
	}

	ath10k_dbg(ar, ATH10K_DBG_BOOT,
		   "boot did not find DT entry, try OTP next: %d\n",
		   ret);

	ret = ath10k_download_and_run_otp(ar);
	if (ret) {
		ath10k_err(ar, "failed to run otp: %d\n", ret);
		return ret;
	}

	ar->cal_mode = ATH10K_CAL_MODE_OTP;

done:
	ath10k_dbg(ar, ATH10K_DBG_BOOT, "boot using calibration mode %s\n",
		   ath10k_cal_mode_str(ar->cal_mode));
	return 0;
}

static int ath10k_init_uart(struct ath10k *ar)
{
	int ret;

	/*
	 * Explicitly setting UART prints to zero as target turns it on
	 * based on scratch registers.
	 */
	ret = ath10k_bmi_write32(ar, hi_serial_enable, 0);
	if (ret) {
		ath10k_warn(ar, "could not disable UART prints (%d)\n", ret);
		return ret;
	}

	if (!uart_print)
		return 0;

	ret = ath10k_bmi_write32(ar, hi_dbg_uart_txpin, ar->hw_params.uart_pin);
	if (ret) {
		ath10k_warn(ar, "could not enable UART prints (%d)\n", ret);
		return ret;
	}

	ret = ath10k_bmi_write32(ar, hi_serial_enable, 1);
	if (ret) {
		ath10k_warn(ar, "could not enable UART prints (%d)\n", ret);
		return ret;
	}

	/* Set the UART baud rate to 19200. */
	ret = ath10k_bmi_write32(ar, hi_desired_baud_rate, 19200);
	if (ret) {
		ath10k_warn(ar, "could not set the baud rate (%d)\n", ret);
		return ret;
	}

	ath10k_info(ar, "UART prints enabled: 19200, tx-pin: %d\n",
		    ar->hw_params.uart_pin);
	return 0;
}

static int ath10k_init_hw_params(struct ath10k *ar)
{
	const struct ath10k_hw_params *uninitialized_var(hw_params);
	int i;

	for (i = 0; i < ARRAY_SIZE(ath10k_hw_params_list); i++) {
		hw_params = &ath10k_hw_params_list[i];

		if (hw_params->id == ar->target_version &&
		    hw_params->dev_id == ar->dev_id)
			break;
	}

	if (i == ARRAY_SIZE(ath10k_hw_params_list)) {
		ath10k_err(ar, "Unsupported hardware version: 0x%x\n",
			   ar->target_version);
		return -EINVAL;
	}

	ar->hw_params = *hw_params;

	ath10k_dbg(ar, ATH10K_DBG_BOOT, "Hardware name %s version 0x%x\n",
		   ar->hw_params.name, ar->target_version);

	return 0;
}

static void ath10k_core_restart(struct work_struct *work)
{
	struct ath10k *ar = container_of(work, struct ath10k, restart_work);

	set_bit(ATH10K_FLAG_CRASH_FLUSH, &ar->dev_flags);

	/* Place a barrier to make sure the compiler doesn't reorder
	 * CRASH_FLUSH and calling other functions.
	 */
	barrier();

	ieee80211_stop_queues(ar->hw);
	ath10k_drain_tx(ar);
	complete_all(&ar->scan.started);
	complete_all(&ar->scan.completed);
	complete_all(&ar->scan.on_channel);
	complete_all(&ar->offchan_tx_completed);
	complete_all(&ar->install_key_done);
	complete_all(&ar->vdev_setup_done);
	complete_all(&ar->thermal.wmi_sync);
	wake_up(&ar->htt.empty_tx_wq);
	wake_up(&ar->wmi.tx_credits_wq);
	wake_up(&ar->peer_mapping_wq);

	mutex_lock(&ar->conf_mutex);

	switch (ar->state) {
	case ATH10K_STATE_ON:
		ar->state = ATH10K_STATE_RESTARTING;
		ath10k_hif_stop(ar);
		ath10k_scan_finish(ar);
		ieee80211_restart_hw(ar->hw);
		break;
	case ATH10K_STATE_OFF:
		/* this can happen if driver is being unloaded
		 * or if the crash happens during FW probing */
		ath10k_warn(ar, "cannot restart a device that hasn't been started\n");
		break;
	case ATH10K_STATE_RESTARTING:
		/* hw restart might be requested from multiple places */
		break;
	case ATH10K_STATE_RESTARTED:
		ar->state = ATH10K_STATE_WEDGED;
		/* fall through */
	case ATH10K_STATE_WEDGED:
		ath10k_warn(ar, "device is wedged, will not restart\n");
		break;
	case ATH10K_STATE_UTF:
		ath10k_warn(ar, "firmware restart in UTF mode not supported\n");
		break;
	}

	mutex_unlock(&ar->conf_mutex);
}

static int ath10k_core_init_firmware_features(struct ath10k *ar)
{
	if (test_bit(ATH10K_FW_FEATURE_WMI_10_2, ar->fw_features) &&
	    !test_bit(ATH10K_FW_FEATURE_WMI_10X, ar->fw_features)) {
		ath10k_err(ar, "feature bits corrupted: 10.2 feature requires 10.x feature to be set as well");
		return -EINVAL;
	}

	if (ar->wmi.op_version >= ATH10K_FW_WMI_OP_VERSION_MAX) {
		ath10k_err(ar, "unsupported WMI OP version (max %d): %d\n",
			   ATH10K_FW_WMI_OP_VERSION_MAX, ar->wmi.op_version);
		return -EINVAL;
	}

	ar->wmi.rx_decap_mode = ATH10K_HW_TXRX_NATIVE_WIFI;
	switch (ath10k_cryptmode_param) {
	case ATH10K_CRYPT_MODE_HW:
		clear_bit(ATH10K_FLAG_RAW_MODE, &ar->dev_flags);
		clear_bit(ATH10K_FLAG_HW_CRYPTO_DISABLED, &ar->dev_flags);
		break;
	case ATH10K_CRYPT_MODE_SW:
		if (!test_bit(ATH10K_FW_FEATURE_RAW_MODE_SUPPORT,
			      ar->fw_features)) {
			ath10k_err(ar, "cryptmode > 0 requires raw mode support from firmware");
			return -EINVAL;
		}

		set_bit(ATH10K_FLAG_RAW_MODE, &ar->dev_flags);
		set_bit(ATH10K_FLAG_HW_CRYPTO_DISABLED, &ar->dev_flags);
		break;
	default:
		ath10k_info(ar, "invalid cryptmode: %d\n",
			    ath10k_cryptmode_param);
		return -EINVAL;
	}

	ar->htt.max_num_amsdu = ATH10K_HTT_MAX_NUM_AMSDU_DEFAULT;
	ar->htt.max_num_ampdu = ATH10K_HTT_MAX_NUM_AMPDU_DEFAULT;

	if (rawmode) {
		if (!test_bit(ATH10K_FW_FEATURE_RAW_MODE_SUPPORT,
			      ar->fw_features)) {
			ath10k_err(ar, "rawmode = 1 requires support from firmware");
			return -EINVAL;
		}
		set_bit(ATH10K_FLAG_RAW_MODE, &ar->dev_flags);
	}

	if (test_bit(ATH10K_FLAG_RAW_MODE, &ar->dev_flags)) {
		ar->wmi.rx_decap_mode = ATH10K_HW_TXRX_RAW;

		/* Workaround:
		 *
		 * Firmware A-MSDU aggregation breaks with RAW Tx encap mode
		 * and causes enormous performance issues (malformed frames,
		 * etc).
		 *
		 * Disabling A-MSDU makes RAW mode stable with heavy traffic
		 * albeit a bit slower compared to regular operation.
		 */
		ar->htt.max_num_amsdu = 1;
	}

	/* Backwards compatibility for firmwares without
	 * ATH10K_FW_IE_WMI_OP_VERSION.
	 */
	if (ar->wmi.op_version == ATH10K_FW_WMI_OP_VERSION_UNSET) {
		if (test_bit(ATH10K_FW_FEATURE_WMI_10X, ar->fw_features)) {
			if (test_bit(ATH10K_FW_FEATURE_WMI_10_2,
				     ar->fw_features))
				ar->wmi.op_version = ATH10K_FW_WMI_OP_VERSION_10_2;
			else
				ar->wmi.op_version = ATH10K_FW_WMI_OP_VERSION_10_1;
		} else {
			ar->wmi.op_version = ATH10K_FW_WMI_OP_VERSION_MAIN;
		}
	}

	/* Backwards compatibility for firmwares without
	 * ATH10K_FW_IE_HTT_OP_VERSION.
	 */
	if (ar->htt.op_version == ATH10K_FW_HTT_OP_VERSION_UNSET) {
		switch (ar->wmi.op_version) {
		case ATH10K_FW_WMI_OP_VERSION_MAIN:
			ar->htt.op_version = ATH10K_FW_HTT_OP_VERSION_MAIN;
			break;
		case ATH10K_FW_WMI_OP_VERSION_10_1:
		case ATH10K_FW_WMI_OP_VERSION_10_2:
		case ATH10K_FW_WMI_OP_VERSION_10_2_4:
			ar->htt.op_version = ATH10K_FW_HTT_OP_VERSION_10_1;
			break;
		case ATH10K_FW_WMI_OP_VERSION_TLV:
			ar->htt.op_version = ATH10K_FW_HTT_OP_VERSION_TLV;
			break;
		case ATH10K_FW_WMI_OP_VERSION_10_4:
		case ATH10K_FW_WMI_OP_VERSION_UNSET:
		case ATH10K_FW_WMI_OP_VERSION_MAX:
			WARN_ON(1);
			return -EINVAL;
		}
	}

	/* CT 10.1 firmware slowly added features, all mostly under one feature
	 * flag.  But, for 10.2, I need to add features at a time so that we can
	 * maintain ability to bisect the firmware and to have fine-grained support
	 * for enabling/disabling firmware features.  For backwards-compt with 10.1
	 * firmware, set all the flags here.
	 */
	if (test_bit(ATH10K_FW_FEATURE_WMI_10X_CT, ar->fw_features) &&
	    (ar->wmi.op_version == ATH10K_FW_WMI_OP_VERSION_10_1)) {
		ath10k_warn(ar, "Adding extra 10.1 CT feature flags\n");
		__set_bit(ATH10K_FW_FEATURE_SET_SPECIAL_CT, ar->fw_features);
		__set_bit(ATH10K_FW_FEATURE_REGDUMP_CT, ar->fw_features);
		__set_bit(ATH10K_FW_FEATURE_TXRATE_CT, ar->fw_features);
		__set_bit(ATH10K_FW_FEATURE_FLUSH_ALL_CT, ar->fw_features);
		__set_bit(ATH10K_FW_FEATURE_PINGPONG_READ_CT, ar->fw_features);
		__set_bit(ATH10K_FW_FEATURE_SKIP_CH_RES_CT, ar->fw_features);
		__set_bit(ATH10K_FW_FEATURE_NOP_CT, ar->fw_features);
	}

	switch (ar->wmi.op_version) {
	case ATH10K_FW_WMI_OP_VERSION_MAIN:
		ar->bmiss_offload_max_vdev = TARGET_BMISS_OFFLOAD_MAX_VDEV;
		ar->skid_limit = TARGET_AST_SKID_LIMIT;
		ar->max_num_peers = TARGET_NUM_PEERS;
		ar->max_num_stations = TARGET_NUM_STATIONS;
		ar->max_num_vdevs = TARGET_NUM_VDEVS;
		ar->htt.max_num_pending_tx = TARGET_NUM_MSDU_DESC;
		ar->fw_stats_req_mask = WMI_STAT_PDEV | WMI_STAT_VDEV |
			WMI_STAT_PEER;
		ar->max_spatial_stream = WMI_MAX_SPATIAL_STREAM;
		ar->num_tids = TARGET_NUM_TIDS;
		break;
	case ATH10K_FW_WMI_OP_VERSION_10_1:
		ar->bmiss_offload_max_vdev = TARGET_10X_BMISS_OFFLOAD_MAX_VDEV;
		ar->skid_limit = TARGET_10X_AST_SKID_LIMIT;
		ar->num_tids = TARGET_10X_NUM_TIDS;
		if (test_bit(ATH10K_FW_FEATURE_WMI_10X_CT, ar->fw_features)) {
			ar->skid_limit = TARGET_10X_AST_SKID_LIMIT_CT;
			ar->max_num_peers = ath10k_modparam_target_num_peers_ct;
			ar->max_num_stations = TARGET_10X_NUM_STATIONS;
			ar->max_num_vdevs = ath10k_modparam_target_num_vdevs_ct;
			ar->htt.max_num_pending_tx = ath10k_modparam_target_num_msdu_desc_ct;
		} else {
			ar->max_num_peers = TARGET_10X_NUM_PEERS;
			ar->max_num_stations = TARGET_10X_NUM_STATIONS;
			ar->max_num_vdevs = TARGET_10X_NUM_VDEVS;
			ar->htt.max_num_pending_tx = TARGET_10X_NUM_MSDU_DESC;
		}
		ar->fw_stats_req_mask = WMI_STAT_PEER;
		ar->max_spatial_stream = WMI_MAX_SPATIAL_STREAM;

		if (test_bit(WMI_SERVICE_PEER_STATS, ar->wmi.svc_map)) {
			ar->num_tids = TARGET_10X_TX_STATS_NUM_TIDS;
		} else {
			ar->num_tids = TARGET_10X_NUM_TIDS;
		}
		break;
	case ATH10K_FW_WMI_OP_VERSION_10_2:
	case ATH10K_FW_WMI_OP_VERSION_10_2_4:
		ar->bmiss_offload_max_vdev = TARGET_10X_BMISS_OFFLOAD_MAX_VDEV;
		ar->skid_limit = TARGET_10X_AST_SKID_LIMIT;
		if (test_bit(WMI_SERVICE_PEER_STATS, ar->wmi.svc_map)) {
			ar->max_num_peers = TARGET_10X_TX_STATS_NUM_PEERS;
			ar->max_num_stations = TARGET_10X_TX_STATS_NUM_STATIONS;
			ar->num_tids = TARGET_10X_TX_STATS_NUM_TIDS;
		} else {
			ar->max_num_peers = TARGET_10X_NUM_PEERS;
			ar->max_num_stations = TARGET_10X_NUM_STATIONS;
			ar->num_tids = TARGET_10X_NUM_TIDS;
		}
		ar->max_num_vdevs = TARGET_10X_NUM_VDEVS;
		ar->htt.max_num_pending_tx = TARGET_10X_NUM_MSDU_DESC;
		ar->fw_stats_req_mask = WMI_STAT_PEER;
		ar->max_spatial_stream = WMI_MAX_SPATIAL_STREAM;
		break;
	case ATH10K_FW_WMI_OP_VERSION_TLV:
		ar->bmiss_offload_max_vdev = TARGET_10X_BMISS_OFFLOAD_MAX_VDEV;
		ar->max_num_peers = TARGET_TLV_NUM_PEERS;
		ar->max_num_stations = TARGET_TLV_NUM_STATIONS;
		ar->max_num_vdevs = TARGET_TLV_NUM_VDEVS;
		ar->max_num_tdls_vdevs = TARGET_TLV_NUM_TDLS_VDEVS;
		ar->htt.max_num_pending_tx = TARGET_TLV_NUM_MSDU_DESC;
		ar->wow.max_num_patterns = TARGET_TLV_NUM_WOW_PATTERNS;
		ar->fw_stats_req_mask = WMI_STAT_PDEV | WMI_STAT_VDEV |
			WMI_STAT_PEER;
		ar->max_spatial_stream = WMI_MAX_SPATIAL_STREAM;
		break;
	case ATH10K_FW_WMI_OP_VERSION_10_4:
		ar->bmiss_offload_max_vdev = TARGET_10_4_BMISS_OFFLOAD_MAX_VDEV;
		ar->skid_limit = TARGET_10_4_AST_SKID_LIMIT;
		ar->max_num_peers = TARGET_10_4_NUM_PEERS;
		ar->max_num_stations = TARGET_10_4_NUM_STATIONS;
		ar->num_active_peers = TARGET_10_4_ACTIVE_PEERS;
		ar->max_num_vdevs = TARGET_10_4_NUM_VDEVS;
		ar->num_tids = TARGET_10_4_TGT_NUM_TIDS;
		ar->htt.max_num_pending_tx = ar->hw_params.num_msdu_desc;
		ar->fw_stats_req_mask = WMI_STAT_PEER;
		ar->max_spatial_stream = ar->hw_params.max_spatial_stream;
		if (test_bit(ATH10K_FW_FEATURE_WMI_10X_CT, ar->fw_features)) {
			ar->max_num_vdevs = 8;
		}
		break;
	case ATH10K_FW_WMI_OP_VERSION_UNSET:
	case ATH10K_FW_WMI_OP_VERSION_MAX:
		WARN_ON(1);
		return -EINVAL;
	}

	ar->request_nohwcrypt = ath10k_modparam_nohwcrypt;
	ar->num_ratectrl_objs = ath10k_modparam_target_num_rate_ctrl_objs_ct;
	ar->eeprom_regdom = _modparam_override_eeprom_regdomain;

	/* Apply user-specified over-rides, if any. */
	if (ar->fwcfg.flags & ATH10K_FWCFG_VDEVS)
		ar->max_num_vdevs = ar->fwcfg.vdevs;
	if (ar->fwcfg.flags & ATH10K_FWCFG_PEERS)
		ar->max_num_peers = ar->fwcfg.peers;
	if (ar->fwcfg.flags & ATH10K_FWCFG_STATIONS)
		ar->max_num_stations = ar->fwcfg.stations;
	if (ar->fwcfg.flags & ATH10K_FWCFG_NOHWCRYPT)
		ar->request_nohwcrypt = ar->fwcfg.nohwcrypt;
	if (ar->fwcfg.flags & ATH10K_FWCFG_RATE_CTRL_OBJS)
		ar->num_ratectrl_objs = ar->fwcfg.rate_ctrl_objs;
	if (ar->fwcfg.flags & ATH10K_FWCFG_TX_DESC)
		ar->htt.max_num_pending_tx = ar->fwcfg.tx_desc;
	if (ar->fwcfg.flags & ATH10K_FWCFG_MAX_NSS)
		ar->max_spatial_stream = ar->fwcfg.max_nss;
	if (ar->fwcfg.flags & ATH10K_FWCFG_NUM_TIDS)
		ar->num_tids = ar->fwcfg.num_tids;
	if (ar->fwcfg.flags & ATH10K_FWCFG_ACTIVE_PEERS)
		ar->num_active_peers = ar->fwcfg.active_peers;
	if (ar->fwcfg.flags & ATH10K_FWCFG_SKID_LIMIT)
		ar->skid_limit = ar->fwcfg.skid_limit;
	if (ar->fwcfg.flags & ATH10K_FWCFG_REGDOM)
		ar->eeprom_regdom = ar->fwcfg.regdom;
	if (ar->fwcfg.flags & ATH10K_FWCFG_BMISS_VDEVS)
		ar->bmiss_offload_max_vdev = ar->fwcfg.bmiss_vdevs;

	/* Some firmware may compile out beacon-miss logic to save firmware RAM
	 * and instruction RAM.
	 */
	if (test_bit(ATH10K_FW_FEATURE_NO_BMISS_CT, ar->fw_features))
		ar->bmiss_offload_max_vdev = 0;

	return 0;
}

int ath10k_core_start(struct ath10k *ar, enum ath10k_firmware_mode mode)
{
	int status;
	u32 i, band;

	lockdep_assert_held(&ar->conf_mutex);

	clear_bit(ATH10K_FLAG_CRASH_FLUSH, &ar->dev_flags);

	ath10k_bmi_start(ar);

	if (ath10k_init_configure_target(ar)) {
		status = -EINVAL;
		goto err;
	}

	status = ath10k_download_cal_data(ar);
	if (status)
		goto err;

	/* Some of of qca988x solutions are having global reset issue
	 * during target initialization. Bypassing PLL setting before
	 * downloading firmware and letting the SoC run on REF_CLK is
	 * fixing the problem. Corresponding firmware change is also needed
	 * to set the clock source once the target is initialized.
	 */
	if (test_bit(ATH10K_FW_FEATURE_SUPPORTS_SKIP_CLOCK_INIT,
		     ar->fw_features)) {
		status = ath10k_bmi_write32(ar, hi_skip_clock_init, 1);
		if (status) {
			ath10k_err(ar, "could not write to skip_clock_init: %d\n",
				   status);
			goto err;
		}
	}

	status = ath10k_download_fw(ar, mode);
	if (status)
		goto err;

	status = ath10k_init_uart(ar);
	if (status)
		goto err;

	ar->htc.htc_ops.target_send_suspend_complete =
		ath10k_send_suspend_complete;

	status = ath10k_htc_init(ar);
	if (status) {
		ath10k_err(ar, "could not init HTC (%d)\n", status);
		goto err;
	}

	status = ath10k_bmi_done(ar);
	if (status)
		goto err;

	status = ath10k_wmi_attach(ar);
	if (status) {
		ath10k_err(ar, "WMI attach failed: %d\n", status);
		goto err;
	}

	status = ath10k_htt_init(ar);
	if (status) {
		ath10k_err(ar, "failed to init htt: %d\n", status);
		goto err_wmi_detach;
	}

	status = ath10k_htt_tx_alloc(&ar->htt);
	if (status) {
		ath10k_err(ar, "failed to alloc htt tx: %d\n", status);
		goto err_wmi_detach;
	}

	status = ath10k_htt_rx_alloc(&ar->htt);
	if (status) {
		ath10k_err(ar, "failed to alloc htt rx: %d\n", status);
		goto err_htt_tx_detach;
	}

	status = ath10k_hif_start(ar);
	if (status) {
		ath10k_err(ar, "could not start HIF: %d\n", status);
		goto err_htt_rx_detach;
	}

	status = ath10k_htc_wait_target(&ar->htc);
	if (status) {
		ath10k_err(ar, "failed to connect to HTC: %d\n", status);
		goto err_hif_stop;
	}

	if (mode == ATH10K_FIRMWARE_MODE_NORMAL) {
		status = ath10k_htt_connect(&ar->htt);
		if (status) {
			ath10k_err(ar, "failed to connect htt (%d)\n", status);
			goto err_hif_stop;
		}
	}

	status = ath10k_wmi_connect(ar);
	if (status) {
		ath10k_err(ar, "could not connect wmi: %d\n", status);
		goto err_hif_stop;
	}

	status = ath10k_htc_start(&ar->htc);
	if (status) {
		ath10k_err(ar, "failed to start htc: %d\n", status);
		goto err_hif_stop;
	}

	if (mode == ATH10K_FIRMWARE_MODE_NORMAL) {
		status = ath10k_wmi_wait_for_service_ready(ar);
		if (status) {
			ath10k_warn(ar, "wmi service ready event not received");
			goto err_hif_stop;
		}
	}

	ath10k_dbg(ar, ATH10K_DBG_BOOT, "firmware %s booted\n",
		   ar->hw->wiphy->fw_version);

	status = ath10k_wmi_cmd_init(ar);
	if (status) {
		ath10k_err(ar, "could not send WMI init command (%d)\n",
			   status);
		goto err_hif_stop;
	}

	status = ath10k_wmi_wait_for_unified_ready(ar);
	if (status) {
		ath10k_err(ar, "wmi unified ready event not received\n");
		goto err_hif_stop;
	}

	/* If firmware indicates Full Rx Reorder support it must be used in a
	 * slightly different manner. Let HTT code know.
	 */
	ar->htt.rx_ring.in_ord_rx = !!(test_bit(WMI_SERVICE_RX_FULL_REORDER,
						ar->wmi.svc_map));

	status = ath10k_htt_rx_ring_refill(ar);
	if (status) {
		ath10k_err(ar, "failed to refill htt rx ring: %d\n", status);
		goto err_hif_stop;
	}

	if (ar->max_num_vdevs >= 64)
		ar->free_vdev_map = 0xFFFFFFFFFFFFFFFFLL;
	else
		ar->free_vdev_map = (1LL << ar->max_num_vdevs) - 1;

	INIT_LIST_HEAD(&ar->arvifs);

	/* we don't care about HTT in UTF mode */
	if (mode == ATH10K_FIRMWARE_MODE_NORMAL) {
		status = ath10k_htt_setup(&ar->htt);
		if (status) {
			ath10k_err(ar, "failed to setup htt: %d\n", status);
			goto err_hif_stop;
		}
	}

	status = ath10k_debug_start(ar);
	if (status)
		goto err_hif_stop;

	if (test_bit(ATH10K_FW_FEATURE_HTT_MGT_CT, ar->fw_features)) {
		ar->ct_all_pkts_htt = true;
	}
	else if (ar->wmi.op_version != ATH10K_FW_WMI_OP_VERSION_10_1) {
		/* Older 10.1 firmware will not have the flag, and we check the HTT version
		 * in htt_rx.c for it.  But, 10.4 has conflicting HTT version, so disable
		 * this feature in newer firmware unless it explicitly has the HTT_MGT_CT feature
		 * flag.
		 */
		ar->ct_all_pkts_htt = false;
	}

	if (test_bit(ATH10K_FW_FEATURE_SET_SPECIAL_CT, ar->fw_features)) {
		/* Apply user-supplied configuration changes. */
		/* Don't worry about failures..not much we can do, and not worth failing init even
		 * if this fails.
		 */
		for (band = 0; band < 2; band++) {
			u32 val;
			for (i = 0; i<MIN_CCA_PWR_COUNT; i++) {
				val = (band << 24) | (i << 16) | ar->eeprom_overrides.bands[band].minCcaPwrCT[i];
				ath10k_wmi_pdev_set_special(ar, SET_SPECIAL_ID_NOISE_FLR_THRESH, val);
			}

			i = 4; /* enable-minccapwr-thresh type */
			val = (band << 24) | (i << 16) | ar->eeprom_overrides.bands[band].enable_minccapwr_thresh;
			ath10k_wmi_pdev_set_special(ar, SET_SPECIAL_ID_NOISE_FLR_THRESH, val);
		}

		/* TODO:  Should probably be per-band?? */
		if (ar->eeprom_overrides.thresh62_ext) {
			ath10k_wmi_pdev_set_special(ar, SET_SPECIAL_ID_THRESH62_EXT,
						    ar->eeprom_overrides.thresh62_ext);
		}

		if (ar->eeprom_overrides.allow_ibss_amsdu) {
			ath10k_wmi_pdev_set_special(ar, SET_SPECIAL_ID_IBSS_AMSDU_OK,
						    ar->eeprom_overrides.allow_ibss_amsdu);
		}

		if (ar->eeprom_overrides.max_txpower != 0xFFFF)
			ath10k_wmi_pdev_set_special(ar, SET_SPECIAL_ID_MAX_TXPOWER,
						    ar->eeprom_overrides.max_txpower);

		if (ar->eeprom_overrides.rc_rate_max_per_thr)
			ath10k_wmi_pdev_set_special(ar, SET_SPECIAL_ID_RC_MAX_PER_THR,
						    ar->eeprom_overrides.rc_rate_max_per_thr);

		if (ar->eeprom_overrides.tx_sta_bw_mask)
			ath10k_wmi_pdev_set_special(ar, SET_SPECIAL_ID_STA_TXBW_MASK,
						    ar->eeprom_overrides.tx_sta_bw_mask);

		if (ar->eeprom_overrides.pdev_xretry_th)
			ath10k_wmi_pdev_set_special(ar, SET_SPECIAL_ID_PDEV_XRETRY_TH,
						    ar->eeprom_overrides.pdev_xretry_th);

		if (ar->eeprom_overrides.rifs_enable_override)
			ath10k_wmi_pdev_set_special(ar, SET_SPECIAL_ID_RIFS_ENABLE,
						    ar->eeprom_overrides.rifs_enable_override);
		if (ar->eeprom_overrides.wmi_wd_keepalive_ms)
			ath10k_wmi_pdev_set_special(ar, SET_SPECIAL_ID_WMI_WD,
						    ar->eeprom_overrides.wmi_wd_keepalive_ms);
		if (ar->eeprom_overrides.ct_pshack)
			ath10k_wmi_pdev_set_special(ar, SET_SPECIAL_ID_PSHACK,
						    ar->eeprom_overrides.ct_pshack);
		if (ar->eeprom_overrides.ct_csi)
			ath10k_wmi_pdev_set_special(ar, SET_SPECIAL_ID_CSI,
						    ar->eeprom_overrides.ct_csi);
		if (ar->eeprom_overrides.rate_bw_disable_mask)
			ath10k_wmi_pdev_set_special(ar, SET_SPECIAL_ID_BW_DISABLE_MASK,
						    ar->eeprom_overrides.rate_bw_disable_mask);
	}

	return 0;

err_hif_stop:
	ath10k_hif_stop(ar);
err_htt_rx_detach:
	ath10k_htt_rx_free(&ar->htt);
err_htt_tx_detach:
	ath10k_htt_tx_free(&ar->htt);
err_wmi_detach:
	ath10k_wmi_detach(ar);
err:
	return status;
}
EXPORT_SYMBOL(ath10k_core_start);

int ath10k_wait_for_suspend(struct ath10k *ar, u32 suspend_opt)
{
	int ret;
	unsigned long time_left;

	reinit_completion(&ar->target_suspend);

	ret = ath10k_wmi_pdev_suspend_target(ar, suspend_opt);
	if (ret) {
		ath10k_warn(ar, "could not suspend target (%d)\n", ret);
		return ret;
	}

	time_left = wait_for_completion_timeout(&ar->target_suspend, 1 * HZ);

	if (!time_left) {
		ath10k_warn(ar, "suspend timed out - target pause event never came\n");
		return -ETIMEDOUT;
	}

	return 0;
}

void ath10k_core_stop(struct ath10k *ar)
{
	lockdep_assert_held(&ar->conf_mutex);
	ath10k_debug_stop(ar);

	/* try to suspend target */
	if (ar->state != ATH10K_STATE_RESTARTING &&
	    ar->state != ATH10K_STATE_UTF)
		ath10k_wait_for_suspend(ar, WMI_PDEV_SUSPEND_AND_DISABLE_INTR);

	ath10k_hif_stop(ar);
	ath10k_htt_tx_free(&ar->htt);
	ath10k_htt_rx_free(&ar->htt);
	ath10k_wmi_detach(ar);
}
EXPORT_SYMBOL(ath10k_core_stop);

/* mac80211 manages fw/hw initialization through start/stop hooks. However in
 * order to know what hw capabilities should be advertised to mac80211 it is
 * necessary to load the firmware (and tear it down immediately since start
 * hook will try to init it again) before registering */
static int ath10k_core_probe_fw(struct ath10k *ar)
{
	struct bmi_target_info target_info;
	int ret = 0;

	ret = ath10k_hif_power_up(ar);
	if (ret) {
		ath10k_err(ar, "could not start pci hif (%d)\n", ret);
		return ret;
	}

	memset(&target_info, 0, sizeof(target_info));
	ret = ath10k_bmi_get_target_info(ar, &target_info);
	if (ret) {
		ath10k_err(ar, "could not get target info (%d)\n", ret);
		goto err_power_down;
	}

	ar->target_version = target_info.version;
	ar->hw->wiphy->hw_version = target_info.version;

	ret = ath10k_init_hw_params(ar);
	if (ret) {
		ath10k_err(ar, "could not get hw params (%d)\n", ret);
		goto err_power_down;
	}

	ret = ath10k_core_fetch_firmware_files(ar);
	if (ret) {
		ath10k_err(ar, "could not fetch firmware files (%d)\n", ret);
		goto err_power_down;
	}

	ath10k_debug_print_hwfw_info(ar);

	ret = ath10k_core_pre_cal_download(ar);
	if (ret) {
		/* pre calibration data download is not necessary
		 * for all the chipsets. Ignore failures and continue.
		 */
		ath10k_dbg(ar, ATH10K_DBG_BOOT,
			   "could not load pre cal data: %d\n", ret);
	}

	ret = ath10k_core_get_board_id_from_otp(ar);
	if (ret && ret != -EOPNOTSUPP) {
		ath10k_err(ar, "failed to get board id from otp: %d\n",
			   ret);
		goto err_free_firmware_files;
	}

	ret = ath10k_core_fetch_board_file(ar);
	if (ret) {
		ath10k_err(ar, "failed to fetch board file: %d\n", ret);
		goto err_free_firmware_files;
	}

	ath10k_debug_print_board_info(ar);

	ret = ath10k_core_init_firmware_features(ar);
	if (ret) {
		ath10k_err(ar, "fatal problem with firmware features: %d\n",
			   ret);
		goto err_free_firmware_files;
	}

	ret = ath10k_swap_code_seg_init(ar);
	if (ret) {
		ath10k_err(ar, "failed to initialize code swap segment: %d\n",
			   ret);
		goto err_free_firmware_files;
	}

	mutex_lock(&ar->conf_mutex);

	ret = ath10k_core_start(ar, ATH10K_FIRMWARE_MODE_NORMAL);
	if (ret) {
		ath10k_err(ar, "could not init core (%d)\n", ret);
		goto err_unlock;
	}

	ath10k_debug_print_boot_info(ar);
	ath10k_core_stop(ar);

	mutex_unlock(&ar->conf_mutex);

	ath10k_hif_power_down(ar);
	return 0;

err_unlock:
	mutex_unlock(&ar->conf_mutex);

err_free_firmware_files:
	ath10k_core_free_firmware_files(ar);

err_power_down:
	ath10k_hif_power_down(ar);

	return ret;
}

static void ath10k_core_register_work(struct work_struct *work)
{
	struct ath10k *ar = container_of(work, struct ath10k, register_work);
	int status;

	status = ath10k_core_probe_fw(ar);
	if (status) {
		ath10k_err(ar, "could not probe fw (%d)\n", status);
		goto err;
	}

	status = ath10k_mac_register(ar);
	if (status) {
		ath10k_err(ar, "could not register to mac80211 (%d)\n", status);
		goto err_release_fw;
	}

	status = ath10k_debug_register(ar);
	if (status) {
		ath10k_err(ar, "unable to initialize debugfs\n");
		goto err_unregister_mac;
	}

	status = ath10k_spectral_create(ar);
	if (status) {
		ath10k_err(ar, "failed to initialize spectral\n");
		goto err_debug_destroy;
	}

	status = ath10k_thermal_register(ar);
	if (status) {
		ath10k_err(ar, "could not register thermal device: %d\n",
			   status);
		goto err_spectral_destroy;
	}

	set_bit(ATH10K_FLAG_CORE_REGISTERED, &ar->dev_flags);
	return;

err_spectral_destroy:
	ath10k_spectral_destroy(ar);
err_debug_destroy:
	ath10k_debug_destroy(ar);
err_unregister_mac:
	ath10k_mac_unregister(ar);
err_release_fw:
	ath10k_core_free_firmware_files(ar);
err:
	/* TODO: It's probably a good idea to release device from the driver
	 * but calling device_release_driver() here will cause a deadlock.
	 */
	return;
}

int ath10k_core_register(struct ath10k *ar, u32 chip_id)
{
	ar->chip_id = chip_id;
	queue_work(ar->workqueue, &ar->register_work);

	return 0;
}
EXPORT_SYMBOL(ath10k_core_register);

void ath10k_core_free_limits(struct ath10k* ar)
{
	int i;
	for (i = 0; i < ARRAY_SIZE(ar->if_comb); i++) {
		kfree(ar->if_comb[i].limits);
	}
	memset(&ar->if_comb, 0, sizeof(ar->if_comb));
}
EXPORT_SYMBOL(ath10k_core_free_limits);

void ath10k_core_unregister(struct ath10k *ar)
{
	cancel_work_sync(&ar->register_work);

	if (!test_bit(ATH10K_FLAG_CORE_REGISTERED, &ar->dev_flags))
		return;

	ath10k_thermal_unregister(ar);
	/* Stop spectral before unregistering from mac80211 to remove the
	 * relayfs debugfs file cleanly. Otherwise the parent debugfs tree
	 * would be already be free'd recursively, leading to a double free.
	 */
	ath10k_spectral_destroy(ar);

	/* We must unregister from mac80211 before we stop HTC and HIF.
	 * Otherwise we will fail to submit commands to FW and mac80211 will be
	 * unhappy about callback failures. */
	ath10k_mac_unregister(ar);

	ath10k_testmode_destroy(ar);

	ath10k_core_free_firmware_files(ar);
	ath10k_core_free_board_files(ar);

	ath10k_core_free_limits(ar);

	ath10k_debug_unregister(ar);
}
EXPORT_SYMBOL(ath10k_core_unregister);

struct ath10k *ath10k_core_create(size_t priv_size, struct device *dev,
				  enum ath10k_bus bus,
				  enum ath10k_hw_rev hw_rev,
				  const struct ath10k_hif_ops *hif_ops)
{
	struct ath10k *ar;
	int ret;

	ar = ath10k_mac_create(priv_size);
	if (!ar)
		return NULL;

	ar->eeprom_overrides.max_txpower = 0xFFFF;
	ar->sta_xretry_kickout_thresh = DEFAULT_ATH10K_KICKOUT_THRESHOLD;

	ar->ath_common.priv = ar;
	ar->ath_common.hw = ar->hw;
	ar->dev = dev;
	ar->hw_rev = hw_rev;
	ar->hif.ops = hif_ops;
	ar->hif.bus = bus;

	switch (hw_rev) {
	case ATH10K_HW_QCA988X:
		ar->regs = &qca988x_regs;
		ar->hw_values = &qca988x_values;
		break;
	case ATH10K_HW_QCA6174:
	case ATH10K_HW_QCA9377:
		ar->regs = &qca6174_regs;
		ar->hw_values = &qca6174_values;
		break;
	case ATH10K_HW_QCA99X0:
		ar->regs = &qca99x0_regs;
		ar->hw_values = &qca99x0_values;
		break;
	case ATH10K_HW_QCA4019:
		ar->regs = &qca4019_regs;
		ar->hw_values = &qca4019_values;
		break;
	default:
		ath10k_err(ar, "unsupported core hardware revision %d\n",
			   hw_rev);
		ret = -ENOTSUPP;
		goto err_free_mac;
	}

	init_completion(&ar->scan.started);
	init_completion(&ar->scan.completed);
	init_completion(&ar->scan.on_channel);
	init_completion(&ar->target_suspend);
	init_completion(&ar->wow.wakeup_completed);

	init_completion(&ar->install_key_done);
	init_completion(&ar->vdev_setup_done);
	init_completion(&ar->thermal.wmi_sync);

	INIT_DELAYED_WORK(&ar->scan.timeout, ath10k_scan_timeout_work);

	ar->workqueue = create_singlethread_workqueue("ath10k_wq");
	if (!ar->workqueue)
		goto err_free_mac;

	ar->workqueue_aux = create_singlethread_workqueue("ath10k_aux_wq");
	if (!ar->workqueue_aux)
		goto err_free_wq;

	mutex_init(&ar->conf_mutex);
	spin_lock_init(&ar->data_lock);
	spin_lock_init(&ar->txqs_lock);

	INIT_LIST_HEAD(&ar->txqs);
	INIT_LIST_HEAD(&ar->peers);
	init_waitqueue_head(&ar->peer_mapping_wq);
	init_waitqueue_head(&ar->htt.empty_tx_wq);
	init_waitqueue_head(&ar->wmi.tx_credits_wq);

	init_completion(&ar->offchan_tx_completed);
	INIT_WORK(&ar->offchan_tx_work, ath10k_offchan_tx_work);
	skb_queue_head_init(&ar->offchan_tx_queue);

	INIT_WORK(&ar->wmi_mgmt_tx_work, ath10k_mgmt_over_wmi_tx_work);
	skb_queue_head_init(&ar->wmi_mgmt_tx_queue);

	INIT_WORK(&ar->register_work, ath10k_core_register_work);
	INIT_WORK(&ar->restart_work, ath10k_core_restart);

	ret = ath10k_debug_create(ar);
	if (ret)
		goto err_free_aux_wq;

	return ar;

err_free_aux_wq:
	destroy_workqueue(ar->workqueue_aux);
err_free_wq:
	destroy_workqueue(ar->workqueue);

err_free_mac:
	ath10k_mac_destroy(ar);

	return NULL;
}
EXPORT_SYMBOL(ath10k_core_create);

void ath10k_core_destroy(struct ath10k *ar)
{
	flush_workqueue(ar->workqueue);
	destroy_workqueue(ar->workqueue);

	flush_workqueue(ar->workqueue_aux);
	destroy_workqueue(ar->workqueue_aux);

	ath10k_debug_destroy(ar);
	ath10k_wmi_free_host_mem(ar);
	ath10k_mac_destroy(ar);
}
EXPORT_SYMBOL(ath10k_core_destroy);

MODULE_AUTHOR("Qualcomm Atheros");
MODULE_DESCRIPTION("Core module for QCA988X PCIe devices.");
MODULE_LICENSE("Dual BSD/GPL");
