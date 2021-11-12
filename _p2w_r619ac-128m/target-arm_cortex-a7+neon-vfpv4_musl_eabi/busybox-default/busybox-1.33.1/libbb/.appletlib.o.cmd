cmd_libbb/appletlib.o := arm-openwrt-linux-muslgnueabi-gcc -Wp,-MD,libbb/.appletlib.o.d   -std=gnu99 -Iinclude -Ilibbb  -include include/autoconf.h -D_GNU_SOURCE -DNDEBUG -D_LARGEFILE_SOURCE -D_LARGEFILE64_SOURCE -D_FILE_OFFSET_BITS=64 -DBB_VER='"1.33.1"'  -Wall -Wshadow -Wwrite-strings -Wundef -Wstrict-prototypes -Wunused -Wunused-parameter -Wunused-function -Wunused-value -Wmissing-prototypes -Wmissing-declarations -Wno-format-security -Wdeclaration-after-statement -Wold-style-definition -finline-limit=0 -fno-builtin-strlen -fomit-frame-pointer -ffunction-sections -fdata-sections -fno-guess-branch-probability -funsigned-char -falign-functions=1 -falign-jumps=1 -falign-labels=1 -falign-loops=1 -fno-unwind-tables -fno-asynchronous-unwind-tables -fno-builtin-printf -Os  -Os -pipe -fno-caller-saves -fno-plt -fhonour-copts -Wno-error=unused-but-set-variable -Wno-error=unused-result -mfloat-abi=hard -fmacro-prefix-map=/workdir/openwrt/build_dir/target-arm_cortex-a7+neon-vfpv4_musl_eabi/busybox-default/busybox-1.33.1=busybox-1.33.1 -fstack-protector -D_FORTIFY_SOURCE=1 -Wl,-z,now -Wl,-z,relro -flto -I/workdir/openwrt/staging_dir/toolchain-arm_cortex-a7+neon-vfpv4_gcc-8.4.0_musl_eabi/usr/include -I/workdir/openwrt/staging_dir/toolchain-arm_cortex-a7+neon-vfpv4_gcc-8.4.0_musl_eabi/include/fortify -I/workdir/openwrt/staging_dir/toolchain-arm_cortex-a7+neon-vfpv4_gcc-8.4.0_musl_eabi/include   -DKBUILD_BASENAME='"appletlib"'  -DKBUILD_MODNAME='"appletlib"' -c -o libbb/appletlib.o libbb/appletlib.c

deps_libbb/appletlib.o := \
  libbb/appletlib.c \
    $(wildcard include/config/feature/individual.h) \
    $(wildcard include/config/feature/sh/embedded/scripts.h) \
    $(wildcard include/config/feature/seamless/bz2.h) \
    $(wildcard include/config/tar.h) \
    $(wildcard include/config/modprobe.h) \
    $(wildcard include/config/insmod.h) \
    $(wildcard include/config/depmod.h) \
    $(wildcard include/config/man.h) \
    $(wildcard include/config/bunzip2.h) \
    $(wildcard include/config/bzcat.h) \
    $(wildcard include/config/feature/compress/usage.h) \
    $(wildcard include/config/show/usage.h) \
    $(wildcard include/config/feature/clean/up.h) \
    $(wildcard include/config/test.h) \
    $(wildcard include/config/locale/support.h) \
    $(wildcard include/config/feature/suid.h) \
    $(wildcard include/config/feature/suid/config.h) \
    $(wildcard include/config/feature/suid/config/quiet.h) \
    $(wildcard include/config/feature/installer.h) \
    $(wildcard include/config/install/no/usr.h) \
    $(wildcard include/config/busybox.h) \
    $(wildcard include/config/shell/ash.h) \
    $(wildcard include/config/shell/hush.h) \
    $(wildcard include/config/feature/sh/standalone.h) \
    $(wildcard include/config/feature/tab/completion.h) \
    $(wildcard include/config/feature/show/script.h) \
    $(wildcard include/config/build/libbusybox.h) \
    $(wildcard include/config/feature/prefer/applets.h) \
  /workdir/staging_dir/_p2w_r619ac-128m/toolchain-arm_cortex-a7+neon-vfpv4_gcc-8.4.0_musl_eabi/include/stdc-predef.h \
  /workdir/staging_dir/_p2w_r619ac-128m/toolchain-arm_cortex-a7+neon-vfpv4_gcc-8.4.0_musl_eabi/include/errno.h \
  /workdir/staging_dir/_p2w_r619ac-128m/toolchain-arm_cortex-a7+neon-vfpv4_gcc-8.4.0_musl_eabi/include/features.h \
  /workdir/staging_dir/_p2w_r619ac-128m/toolchain-arm_cortex-a7+neon-vfpv4_gcc-8.4.0_musl_eabi/include/sys/glibc-types.h \
  /workdir/staging_dir/_p2w_r619ac-128m/toolchain-arm_cortex-a7+neon-vfpv4_gcc-8.4.0_musl_eabi/include/sys/cdefs.h \
  /workdir/staging_dir/_p2w_r619ac-128m/toolchain-arm_cortex-a7+neon-vfpv4_gcc-8.4.0_musl_eabi/include/bits/errno.h \
  include/busybox.h \
    $(wildcard include/config/feature/sh/nofork.h) \
    $(wildcard include/config/feature/shared/busybox.h) \
  include/libbb.h \
    $(wildcard include/config/feature/shadowpasswds.h) \
    $(wildcard include/config/use/bb/shadow.h) \
    $(wildcard include/config/selinux.h) \
    $(wildcard include/config/feature/utmp.h) \
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
    $(wildcard include/config/feature/seamless/gz.h) \
    $(wildcard include/config/feature/seamless/z.h) \
    $(wildcard include/config/float/duration.h) \
    $(wildcard include/config/feature/check/names.h) \
    $(wildcard include/config/long/opts.h) \
    $(wildcard include/config/feature/pidfile.h) \
    $(wildcard include/config/feature/syslog.h) \
    $(wildcard include/config/feature/syslog/info.h) \
    $(wildcard include/config/warn/simple/msg.h) \
    $(wildcard include/config/ash.h) \
    $(wildcard include/config/sh/is/ash.h) \
    $(wildcard include/config/bash/is/ash.h) \
    $(wildcard include/config/hush.h) \
    $(wildcard include/config/sh/is/hush.h) \
    $(wildcard include/config/bash/is/hush.h) \
    $(wildcard include/config/echo.h) \
    $(wildcard include/config/printf.h) \
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
    $(wildcard include/config/feature/devfs.h) \
  include/platform.h \
    $(wildcard include/config/werror.h) \
    $(wildcard include/config/big/endian.h) \
    $(wildcard include/config/little/endian.h) \
    $(wildcard include/config/nommu.h) \
  /workdir/staging_dir/_p2w_r619ac-128m/toolchain-arm_cortex-a7+neon-vfpv4_gcc-8.4.0_musl_eabi/include/limits.h \
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
  include/applet_metadata.h \
  /workdir/staging_dir/_p2w_r619ac-128m/toolchain-arm_cortex-a7+neon-vfpv4_gcc-8.4.0_musl_eabi/include/malloc.h \
  include/applets.h \
    $(wildcard include/config/feature/verbose/usage.h) \
    $(wildcard include/config/ar.h) \
    $(wildcard include/config/uncompress.h) \
    $(wildcard include/config/gunzip.h) \
    $(wildcard include/config/zcat.h) \
    $(wildcard include/config/unlzma.h) \
    $(wildcard include/config/lzcat.h) \
    $(wildcard include/config/lzma.h) \
    $(wildcard include/config/unxz.h) \
    $(wildcard include/config/xzcat.h) \
    $(wildcard include/config/xz.h) \
    $(wildcard include/config/bzip2.h) \
    $(wildcard include/config/cpio.h) \
    $(wildcard include/config/dpkg.h) \
    $(wildcard include/config/dpkg/deb.h) \
    $(wildcard include/config/gzip.h) \
    $(wildcard include/config/lzop.h) \
    $(wildcard include/config/unlzop.h) \
    $(wildcard include/config/lzopcat.h) \
    $(wildcard include/config/rpm.h) \
    $(wildcard include/config/rpm2cpio.h) \
    $(wildcard include/config/unzip.h) \
    $(wildcard include/config/chvt.h) \
    $(wildcard include/config/clear.h) \
    $(wildcard include/config/deallocvt.h) \
    $(wildcard include/config/dumpkmap.h) \
    $(wildcard include/config/fgconsole.h) \
    $(wildcard include/config/kbd/mode.h) \
    $(wildcard include/config/loadfont.h) \
    $(wildcard include/config/setfont.h) \
    $(wildcard include/config/loadkmap.h) \
    $(wildcard include/config/openvt.h) \
    $(wildcard include/config/reset.h) \
    $(wildcard include/config/resize.h) \
    $(wildcard include/config/setconsole.h) \
    $(wildcard include/config/setkeycodes.h) \
    $(wildcard include/config/setlogcons.h) \
    $(wildcard include/config/showkey.h) \
    $(wildcard include/config/basename.h) \
    $(wildcard include/config/cat.h) \
    $(wildcard include/config/chgrp.h) \
    $(wildcard include/config/chmod.h) \
    $(wildcard include/config/chroot.h) \
    $(wildcard include/config/cksum.h) \
    $(wildcard include/config/comm.h) \
    $(wildcard include/config/cp.h) \
    $(wildcard include/config/cut.h) \
    $(wildcard include/config/date.h) \
    $(wildcard include/config/dd.h) \
    $(wildcard include/config/df.h) \
    $(wildcard include/config/dirname.h) \
    $(wildcard include/config/dos2unix.h) \
    $(wildcard include/config/unix2dos.h) \
    $(wildcard include/config/du.h) \
    $(wildcard include/config/env.h) \
    $(wildcard include/config/expand.h) \
    $(wildcard include/config/unexpand.h) \
    $(wildcard include/config/expr.h) \
    $(wildcard include/config/factor.h) \
    $(wildcard include/config/false.h) \
    $(wildcard include/config/fold.h) \
    $(wildcard include/config/head.h) \
    $(wildcard include/config/hostid.h) \
    $(wildcard include/config/groups.h) \
    $(wildcard include/config/id.h) \
    $(wildcard include/config/install.h) \
    $(wildcard include/config/link.h) \
    $(wildcard include/config/ln.h) \
    $(wildcard include/config/logname.h) \
    $(wildcard include/config/md5sum.h) \
    $(wildcard include/config/sha1sum.h) \
    $(wildcard include/config/sha3sum.h) \
    $(wildcard include/config/sha256sum.h) \
    $(wildcard include/config/sha512sum.h) \
    $(wildcard include/config/mkdir.h) \
    $(wildcard include/config/mkfifo.h) \
    $(wildcard include/config/mknod.h) \
    $(wildcard include/config/mktemp.h) \
    $(wildcard include/config/mv.h) \
    $(wildcard include/config/nice.h) \
    $(wildcard include/config/nl.h) \
    $(wildcard include/config/nohup.h) \
    $(wildcard include/config/nproc.h) \
    $(wildcard include/config/od.h) \
    $(wildcard include/config/paste.h) \
    $(wildcard include/config/printenv.h) \
    $(wildcard include/config/pwd.h) \
    $(wildcard include/config/readlink.h) \
    $(wildcard include/config/realpath.h) \
    $(wildcard include/config/rm.h) \
    $(wildcard include/config/rmdir.h) \
    $(wildcard include/config/seq.h) \
    $(wildcard include/config/shred.h) \
    $(wildcard include/config/shuf.h) \
    $(wildcard include/config/sleep.h) \
    $(wildcard include/config/sort.h) \
    $(wildcard include/config/split.h) \
    $(wildcard include/config/stat.h) \
    $(wildcard include/config/stty.h) \
    $(wildcard include/config/sum.h) \
    $(wildcard include/config/sync.h) \
    $(wildcard include/config/fsync.h) \
    $(wildcard include/config/tac.h) \
    $(wildcard include/config/tail.h) \
    $(wildcard include/config/tee.h) \
    $(wildcard include/config/timeout.h) \
    $(wildcard include/config/touch.h) \
    $(wildcard include/config/tr.h) \
    $(wildcard include/config/true.h) \
    $(wildcard include/config/truncate.h) \
    $(wildcard include/config/tty.h) \
    $(wildcard include/config/uname.h) \
    $(wildcard include/config/bb/arch.h) \
    $(wildcard include/config/uniq.h) \
    $(wildcard include/config/unlink.h) \
    $(wildcard include/config/usleep.h) \
    $(wildcard include/config/uudecode.h) \
    $(wildcard include/config/base32.h) \
    $(wildcard include/config/base64.h) \
    $(wildcard include/config/uuencode.h) \
    $(wildcard include/config/wc.h) \
    $(wildcard include/config/users.h) \
    $(wildcard include/config/w.h) \
    $(wildcard include/config/who.h) \
    $(wildcard include/config/whoami.h) \
    $(wildcard include/config/yes.h) \
    $(wildcard include/config/pipe/progress.h) \
    $(wildcard include/config/run/parts.h) \
    $(wildcard include/config/start/stop/daemon.h) \
    $(wildcard include/config/which.h) \
    $(wildcard include/config/chattr.h) \
    $(wildcard include/config/fsck.h) \
    $(wildcard include/config/lsattr.h) \
    $(wildcard include/config/tune2fs.h) \
    $(wildcard include/config/awk.h) \
    $(wildcard include/config/cmp.h) \
    $(wildcard include/config/diff.h) \
    $(wildcard include/config/ed.h) \
    $(wildcard include/config/patch.h) \
    $(wildcard include/config/sed.h) \
    $(wildcard include/config/vi.h) \
    $(wildcard include/config/find.h) \
    $(wildcard include/config/grep.h) \
    $(wildcard include/config/egrep.h) \
    $(wildcard include/config/fgrep.h) \
    $(wildcard include/config/xargs.h) \
    $(wildcard include/config/bootchartd.h) \
    $(wildcard include/config/halt.h) \
    $(wildcard include/config/poweroff.h) \
    $(wildcard include/config/reboot.h) \
    $(wildcard include/config/init.h) \
    $(wildcard include/config/linuxrc.h) \
    $(wildcard include/config/nuke.h) \
    $(wildcard include/config/resume.h) \
    $(wildcard include/config/unit/test.h) \
    $(wildcard include/config/add/shell.h) \
    $(wildcard include/config/remove/shell.h) \
    $(wildcard include/config/addgroup.h) \
    $(wildcard include/config/adduser.h) \
    $(wildcard include/config/chpasswd.h) \
    $(wildcard include/config/cryptpw.h) \
    $(wildcard include/config/mkpasswd.h) \
    $(wildcard include/config/deluser.h) \
    $(wildcard include/config/delgroup.h) \
    $(wildcard include/config/getty.h) \
    $(wildcard include/config/login.h) \
    $(wildcard include/config/passwd.h) \
    $(wildcard include/config/su.h) \
    $(wildcard include/config/sulogin.h) \
    $(wildcard include/config/vlock.h) \
    $(wildcard include/config/makemime.h) \
    $(wildcard include/config/popmaildir.h) \
    $(wildcard include/config/reformime.h) \
    $(wildcard include/config/sendmail.h) \
    $(wildcard include/config/adjtimex.h) \
    $(wildcard include/config/bbconfig.h) \
    $(wildcard include/config/bc.h) \
    $(wildcard include/config/dc.h) \
    $(wildcard include/config/beep.h) \
    $(wildcard include/config/chat.h) \
    $(wildcard include/config/conspy.h) \
    $(wildcard include/config/crond.h) \
    $(wildcard include/config/crontab.h) \
    $(wildcard include/config/devfsd.h) \
    $(wildcard include/config/devmem.h) \
    $(wildcard include/config/fbsplash.h) \
    $(wildcard include/config/flash/eraseall.h) \
    $(wildcard include/config/flash/lock.h) \
    $(wildcard include/config/flash/unlock.h) \
    $(wildcard include/config/flashcp.h) \
    $(wildcard include/config/hdparm.h) \
    $(wildcard include/config/hexedit.h) \
    $(wildcard include/config/i2cget.h) \
    $(wildcard include/config/i2cset.h) \
    $(wildcard include/config/i2cdump.h) \
    $(wildcard include/config/i2cdetect.h) \
    $(wildcard include/config/i2ctransfer.h) \
    $(wildcard include/config/inotifyd.h) \
    $(wildcard include/config/less.h) \
    $(wildcard include/config/lock.h) \
    $(wildcard include/config/lsscsi.h) \
    $(wildcard include/config/makedevs.h) \
    $(wildcard include/config/microcom.h) \
    $(wildcard include/config/mim.h) \
    $(wildcard include/config/mt.h) \
    $(wildcard include/config/nandwrite.h) \
    $(wildcard include/config/nanddump.h) \
    $(wildcard include/config/partprobe.h) \
    $(wildcard include/config/raidautorun.h) \
    $(wildcard include/config/readahead.h) \
    $(wildcard include/config/rfkill.h) \
    $(wildcard include/config/runlevel.h) \
    $(wildcard include/config/rx.h) \
    $(wildcard include/config/setfattr.h) \
    $(wildcard include/config/setserial.h) \
    $(wildcard include/config/strings.h) \
    $(wildcard include/config/time.h) \
    $(wildcard include/config/ts.h) \
    $(wildcard include/config/ttysize.h) \
    $(wildcard include/config/ubiattach.h) \
    $(wildcard include/config/ubidetach.h) \
    $(wildcard include/config/ubimkvol.h) \
    $(wildcard include/config/ubirmvol.h) \
    $(wildcard include/config/ubirsvol.h) \
    $(wildcard include/config/ubiupdatevol.h) \
    $(wildcard include/config/ubirename.h) \
    $(wildcard include/config/volname.h) \
    $(wildcard include/config/watchdog.h) \
    $(wildcard include/config/modprobe/small.h) \
    $(wildcard include/config/lsmod.h) \
    $(wildcard include/config/modinfo.h) \
    $(wildcard include/config/rmmod.h) \
    $(wildcard include/config/arp.h) \
    $(wildcard include/config/arping.h) \
    $(wildcard include/config/brctl.h) \
    $(wildcard include/config/dnsd.h) \
    $(wildcard include/config/ether/wake.h) \
    $(wildcard include/config/ftpd.h) \
    $(wildcard include/config/ftpget.h) \
    $(wildcard include/config/ftpput.h) \
    $(wildcard include/config/dnsdomainname.h) \
    $(wildcard include/config/hostname.h) \
    $(wildcard include/config/httpd.h) \
    $(wildcard include/config/ifconfig.h) \
    $(wildcard include/config/ifenslave.h) \
    $(wildcard include/config/ifplugd.h) \
    $(wildcard include/config/ifup.h) \
    $(wildcard include/config/ifdown.h) \
    $(wildcard include/config/inetd.h) \
    $(wildcard include/config/ip.h) \
    $(wildcard include/config/ipaddr.h) \
    $(wildcard include/config/iplink.h) \
    $(wildcard include/config/iproute.h) \
    $(wildcard include/config/iprule.h) \
    $(wildcard include/config/iptunnel.h) \
    $(wildcard include/config/ipneigh.h) \
    $(wildcard include/config/ipcalc.h) \
    $(wildcard include/config/fakeidentd.h) \
    $(wildcard include/config/nameif.h) \
    $(wildcard include/config/nbdclient.h) \
    $(wildcard include/config/nc.h) \
    $(wildcard include/config/netcat.h) \
    $(wildcard include/config/netmsg.h) \
    $(wildcard include/config/netstat.h) \
    $(wildcard include/config/nslookup.h) \
    $(wildcard include/config/ntpd.h) \
    $(wildcard include/config/ping.h) \
    $(wildcard include/config/ping6.h) \
    $(wildcard include/config/pscan.h) \
    $(wildcard include/config/slattach.h) \
    $(wildcard include/config/ssl/client.h) \
    $(wildcard include/config/tc.h) \
    $(wildcard include/config/tcpsvd.h) \
    $(wildcard include/config/udpsvd.h) \
    $(wildcard include/config/telnet.h) \
    $(wildcard include/config/telnetd.h) \
    $(wildcard include/config/feature/tftp/get.h) \
    $(wildcard include/config/feature/tftp/put.h) \
    $(wildcard include/config/tftp.h) \
    $(wildcard include/config/tftpd.h) \
    $(wildcard include/config/traceroute.h) \
    $(wildcard include/config/traceroute6.h) \
    $(wildcard include/config/tunctl.h) \
    $(wildcard include/config/vconfig.h) \
    $(wildcard include/config/wget.h) \
    $(wildcard include/config/whois.h) \
    $(wildcard include/config/zcip.h) \
    $(wildcard include/config/lpd.h) \
    $(wildcard include/config/lpq.h) \
    $(wildcard include/config/lpr.h) \
    $(wildcard include/config/free.h) \
    $(wildcard include/config/fuser.h) \
    $(wildcard include/config/iostat.h) \
    $(wildcard include/config/lsof.h) \
    $(wildcard include/config/mpstat.h) \
    $(wildcard include/config/nmeter.h) \
    $(wildcard include/config/powertop.h) \
    $(wildcard include/config/ps.h) \
    $(wildcard include/config/minips.h) \
    $(wildcard include/config/pstree.h) \
    $(wildcard include/config/pwdx.h) \
    $(wildcard include/config/smemcap.h) \
    $(wildcard include/config/bb/sysctl.h) \
    $(wildcard include/config/top.h) \
    $(wildcard include/config/uptime.h) \
    $(wildcard include/config/watch.h) \
    $(wildcard include/config/chpst.h) \
    $(wildcard include/config/envdir.h) \
    $(wildcard include/config/envuidgid.h) \
    $(wildcard include/config/setuidgid.h) \
    $(wildcard include/config/softlimit.h) \
    $(wildcard include/config/runsv.h) \
    $(wildcard include/config/runsvdir.h) \
    $(wildcard include/config/sv.h) \
    $(wildcard include/config/svc.h) \
    $(wildcard include/config/svok.h) \
    $(wildcard include/config/svlogd.h) \
    $(wildcard include/config/chcon.h) \
    $(wildcard include/config/getenforce.h) \
    $(wildcard include/config/getsebool.h) \
    $(wildcard include/config/load/policy.h) \
    $(wildcard include/config/matchpathcon.h) \
    $(wildcard include/config/runcon.h) \
    $(wildcard include/config/selinuxenabled.h) \
    $(wildcard include/config/setenforce.h) \
    $(wildcard include/config/setfiles.h) \
    $(wildcard include/config/restorecon.h) \
    $(wildcard include/config/setsebool.h) \
    $(wildcard include/config/cttyhack.h) \
    $(wildcard include/config/klogd.h) \
    $(wildcard include/config/logger.h) \
    $(wildcard include/config/logread.h) \
    $(wildcard include/config/syslogd.h) \
    $(wildcard include/config/acpid.h) \
    $(wildcard include/config/blkdiscard.h) \
    $(wildcard include/config/blkid.h) \
    $(wildcard include/config/blockdev.h) \
    $(wildcard include/config/cal.h) \
    $(wildcard include/config/chrt.h) \
    $(wildcard include/config/dmesg.h) \
    $(wildcard include/config/eject.h) \
    $(wildcard include/config/fallocate.h) \
    $(wildcard include/config/fatattr.h) \
    $(wildcard include/config/fbset.h) \
    $(wildcard include/config/fdformat.h) \
    $(wildcard include/config/fdisk.h) \
    $(wildcard include/config/findfs.h) \
    $(wildcard include/config/flock.h) \
    $(wildcard include/config/fdflush.h) \
    $(wildcard include/config/freeramdisk.h) \
    $(wildcard include/config/fsck/minix.h) \
    $(wildcard include/config/fsfreeze.h) \
    $(wildcard include/config/fstrim.h) \
    $(wildcard include/config/getopt.h) \
    $(wildcard include/config/hexdump.h) \
    $(wildcard include/config/hd.h) \
    $(wildcard include/config/xxd.h) \
    $(wildcard include/config/hwclock.h) \
    $(wildcard include/config/ionice.h) \
    $(wildcard include/config/ipcrm.h) \
    $(wildcard include/config/ipcs.h) \
    $(wildcard include/config/last.h) \
    $(wildcard include/config/losetup.h) \
    $(wildcard include/config/lspci.h) \
    $(wildcard include/config/lsusb.h) \
    $(wildcard include/config/mdev.h) \
    $(wildcard include/config/mesg.h) \
    $(wildcard include/config/mke2fs.h) \
    $(wildcard include/config/mkfs/ext2.h) \
    $(wildcard include/config/mkfs/minix.h) \
    $(wildcard include/config/mkfs/reiser.h) \
    $(wildcard include/config/mkdosfs.h) \
    $(wildcard include/config/mkfs/vfat.h) \
    $(wildcard include/config/mkswap.h) \
    $(wildcard include/config/more.h) \
    $(wildcard include/config/mount.h) \
    $(wildcard include/config/mountpoint.h) \
    $(wildcard include/config/nologin.h) \
    $(wildcard include/config/nsenter.h) \
    $(wildcard include/config/pivot/root.h) \
    $(wildcard include/config/rdate.h) \
    $(wildcard include/config/rdev.h) \
    $(wildcard include/config/readprofile.h) \
    $(wildcard include/config/renice.h) \
    $(wildcard include/config/rev.h) \
    $(wildcard include/config/rtcwake.h) \
    $(wildcard include/config/script.h) \
    $(wildcard include/config/scriptreplay.h) \
    $(wildcard include/config/setarch.h) \
    $(wildcard include/config/linux32.h) \
    $(wildcard include/config/linux64.h) \
    $(wildcard include/config/setpriv.h) \
    $(wildcard include/config/setsid.h) \
    $(wildcard include/config/swapon.h) \
    $(wildcard include/config/swapoff.h) \
    $(wildcard include/config/switch/root.h) \
    $(wildcard include/config/taskset.h) \
    $(wildcard include/config/uevent.h) \
    $(wildcard include/config/umount.h) \
    $(wildcard include/config/unshare.h) \
    $(wildcard include/config/wall.h) \
    $(wildcard include/config/udhcpc6.h) \
    $(wildcard include/config/udhcpc.h) \
    $(wildcard include/config/udhcpd.h) \
    $(wildcard include/config/dhcprelay.h) \
    $(wildcard include/config/dumpleases.h) \
  include/applet_tables.h \
  include/usage_compressed.h \

libbb/appletlib.o: $(deps_libbb/appletlib.o)

$(deps_libbb/appletlib.o):
