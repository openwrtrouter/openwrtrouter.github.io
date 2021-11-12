if USE_SYSTEM_SHARED_LIB
SUBDIRS = libcork libipset src server
else
SUBDIRS = libsodium libcork libipset libudns libev src server
endif

if ENABLE_DOCUMENTATION
SUBDIRS += doc
endif

ACLOCAL_AMFLAGS = -I m4

pkgconfiglibdir = $(libdir)/pkgconfig
pkgconfiglib_DATA = shadowsocks-libev.pc
