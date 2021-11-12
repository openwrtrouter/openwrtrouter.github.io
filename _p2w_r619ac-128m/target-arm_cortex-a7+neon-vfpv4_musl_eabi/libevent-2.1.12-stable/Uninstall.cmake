# https://gitlab.kitware.com/cmake/community/wikis/FAQ#can-i-do-make-uninstall-with-cmake

if(NOT EXISTS "/workdir/openwrt/build_dir/target-arm_cortex-a7+neon-vfpv4_musl_eabi/libevent-2.1.12-stable/install_manifest.txt")
  message(FATAL_ERROR "Cannot find install manifest: /workdir/openwrt/build_dir/target-arm_cortex-a7+neon-vfpv4_musl_eabi/libevent-2.1.12-stable/install_manifest.txt")
endif(NOT EXISTS "/workdir/openwrt/build_dir/target-arm_cortex-a7+neon-vfpv4_musl_eabi/libevent-2.1.12-stable/install_manifest.txt")

file(READ "/workdir/openwrt/build_dir/target-arm_cortex-a7+neon-vfpv4_musl_eabi/libevent-2.1.12-stable/install_manifest.txt" files)
string(REGEX REPLACE "\n" ";" files "${files}")
foreach(file ${files})
  message(STATUS "Uninstalling $ENV{DESTDIR}${file}")
  if(IS_SYMLINK "$ENV{DESTDIR}${file}" OR EXISTS "$ENV{DESTDIR}${file}")
    exec_program(
      "/workdir/staging_dir/_p2w_r619ac-128m/host/bin/cmake" ARGS "-E remove \"$ENV{DESTDIR}${file}\""
      OUTPUT_VARIABLE rm_out
      RETURN_VALUE rm_retval
      )
    if(NOT "${rm_retval}" STREQUAL 0)
      message(FATAL_ERROR "Problem when removing $ENV{DESTDIR}${file}")
    endif(NOT "${rm_retval}" STREQUAL 0)
  else(IS_SYMLINK "$ENV{DESTDIR}${file}" OR EXISTS "$ENV{DESTDIR}${file}")
    message(STATUS "File $ENV{DESTDIR}${file} does not exist.")
  endif(IS_SYMLINK "$ENV{DESTDIR}${file}" OR EXISTS "$ENV{DESTDIR}${file}")
endforeach(file)
