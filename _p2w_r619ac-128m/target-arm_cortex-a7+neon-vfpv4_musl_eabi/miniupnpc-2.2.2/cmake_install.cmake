# Install script for directory: /workdir/openwrt/build_dir/target-arm_cortex-a7+neon-vfpv4_musl_eabi/miniupnpc-2.2.2

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "TRUE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/workdir/openwrt/staging_dir/toolchain-arm_cortex-a7+neon-vfpv4_gcc-8.4.0_musl_eabi/bin/arm-openwrt-linux-muslgnueabi-objdump")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/miniupnpc/miniupnpc-private.cmake")
    file(DIFFERENT EXPORT_FILE_CHANGED FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/miniupnpc/miniupnpc-private.cmake"
         "/workdir/openwrt/build_dir/target-arm_cortex-a7+neon-vfpv4_musl_eabi/miniupnpc-2.2.2/CMakeFiles/Export/lib/cmake/miniupnpc/miniupnpc-private.cmake")
    if(EXPORT_FILE_CHANGED)
      file(GLOB OLD_CONFIG_FILES "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/miniupnpc/miniupnpc-private-*.cmake")
      if(OLD_CONFIG_FILES)
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/miniupnpc/miniupnpc-private.cmake\" will be replaced.  Removing files [${OLD_CONFIG_FILES}].")
        file(REMOVE ${OLD_CONFIG_FILES})
      endif()
    endif()
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/miniupnpc" TYPE FILE FILES "/workdir/openwrt/build_dir/target-arm_cortex-a7+neon-vfpv4_musl_eabi/miniupnpc-2.2.2/CMakeFiles/Export/lib/cmake/miniupnpc/miniupnpc-private.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/workdir/openwrt/build_dir/target-arm_cortex-a7+neon-vfpv4_musl_eabi/miniupnpc-2.2.2/libminiupnpc.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/miniupnpc/libminiupnpc-static.cmake")
    file(DIFFERENT EXPORT_FILE_CHANGED FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/miniupnpc/libminiupnpc-static.cmake"
         "/workdir/openwrt/build_dir/target-arm_cortex-a7+neon-vfpv4_musl_eabi/miniupnpc-2.2.2/CMakeFiles/Export/lib/cmake/miniupnpc/libminiupnpc-static.cmake")
    if(EXPORT_FILE_CHANGED)
      file(GLOB OLD_CONFIG_FILES "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/miniupnpc/libminiupnpc-static-*.cmake")
      if(OLD_CONFIG_FILES)
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/miniupnpc/libminiupnpc-static.cmake\" will be replaced.  Removing files [${OLD_CONFIG_FILES}].")
        file(REMOVE ${OLD_CONFIG_FILES})
      endif()
    endif()
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/miniupnpc" TYPE FILE FILES "/workdir/openwrt/build_dir/target-arm_cortex-a7+neon-vfpv4_musl_eabi/miniupnpc-2.2.2/CMakeFiles/Export/lib/cmake/miniupnpc/libminiupnpc-static.cmake")
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/miniupnpc" TYPE FILE FILES "/workdir/openwrt/build_dir/target-arm_cortex-a7+neon-vfpv4_musl_eabi/miniupnpc-2.2.2/CMakeFiles/Export/lib/cmake/miniupnpc/libminiupnpc-static-release.cmake")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES
    "/workdir/openwrt/build_dir/target-arm_cortex-a7+neon-vfpv4_musl_eabi/miniupnpc-2.2.2/libminiupnpc.so.2.2.2"
    "/workdir/openwrt/build_dir/target-arm_cortex-a7+neon-vfpv4_musl_eabi/miniupnpc-2.2.2/libminiupnpc.so.17"
    )
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libminiupnpc.so.2.2.2"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libminiupnpc.so.17"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      if(CMAKE_INSTALL_DO_STRIP)
        execute_process(COMMAND "/workdir/openwrt/build_dir/target-arm_cortex-a7+neon-vfpv4_musl_eabi/miniupnpc-2.2.2/:" "${file}")
      endif()
    endif()
  endforeach()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/workdir/openwrt/build_dir/target-arm_cortex-a7+neon-vfpv4_musl_eabi/miniupnpc-2.2.2/libminiupnpc.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libminiupnpc.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libminiupnpc.so")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/workdir/openwrt/build_dir/target-arm_cortex-a7+neon-vfpv4_musl_eabi/miniupnpc-2.2.2/:" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libminiupnpc.so")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/miniupnpc/libminiupnpc-shared.cmake")
    file(DIFFERENT EXPORT_FILE_CHANGED FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/miniupnpc/libminiupnpc-shared.cmake"
         "/workdir/openwrt/build_dir/target-arm_cortex-a7+neon-vfpv4_musl_eabi/miniupnpc-2.2.2/CMakeFiles/Export/lib/cmake/miniupnpc/libminiupnpc-shared.cmake")
    if(EXPORT_FILE_CHANGED)
      file(GLOB OLD_CONFIG_FILES "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/miniupnpc/libminiupnpc-shared-*.cmake")
      if(OLD_CONFIG_FILES)
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/miniupnpc/libminiupnpc-shared.cmake\" will be replaced.  Removing files [${OLD_CONFIG_FILES}].")
        file(REMOVE ${OLD_CONFIG_FILES})
      endif()
    endif()
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/miniupnpc" TYPE FILE FILES "/workdir/openwrt/build_dir/target-arm_cortex-a7+neon-vfpv4_musl_eabi/miniupnpc-2.2.2/CMakeFiles/Export/lib/cmake/miniupnpc/libminiupnpc-shared.cmake")
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/miniupnpc" TYPE FILE FILES "/workdir/openwrt/build_dir/target-arm_cortex-a7+neon-vfpv4_musl_eabi/miniupnpc-2.2.2/CMakeFiles/Export/lib/cmake/miniupnpc/libminiupnpc-shared-release.cmake")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/miniupnpc" TYPE FILE FILES
    "/workdir/openwrt/build_dir/target-arm_cortex-a7+neon-vfpv4_musl_eabi/miniupnpc-2.2.2/miniupnpc.h"
    "/workdir/openwrt/build_dir/target-arm_cortex-a7+neon-vfpv4_musl_eabi/miniupnpc-2.2.2/miniwget.h"
    "/workdir/openwrt/build_dir/target-arm_cortex-a7+neon-vfpv4_musl_eabi/miniupnpc-2.2.2/upnpcommands.h"
    "/workdir/openwrt/build_dir/target-arm_cortex-a7+neon-vfpv4_musl_eabi/miniupnpc-2.2.2/igd_desc_parse.h"
    "/workdir/openwrt/build_dir/target-arm_cortex-a7+neon-vfpv4_musl_eabi/miniupnpc-2.2.2/upnpreplyparse.h"
    "/workdir/openwrt/build_dir/target-arm_cortex-a7+neon-vfpv4_musl_eabi/miniupnpc-2.2.2/upnperrors.h"
    "/workdir/openwrt/build_dir/target-arm_cortex-a7+neon-vfpv4_musl_eabi/miniupnpc-2.2.2/upnpdev.h"
    "/workdir/openwrt/build_dir/target-arm_cortex-a7+neon-vfpv4_musl_eabi/miniupnpc-2.2.2/miniupnpctypes.h"
    "/workdir/openwrt/build_dir/target-arm_cortex-a7+neon-vfpv4_musl_eabi/miniupnpc-2.2.2/portlistingparse.h"
    "/workdir/openwrt/build_dir/target-arm_cortex-a7+neon-vfpv4_musl_eabi/miniupnpc-2.2.2/miniupnpc_declspec.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/miniupnpc" TYPE FILE FILES "/workdir/openwrt/build_dir/target-arm_cortex-a7+neon-vfpv4_musl_eabi/miniupnpc-2.2.2/miniupnpc-config.cmake")
endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/workdir/openwrt/build_dir/target-arm_cortex-a7+neon-vfpv4_musl_eabi/miniupnpc-2.2.2/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
