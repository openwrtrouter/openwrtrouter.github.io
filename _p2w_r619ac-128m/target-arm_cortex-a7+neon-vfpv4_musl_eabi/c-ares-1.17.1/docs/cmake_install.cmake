# Install script for directory: /workdir/openwrt/build_dir/target-arm_cortex-a7+neon-vfpv4_musl_eabi/c-ares-1.17.1/docs

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

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/man/man3" TYPE FILE FILES
    "/workdir/openwrt/build_dir/target-arm_cortex-a7+neon-vfpv4_musl_eabi/c-ares-1.17.1/docs/ares_cancel.3"
    "/workdir/openwrt/build_dir/target-arm_cortex-a7+neon-vfpv4_musl_eabi/c-ares-1.17.1/docs/ares_create_query.3"
    "/workdir/openwrt/build_dir/target-arm_cortex-a7+neon-vfpv4_musl_eabi/c-ares-1.17.1/docs/ares_destroy.3"
    "/workdir/openwrt/build_dir/target-arm_cortex-a7+neon-vfpv4_musl_eabi/c-ares-1.17.1/docs/ares_destroy_options.3"
    "/workdir/openwrt/build_dir/target-arm_cortex-a7+neon-vfpv4_musl_eabi/c-ares-1.17.1/docs/ares_dup.3"
    "/workdir/openwrt/build_dir/target-arm_cortex-a7+neon-vfpv4_musl_eabi/c-ares-1.17.1/docs/ares_expand_name.3"
    "/workdir/openwrt/build_dir/target-arm_cortex-a7+neon-vfpv4_musl_eabi/c-ares-1.17.1/docs/ares_expand_string.3"
    "/workdir/openwrt/build_dir/target-arm_cortex-a7+neon-vfpv4_musl_eabi/c-ares-1.17.1/docs/ares_fds.3"
    "/workdir/openwrt/build_dir/target-arm_cortex-a7+neon-vfpv4_musl_eabi/c-ares-1.17.1/docs/ares_free_data.3"
    "/workdir/openwrt/build_dir/target-arm_cortex-a7+neon-vfpv4_musl_eabi/c-ares-1.17.1/docs/ares_free_hostent.3"
    "/workdir/openwrt/build_dir/target-arm_cortex-a7+neon-vfpv4_musl_eabi/c-ares-1.17.1/docs/ares_free_string.3"
    "/workdir/openwrt/build_dir/target-arm_cortex-a7+neon-vfpv4_musl_eabi/c-ares-1.17.1/docs/ares_freeaddrinfo.3"
    "/workdir/openwrt/build_dir/target-arm_cortex-a7+neon-vfpv4_musl_eabi/c-ares-1.17.1/docs/ares_get_servers.3"
    "/workdir/openwrt/build_dir/target-arm_cortex-a7+neon-vfpv4_musl_eabi/c-ares-1.17.1/docs/ares_get_servers_ports.3"
    "/workdir/openwrt/build_dir/target-arm_cortex-a7+neon-vfpv4_musl_eabi/c-ares-1.17.1/docs/ares_getaddrinfo.3"
    "/workdir/openwrt/build_dir/target-arm_cortex-a7+neon-vfpv4_musl_eabi/c-ares-1.17.1/docs/ares_gethostbyaddr.3"
    "/workdir/openwrt/build_dir/target-arm_cortex-a7+neon-vfpv4_musl_eabi/c-ares-1.17.1/docs/ares_gethostbyname.3"
    "/workdir/openwrt/build_dir/target-arm_cortex-a7+neon-vfpv4_musl_eabi/c-ares-1.17.1/docs/ares_gethostbyname_file.3"
    "/workdir/openwrt/build_dir/target-arm_cortex-a7+neon-vfpv4_musl_eabi/c-ares-1.17.1/docs/ares_getnameinfo.3"
    "/workdir/openwrt/build_dir/target-arm_cortex-a7+neon-vfpv4_musl_eabi/c-ares-1.17.1/docs/ares_getsock.3"
    "/workdir/openwrt/build_dir/target-arm_cortex-a7+neon-vfpv4_musl_eabi/c-ares-1.17.1/docs/ares_inet_ntop.3"
    "/workdir/openwrt/build_dir/target-arm_cortex-a7+neon-vfpv4_musl_eabi/c-ares-1.17.1/docs/ares_inet_pton.3"
    "/workdir/openwrt/build_dir/target-arm_cortex-a7+neon-vfpv4_musl_eabi/c-ares-1.17.1/docs/ares_init.3"
    "/workdir/openwrt/build_dir/target-arm_cortex-a7+neon-vfpv4_musl_eabi/c-ares-1.17.1/docs/ares_init_options.3"
    "/workdir/openwrt/build_dir/target-arm_cortex-a7+neon-vfpv4_musl_eabi/c-ares-1.17.1/docs/ares_library_cleanup.3"
    "/workdir/openwrt/build_dir/target-arm_cortex-a7+neon-vfpv4_musl_eabi/c-ares-1.17.1/docs/ares_library_init.3"
    "/workdir/openwrt/build_dir/target-arm_cortex-a7+neon-vfpv4_musl_eabi/c-ares-1.17.1/docs/ares_library_init_android.3"
    "/workdir/openwrt/build_dir/target-arm_cortex-a7+neon-vfpv4_musl_eabi/c-ares-1.17.1/docs/ares_library_initialized.3"
    "/workdir/openwrt/build_dir/target-arm_cortex-a7+neon-vfpv4_musl_eabi/c-ares-1.17.1/docs/ares_mkquery.3"
    "/workdir/openwrt/build_dir/target-arm_cortex-a7+neon-vfpv4_musl_eabi/c-ares-1.17.1/docs/ares_parse_a_reply.3"
    "/workdir/openwrt/build_dir/target-arm_cortex-a7+neon-vfpv4_musl_eabi/c-ares-1.17.1/docs/ares_parse_aaaa_reply.3"
    "/workdir/openwrt/build_dir/target-arm_cortex-a7+neon-vfpv4_musl_eabi/c-ares-1.17.1/docs/ares_parse_caa_reply.3"
    "/workdir/openwrt/build_dir/target-arm_cortex-a7+neon-vfpv4_musl_eabi/c-ares-1.17.1/docs/ares_parse_mx_reply.3"
    "/workdir/openwrt/build_dir/target-arm_cortex-a7+neon-vfpv4_musl_eabi/c-ares-1.17.1/docs/ares_parse_naptr_reply.3"
    "/workdir/openwrt/build_dir/target-arm_cortex-a7+neon-vfpv4_musl_eabi/c-ares-1.17.1/docs/ares_parse_ns_reply.3"
    "/workdir/openwrt/build_dir/target-arm_cortex-a7+neon-vfpv4_musl_eabi/c-ares-1.17.1/docs/ares_parse_ptr_reply.3"
    "/workdir/openwrt/build_dir/target-arm_cortex-a7+neon-vfpv4_musl_eabi/c-ares-1.17.1/docs/ares_parse_soa_reply.3"
    "/workdir/openwrt/build_dir/target-arm_cortex-a7+neon-vfpv4_musl_eabi/c-ares-1.17.1/docs/ares_parse_srv_reply.3"
    "/workdir/openwrt/build_dir/target-arm_cortex-a7+neon-vfpv4_musl_eabi/c-ares-1.17.1/docs/ares_parse_txt_reply.3"
    "/workdir/openwrt/build_dir/target-arm_cortex-a7+neon-vfpv4_musl_eabi/c-ares-1.17.1/docs/ares_process.3"
    "/workdir/openwrt/build_dir/target-arm_cortex-a7+neon-vfpv4_musl_eabi/c-ares-1.17.1/docs/ares_query.3"
    "/workdir/openwrt/build_dir/target-arm_cortex-a7+neon-vfpv4_musl_eabi/c-ares-1.17.1/docs/ares_save_options.3"
    "/workdir/openwrt/build_dir/target-arm_cortex-a7+neon-vfpv4_musl_eabi/c-ares-1.17.1/docs/ares_search.3"
    "/workdir/openwrt/build_dir/target-arm_cortex-a7+neon-vfpv4_musl_eabi/c-ares-1.17.1/docs/ares_send.3"
    "/workdir/openwrt/build_dir/target-arm_cortex-a7+neon-vfpv4_musl_eabi/c-ares-1.17.1/docs/ares_set_local_dev.3"
    "/workdir/openwrt/build_dir/target-arm_cortex-a7+neon-vfpv4_musl_eabi/c-ares-1.17.1/docs/ares_set_local_ip4.3"
    "/workdir/openwrt/build_dir/target-arm_cortex-a7+neon-vfpv4_musl_eabi/c-ares-1.17.1/docs/ares_set_local_ip6.3"
    "/workdir/openwrt/build_dir/target-arm_cortex-a7+neon-vfpv4_musl_eabi/c-ares-1.17.1/docs/ares_set_servers.3"
    "/workdir/openwrt/build_dir/target-arm_cortex-a7+neon-vfpv4_musl_eabi/c-ares-1.17.1/docs/ares_set_servers_csv.3"
    "/workdir/openwrt/build_dir/target-arm_cortex-a7+neon-vfpv4_musl_eabi/c-ares-1.17.1/docs/ares_set_servers_ports.3"
    "/workdir/openwrt/build_dir/target-arm_cortex-a7+neon-vfpv4_musl_eabi/c-ares-1.17.1/docs/ares_set_servers_ports_csv.3"
    "/workdir/openwrt/build_dir/target-arm_cortex-a7+neon-vfpv4_musl_eabi/c-ares-1.17.1/docs/ares_set_socket_callback.3"
    "/workdir/openwrt/build_dir/target-arm_cortex-a7+neon-vfpv4_musl_eabi/c-ares-1.17.1/docs/ares_set_socket_configure_callback.3"
    "/workdir/openwrt/build_dir/target-arm_cortex-a7+neon-vfpv4_musl_eabi/c-ares-1.17.1/docs/ares_set_socket_functions.3"
    "/workdir/openwrt/build_dir/target-arm_cortex-a7+neon-vfpv4_musl_eabi/c-ares-1.17.1/docs/ares_set_sortlist.3"
    "/workdir/openwrt/build_dir/target-arm_cortex-a7+neon-vfpv4_musl_eabi/c-ares-1.17.1/docs/ares_strerror.3"
    "/workdir/openwrt/build_dir/target-arm_cortex-a7+neon-vfpv4_musl_eabi/c-ares-1.17.1/docs/ares_timeout.3"
    "/workdir/openwrt/build_dir/target-arm_cortex-a7+neon-vfpv4_musl_eabi/c-ares-1.17.1/docs/ares_version.3"
    )
endif()

