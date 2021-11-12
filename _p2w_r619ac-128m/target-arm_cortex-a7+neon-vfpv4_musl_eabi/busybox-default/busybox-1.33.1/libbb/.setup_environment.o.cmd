cmd_libbb/setup_environment.o := arm-openwrt-linux-muslgnueabi-gcc -Wp,-MD,libbb/.setup_environment.o.d   -std=gnu99 -Iinclude -Ilibbb  -include include/autoconf.h -D_GNU_SOURCE -DNDEBUG -D_LARGEFILE_SOURCE -D_LARGEFILE64_SOURCE -D_FILE_OFFSET_BITS=64 -DBB_VER='"1.33.1"'  -Wall -Wshadow -Wwrite-strings -Wundef -Wstrict-prototypes -Wunused -Wunused-parameter -Wunused-function -Wunused-value -Wmissing-prototypes -Wmissing-declarations -Wno-format-security -Wdeclaration-after-statement -Wold-style-definition -finline-limit=0 -fno-builtin-strlen -fomit-frame-pointer -ffunction-sections -fdata-sections -fno-guess-branch-probability -funsigned-char -falign-functions=1 -falign-jumps=1 -falign-labels=1 -falign-loops=1 -fno-unwind-tables -fno-asynchronous-unwind-tables -fno-builtin-printf -Os  -Os -pipe -fno-caller-saves -fno-plt -fhonour-copts -Wno-error=unused-but-set-variable -Wno-error=unused-result -mfloat-abi=hard -fmacro-prefix-map=/workdir/openwrt/build_dir/target-arm_cortex-a7+neon-vfpv4_musl_eabi/busybox-default/busybox-1.33.1=busybox-1.33.1 -fstack-protector -D_FORTIFY_SOURCE=1 -Wl,-z,now -Wl,-z,relro -flto -I/workdir/openwrt/staging_dir/toolchain-arm_cortex-a7+neon-vfpv4_gcc-8.4.0_musl_eabi/usr/include -I/workdir/openwrt/staging_dir/toolchain-arm_cortex-a7+neon-vfpv4_gcc-8.4.0_musl_eabi/include/fortify -I/workdir/openwrt/staging_dir/toolchain-arm_cortex-a7+neon-vfpv4_gcc-8.4.0_musl_eabi/include   -DKBUILD_BASENAME='"setup_environment"'  -DKBUILD_MODNAME='"setup_environment"' -c -o libbb/setup_environment.o libbb/setup_environment.c

deps_libbb/setup_environment.o := \
  libbb/setup_environment.c \
  /workdir/staging_dir/_p2w_r619ac-128m/toolchain-arm_cortex-a7+neon-vfpv4_gcc-8.4.0_musl_eabi/include/stdc-predef.h \
  include/libbb.h \
    $(wildcard include/config/feature/shadowpasswds.h) \
    $(wildcard include/config/use/bb/shadow.h) \
    $(wildcard include/config/selinux.h) \
    $(wildcard include/config/feature/utmp.h) \
    $(wildcard include/config/locale/support.h) \
    $(wildcard include/config/use/bb/pwd/grp.h) \
    $(wildcard include/config/lfs.h) \
    $(wildcard include/config/feature/buffers/go/on/stack.h) \
    $(wildcard include/config/feature/buffers/go/in/bss.h) \
    $(wildcard include/config/variable/arch/pagesize.h) \
    $(wildcard include/config/feature/verbose.h) \
    $(wildcard include/config/feature/etc/services.h) \
    $(wildcard include/config/feature/ipv6.h) \
    $(wildcard include/config/feature/seamless/xz.h) \
    $(wildcard include/config/feature/seamless/lzma.h) \
    $(wildcard include/config/feature/seamless/bz2.h) \
    $(wildcard include/config/feature/seamless/gz.h) \
    $(wildcard include/config/feature/seamless/z.h) \
    $(wildcard include/config/float/duration.h) \
    $(wildcard include/config/feature/check/names.h) \
    $(wildcard include/config/feature/prefer/applets.h) \
    $(wildcard include/config/long/opts.h) \
    $(wildcard include/config/feature/pidfile.h) \
    $(wildcard include/config/feature/syslog.h) \
    $(wildcard include/config/feature/syslog/info.h) \
    $(wildcard include/config/warn/simple/msg.h) \
    $(wildcard include/config/feature/individual.h) \
    $(wildcard include/config/ash.h) \
    $(wildcard include/config/sh/is/ash.h) \
    $(wildcard include/config/bash/is/ash.h) \
    $(wildcard include/config/hush.h) \
    $(wildcard include/config/sh/is/hush.h) \
    $(wildcard include/config/bash/is/hush.h) \
    $(wildcard include/config/echo.h) \
    $(wildcard include/config/printf.h) \
    $(wildcard include/config/test.h) \
    $(wildcard include/config/test1.h) \
    $(wildcard include/config/test2.h) \
    $(wildcard include/config/kill.h) \
    $(wildcard include/config/killall.h) \
    $(wildcard include/config/killall5.h) \
    $(wildcard include/config/chown.h) \
    $(wildcard include/config/ls.h) \
    $(wildcard include/config/xxx.h) \
    $(wildcard include/config/route.h) \
    $(wildcard include/config/feature/hwib.h) \
    $(wildcard include/config/desktop.h) \
    $(wildcard include/config/feature/crond/d.h) \
    $(wildcard include/config/feature/setpriv/capabilities.h) \
    $(wildcard include/config/run/init.h) \
    $(wildcard include/config/feature/securetty.h) \
    $(wildcard include/config/pam.h) \
    $(wildcard include/config/use/bb/crypt.h) \
    $(wildcard include/config/feature/adduser/to/group.h) \
    $(wildcard include/config/feature/del/user/from/group.h) \
    $(wildcard include/config/ioctl/hex2str/error.h) \
    $(wildcard include/config/feature/editing.h) \
    $(wildcard include/config/feature/editing/history.h) \
    $(wildcard include/config/feature/tab/completion.h) \
    $(wildcard include/config/shell/ash.h) \
    $(wildcard include/config/shell/hush.h) \
    $(wildcard include/config/feature/editing/savehistory.h) \
    $(wildcard include/config/feature/username/completion.h) \
    $(wildcard include/config/feature/editing/vi.h) \
    $(wildcard include/config/feature/editing/save/on/exit.h) \
    $(wildcard include/config/pmap.h) \
    $(wildcard include/config/feature/show/threads.h) \
    $(wildcard include/config/feature/ps/additional/columns.h) \
    $(wildcard include/config/feature/topmem.h) \
    $(wildcard include/config/feature/top/smp/process.h) \
    $(wildcard include/config/pgrep.h) \
    $(wildcard include/config/pkill.h) \
    $(wildcard include/config/pidof.h) \
    $(wildcard include/config/sestatus.h) \
    $(wildcard include/config/unicode/support.h) \
    $(wildcard include/config/feature/mtab/support.h) \
    $(wildcard include/config/feature/clean/up.h) \
    $(wildcard include/config/feature/devfs.h) \
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
  /workdir/staging_dir/_p2w_r619ac-128m/toolchain-arm_cortex-a7+neon-vfpv4_gcc-8.4.0_musl_eabi/include/ctype.h \
  /workdir/staging_dir/_p2w_r619ac-128m/toolchain-arm_cortex-a7+neon-vfpv4_gcc-8.4.0_musl_eabi/include/dirent.h \
  /workdir/staging_dir/_p2w_r619ac-128m/toolchain-arm_cortex-a7+neon-vfpv4_gcc-8.4.0_musl_eabi/include/errno.h \
  /workdir/staging_dir/_p2w_r619ac-128m/toolchain-arm_cortex-a7+neon-vfpv4_gcc-8.4.0_musl_eabi/include/bits/errno.h \
  /workdir/staging_dir/_p2w_r619ac-128m/toolchain-arm_cortex-a7+neon-vfpv4_gcc-8.4.0_musl_eabi/include/fcntl.h \
  /workdir/staging_dir/_p2w_r619ac-128m/toolchain-arm_cortex-a7+neon-vfpv4_gcc-8.4.0_musl_eabi/include/bits/fcntl.h \
  /workdir/staging_dir/_p2w_r619ac-128m/toolchain-arm_cortex-a7+neon-vfpv4_gcc-8.4.0_musl_eabi/include/inttypes.h \
  /workdir/staging_dir/_p2w_r619ac-128m/toolchain-arm_cortex-a7+neon-vfpv4_gcc-8.4.0_musl_eabi/include/netdb.h \
  /workdir/staging_dir/_p2w_r619ac-128m/toolchain-arm_cortex-a7+neon-vfpv4_gcc-8.4.0_musl_eabi/include/netinet/in.h \
  /workdir/openwrt/staging_dir/toolchain-arm_cortex-a7+neon-vfpv4_gcc-8.4.0_musl_eabi/include/fortify/sys/socket.h \
  /workdir/staging_dir/_p2w_r619ac-128m/toolchain-arm_cortex-a7+neon-vfpv4_gcc-8.4.0_musl_eabi/include/sys/socket.h \
  /workdir/staging_dir/_p2w_r619ac-128m/toolchain-arm_cortex-a7+neon-vfpv4_gcc-8.4.0_musl_eabi/include/bits/socket.h \
  /workdir/openwrt/staging_dir/toolchain-arm_cortex-a7+neon-vfpv4_gcc-8.4.0_musl_eabi/include/fortify/sys/../fortify-headers.h \
  /workdir/staging_dir/_p2w_r619ac-128m/toolchain-arm_cortex-a7+neon-vfpv4_gcc-8.4.0_musl_eabi/include/setjmp.h \
  /workdir/staging_dir/_p2w_r619ac-128m/toolchain-arm_cortex-a7+neon-vfpv4_gcc-8.4.0_musl_eabi/include/bits/setjmp.h \
  /workdir/staging_dir/_p2w_r619ac-128m/toolchain-arm_cortex-a7+neon-vfpv4_gcc-8.4.0_musl_eabi/include/signal.h \
  /workdir/staging_dir/_p2w_r619ac-128m/toolchain-arm_cortex-a7+neon-vfpv4_gcc-8.4.0_musl_eabi/include/bits/signal.h \
  /workdir/staging_dir/_p2w_r619ac-128m/toolchain-arm_cortex-a7+neon-vfpv4_gcc-8.4.0_musl_eabi/include/paths.h \
  /workdir/openwrt/staging_dir/toolchain-arm_cortex-a7+neon-vfpv4_gcc-8.4.0_musl_eabi/include/fortify/stdio.h \
  /workdir/staging_dir/_p2w_r619ac-128m/toolchain-arm_cortex-a7+neon-vfpv4_gcc-8.4.0_musl_eabi/include/stdio.h \
  /workdir/openwrt/staging_dir/toolchain-arm_cortex-a7+neon-vfpv4_gcc-8.4.0_musl_eabi/include/fortify/stdlib.h \
  /workdir/staging_dir/_p2w_r619ac-128m/toolchain-arm_cortex-a7+neon-vfpv4_gcc-8.4.0_musl_eabi/include/stdlib.h \
  /workdir/staging_dir/_p2w_r619ac-128m/toolchain-arm_cortex-a7+neon-vfpv4_gcc-8.4.0_musl_eabi/include/alloca.h \
  /workdir/staging_dir/_p2w_r619ac-128m/toolchain-arm_cortex-a7+neon-vfpv4_gcc-8.4.0_musl_eabi/include/limits.h \
  /workdir/staging_dir/_p2w_r619ac-128m/toolchain-arm_cortex-a7+neon-vfpv4_gcc-8.4.0_musl_eabi/include/stdarg.h \
  /workdir/staging_dir/_p2w_r619ac-128m/toolchain-arm_cortex-a7+neon-vfpv4_gcc-8.4.0_musl_eabi/include/stddef.h \
  /workdir/openwrt/staging_dir/toolchain-arm_cortex-a7+neon-vfpv4_gcc-8.4.0_musl_eabi/include/fortify/string.h \
  /workdir/staging_dir/_p2w_r619ac-128m/toolchain-arm_cortex-a7+neon-vfpv4_gcc-8.4.0_musl_eabi/include/string.h \
  /workdir/openwrt/staging_dir/toolchain-arm_cortex-a7+neon-vfpv4_gcc-8.4.0_musl_eabi/include/fortify/strings.h \
  /workdir/staging_dir/_p2w_r619ac-128m/toolchain-arm_cortex-a7+neon-vfpv4_gcc-8.4.0_musl_eabi/include/strings.h \
  /workdir/staging_dir/_p2w_r619ac-128m/toolchain-arm_cortex-a7+neon-vfpv4_gcc-8.4.0_musl_eabi/include/libgen.h \
  /workdir/openwrt/staging_dir/toolchain-arm_cortex-a7+neon-vfpv4_gcc-8.4.0_musl_eabi/include/fortify/poll.h \
  /workdir/staging_dir/_p2w_r619ac-128m/toolchain-arm_cortex-a7+neon-vfpv4_gcc-8.4.0_musl_eabi/include/poll.h \
  /workdir/staging_dir/_p2w_r619ac-128m/toolchain-arm_cortex-a7+neon-vfpv4_gcc-8.4.0_musl_eabi/include/bits/poll.h \
  /workdir/staging_dir/_p2w_r619ac-128m/toolchain-arm_cortex-a7+neon-vfpv4_gcc-8.4.0_musl_eabi/include/sys/ioctl.h \
  /workdir/staging_dir/_p2w_r619ac-128m/toolchain-arm_cortex-a7+neon-vfpv4_gcc-8.4.0_musl_eabi/include/bits/ioctl.h \
  /workdir/staging_dir/_p2w_r619ac-128m/toolchain-arm_cortex-a7+neon-vfpv4_gcc-8.4.0_musl_eabi/include/bits/ioctl_fix.h \
  /workdir/staging_dir/_p2w_r619ac-128m/toolchain-arm_cortex-a7+neon-vfpv4_gcc-8.4.0_musl_eabi/include/sys/mman.h \
  /workdir/staging_dir/_p2w_r619ac-128m/toolchain-arm_cortex-a7+neon-vfpv4_gcc-8.4.0_musl_eabi/include/bits/mman.h \
  /workdir/staging_dir/_p2w_r619ac-128m/toolchain-arm_cortex-a7+neon-vfpv4_gcc-8.4.0_musl_eabi/include/sys/resource.h \
  /workdir/staging_dir/_p2w_r619ac-128m/toolchain-arm_cortex-a7+neon-vfpv4_gcc-8.4.0_musl_eabi/include/sys/time.h \
  /workdir/openwrt/staging_dir/toolchain-arm_cortex-a7+neon-vfpv4_gcc-8.4.0_musl_eabi/include/fortify/sys/select.h \
  /workdir/staging_dir/_p2w_r619ac-128m/toolchain-arm_cortex-a7+neon-vfpv4_gcc-8.4.0_musl_eabi/include/sys/select.h \
  /workdir/staging_dir/_p2w_r619ac-128m/toolchain-arm_cortex-a7+neon-vfpv4_gcc-8.4.0_musl_eabi/include/bits/resource.h \
  /workdir/staging_dir/_p2w_r619ac-128m/toolchain-arm_cortex-a7+neon-vfpv4_gcc-8.4.0_musl_eabi/include/sys/stat.h \
  /workdir/staging_dir/_p2w_r619ac-128m/toolchain-arm_cortex-a7+neon-vfpv4_gcc-8.4.0_musl_eabi/include/bits/stat.h \
  /workdir/staging_dir/_p2w_r619ac-128m/toolchain-arm_cortex-a7+neon-vfpv4_gcc-8.4.0_musl_eabi/include/sys/types.h \
  /workdir/staging_dir/_p2w_r619ac-128m/toolchain-arm_cortex-a7+neon-vfpv4_gcc-8.4.0_musl_eabi/include/sys/sysmacros.h \
  /workdir/staging_dir/_p2w_r619ac-128m/toolchain-arm_cortex-a7+neon-vfpv4_gcc-8.4.0_musl_eabi/include/sys/wait.h \
  /workdir/staging_dir/_p2w_r619ac-128m/toolchain-arm_cortex-a7+neon-vfpv4_gcc-8.4.0_musl_eabi/include/termios.h \
  /workdir/staging_dir/_p2w_r619ac-128m/toolchain-arm_cortex-a7+neon-vfpv4_gcc-8.4.0_musl_eabi/include/bits/termios.h \
  /workdir/staging_dir/_p2w_r619ac-128m/toolchain-arm_cortex-a7+neon-vfpv4_gcc-8.4.0_musl_eabi/include/time.h \
  /workdir/staging_dir/_p2w_r619ac-128m/toolchain-arm_cortex-a7+neon-vfpv4_gcc-8.4.0_musl_eabi/include/sys/param.h \
  /workdir/staging_dir/_p2w_r619ac-128m/toolchain-arm_cortex-a7+neon-vfpv4_gcc-8.4.0_musl_eabi/include/pwd.h \
  /workdir/staging_dir/_p2w_r619ac-128m/toolchain-arm_cortex-a7+neon-vfpv4_gcc-8.4.0_musl_eabi/include/grp.h \
  /workdir/staging_dir/_p2w_r619ac-128m/toolchain-arm_cortex-a7+neon-vfpv4_gcc-8.4.0_musl_eabi/include/shadow.h \
  /workdir/staging_dir/_p2w_r619ac-128m/toolchain-arm_cortex-a7+neon-vfpv4_gcc-8.4.0_musl_eabi/include/mntent.h \
  /workdir/staging_dir/_p2w_r619ac-128m/toolchain-arm_cortex-a7+neon-vfpv4_gcc-8.4.0_musl_eabi/include/sys/statfs.h \
  /workdir/staging_dir/_p2w_r619ac-128m/toolchain-arm_cortex-a7+neon-vfpv4_gcc-8.4.0_musl_eabi/include/sys/statvfs.h \
  /workdir/staging_dir/_p2w_r619ac-128m/toolchain-arm_cortex-a7+neon-vfpv4_gcc-8.4.0_musl_eabi/include/bits/statfs.h \
  /workdir/staging_dir/_p2w_r619ac-128m/toolchain-arm_cortex-a7+neon-vfpv4_gcc-8.4.0_musl_eabi/include/arpa/inet.h \
  include/xatonum.h \

libbb/setup_environment.o: $(deps_libbb/setup_environment.o)

$(deps_libbb/setup_environment.o):
