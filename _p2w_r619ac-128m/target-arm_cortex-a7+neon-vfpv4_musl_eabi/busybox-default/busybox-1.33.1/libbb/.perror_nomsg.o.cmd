cmd_libbb/perror_nomsg.o := arm-openwrt-linux-muslgnueabi-gcc -Wp,-MD,libbb/.perror_nomsg.o.d   -std=gnu99 -Iinclude -Ilibbb  -include include/autoconf.h -D_GNU_SOURCE -DNDEBUG -D_LARGEFILE_SOURCE -D_LARGEFILE64_SOURCE -D_FILE_OFFSET_BITS=64 -DBB_VER='"1.33.1"'  -Wall -Wshadow -Wwrite-strings -Wundef -Wstrict-prototypes -Wunused -Wunused-parameter -Wunused-function -Wunused-value -Wmissing-prototypes -Wmissing-declarations -Wno-format-security -Wdeclaration-after-statement -Wold-style-definition -finline-limit=0 -fno-builtin-strlen -fomit-frame-pointer -ffunction-sections -fdata-sections -fno-guess-branch-probability -funsigned-char -falign-functions=1 -falign-jumps=1 -falign-labels=1 -falign-loops=1 -fno-unwind-tables -fno-asynchronous-unwind-tables -fno-builtin-printf -Os  -Os -pipe -fno-caller-saves -fno-plt -fhonour-copts -Wno-error=unused-but-set-variable -Wno-error=unused-result -mfloat-abi=hard -fmacro-prefix-map=/workdir/openwrt/build_dir/target-arm_cortex-a7+neon-vfpv4_musl_eabi/busybox-default/busybox-1.33.1=busybox-1.33.1 -fstack-protector -D_FORTIFY_SOURCE=1 -Wl,-z,now -Wl,-z,relro -flto -I/workdir/openwrt/staging_dir/toolchain-arm_cortex-a7+neon-vfpv4_gcc-8.4.0_musl_eabi/usr/include -I/workdir/openwrt/staging_dir/toolchain-arm_cortex-a7+neon-vfpv4_gcc-8.4.0_musl_eabi/include/fortify -I/workdir/openwrt/staging_dir/toolchain-arm_cortex-a7+neon-vfpv4_gcc-8.4.0_musl_eabi/include   -DKBUILD_BASENAME='"perror_nomsg"'  -DKBUILD_MODNAME='"perror_nomsg"' -c -o libbb/perror_nomsg.o libbb/perror_nomsg.c

deps_libbb/perror_nomsg.o := \
  libbb/perror_nomsg.c \
  /workdir/staging_dir/_p2w_r619ac-128m/toolchain-arm_cortex-a7+neon-vfpv4_gcc-8.4.0_musl_eabi/include/stdc-predef.h \
  include/platform.h \
    $(wildcard include/config/werror.h) \
    $(wildcard include/config/big/endian.h) \
    $(wildcard include/config/little/endian.h) \
    $(wildcard include/config/nommu.h) \
  /workdir/staging_dir/_p2w_r619ac-128m/toolchain-arm_cortex-a7+neon-vfpv4_gcc-8.4.0_musl_eabi/include/limits.h \
  /workdir/staging_dir/_p2w_r619ac-128m/toolchain-arm_cortex-a7+neon-vfpv4_gcc-8.4.0_musl_eabi/include/features.h \
  /workdir/staging_dir/_p2w_r619ac-128m/toolchain-arm_cortex-a7+neon-vfpv4_gcc-8.4.0_musl_eabi/include/sys/glibc-types.h \
  /workdir/staging_dir/_p2w_r619ac-128m/toolchain-arm_cortex-a7+neon-vfpv4_gcc-8.4.0_musl_eabi/include/sys/cdefs.h \
  /workdir/staging_dir/_p2w_r619ac-128m/toolchain-arm_cortex-a7+neon-vfpv4_gcc-8.4.0_musl_eabi/include/bits/limits.h \
  /workdir/staging_dir/_p2w_r619ac-128m/toolchain-arm_cortex-a7+neon-vfpv4_gcc-8.4.0_musl_eabi/include/byteswap.h \
  /workdir/staging_dir/_p2w_r619ac-128m/toolchain-arm_cortex-a7+neon-vfpv4_gcc-8.4.0_musl_eabi/include/stdint.h \
  /workdir/staging_dir/_p2w_r619ac-128m/toolchain-arm_cortex-a7+neon-vfpv4_gcc-8.4.0_musl_eabi/include/bits/alltypes.h \
  /workdir/staging_dir/_p2w_r619ac-128m/toolchain-arm_cortex-a7+neon-vfpv4_gcc-8.4.0_musl_eabi/include/bits/stdint.h \
  /workdir/staging_dir/_p2w_r619ac-128m/toolchain-arm_cortex-a7+neon-vfpv4_gcc-8.4.0_musl_eabi/include/endian.h \
  /workdir/staging_dir/_p2w_r619ac-128m/toolchain-arm_cortex-a7+neon-vfpv4_gcc-8.4.0_musl_eabi/include/stdbool.h \
  /workdir/openwrt/staging_dir/toolchain-arm_cortex-a7+neon-vfpv4_gcc-8.4.0_musl_eabi/include/fortify/unistd.h \
  /workdir/staging_dir/_p2w_r619ac-128m/toolchain-arm_cortex-a7+neon-vfpv4_gcc-8.4.0_musl_eabi/include/unistd.h \
  /workdir/staging_dir/_p2w_r619ac-128m/toolchain-arm_cortex-a7+neon-vfpv4_gcc-8.4.0_musl_eabi/include/bits/posix.h \
  /workdir/openwrt/staging_dir/toolchain-arm_cortex-a7+neon-vfpv4_gcc-8.4.0_musl_eabi/include/fortify/fortify-headers.h \

libbb/perror_nomsg.o: $(deps_libbb/perror_nomsg.o)

$(deps_libbb/perror_nomsg.o):
