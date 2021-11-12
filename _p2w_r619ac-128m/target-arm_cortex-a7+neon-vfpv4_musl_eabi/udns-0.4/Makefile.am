# Copyright 2016 Yousong Zhou

lib_LTLIBRARIES=libudns.la
libudns_la_SOURCES= udns_dn.c udns_dntosp.c udns_parse.c udns_resolver.c udns_init.c \
	udns_misc.c udns_XtoX.c \
	udns_rr_a.c udns_rr_ptr.c udns_rr_mx.c udns_rr_txt.c udns_bl.c \
	udns_rr_srv.c udns_rr_naptr.c udns_codes.c udns_jran.c
include_HEADERS= udns.h

bin_PROGRAMS = dnsget rblcheck ex-rdns
dnsget_SOURCES = dnsget.c
rblcheck_SOURCES = rblcheck.c
ex_rdns_SOURCES = ex-rdns.c
dnsget_LDADD = $(top_builddir)/libudns.la
rblcheck_LDADD = $(top_builddir)/libudns.la
ex_rdns_LDADD = $(top_builddir)/libudns.la
