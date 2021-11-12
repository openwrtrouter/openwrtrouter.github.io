#include "iwinfo.h"
#include "iwinfo_ra.h"
#include "iwinfo_wext.h"

#define MIDFIX5G "x"

/*
 * Ralink ISO 3166 to Country/Region Code mapping.
 */

static struct ISO3166_to_CCode
{
	u_int16_t iso3166;
	u_int16_t ccode;
} CountryCodes[] =
    {
	{0x3030 /* 00 */, 0},	/* World */
	{0x4145 /* AE */, 784}, /* U.A.E. */
	{0x414C /* AL */, 8},	/* Albania */
	{0x414D /* AM */, 51},	/* Armenia */
	{0x4152 /* AR */, 32},	/* Argentina */
	{0x4154 /* AT */, 40},	/* Austria */
	{0x4155 /* AU */, 36},	/* Australia */
	{0x415A /* AZ */, 31},	/* Azerbaijan */
	{0x4245 /* BE */, 56},	/* Belgium */
	{0x4247 /* BG */, 100}, /* Bulgaria */
	{0x4248 /* BH */, 48},	/* Bahrain */
	{0x424E /* BN */, 96},	/* Brunei Darussalam */
	{0x424F /* BO */, 68},	/* Bolivia */
	{0x4252 /* BR */, 76},	/* Brazil */
	{0x4259 /* BY */, 112}, /* Belarus */
	{0x425A /* BZ */, 84},	/* Belize */
	{0x4341 /* CA */, 124}, /* Canada */
	{0x4348 /* CH */, 756}, /* Switzerland */
	{0x434C /* CL */, 152}, /* Chile */
	{0x434E /* CN */, 156}, /* People's Republic of China */
	{0x434F /* CO */, 170}, /* Colombia */
	{0x4352 /* CR */, 188}, /* Costa Rica */
	{0x4359 /* CY */, 196}, /* Cyprus */
	{0x435A /* CZ */, 203}, /* Czech Republic */
	{0x4445 /* DE */, 276}, /* Germany */
	{0x444B /* DK */, 208}, /* Denmark */
	{0x444F /* DO */, 214}, /* Dominican Republic */
	{0x445A /* DZ */, 12},	/* Algeria */
	{0x4543 /* EC */, 218}, /* Ecuador */
	{0x4545 /* EE */, 233}, /* Estonia */
	{0x4547 /* EG */, 818}, /* Egypt */
	{0x4553 /* ES */, 724}, /* Spain */
	{0x4649 /* FI */, 246}, /* Finland */
	{0x464F /* FO */, 234}, /* Faeroe Islands */
	{0x4652 /* FR */, 250}, /* France */
	{0x4652 /* FR */, 255}, /* France2 */
	{0x4742 /* GB */, 826}, /* United Kingdom */
	{0x4745 /* GE */, 268}, /* Georgia */
	{0x4752 /* GR */, 300}, /* Greece */
	{0x4754 /* GT */, 320}, /* Guatemala */
	{0x484B /* HK */, 344}, /* Hong Kong S.A.R., P.R.C. */
	{0x484E /* HN */, 340}, /* Honduras */
	{0x4852 /* HR */, 191}, /* Croatia */
	{0x4855 /* HU */, 348}, /* Hungary */
	{0x4944 /* ID */, 360}, /* Indonesia */
	{0x4945 /* IE */, 372}, /* Ireland */
	{0x494C /* IL */, 376}, /* Israel */
	{0x494E /* IN */, 356}, /* India */
	{0x4951 /* IQ */, 368}, /* Iraq */
	{0x4952 /* IR */, 364}, /* Iran */
	{0x4953 /* IS */, 352}, /* Iceland */
	{0x4954 /* IT */, 380}, /* Italy */
	{0x4A4D /* JM */, 388}, /* Jamaica */
	{0x4A4F /* JO */, 400}, /* Jordan */
	{0x4A50 /* JP */, 392}, /* Japan */
	{0x4A50 /* JP */, 393}, /* Japan (JP1) */
	{0x4A50 /* JP */, 394}, /* Japan (JP0) */
	{0x4A50 /* JP */, 395}, /* Japan (JP1-1) */
	{0x4A50 /* JP */, 396}, /* Japan (JE1) */
	{0x4A50 /* JP */, 397}, /* Japan (JE2) */
	{0x4A50 /* JP */, 399}, /* Japan (JP6) */
	{0x4A50 /* JP */, 900}, /* Japan */
	{0x4A50 /* JP */, 901}, /* Japan */
	{0x4A50 /* JP */, 902}, /* Japan */
	{0x4A50 /* JP */, 903}, /* Japan */
	{0x4A50 /* JP */, 904}, /* Japan */
	{0x4A50 /* JP */, 905}, /* Japan */
	{0x4A50 /* JP */, 906}, /* Japan */
	{0x4A50 /* JP */, 907}, /* Japan */
	{0x4A50 /* JP */, 908}, /* Japan */
	{0x4A50 /* JP */, 909}, /* Japan */
	{0x4A50 /* JP */, 910}, /* Japan */
	{0x4A50 /* JP */, 911}, /* Japan */
	{0x4A50 /* JP */, 912}, /* Japan */
	{0x4A50 /* JP */, 913}, /* Japan */
	{0x4A50 /* JP */, 914}, /* Japan */
	{0x4A50 /* JP */, 915}, /* Japan */
	{0x4A50 /* JP */, 916}, /* Japan */
	{0x4A50 /* JP */, 917}, /* Japan */
	{0x4A50 /* JP */, 918}, /* Japan */
	{0x4A50 /* JP */, 919}, /* Japan */
	{0x4A50 /* JP */, 920}, /* Japan */
	{0x4A50 /* JP */, 921}, /* Japan */
	{0x4A50 /* JP */, 922}, /* Japan */
	{0x4A50 /* JP */, 923}, /* Japan */
	{0x4A50 /* JP */, 924}, /* Japan */
	{0x4A50 /* JP */, 925}, /* Japan */
	{0x4A50 /* JP */, 926}, /* Japan */
	{0x4A50 /* JP */, 927}, /* Japan */
	{0x4A50 /* JP */, 928}, /* Japan */
	{0x4A50 /* JP */, 929}, /* Japan */
	{0x4A50 /* JP */, 930}, /* Japan */
	{0x4A50 /* JP */, 931}, /* Japan */
	{0x4A50 /* JP */, 932}, /* Japan */
	{0x4A50 /* JP */, 933}, /* Japan */
	{0x4A50 /* JP */, 934}, /* Japan */
	{0x4A50 /* JP */, 935}, /* Japan */
	{0x4A50 /* JP */, 936}, /* Japan */
	{0x4A50 /* JP */, 937}, /* Japan */
	{0x4A50 /* JP */, 938}, /* Japan */
	{0x4A50 /* JP */, 939}, /* Japan */
	{0x4A50 /* JP */, 940}, /* Japan */
	{0x4A50 /* JP */, 941}, /* Japan */
	{0x4B45 /* KE */, 404}, /* Kenya */
	{0x4B50 /* KP */, 408}, /* North Korea */
	{0x4B52 /* KR */, 410}, /* South Korea */
	{0x4B52 /* KR */, 411}, /* South Korea */
	{0x4B57 /* KW */, 414}, /* Kuwait */
	{0x4B5A /* KZ */, 398}, /* Kazakhstan */
	{0x4C42 /* LB */, 422}, /* Lebanon */
	{0x4C49 /* LI */, 438}, /* Liechtenstein */
	{0x4C54 /* LT */, 440}, /* Lithuania */
	{0x4C55 /* LU */, 442}, /* Luxembourg */
	{0x4C56 /* LV */, 428}, /* Latvia */
	{0x4C59 /* LY */, 434}, /* Libya */
	{0x4D41 /* MA */, 504}, /* Morocco */
	{0x4D43 /* MC */, 492}, /* Principality of Monaco */
	{0x4D4B /* MK */, 807}, /* the Former Yugoslav Republic of Macedonia */
	{0x4D4F /* MO */, 446}, /* Macau */
	{0x4D58 /* MX */, 484}, /* Mexico */
	{0x4D59 /* MY */, 458}, /* Malaysia */
	{0x4E49 /* NI */, 558}, /* Nicaragua */
	{0x4E4C /* NL */, 528}, /* Netherlands */
	{0x4E4F /* NO */, 578}, /* Norway */
	{0x4E5A /* NZ */, 554}, /* New Zealand */
	{0x4F4D /* OM */, 512}, /* Oman */
	{0x5041 /* PA */, 591}, /* Panama */
	{0x5045 /* PE */, 604}, /* Peru */
	{0x5048 /* PH */, 608}, /* Republic of the Philippines */
	{0x504B /* PK */, 586}, /* Islamic Republic of Pakistan */
	{0x504C /* PL */, 616}, /* Poland */
	{0x5052 /* PR */, 630}, /* Puerto Rico */
	{0x5054 /* PT */, 620}, /* Portugal */
	{0x5059 /* PY */, 600}, /* Paraguay */
	{0x5141 /* QA */, 634}, /* Qatar */
	{0x524F /* RO */, 642}, /* Romania */
	{0x5255 /* RU */, 643}, /* Russia */
	{0x5341 /* SA */, 682}, /* Saudi Arabia */
	{0x5345 /* SE */, 752}, /* Sweden */
	{0x5347 /* SG */, 702}, /* Singapore */
	{0x5349 /* SI */, 705}, /* Slovenia */
	{0x534B /* SK */, 703}, /* Slovak Republic */
	{0x5356 /* SV */, 222}, /* El Salvador */
	{0x5359 /* SY */, 760}, /* Syria */
	{0x5448 /* TH */, 764}, /* Thailand */
	{0x544E /* TN */, 788}, /* Tunisia */
	{0x5452 /* TR */, 792}, /* Turkey */
	{0x5454 /* TT */, 780}, /* Trinidad y Tobago */
	{0x5457 /* TW */, 158}, /* Taiwan */
	{0x5541 /* UA */, 804}, /* Ukraine */
	{0x554B /* UK */, 826}, /* United Kingdom */
	{0x5553 /* US */, 840}, /* United States */
	{0x5553 /* US */, 842}, /* United States (Public Safety)*/
	{0x5559 /* UY */, 858}, /* Uruguay */
	{0x555A /* UZ */, 860}, /* Uzbekistan */
	{0x5645 /* VE */, 862}, /* Venezuela */
	{0x564E /* VN */, 704}, /* Viet Nam */
	{0x5945 /* YE */, 887}, /* Yemen */
	{0x5A41 /* ZA */, 710}, /* South Africa */
	{0x5A57 /* ZW */, 716}, /* Zimbabwe */
};

int is_5g(const char *ifname)
{
	if (!strncmp(ifname, "ra"MIDFIX5G, 3))
		return 1;
	else if (!strncmp(ifname, "wds"MIDFIX5G, 4))
		return 1;
	else if (!strncmp(ifname, "apcli"MIDFIX5G, 6))
		return 1;

	return 0;
}

static int ra_ioctl(const char *ifname, int cmd, struct iwreq *wrq)
{
	if (!strncmp(ifname, "mon.", 4))
		strncpy(wrq->ifr_name, &ifname[4], IFNAMSIZ);
	else
		strncpy(wrq->ifr_name, ifname, IFNAMSIZ);

	return iwinfo_ioctl(cmd, wrq);
}

int ra_oid_ioctl(const char *ifname, unsigned long oid, char *ptr, unsigned long ptr_len)
{
	struct iwreq wrq;
	int cmd = RT_PRIV_IOCTL;
	strcpy(wrq.ifr_name, ifname);
	wrq.u.data.length = ptr_len;
	wrq.u.data.pointer = ptr;
	wrq.u.data.flags = oid;

	return iwinfo_ioctl(RT_PRIV_IOCTL, &wrq);
}

int iwpriv_set(const char *name, const char *key, const char *val)
{
	int socket_id, ret = 0;
	struct iwreq wrq;
	char data[64];
	snprintf(data, 64, "%s=%s", key, val);
	socket_id = socket(AF_INET, SOCK_DGRAM, 0);

	wrq.u.data.length = strlen(data);
	wrq.u.data.pointer = data;
	wrq.u.data.flags = 0;
	ret = ra_ioctl(name, RTPRIV_IOCTL_SET, &wrq);
	close(socket_id);
	return ret;
}

int ra_probe(const char *ifname)
{
	unsigned char data[12];
	int version;
	if (strncmp(ifname, "ra", 2) && strncmp(ifname, "wds", 3) && strncmp(ifname, "apcli", 5))
		return 0;
	if (ra_oid_ioctl(ifname, RT_OID_VERSION_INFO, data, sizeof(data)) == 0)
	{
		data[1] = data[2];
		data[2] = data[4];
		data[3] = data[6];
		data[4] = '\0';
		version = atoi(data);
		if (version >= 2500)
			return 1;
		else
			return 0;
	}
	else
		return -1;
}

void ra_close(void)
{
	iwinfo_close();
}

int ra_get_mode(const char *ifname, int *buf)
{
	if (strncmp(ifname, "ra", 2) == 0)
		*buf = IWINFO_OPMODE_MASTER;
	else if (strncmp(ifname, "apcli", 5) == 0)
		*buf = IWINFO_OPMODE_CLIENT;
	else if (strncmp(ifname, "wds", 3) == 0)
		*buf = IWINFO_OPMODE_WDS;
	else
		*buf = IWINFO_OPMODE_UNKNOWN;

	return 0;
}

int ra_get_ssid(const char *ifname, char *buf)
{
	struct iwreq wrq;

	wrq.u.essid.pointer = (caddr_t)buf;
	wrq.u.essid.length = IW_ESSID_MAX_SIZE + 1;
	wrq.u.essid.flags = 0;

	if (ra_ioctl(ifname, SIOCGIWESSID, &wrq) >= 0)
		return 0;

	return -1;
}

int ra_get_bssid(const char *ifname, char *buf)
{
	struct iwreq wrq;

	if (ra_ioctl(ifname, SIOCGIWAP, &wrq) >= 0)
	{
		sprintf(buf, "%02X:%02X:%02X:%02X:%02X:%02X",
			(uint8_t)wrq.u.ap_addr.sa_data[0], (uint8_t)wrq.u.ap_addr.sa_data[1],
			(uint8_t)wrq.u.ap_addr.sa_data[2], (uint8_t)wrq.u.ap_addr.sa_data[3],
			(uint8_t)wrq.u.ap_addr.sa_data[4], (uint8_t)wrq.u.ap_addr.sa_data[5]);

		return 0;
	}

	return -1;
}

static int32_t ra_freq2mhz(const struct iw_freq *in)
{
	int i;
	int32_t res = in->m;
	if (in->e == 6) {
		return res;
	} else if (in->e > 6) {
		for (i=in->e; i>6; --i) {
			res *= 10;
		}
	} else {
		for (i=in->e; i<6; ++i) {
			res /= 10;
		}
	}
	return res;
}

int ra_get_channel(const char *ifname, int *buf)
{
	struct iwreq wrq;

	if (ra_ioctl(ifname, SIOCGIWFREQ, &wrq) >= 0)
	{
		*buf = wrq.u.freq.i;
		return 0;
	}

	return -1;
}

int ra_get_frequency(const char *ifname, int *buf)
{
	struct iwreq wrq;

	if (ra_ioctl(ifname, SIOCGIWFREQ, &wrq) >= 0)
	{
		*buf = ra_freq2mhz(&wrq.u.freq);
		return 0;
	}
	return -1;
}

int ra_get_txpower(const char *ifname, int *buf)
{
	*buf = 20;
	return 0;
}

int ra_get_bitrate(const char *ifname, int *buf)
{
	struct iwreq wrq;

	if (ra_ioctl(ifname, SIOCGIWRATE, &wrq) >= 0)
	{
		*buf = (wrq.u.bitrate.value / 1000);
		return 0;
	}

	return -1;
}

int ra_get_signal(const char *ifname, int *buf)
{
	int ra_snr_sum, num;
	char tmp_buf[8192];
	struct iwinfo_assoclist_entry tmp;
	int ret_len, i;

	if (ra_get_assoclist(ifname, tmp_buf, &ret_len) == 0)
	{
		num = ret_len / sizeof(struct iwinfo_assoclist_entry);
		ra_snr_sum = 0;
		for (i = 0; i < num; i++)
		{
			memset(&tmp, 0, sizeof(struct iwinfo_assoclist_entry));
			memcpy(&tmp, tmp_buf + i * sizeof(struct iwinfo_assoclist_entry), sizeof(struct iwinfo_assoclist_entry));

			ra_snr_sum -= tmp.signal;
		}
		if (num > 0)
			*buf = -(ra_snr_sum / num);
		else
			*buf = -95;

		return 0;
	}
	else
		return -1;
}

int ra_get_noise(const char *ifname, int *buf)
{
	*buf = -95;
	return 0;
}

int ra_get_quality(const char *ifname, int *buf)
{
	int tmp;

	if (ra_get_signal(ifname, &tmp) == 0)
		*buf = 100 - (tmp / -95 * 100);
	else
		*buf = 100;

	return 0;
}

int ra_get_quality_max(const char *ifname, int *buf)
{
	*buf = 100;
	return 0;
}

static char *ra_array_get(char *p, int idx) {
	int i;
	char *tail;
	for (i=0; i<idx; ++i) {
		p = strchr(p, ';');
		if (p == NULL) {
			return NULL;
		}
		p += 1;
	}
	tail = strchr(p, ';');
	if (!tail) {
		tail = strchr(p, '\n');
	}
	if (!tail) {
		*tail = '\0';
	}
	return p;
}

int ra_get_encryption(const char *ifname, char *buf)
{
	FILE *fp;
	const char *filename;
	long filesize;
	int ret = -1;
	char buffer[256] = {0};
	char *p = NULL;
	int idx;
	int aes = 0;

	struct iwinfo_crypto_entry *enc = (struct iwinfo_crypto_entry *)buf;

	char data[10];
	if (ra_oid_ioctl(ifname, RT_OID_VERSION_INFO, data, sizeof(data)) < 0)
		return -1;

	if (is_5g(ifname)) {
		filename = "/tmp/profiles/mt_dbdc_5g.dat";
	} else {
		filename = "/tmp/profiles/mt_dbdc_2g.dat";
	}
	fp = fopen(filename, "r");
	if (fp == NULL)
	{
		fprintf(stderr, "open ifname:%s failed.\n", ifname);
		return -1;
	}
	idx = ifname[strlen(ifname)-1] - '0';
	while (fgets(buffer, sizeof(buffer), fp) != NULL) {
		if (!strncmp(buffer, "AuthMode=", 9)) {
			p = buffer + 9;
			p = ra_array_get(p, idx);
			if (!p)
				goto end;
			if (strstr(p, "WPA"))
			{
				enc->enabled = 1;
				if (strstr(p, "WPA1PSKWPA2PSK"))
					enc->wpa_version = 3;
				else if (strstr(p, "WPA2PSK"))
					enc->wpa_version = 2;
				else if (strstr(p, "WPAPSK"))
					enc->wpa_version = 1;
				else
					enc->wpa_version = 1;

				enc->auth_suites |= IWINFO_KMGMT_PSK;
			}
			else if (strstr(p, "WEP"))
			{
				enc->enabled = 1;
				enc->auth_algs |= IWINFO_AUTH_OPEN;
				enc->pair_ciphers |= IWINFO_CIPHER_WEP104;
				enc->auth_suites |= IWINFO_KMGMT_NONE;
				enc->group_ciphers = enc->pair_ciphers;
			}
		} else if (!strncmp(buffer, "EncrypType=", 11)) {
			if (enc->pair_ciphers & IWINFO_CIPHER_WEP104)
				continue;
			p = buffer + 11;
			p = ra_array_get(p, idx);
			if (!p)
				goto end;
			if (strstr(p, "AES"))
				aes = 1;
		}
	}

	if (enc->enabled && enc->auth_suites & IWINFO_KMGMT_PSK) {
		if (aes)
			enc->pair_ciphers |= IWINFO_CIPHER_CCMP;
		else
			enc->pair_ciphers |= IWINFO_CIPHER_TKIP;

		enc->group_ciphers = enc->pair_ciphers;
	}

	ret = 0;
end:
	fclose(fp);
	return ret;
}

int ra_get_phyname(const char *ifname, char *buf) {
	if (is_5g(ifname)) {
		strcpy(buf, "ra"MIDFIX5G);
	} else {
		strcpy(buf, "ra");
	}
	return 0;
}

int getRate(MACHTTRANSMIT_SETTING HTSetting)
{
	int MCSMappingRateTable[] =
	    {
		2, 4, 11, 22,								    /* CCK*/
		12, 18, 24, 36, 48, 72, 96, 108,					    /* OFDM*/
		13, 26, 39, 52, 78, 104, 117, 130, 26, 52, 78, 104, 156, 208, 234, 260,	    /* 20MHz, 800ns GI, MCS: 0 ~ 15*/
		39, 78, 117, 156, 234, 312, 351, 390,					    /* 20MHz, 800ns GI, MCS: 16 ~ 23*/
		27, 54, 81, 108, 162, 216, 243, 270, 54, 108, 162, 216, 324, 432, 486, 540, /* 40MHz, 800ns GI, MCS: 0 ~ 15*/
		81, 162, 243, 324, 486, 648, 729, 810,					    /* 40MHz, 800ns GI, MCS: 16 ~ 23*/
		14, 29, 43, 57, 87, 115, 130, 144, 29, 59, 87, 115, 173, 230, 260, 288,	    /* 20MHz, 400ns GI, MCS: 0 ~ 15*/
		43, 87, 130, 173, 260, 317, 390, 433,					    /* 20MHz, 400ns GI, MCS: 16 ~ 23*/
		30, 60, 90, 120, 180, 240, 270, 300, 60, 120, 180, 240, 360, 480, 540, 600, /* 40MHz, 400ns GI, MCS: 0 ~ 15*/
		90, 180, 270, 360, 540, 720, 810, 900,
		13, 26, 39, 52, 78, 104, 117, 130, 156,		 /* 11ac: 20Mhz, 800ns GI, MCS: 0~8 */
		27, 54, 81, 108, 162, 216, 243, 270, 324, 360,	 /*11ac: 40Mhz, 800ns GI, MCS: 0~9 */
		59, 117, 176, 234, 351, 468, 527, 585, 702, 780, /*11ac: 80Mhz, 800ns GI, MCS: 0~9 */
		14, 29, 43, 57, 87, 115, 130, 144, 173,		 /* 11ac: 20Mhz, 400ns GI, MCS: 0~8 */
		30, 60, 90, 120, 180, 240, 270, 300, 360, 400,	 /*11ac: 40Mhz, 400ns GI, MCS: 0~9 */
		65, 130, 195, 260, 390, 520, 585, 650, 780, 867	 /*11ac: 80Mhz, 400ns GI, MCS: 0~9 */
	    };

	int rate_count = sizeof(MCSMappingRateTable) / sizeof(int);
	int rate_index = 0;
	int value = 0;

	if (HTSetting.field.MODE >= 4)
	{
		if (HTSetting.field.BW == 0)
		{
			rate_index = 108 +
				     ((unsigned char)HTSetting.field.ShortGI * 29) +
				     ((unsigned char)HTSetting.field.MCS);
		}
		else if (HTSetting.field.BW == 1)
		{
			rate_index = 117 +
				     ((unsigned char)HTSetting.field.ShortGI * 29) +
				     ((unsigned char)HTSetting.field.MCS);
		}
		else if (HTSetting.field.BW == 2)
		{
			rate_index = 127 +
				     ((unsigned char)HTSetting.field.ShortGI * 29) +
				     ((unsigned char)HTSetting.field.MCS);
		}
	}
	else if (HTSetting.field.MODE >= 2)
	{
		/*    	rate_index = 12 + ((UCHAR)ht_setting.field.BW *16) + ((UCHAR)ht_setting.field.ShortGI *32) + ((UCHAR)ht_setting.field.MCS);*/
		rate_index = 12 + ((unsigned char)HTSetting.field.BW * 24) + ((unsigned char)HTSetting.field.ShortGI * 48) + ((unsigned char)HTSetting.field.MCS);
	}
	else if (HTSetting.field.MODE == 1)
		rate_index = (unsigned char)(HTSetting.field.MCS) + 4;
	else if (HTSetting.field.MODE == 0)
		rate_index = (unsigned char)(HTSetting.field.MCS);

	if (rate_index < 0)
		rate_index = 0;

	if (rate_index >= rate_count)
		rate_index = rate_count - 1;

	return (MCSMappingRateTable[rate_index] * 5 * 100);
}

int ra_get_assoclist(const char *ifname, char *buf, int *len)
{
	int ret, i;
	int bl = 0, tl, noise;
	struct iwreq wrq;
	struct iwinfo_assoclist_entry entry;

	if (!strncmp(ifname, "apcli", 5))
		return -1;

	char table[8192];

	strcpy(wrq.ifr_ifrn.ifrn_name, ifname);
	wrq.u.data.pointer = (caddr_t)&table;
	wrq.u.data.flags = 0;

	ret = ra_ioctl(ifname, RTPRIV_IOCTL_GET_MAC_TABLE_STRUCT, &wrq);
	if (ret < 0)
	{
		fprintf(stderr, "assoclist ioctl fails\n");
		return -1;
	}

	RT_802_11_MAC_TABLE *a = &table;

	*len = a->Num * sizeof(struct iwinfo_assoclist_entry);

	for (i = 0; i < a->Num; i++)
	{
		RT_802_11_MAC_ENTRY *pe = &(a->Entry[i]);
		memset(&entry, 0, sizeof(entry));

		entry.signal = ((int)(pe->AvgRssi0) + (int)(pe->AvgRssi1)) / 2;

		entry.noise = -95;
		entry.inactive = pe->ConnectedTime * 1000;

		memcpy(&entry.mac, &pe->Addr, sizeof(entry.mac));

		entry.tx_packets = 0;
		entry.rx_packets = 0;

		entry.tx_rate.rate = getRate(pe->TxRate);
		entry.tx_rate.mcs = pe->TxRate.field.MCS;
		entry.tx_rate.is_40mhz = pe->TxRate.field.BW;
		entry.tx_rate.is_short_gi = pe->TxRate.field.ShortGI;

		entry.rx_rate = entry.tx_rate;

		memcpy(&buf[bl], &entry, sizeof(struct iwinfo_assoclist_entry));

		bl += sizeof(struct iwinfo_assoclist_entry);

		*len = bl;
	}
	return 0;
}

int ra_get_txpwrlist(const char *ifname, char *buf, int *len)
{
	struct iwinfo_txpwrlist_entry entry;
	uint8_t dbm[9] = {0, 6, 8, 10, 12, 14, 16, 18, 20};
	uint8_t mw[9] = {1, 3, 6, 10, 15, 25, 39, 63, 100};
	int i;

	for (i = 0; i < 9; i++)
	{
		entry.dbm = dbm[i];
		entry.mw = mw[i];
		memcpy(&buf[i * sizeof(entry)], &entry, sizeof(entry));
	}

	*len = 9 * sizeof(entry);
	return 0;
}

static void bssid2mac(char *macStr, unsigned char *mac)
{
	unsigned int iMac[6];
	int i;
	sscanf(macStr, "%x:%x:%x:%x:%x:%x", &iMac[0], &iMac[1], &iMac[2], &iMac[3], &iMac[4], &iMac[5]);
	for (i = 0; i < 6; i++)
		mac[i] = (unsigned char)iMac[i];
}

static void parse_security(char *sec, struct iwinfo_crypto_entry *enc)
{
	memset(enc, 0, sizeof(struct iwinfo_crypto_entry));
	enc->enabled = 0;
	if (strstr(sec, "WPA"))
	{
		enc->enabled = 1;
		if (strstr(sec, "WPAPSKWPA2PSK"))
			enc->wpa_version = 3;
		else if (strstr(sec, "WPA2PSK"))
			enc->wpa_version = 2;
		else if (strstr(sec, "WPAPSK"))
			enc->wpa_version = 1;
		else if (strstr(sec, "WPA"))
			enc->wpa_version = 1;

		enc->auth_suites |= IWINFO_KMGMT_PSK;

		if (strstr(sec, "AES"))
			enc->pair_ciphers |= IWINFO_CIPHER_CCMP;
		if (strstr(sec, "TKIP"))
			enc->pair_ciphers |= IWINFO_CIPHER_TKIP;

		enc->group_ciphers = enc->pair_ciphers;
	}
	else if (strstr(sec, "WEP"))
	{
		enc->enabled = 1;
		enc->auth_algs |= IWINFO_AUTH_OPEN;
		enc->pair_ciphers |= IWINFO_CIPHER_WEP104;
		enc->auth_suites |= IWINFO_KMGMT_NONE;
		enc->group_ciphers = enc->pair_ciphers;
	}
}

int rtrim(char *s)
{
	int i;

	i = strlen(s) - 1;
	while ((s[i] == ' ' || s[i] == '\t') && i >= 0)
	{
		i--;
	};
	s[i + 1] = '\0';
	return i + 1;
}

static void fill_find_entry(char *sp, struct iwinfo_scanlist_entry *e)
{
	char site_channel[4];
	char site_ssid[33];
	char site_bssid[20];
	char site_security[23];
	char site_signal[9];
	char site_wirelessmode[7];
	char ssid_str[128];
	int len;

	sp += 4; // skip No
	memcpy(site_channel, sp, 4);
	memcpy(site_ssid, sp + 4, 33);
	memcpy(site_bssid, sp + 37, 20);
	memcpy(site_security, sp + 57, 23);
	memcpy(site_signal, sp + 80, 9);

	rtrim(site_bssid);
	rtrim(site_channel);
	rtrim(site_security);
	rtrim(site_signal);

	e->channel = atoi(site_channel);
	bssid2mac((unsigned char *)site_bssid, (unsigned char *)e->mac);
	e->mode = IWINFO_OPMODE_MASTER;
	//e->crypto.enable = 0;
	parse_security((char *)site_security, &e->crypto);

	int quality = atoi(site_signal);
	int8_t rssi;
	rssi = (quality * 95 / 100) - 95;

	if (quality < 5)
	{
		rssi = -95;
	}

	e->signal = rssi;
	e->quality = quality;
	e->quality_max = 100;

	len = rtrim(site_ssid);
	if (!strlen(site_ssid))
	{
		strcpy(site_ssid, "???");
		len = 3;
	}
	memcpy(e->ssid, site_ssid, len);
}

static char *next_line(char *sp) {
	while (*sp != '\n' && *sp != '\0')
		++sp;
	if (*sp == '\n')
		++sp; // skip \n
	return sp;
}

int ra_get_scanlist(const char *ifname, char *buf, int *len)
{
	struct iwreq wrq;
	char data[8192];
	char *sp, *empty, *end;

	int line_len, i;

	int is5g = is_5g(ifname);

	iwpriv_set(ifname, "SiteSurvey", "1");
	sleep(3);

	memset(data, 0, sizeof(data));
	wrq.u.data.length = sizeof(data);
	wrq.u.data.pointer = data;
	wrq.u.data.flags = 0;

	if (ra_ioctl(ifname, RTPRIV_IOCTL_GSITESURVEY, &wrq) >= 0)
	{
		struct iwinfo_scanlist_entry e;
		// No  Ch  SSID                             BSSID               Security               Siganl(%)W-Mode  ExtCH  NT SSID_Len WPS DPID BcnRept
		line_len = 4 + 4 + 33 + 20 + 23 + 9 + 8 + 7 + 3 + 9; // WPS DPID may not present
		if (wrq.u.data.length < line_len + 3 + 10)
			return -1;
		sp = wrq.u.data.pointer;
		for (i = 0; i < 3; ++i) {
			// skip \n+'Total=xxxx'+\n+HEADER+\n
			sp = next_line(sp);
		}
		end = sp + strlen(sp);
		i = 0;
		while (*sp >= '0' && end > sp)
		{
			memset(&e, 0, sizeof(struct iwinfo_scanlist_entry));

			fill_find_entry(sp, &e);
			if ((e.channel < 34) ^ is5g) {
				memcpy(&buf[i * sizeof(struct iwinfo_scanlist_entry)], &e, sizeof(struct iwinfo_scanlist_entry));
				i++;
			}
			sp += line_len;
			sp = next_line(sp);
		}
		*len = i * sizeof(struct iwinfo_scanlist_entry);
		return 0;
	}
	return -1;
}

#define RA_MAX_CH_2G 13
static const uint8_t CH5G[]={
	/* 802.11 UNI / HyperLan 2 */
	36, 40, 44, 48, 52, 56, 60, 64, //8

	/* 802.11 HyperLan 2 */
	100, 104, 108, 112, 116, 120, 124, 128, 132, 136, //10

	/* 802.11 UNII */
	140, 144, 149, 153, 157, 161, 165
};

int ra_get_freqlist(const char *ifname, char *buf, int *len)
{

	struct iwinfo_freqlist_entry entry;
	int i, bl;
	bl = 0;

	if (is_5g(ifname)) {
		for (i=0; i<ARRAY_SIZE(CH5G); ++i) {
			entry.mhz = 5000 + 5 * CH5G[i];
			entry.channel =  CH5G[i];
			entry.restricted = 0;

			memcpy(&buf[bl], &entry, sizeof(struct iwinfo_freqlist_entry));
			bl += sizeof(struct iwinfo_freqlist_entry);
		}
	} else {
		for (i = 0; i < RA_MAX_CH_2G; i++)
		{
			entry.mhz = 2412 + 5 * i;
			entry.channel = i + 1;
			entry.restricted = 0;

			memcpy(&buf[bl], &entry, sizeof(struct iwinfo_freqlist_entry));
			bl += sizeof(struct iwinfo_freqlist_entry);
		}
	}

	*len = bl;
	return 0;
}

int ra_get_country(const char *ifname, char *buf)
{
	char data[10];
	if (ra_oid_ioctl(ifname, RT_OID_VERSION_INFO, data, sizeof(data)) < 0)
		return -1;
	strncpy(buf, "US", 2);
	return 0;
}

int ra_get_countrylist(const char *ifname, char *buf, int *len)
{

	int i, count;
	struct ISO3166_to_CCode *e, *p = NULL;
	struct iwinfo_country_entry *c = (struct iwinfo_country_entry *)buf;
	char data[10];
	if (ra_oid_ioctl(ifname, RT_OID_VERSION_INFO, data, sizeof(data)) < 0)
		return -1;
	count = 0;

	for (int i = 0; i < (sizeof(CountryCodes) / sizeof(CountryCodes[0])); i++)
	{
		e = &CountryCodes[i];

		if (!p || (e->iso3166 != p->iso3166))
		{
			c->iso3166 = e->iso3166;
			snprintf(c->ccode, sizeof(c->ccode), "%i", e->ccode);

			c++;
			count++;
		}

		p = e;
	}

	*len = (count * sizeof(struct iwinfo_country_entry));
	return 0;
}

int ra_get_hwmodelist(const char *ifname, int *buf)
{
	char data[10];

	if (ra_oid_ioctl(ifname, RT_OID_VERSION_INFO, data, sizeof(data)) < 0)
		return -1;
	if (is_5g(ifname))
	{
		*buf |= IWINFO_80211_A;
		*buf |= IWINFO_80211_N;
		*buf |= IWINFO_80211_AC;
	}
	else
	{
		*buf |= IWINFO_80211_B;
		*buf |= IWINFO_80211_G;
		*buf |= IWINFO_80211_N;
	}

	return 0;
}

int ra_get_htmodelist(const char *ifname, int *buf) {
	*buf = IWINFO_HTMODE_HT20 | IWINFO_HTMODE_HT40 | IWINFO_HTMODE_VHT20 | IWINFO_HTMODE_VHT40 | IWINFO_HTMODE_VHT80;

	return 0;
}

int ra_get_mbssid_support(const char *ifname, int *buf)
{
	char data[10];

	if (ra_oid_ioctl(ifname, RT_OID_VERSION_INFO, data, sizeof(data)) < 0)
		return -1;
	*buf = 1;
	return 0;
}

int iwinfo_hardware_id_from_mtd(struct iwinfo_hardware_id *id);

int ra_get_hardware_id(const char *ifname, char *buf)
{
	struct iwinfo_hardware_id *id = (struct iwinfo_hardware_id *)buf;
	memset(id, 0, sizeof(struct iwinfo_hardware_id));
	char data[10];
	if (ra_oid_ioctl(ifname, RT_OID_VERSION_INFO, data, sizeof(data)) < 0)
		return -1;
	return iwinfo_hardware_id_from_mtd(id);
}

struct iwinfo_hardware_entry * iwinfo_hardware(struct iwinfo_hardware_id *id);

int ra_get_hardware_name(const char *ifname, char *buf)
{
	struct iwinfo_hardware_id id;
	struct iwinfo_hardware_entry *e;

	if (ra_get_hardware_id(ifname, (char *)&id))
		return -1;

	e = iwinfo_hardware(&id);
	if (!e)
		return -1;

	strcpy(buf, e->device_name);

	return 0;
}

int ra_get_txpower_offset(const char *ifname, int *buf)
{
	/* Stub */
	*buf = 0;
	return -1;
}

int ra_get_frequency_offset(const char *ifname, int *buf)
{
	return ra_get_frequency(ifname, buf);
}
