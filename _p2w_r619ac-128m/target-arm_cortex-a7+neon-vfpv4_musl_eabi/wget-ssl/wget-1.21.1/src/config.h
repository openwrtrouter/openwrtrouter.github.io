/* src/config.h.  Generated from config.h.in by configure.  */
/* src/config.h.in.  Generated from configure.ac by autoheader.  */

/* Define if building universal (internal helper macro) */
/* #undef AC_APPLE_UNIVERSAL_BUILD */

/* Define to the number of bits in type 'ptrdiff_t'. */
/* #undef BITSIZEOF_PTRDIFF_T */

/* Define to the number of bits in type 'sig_atomic_t'. */
/* #undef BITSIZEOF_SIG_ATOMIC_T */

/* Define to the number of bits in type 'size_t'. */
/* #undef BITSIZEOF_SIZE_T */

/* Define to the number of bits in type 'wchar_t'. */
/* #undef BITSIZEOF_WCHAR_T */

/* Define to the number of bits in type 'wint_t'. */
/* #undef BITSIZEOF_WINT_T */

/* Define to 1 if using `alloca.c'. */
/* #undef C_ALLOCA */

/* Define as the bit index in the word where to find bit 0 of the exponent of
   'double'. */
/* #undef DBL_EXPBIT0_BIT */

/* Define as the word index where to find the exponent of 'double'. */
/* #undef DBL_EXPBIT0_WORD */

/* the name of the file descriptor member of DIR */
/* #undef DIR_FD_MEMBER_NAME */

#ifdef DIR_FD_MEMBER_NAME
# define DIR_TO_FD(Dir_p) ((Dir_p)->DIR_FD_MEMBER_NAME)
#else
# define DIR_TO_FD(Dir_p) -1
#endif


/* Define to 1 if // is a file system root distinct from /. */
/* #undef DOUBLE_SLASH_IS_DISTINCT_ROOT */

/* Define if struct dirent has a member d_ino that actually works. */
#define D_INO_IN_DIRENT 1

/* Define if you want the debug output support compiled in. */
#define ENABLE_DEBUG 1

/* Define if you want the HTTP Digest Authorization compiled in. */
#define ENABLE_DIGEST 1

/* Define if IPv6 support is enabled. */
#define ENABLE_IPV6 1

/* Define if IRI support is enabled. */
/* #undef ENABLE_IRI */

/* Define to 1 if translation of program messages to the user's native
   language is requested. */
/* #undef ENABLE_NLS */

/* Define if you want the NTLM authorization support compiled in. */
#define ENABLE_NTLM 1

/* Define if you want Opie support for FTP compiled in. */
#define ENABLE_OPIE 1

/* Define if you want file meta-data storing into POSIX Extended Attributes
   compiled in. */
#define ENABLE_XATTR 1

/* Define this to 1 if F_DUPFD behavior does not match POSIX */
/* #undef FCNTL_DUPFD_BUGGY */

/* Define to nothing if C supports flexible array members, and to 1 if it does
   not. That way, with a declaration like 'struct s { int n; short
   d[FLEXIBLE_ARRAY_MEMBER]; };', the struct hack can be used with pre-C99
   compilers. Use 'FLEXSIZEOF (struct s, d, N * sizeof (short))' to calculate
   the size in bytes of such a struct containing an N-element array. */
#define FLEXIBLE_ARRAY_MEMBER /**/

/* Define to 1 if fopen() fails to recognize a trailing slash. */
/* #undef FOPEN_TRAILING_SLASH_BUG */

/* Define to 1 if the system's ftello function has the Solaris bug. */
/* #undef FTELLO_BROKEN_AFTER_SWITCHING_FROM_READ_TO_WRITE */

/* Define to 1 if fflush is known to work on stdin as per POSIX.1-2008, 0 if
   fflush is known to not work, -1 if unknown. */
#define FUNC_FFLUSH_STDIN (-1)

/* Define to 1 if mkdir mistakenly creates a directory given with a trailing
   dot component. */
/* #undef FUNC_MKDIR_DOT_BUG */

/* Define to 1 if nl_langinfo (YESEXPR) returns a non-empty string. */
#define FUNC_NL_LANGINFO_YESEXPR_WORKS 1

/* Define to 1 if realpath() can malloc memory, always gives an absolute path,
   and handles trailing slash correctly. */
#define FUNC_REALPATH_WORKS 1

/* Define to 1 if futimesat mishandles a NULL file name. */
/* #undef FUTIMESAT_NULL_BUG */

/* Define to 1 if this is a fuzzing build */
/* #undef FUZZING */

/* Define to the type of elements in the array set by `getgroups'. Usually
   this is either `int' or `gid_t'. */
#define GETGROUPS_T gid_t

/* Define this to 1 if getgroups(0,NULL) does not return the number of groups.
   */
/* #undef GETGROUPS_ZERO_BUG */

/* Define this to 'void' or 'struct timezone' to match the system's
   declaration of the second argument to gettimeofday. */
#define GETTIMEOFDAY_TIMEZONE void

/* Compile Gnulib crypto stream ops. */
#define GL_COMPILE_CRYPTO_STREAM 1

/* Define to a C preprocessor expression that evaluates to 1 or 0, depending
   whether the gnulib module canonicalize shall be considered present. */
#define GNULIB_CANONICALIZE 1

/* Define to a C preprocessor expression that evaluates to 1 or 0, depending
   whether the gnulib module dirname shall be considered present. */
#define GNULIB_DIRNAME 1

/* Define to a C preprocessor expression that evaluates to 1 or 0, depending
   whether the gnulib module fdopendir shall be considered present. */
#define GNULIB_FDOPENDIR 1

/* Define to a C preprocessor expression that evaluates to 1 or 0, depending
   whether the gnulib module fd-safer-flag shall be considered present. */
#define GNULIB_FD_SAFER_FLAG 1

/* Define to a C preprocessor expression that evaluates to 1 or 0, depending
   whether the gnulib module fflush shall be considered present. */
#define GNULIB_FFLUSH 1

/* Define to a C preprocessor expression that evaluates to 1 or 0, depending
   whether the gnulib module fnmatch-gnu shall be considered present. */
#define GNULIB_FNMATCH_GNU 1

/* Define to a C preprocessor expression that evaluates to 1 or 0, depending
   whether the gnulib module fopen-gnu shall be considered present. */
#define GNULIB_FOPEN_GNU 1

/* Define to a C preprocessor expression that evaluates to 1 or 0, depending
   whether the gnulib module fscanf shall be considered present. */
#define GNULIB_FSCANF 1

/* Define to a C preprocessor expression that evaluates to 1 or 0, depending
   whether the gnulib module getcwd shall be considered present. */
#define GNULIB_GETCWD 1

/* Define to a C preprocessor expression that evaluates to 1 or 0, depending
   whether the gnulib module isblank shall be considered present. */
#define GNULIB_ISBLANK 1

/* Define to a C preprocessor expression that evaluates to 1 or 0, depending
   whether the gnulib module lock shall be considered present. */
#define GNULIB_LOCK 1

/* Define to a C preprocessor expression that evaluates to 1 or 0, depending
   whether the gnulib module mkostemp shall be considered present. */
#define GNULIB_MKOSTEMP 1

/* Define to a C preprocessor expression that evaluates to 1 or 0, depending
   whether the gnulib module msvc-nothrow shall be considered present. */
#define GNULIB_MSVC_NOTHROW 1

/* Define to a C preprocessor expression that evaluates to 1 or 0, depending
   whether the gnulib module openat shall be considered present. */
#define GNULIB_OPENAT 1

/* Define to a C preprocessor expression that evaluates to 1 or 0, depending
   whether the gnulib module pipe2-safer shall be considered present. */
#define GNULIB_PIPE2_SAFER 1

/* Define to 1 if printf and friends should be labeled with attribute
   "__gnu_printf__" instead of "__printf__" */
/* #undef GNULIB_PRINTF_ATTRIBUTE_FLAVOR_GNU */

/* Define to a C preprocessor expression that evaluates to 1 or 0, depending
   whether the gnulib module scanf shall be considered present. */
#define GNULIB_SCANF 1

/* Define to a C preprocessor expression that evaluates to 1 or 0, depending
   whether the gnulib module sigpipe shall be considered present. */
#define GNULIB_SIGPIPE 1

/* Define to a C preprocessor expression that evaluates to 1 or 0, depending
   whether the gnulib module snprintf shall be considered present. */
#define GNULIB_SNPRINTF 1

/* Define to a C preprocessor expression that evaluates to 1 or 0, depending
   whether the gnulib module strerror shall be considered present. */
#define GNULIB_STRERROR 1

/* Define to a C preprocessor expression that evaluates to 1 or 0, depending
   whether the gnulib module strerror_r-posix shall be considered present. */
#define GNULIB_STRERROR_R_POSIX 1

/* Define to a C preprocessor expression that evaluates to 1 or 0, depending
   whether the gnulib module tempname shall be considered present. */
#define GNULIB_TEMPNAME 1

/* Define to 1 when the gnulib module accept should be tested. */
#define GNULIB_TEST_ACCEPT 1

/* Define to 1 when the gnulib module access should be tested. */
#define GNULIB_TEST_ACCESS 1

/* Define to 1 when the gnulib module bind should be tested. */
#define GNULIB_TEST_BIND 1

/* Define to 1 when the gnulib module btowc should be tested. */
#define GNULIB_TEST_BTOWC 1

/* Define to 1 when the gnulib module canonicalize should be tested. */
#define GNULIB_TEST_CANONICALIZE 1

/* Define to 1 when the gnulib module canonicalize_file_name should be tested.
   */
#define GNULIB_TEST_CANONICALIZE_FILE_NAME 1

/* Define to 1 when the gnulib module chdir should be tested. */
#define GNULIB_TEST_CHDIR 1

/* Define to 1 when the gnulib module cloexec should be tested. */
#define GNULIB_TEST_CLOEXEC 1

/* Define to 1 when the gnulib module close should be tested. */
#define GNULIB_TEST_CLOSE 1

/* Define to 1 when the gnulib module closedir should be tested. */
#define GNULIB_TEST_CLOSEDIR 1

/* Define to 1 when the gnulib module connect should be tested. */
#define GNULIB_TEST_CONNECT 1

/* Define to 1 when the gnulib module dirfd should be tested. */
#define GNULIB_TEST_DIRFD 1

/* Define to 1 when the gnulib module dup should be tested. */
#define GNULIB_TEST_DUP 1

/* Define to 1 when the gnulib module dup2 should be tested. */
#define GNULIB_TEST_DUP2 1

/* Define to 1 when the gnulib module environ should be tested. */
#define GNULIB_TEST_ENVIRON 1

/* Define to 1 when the gnulib module fchdir should be tested. */
#define GNULIB_TEST_FCHDIR 1

/* Define to 1 when the gnulib module fcntl should be tested. */
#define GNULIB_TEST_FCNTL 1

/* Define to 1 when the gnulib module fdopendir should be tested. */
#define GNULIB_TEST_FDOPENDIR 1

/* Define to 1 when the gnulib module fflush should be tested. */
#define GNULIB_TEST_FFLUSH 1

/* Define to 1 when the gnulib module fnmatch should be tested. */
#define GNULIB_TEST_FNMATCH 1

/* Define to 1 when the gnulib module fopen should be tested. */
#define GNULIB_TEST_FOPEN 1

/* Define to 1 when the gnulib module fpurge should be tested. */
#define GNULIB_TEST_FPURGE 1

/* Define to 1 when the gnulib module free-posix should be tested. */
#define GNULIB_TEST_FREE_POSIX 1

/* Define to 1 when the gnulib module fseek should be tested. */
#define GNULIB_TEST_FSEEK 1

/* Define to 1 when the gnulib module fseeko should be tested. */
#define GNULIB_TEST_FSEEKO 1

/* Define to 1 when the gnulib module fstat should be tested. */
#define GNULIB_TEST_FSTAT 1

/* Define to 1 when the gnulib module fstatat should be tested. */
#define GNULIB_TEST_FSTATAT 1

/* Define to 1 when the gnulib module ftell should be tested. */
#define GNULIB_TEST_FTELL 1

/* Define to 1 when the gnulib module ftello should be tested. */
#define GNULIB_TEST_FTELLO 1

/* Define to 1 when the gnulib module futimens should be tested. */
#define GNULIB_TEST_FUTIMENS 1

/* Define to 1 when the gnulib module getaddrinfo should be tested. */
#define GNULIB_TEST_GETADDRINFO 1

/* Define to 1 when the gnulib module getcwd should be tested. */
#define GNULIB_TEST_GETCWD 1

/* Define to 1 when the gnulib module getdelim should be tested. */
#define GNULIB_TEST_GETDELIM 1

/* Define to 1 when the gnulib module getdtablesize should be tested. */
#define GNULIB_TEST_GETDTABLESIZE 1

/* Define to 1 when the gnulib module getgroups should be tested. */
#define GNULIB_TEST_GETGROUPS 1

/* Define to 1 when the gnulib module getline should be tested. */
#define GNULIB_TEST_GETLINE 1

/* Define to 1 when the gnulib module getopt-posix should be tested. */
#define GNULIB_TEST_GETOPT_POSIX 1

/* Define to 1 when the gnulib module getpass should be tested. */
#define GNULIB_TEST_GETPASS 1

/* Define to 1 when the gnulib module getpeername should be tested. */
#define GNULIB_TEST_GETPEERNAME 1

/* Define to 1 when the gnulib module getrandom should be tested. */
#define GNULIB_TEST_GETRANDOM 1

/* Define to 1 when the gnulib module getsockname should be tested. */
#define GNULIB_TEST_GETSOCKNAME 1

/* Define to 1 when the gnulib module gettimeofday should be tested. */
#define GNULIB_TEST_GETTIMEOFDAY 1

/* Define to 1 when the gnulib module group-member should be tested. */
#define GNULIB_TEST_GROUP_MEMBER 1

/* Define to 1 when the gnulib module ioctl should be tested. */
#define GNULIB_TEST_IOCTL 1

/* Define to 1 when the gnulib module iswblank should be tested. */
#define GNULIB_TEST_ISWBLANK 1

/* Define to 1 when the gnulib module iswdigit should be tested. */
#define GNULIB_TEST_ISWDIGIT 1

/* Define to 1 when the gnulib module iswxdigit should be tested. */
#define GNULIB_TEST_ISWXDIGIT 1

/* Define to 1 when the gnulib module link should be tested. */
#define GNULIB_TEST_LINK 1

/* Define to 1 when the gnulib module listen should be tested. */
#define GNULIB_TEST_LISTEN 1

/* Define to 1 when the gnulib module localeconv should be tested. */
#define GNULIB_TEST_LOCALECONV 1

/* Define to 1 when the gnulib module lseek should be tested. */
#define GNULIB_TEST_LSEEK 1

/* Define to 1 when the gnulib module lstat should be tested. */
#define GNULIB_TEST_LSTAT 1

/* Define to 1 when the gnulib module malloc-posix should be tested. */
#define GNULIB_TEST_MALLOC_POSIX 1

/* Define to 1 when the gnulib module mbrtowc should be tested. */
#define GNULIB_TEST_MBRTOWC 1

/* Define to 1 when the gnulib module mbsinit should be tested. */
#define GNULIB_TEST_MBSINIT 1

/* Define to 1 when the gnulib module mbsrtowcs should be tested. */
#define GNULIB_TEST_MBSRTOWCS 1

/* Define to 1 when the gnulib module mbtowc should be tested. */
#define GNULIB_TEST_MBTOWC 1

/* Define to 1 when the gnulib module memchr should be tested. */
#define GNULIB_TEST_MEMCHR 1

/* Define to 1 when the gnulib module mempcpy should be tested. */
#define GNULIB_TEST_MEMPCPY 1

/* Define to 1 when the gnulib module memrchr should be tested. */
#define GNULIB_TEST_MEMRCHR 1

/* Define to 1 when the gnulib module mkdir should be tested. */
#define GNULIB_TEST_MKDIR 1

/* Define to 1 when the gnulib module mkostemp should be tested. */
#define GNULIB_TEST_MKOSTEMP 1

/* Define to 1 when the gnulib module mkstemp should be tested. */
#define GNULIB_TEST_MKSTEMP 1

/* Define to 1 when the gnulib module mktime should be tested. */
#define GNULIB_TEST_MKTIME 1

/* Define to 1 when the gnulib module nanosleep should be tested. */
#define GNULIB_TEST_NANOSLEEP 1

/* Define to 1 when the gnulib module nl_langinfo should be tested. */
#define GNULIB_TEST_NL_LANGINFO 1

/* Define to 1 when the gnulib module open should be tested. */
#define GNULIB_TEST_OPEN 1

/* Define to 1 when the gnulib module openat should be tested. */
#define GNULIB_TEST_OPENAT 1

/* Define to 1 when the gnulib module opendir should be tested. */
#define GNULIB_TEST_OPENDIR 1

/* Define to 1 when the gnulib module pipe should be tested. */
#define GNULIB_TEST_PIPE 1

/* Define to 1 when the gnulib module pipe2 should be tested. */
#define GNULIB_TEST_PIPE2 1

/* Define to 1 when the gnulib module posix_spawn should be tested. */
#define GNULIB_TEST_POSIX_SPAWN 1

/* Define to 1 when the gnulib module posix_spawnattr_destroy should be
   tested. */
#define GNULIB_TEST_POSIX_SPAWNATTR_DESTROY 1

/* Define to 1 when the gnulib module posix_spawnattr_init should be tested.
   */
#define GNULIB_TEST_POSIX_SPAWNATTR_INIT 1

/* Define to 1 when the gnulib module posix_spawnattr_setflags should be
   tested. */
#define GNULIB_TEST_POSIX_SPAWNATTR_SETFLAGS 1

/* Define to 1 when the gnulib module posix_spawnattr_setpgroup should be
   tested. */
#define GNULIB_TEST_POSIX_SPAWNATTR_SETPGROUP 1

/* Define to 1 when the gnulib module posix_spawnattr_setsigmask should be
   tested. */
#define GNULIB_TEST_POSIX_SPAWNATTR_SETSIGMASK 1

/* Define to 1 when the gnulib module posix_spawnp should be tested. */
#define GNULIB_TEST_POSIX_SPAWNP 1

/* Define to 1 when the gnulib module posix_spawn_file_actions_addchdir should
   be tested. */
#define GNULIB_TEST_POSIX_SPAWN_FILE_ACTIONS_ADDCHDIR 1

/* Define to 1 when the gnulib module posix_spawn_file_actions_addclose should
   be tested. */
#define GNULIB_TEST_POSIX_SPAWN_FILE_ACTIONS_ADDCLOSE 1

/* Define to 1 when the gnulib module posix_spawn_file_actions_adddup2 should
   be tested. */
#define GNULIB_TEST_POSIX_SPAWN_FILE_ACTIONS_ADDDUP2 1

/* Define to 1 when the gnulib module posix_spawn_file_actions_addopen should
   be tested. */
#define GNULIB_TEST_POSIX_SPAWN_FILE_ACTIONS_ADDOPEN 1

/* Define to 1 when the gnulib module posix_spawn_file_actions_destroy should
   be tested. */
#define GNULIB_TEST_POSIX_SPAWN_FILE_ACTIONS_DESTROY 1

/* Define to 1 when the gnulib module posix_spawn_file_actions_init should be
   tested. */
#define GNULIB_TEST_POSIX_SPAWN_FILE_ACTIONS_INIT 1

/* Define to 1 when the gnulib module raise should be tested. */
#define GNULIB_TEST_RAISE 1

/* Define to 1 when the gnulib module rawmemchr should be tested. */
#define GNULIB_TEST_RAWMEMCHR 1

/* Define to 1 when the gnulib module readdir should be tested. */
#define GNULIB_TEST_READDIR 1

/* Define to 1 when the gnulib module readlink should be tested. */
#define GNULIB_TEST_READLINK 1

/* Define to 1 when the gnulib module realloc-posix should be tested. */
#define GNULIB_TEST_REALLOC_POSIX 1

/* Define to 1 when the gnulib module recv should be tested. */
#define GNULIB_TEST_RECV 1

/* Define to 1 when the gnulib module rewinddir should be tested. */
#define GNULIB_TEST_REWINDDIR 1

/* Define to 1 when the gnulib module secure_getenv should be tested. */
#define GNULIB_TEST_SECURE_GETENV 1

/* Define to 1 when the gnulib module select should be tested. */
#define GNULIB_TEST_SELECT 1

/* Define to 1 when the gnulib module send should be tested. */
#define GNULIB_TEST_SEND 1

/* Define to 1 when the gnulib module setlocale_null should be tested. */
#define GNULIB_TEST_SETLOCALE_NULL 1

/* Define to 1 when the gnulib module setsockopt should be tested. */
#define GNULIB_TEST_SETSOCKOPT 1

/* Define to 1 when the gnulib module sigaction should be tested. */
#define GNULIB_TEST_SIGACTION 1

/* Define to 1 when the gnulib module sigprocmask should be tested. */
#define GNULIB_TEST_SIGPROCMASK 1

/* Define to 1 when the gnulib module snprintf should be tested. */
#define GNULIB_TEST_SNPRINTF 1

/* Define to 1 when the gnulib module socket should be tested. */
#define GNULIB_TEST_SOCKET 1

/* Define to 1 when the gnulib module stat should be tested. */
#define GNULIB_TEST_STAT 1

/* Define to 1 when the gnulib module stpcpy should be tested. */
#define GNULIB_TEST_STPCPY 1

/* Define to 1 when the gnulib module strchrnul should be tested. */
#define GNULIB_TEST_STRCHRNUL 1

/* Define to 1 when the gnulib module strdup should be tested. */
#define GNULIB_TEST_STRDUP 1

/* Define to 1 when the gnulib module strerror should be tested. */
#define GNULIB_TEST_STRERROR 1

/* Define to 1 when the gnulib module strerror_r should be tested. */
#define GNULIB_TEST_STRERROR_R 1

/* Define to 1 when the gnulib module strndup should be tested. */
#define GNULIB_TEST_STRNDUP 1

/* Define to 1 when the gnulib module strnlen should be tested. */
#define GNULIB_TEST_STRNLEN 1

/* Define to 1 when the gnulib module strpbrk should be tested. */
#define GNULIB_TEST_STRPBRK 1

/* Define to 1 when the gnulib module strptime should be tested. */
#define GNULIB_TEST_STRPTIME 1

/* Define to 1 when the gnulib module strtok_r should be tested. */
#define GNULIB_TEST_STRTOK_R 1

/* Define to 1 when the gnulib module strtoll should be tested. */
#define GNULIB_TEST_STRTOLL 1

/* Define to 1 when the gnulib module symlink should be tested. */
#define GNULIB_TEST_SYMLINK 1

/* Define to 1 when the gnulib module timegm should be tested. */
#define GNULIB_TEST_TIMEGM 1

/* Define to 1 when the gnulib module time_r should be tested. */
#define GNULIB_TEST_TIME_R 1

/* Define to 1 when the gnulib module uninorm/u8-normalize should be tested.
   */
#define GNULIB_TEST_UNINORM_U8_NORMALIZE 1

/* Define to 1 when the gnulib module unlink should be tested. */
#define GNULIB_TEST_UNLINK 1

/* Define to 1 when the gnulib module utime should be tested. */
#define GNULIB_TEST_UTIME 1

/* Define to 1 when the gnulib module vasprintf should be tested. */
#define GNULIB_TEST_VASPRINTF 1

/* Define to 1 when the gnulib module vsnprintf should be tested. */
#define GNULIB_TEST_VSNPRINTF 1

/* Define to 1 when the gnulib module waitpid should be tested. */
#define GNULIB_TEST_WAITPID 1

/* Define to 1 when the gnulib module wcrtomb should be tested. */
#define GNULIB_TEST_WCRTOMB 1

/* Define to 1 when the gnulib module wcwidth should be tested. */
#define GNULIB_TEST_WCWIDTH 1

/* Define to 1 when the gnulib module wmemchr should be tested. */
#define GNULIB_TEST_WMEMCHR 1

/* Define to 1 when the gnulib module wmempcpy should be tested. */
#define GNULIB_TEST_WMEMPCPY 1

/* Define to 1 when the gnulib module write should be tested. */
#define GNULIB_TEST_WRITE 1

/* Define to a C preprocessor expression that evaluates to 1 or 0, depending
   whether the gnulib module unistr/u8-mbtouc-unsafe shall be considered
   present. */
#define GNULIB_UNISTR_U8_MBTOUC_UNSAFE 1

/* Define to a C preprocessor expression that evaluates to 1 or 0, depending
   whether the gnulib module unistr/u8-uctomb shall be considered present. */
#define GNULIB_UNISTR_U8_UCTOMB 1

/* Define to a C preprocessor expression that evaluates to 1 or 0, depending
   whether the gnulib module xalloc shall be considered present. */
#define GNULIB_XALLOC 1

/* Define to a C preprocessor expression that evaluates to 1 or 0, depending
   whether the gnulib module xalloc-die shall be considered present. */
#define GNULIB_XALLOC_DIE 1

/* Define to 1 if you have 'alloca' after including <alloca.h>, a header that
   may be supplied by this distribution. */
#define HAVE_ALLOCA 1

/* Define to 1 if <alloca.h> works. */
#define HAVE_ALLOCA_H 1

/* Define to 1 if you have the <arpa/inet.h> header file. */
#define HAVE_ARPA_INET_H 1

/* Define to 1 if you have the <bcrypt.h> header file. */
/* #undef HAVE_BCRYPT_H */

/* Define to 1 if you have the <bp-sym.h> header file. */
/* #undef HAVE_BP_SYM_H */

/* Define to 1 if you have the `btowc' function. */
#define HAVE_BTOWC 1

/* Define to 1 if nanosleep mishandles large arguments. */
#define HAVE_BUG_BIG_NANOSLEEP 1

/* Define to 1 if you have the <byteswap.h> header file. */
#define HAVE_BYTESWAP_H 1

/* Define to 1 if you have the `canonicalize_file_name' function. */
/* #undef HAVE_CANONICALIZE_FILE_NAME */

/* Define to 1 if you have the `catgets' function. */
#define HAVE_CATGETS 1

/* Define to 1 if you have the Mac OS X function CFLocaleCopyCurrent in the
   CoreFoundation framework. */
/* #undef HAVE_CFLOCALECOPYCURRENT */

/* Define to 1 if you have the Mac OS X function CFPreferencesCopyAppValue in
   the CoreFoundation framework. */
/* #undef HAVE_CFPREFERENCESCOPYAPPVALUE */

/* Define to 1 if you have the `clock_gettime' function. */
#define HAVE_CLOCK_GETTIME 1

/* Define to 1 if you have the `clock_settime' function. */
#define HAVE_CLOCK_SETTIME 1

/* Define to 1 if you have the `closedir' function. */
#define HAVE_CLOSEDIR 1

/* Define to 1 if you have the `confstr' function. */
/* #undef HAVE_CONFSTR */

/* Define to 1 if you have the <crtdefs.h> header file. */
/* #undef HAVE_CRTDEFS_H */

/* Define if the GNU dcgettext() function is already present or preinstalled.
   */
/* #undef HAVE_DCGETTEXT */

/* Define to 1 if you have the declaration of `alarm', and to 0 if you don't.
   */
#define HAVE_DECL_ALARM 1

/* Define to 1 if you have the declaration of `clearerr_unlocked', and to 0 if
   you don't. */
#define HAVE_DECL_CLEARERR_UNLOCKED 1

/* Define to 1 if you have the declaration of `dirfd', and to 0 if you don't.
   */
#define HAVE_DECL_DIRFD 1

/* Define to 1 if you have the declaration of `ecvt', and to 0 if you don't.
   */
#define HAVE_DECL_ECVT 1

/* Define to 1 if you have the declaration of `execvpe', and to 0 if you
   don't. */
#define HAVE_DECL_EXECVPE 1

/* Define to 1 if you have the declaration of `fchdir', and to 0 if you don't.
   */
#define HAVE_DECL_FCHDIR 1

/* Define to 1 if you have the declaration of `fcloseall', and to 0 if you
   don't. */
#define HAVE_DECL_FCLOSEALL 0

/* Define to 1 if you have the declaration of `fcvt', and to 0 if you don't.
   */
#define HAVE_DECL_FCVT 1

/* Define to 1 if you have the declaration of `fdopendir', and to 0 if you
   don't. */
#define HAVE_DECL_FDOPENDIR 1

/* Define to 1 if you have the declaration of `feof_unlocked', and to 0 if you
   don't. */
#define HAVE_DECL_FEOF_UNLOCKED 1

/* Define to 1 if you have the declaration of `ferror_unlocked', and to 0 if
   you don't. */
#define HAVE_DECL_FERROR_UNLOCKED 1

/* Define to 1 if you have the declaration of `fflush_unlocked', and to 0 if
   you don't. */
#define HAVE_DECL_FFLUSH_UNLOCKED 1

/* Define to 1 if you have the declaration of `fgets_unlocked', and to 0 if
   you don't. */
#define HAVE_DECL_FGETS_UNLOCKED 1

/* Define to 1 if you have the declaration of `flockfile', and to 0 if you
   don't. */
#define HAVE_DECL_FLOCKFILE 1

/* Define to 1 if you have the declaration of `fpurge', and to 0 if you don't.
   */
#define HAVE_DECL_FPURGE 0

/* Define to 1 if you have the declaration of `fputc_unlocked', and to 0 if
   you don't. */
#define HAVE_DECL_FPUTC_UNLOCKED 1

/* Define to 1 if you have the declaration of `fputs_unlocked', and to 0 if
   you don't. */
#define HAVE_DECL_FPUTS_UNLOCKED 1

/* Define to 1 if you have the declaration of `fread_unlocked', and to 0 if
   you don't. */
#define HAVE_DECL_FREAD_UNLOCKED 1

/* Define to 1 if you have the declaration of `freeaddrinfo', and to 0 if you
   don't. */
#define HAVE_DECL_FREEADDRINFO 1

/* Define to 1 if you have the declaration of `fseeko', and to 0 if you don't.
   */
#define HAVE_DECL_FSEEKO 1

/* Define to 1 if you have the declaration of `ftello', and to 0 if you don't.
   */
#define HAVE_DECL_FTELLO 1

/* Define to 1 if you have the declaration of `funlockfile', and to 0 if you
   don't. */
#define HAVE_DECL_FUNLOCKFILE 1

/* Define to 1 if you have the declaration of `fwrite_unlocked', and to 0 if
   you don't. */
#define HAVE_DECL_FWRITE_UNLOCKED 1

/* Define to 1 if you have the declaration of `gai_strerror', and to 0 if you
   don't. */
#define HAVE_DECL_GAI_STRERROR 1

/* Define to 1 if you have the declaration of `gai_strerrorA', and to 0 if you
   don't. */
#define HAVE_DECL_GAI_STRERRORA 0

/* Define to 1 if you have the declaration of `gcvt', and to 0 if you don't.
   */
#define HAVE_DECL_GCVT 1

/* Define to 1 if you have the declaration of `getaddrinfo', and to 0 if you
   don't. */
#define HAVE_DECL_GETADDRINFO 1

/* Define to 1 if you have the declaration of `getchar_unlocked', and to 0 if
   you don't. */
#define HAVE_DECL_GETCHAR_UNLOCKED 1

/* Define to 1 if you have the declaration of `getcwd', and to 0 if you don't.
   */
#define HAVE_DECL_GETCWD 1

/* Define to 1 if you have the declaration of `getc_unlocked', and to 0 if you
   don't. */
#define HAVE_DECL_GETC_UNLOCKED 1

/* Define to 1 if you have the declaration of `getdelim', and to 0 if you
   don't. */
#define HAVE_DECL_GETDELIM 1

/* Define to 1 if you have the declaration of `getdtablesize', and to 0 if you
   don't. */
#define HAVE_DECL_GETDTABLESIZE 1

/* Define to 1 if you have the declaration of `getline', and to 0 if you
   don't. */
#define HAVE_DECL_GETLINE 1

/* Define to 1 if you have the declaration of `getnameinfo', and to 0 if you
   don't. */
#define HAVE_DECL_GETNAMEINFO 1

/* Define to 1 if you have the declaration of `h_errno', and to 0 if you
   don't. */
#define HAVE_DECL_H_ERRNO 1

/* Define to 1 if you have the declaration of `inet_ntop', and to 0 if you
   don't. */
#define HAVE_DECL_INET_NTOP 1

/* Define to 1 if you have the declaration of `isblank', and to 0 if you
   don't. */
#define HAVE_DECL_ISBLANK 1

/* Define to 1 if you have the declaration of `iswblank', and to 0 if you
   don't. */
#define HAVE_DECL_ISWBLANK 1

/* Define to 1 if you have the declaration of `localtime_r', and to 0 if you
   don't. */
#define HAVE_DECL_LOCALTIME_R 1

/* Define to 1 if you have the declaration of `mbrtowc', and to 0 if you
   don't. */
/* #undef HAVE_DECL_MBRTOWC */

/* Define to 1 if you have the declaration of `mbsinit', and to 0 if you
   don't. */
/* #undef HAVE_DECL_MBSINIT */

/* Define to 1 if you have the declaration of `mbsrtowcs', and to 0 if you
   don't. */
/* #undef HAVE_DECL_MBSRTOWCS */

/* Define to 1 if you have the declaration of `memrchr', and to 0 if you
   don't. */
#define HAVE_DECL_MEMRCHR 1

/* Define to 1 if you have the declaration of `program_invocation_name', and
   to 0 if you don't. */
#define HAVE_DECL_PROGRAM_INVOCATION_NAME 1

/* Define to 1 if you have the declaration of `program_invocation_short_name',
   and to 0 if you don't. */
#define HAVE_DECL_PROGRAM_INVOCATION_SHORT_NAME 1

/* Define to 1 if you have the declaration of `putchar_unlocked', and to 0 if
   you don't. */
#define HAVE_DECL_PUTCHAR_UNLOCKED 1

/* Define to 1 if you have the declaration of `putc_unlocked', and to 0 if you
   don't. */
#define HAVE_DECL_PUTC_UNLOCKED 1

/* Define to 1 if you have the declaration of `snprintf', and to 0 if you
   don't. */
#define HAVE_DECL_SNPRINTF 1

/* Define to 1 if you have the declaration of `strdup', and to 0 if you don't.
   */
#define HAVE_DECL_STRDUP 1

/* Define to 1 if you have the declaration of `strerror_r', and to 0 if you
   don't. */
#define HAVE_DECL_STRERROR_R 1

/* Define to 1 if you have the declaration of `strncasecmp', and to 0 if you
   don't. */
#define HAVE_DECL_STRNCASECMP 1

/* Define to 1 if you have the declaration of `strndup', and to 0 if you
   don't. */
#define HAVE_DECL_STRNDUP 1

/* Define to 1 if you have the declaration of `strnlen', and to 0 if you
   don't. */
#define HAVE_DECL_STRNLEN 1

/* Define to 1 if you have the declaration of `strtok_r', and to 0 if you
   don't. */
#define HAVE_DECL_STRTOK_R 1

/* Define to 1 if you have the declaration of `towlower', and to 0 if you
   don't. */
/* #undef HAVE_DECL_TOWLOWER */

/* Define to 1 if you have the declaration of `vsnprintf', and to 0 if you
   don't. */
#define HAVE_DECL_VSNPRINTF 1

/* Define to 1 if you have the declaration of `wcrtomb', and to 0 if you
   don't. */
/* #undef HAVE_DECL_WCRTOMB */

/* Define to 1 if you have the declaration of `wcsdup', and to 0 if you don't.
   */
#define HAVE_DECL_WCSDUP 1

/* Define to 1 if you have the declaration of `wcwidth', and to 0 if you
   don't. */
#define HAVE_DECL_WCWIDTH 1

/* Define to 1 if you have the declaration of `_fseeki64', and to 0 if you
   don't. */
/* #undef HAVE_DECL__FSEEKI64 */

/* Define to 1 if you have the declaration of `_snprintf', and to 0 if you
   don't. */
#define HAVE_DECL__SNPRINTF 0

/* Define to 1 if you have the declaration of `__argv', and to 0 if you don't.
   */
#define HAVE_DECL___ARGV 0

/* Define to 1 if you have the declaration of `__fsetlocking', and to 0 if you
   don't. */
#define HAVE_DECL___FSETLOCKING 1

/* Define to 1 if you have the <dirent.h> header file. */
#define HAVE_DIRENT_H 1

/* Define to 1 if you have the `dirfd' function. */
#define HAVE_DIRFD 1

/* Define to 1 if you have the <dlfcn.h> header file. */
#define HAVE_DLFCN_H 1

/* Define to 1 if you have the `drand48' function. */
#define HAVE_DRAND48 1

/* Define if you have the declaration of environ. */
#define HAVE_ENVIRON_DECL 1

/* Define to 1 if you have the `faccessat' function. */
#define HAVE_FACCESSAT 1

/* Define to 1 if you have the `fchdir' function. */
#define HAVE_FCHDIR 1

/* Define to 1 if you have the `fcntl' function. */
#define HAVE_FCNTL 1

/* Define to 1 if you have the `fdopendir' function. */
#define HAVE_FDOPENDIR 1

/* Define to 1 if you have the <features.h> header file. */
#define HAVE_FEATURES_H 1

/* Define to 1 if you have the `flock' function. */
#define HAVE_FLOCK 1

/* Define to 1 if you have the `flockfile' function. */
#define HAVE_FLOCKFILE 1

/* Define to 1 if you have the `fmemopen' function. */
#define HAVE_FMEMOPEN 1

/* Define to 1 if you have the `fnmatch' function. */
#define HAVE_FNMATCH 1

/* Define to 1 if you have the <fnmatch.h> header file. */
#define HAVE_FNMATCH_H 1

/* Define to 1 if you have the `fpurge' function. */
#define HAVE_FPURGE 1

/* Define to 1 if fseeko (and presumably ftello) exists and is declared. */
#define HAVE_FSEEKO 1

/* Define to 1 if you have the `fstatat' function. */
#define HAVE_FSTATAT 1

/* Define to 1 if you have the `ftello' function. */
#define HAVE_FTELLO 1

/* Define to 1 if you have the `funlockfile' function. */
#define HAVE_FUNLOCKFILE 1

/* Define to 1 if you have the `futimens' function. */
#define HAVE_FUTIMENS 1

/* Define to 1 if you have the `futimes' function. */
#define HAVE_FUTIMES 1

/* Define to 1 if you have the `futimesat' function. */
#define HAVE_FUTIMESAT 1

/* Define to 1 if getaddrinfo exists, or to 0 otherwise. */
#define HAVE_GETADDRINFO 1

/* Define to 1 if getcwd works, but with shorter paths than is generally
   tested with the replacement. */
/* #undef HAVE_GETCWD_SHORTER */

/* Define to 1 if you have the `getdelim' function. */
#define HAVE_GETDELIM 1

/* Define to 1 if you have the `getdtablesize' function. */
#define HAVE_GETDTABLESIZE 1

/* Define to 1 if you have the `getegid' function. */
#define HAVE_GETEGID 1

/* Define to 1 if you have the `geteuid' function. */
#define HAVE_GETEUID 1

/* Define to 1 if you have the `getexecname' function. */
/* #undef HAVE_GETEXECNAME */

/* Define to 1 if you have the `getgid' function. */
#define HAVE_GETGID 1

/* Define to 1 if your system has a working `getgroups' function. */
#define HAVE_GETGROUPS 1

/* Define to 1 if you have the `gethostbyname' function. */
#define HAVE_GETHOSTBYNAME 1

/* Define to 1 if you have the <getopt.h> header file. */
#define HAVE_GETOPT_H 1

/* Define to 1 if you have the `getopt_long_only' function. */
#define HAVE_GETOPT_LONG_ONLY 1

/* Define to 1 if you have the `getpagesize' function. */
#define HAVE_GETPAGESIZE 1

/* Define to 1 if you have the `getpass' function. */
#define HAVE_GETPASS 1

/* Define to 1 if you have the `getprogname' function. */
/* #undef HAVE_GETPROGNAME */

/* Define to 1 if you have the `getrandom' function. */
#define HAVE_GETRANDOM 1

/* Define to 1 if you have the `getservbyname' function. */
#define HAVE_GETSERVBYNAME 1

/* Define if the GNU gettext() function is already present or preinstalled. */
/* #undef HAVE_GETTEXT */

/* Define to 1 if you have the `gettimeofday' function. */
#define HAVE_GETTIMEOFDAY 1

/* Define to 1 if you have the `getuid' function. */
#define HAVE_GETUID 1

/* Define to 1 if you have the `gnutls_priority_set_direct' function. */
/* #undef HAVE_GNUTLS_PRIORITY_SET_DIRECT */

/* Define if GPGME is available. */
/* #undef HAVE_GPGME */

/* Define if you have the iconv() function and it works. */
#define HAVE_ICONV 1

/* Define to 1 if you have the <iconv.h> header file. */
#define HAVE_ICONV_H 1

/* Define to 1 if you have the `inet_ntop' function. */
/* #undef HAVE_INET_NTOP */

/* Define to 1 if the compiler supports one of the keywords 'inline',
   '__inline__', '__inline' and effectively inlines functions marked as such.
   */
#define HAVE_INLINE 1

/* Define to 1 if the system has the type `int64_t'. */
#define HAVE_INT64_T 1

/* Define if you have the 'intmax_t' type in <stdint.h> or <inttypes.h>. */
#define HAVE_INTMAX_T 1

/* Define to 1 if the system has the type `intptr_t'. */
#define HAVE_INTPTR_T 1

/* Define to 1 if you have the <inttypes.h> header file. */
#define HAVE_INTTYPES_H 1

/* Define if <inttypes.h> exists, doesn't clash with <sys/types.h>, and
   declares uintmax_t. */
#define HAVE_INTTYPES_H_WITH_UINTMAX 1

/* Define to 1 if you have the `ioctl' function. */
#define HAVE_IOCTL 1

/* Define to 1 if <sys/socket.h> defines AF_INET. */
#define HAVE_IPV4 1

/* Define to 1 if <sys/socket.h> defines AF_INET6. */
#define HAVE_IPV6 1

/* Define to 1 if you have the `isatty' function. */
#define HAVE_ISATTY 1

/* Define to 1 if you have the `isblank' function. */
#define HAVE_ISBLANK 1

/* Define to 1 if you have the `issetugid' function. */
/* #undef HAVE_ISSETUGID */

/* Define to 1 if you have the `iswblank' function. */
#define HAVE_ISWBLANK 1

/* Define to 1 if you have the `iswcntrl' function. */
#define HAVE_ISWCNTRL 1

/* Define to 1 if you have the `iswctype' function. */
#define HAVE_ISWCTYPE 1

/* Define if you have <langinfo.h> and nl_langinfo(CODESET). */
#define HAVE_LANGINFO_CODESET 1

/* Define to 1 if you have the <langinfo.h> header file. */
#define HAVE_LANGINFO_H 1

/* Define if libcares is available. */
/* #undef HAVE_LIBCARES */

/* Define to 1 if you have the `dl' library (-ldl). */
#define HAVE_LIBDL 1

/* Define to 1 if you have the `eay32' library (-leay32). */
/* #undef HAVE_LIBEAY32 */

/* Define if you have the libgnutls library. */
/* #undef HAVE_LIBGNUTLS */

/* Define to 1 if you have the <libintl.h> header file. */
#define HAVE_LIBINTL_H 1

/* Define if libpcre is available. */
#define HAVE_LIBPCRE 1

/* Define if libpcre2 is available. */
/* #undef HAVE_LIBPCRE2 */

/* PSL support enabled */
/* #undef HAVE_LIBPSL */

/* Define if you have the libssl library. */
#define HAVE_LIBSSL 1

/* Define to 1 if you have the `ssl32' library (-lssl32). */
/* #undef HAVE_LIBSSL32 */

/* Define if you have the libunistring library. */
/* #undef HAVE_LIBUNISTRING */

/* Define if using libuuid. */
/* #undef HAVE_LIBUUID */

/* Define if using zlib. */
#define HAVE_LIBZ 1

/* Define to 1 if the bcrypt library is guaranteed to be present. */
/* #undef HAVE_LIB_BCRYPT */

/* Define to 1 if you have the <limits.h> header file. */
#define HAVE_LIMITS_H 1

/* Define to 1 if you have the `link' function. */
#define HAVE_LINK 1

/* Define to 1 if you have 'struct sockaddr_alg' defined. */
#define HAVE_LINUX_IF_ALG_H 1

/* Define to 1 if you have the `localtime_r' function. */
#define HAVE_LOCALTIME_R 1

/* Define to 1 if the system has the type 'long long int'. */
#define HAVE_LONG_LONG_INT 1

/* Define to 1 if you have the `lstat' function. */
#define HAVE_LSTAT 1

/* Define to 1 if you have the `lutimes' function. */
#define HAVE_LUTIMES 1

/* Define to 1 if you have the <malloc.h> header file. */
#define HAVE_MALLOC_H 1

/* Define if the 'malloc' function is POSIX compliant. */
#define HAVE_MALLOC_POSIX 1

/* Define to 1 if mmap()'s MAP_ANONYMOUS flag is available after including
   config.h and <sys/mman.h>. */
#define HAVE_MAP_ANONYMOUS 1

/* Define to 1 if you have the `mbrtowc' function. */
#define HAVE_MBRTOWC 1

/* Define to 1 if you have the `mbsinit' function. */
#define HAVE_MBSINIT 1

/* Define to 1 if you have the `mbsrtowcs' function. */
#define HAVE_MBSRTOWCS 1

/* Define to 1 if <wchar.h> declares mbstate_t. */
#define HAVE_MBSTATE_T 1

/* Define to 1 if you have the `mbtowc' function. */
#define HAVE_MBTOWC 1

/* Define to 1 if you have the `mempcpy' function. */
#define HAVE_MEMPCPY 1

/* Define to 1 if you have the `memrchr' function. */
#define HAVE_MEMRCHR 1

/* Define if using metalink. */
/* #undef HAVE_METALINK */

/* Define to 1 if getcwd minimally works, that is, its result can be trusted
   when it succeeds. */
#define HAVE_MINIMALLY_WORKING_GETCWD 1

/* Define to 1 if you have the <minix/config.h> header file. */
/* #undef HAVE_MINIX_CONFIG_H */

/* Define to 1 if <limits.h> defines the MIN and MAX macros. */
/* #undef HAVE_MINMAX_IN_LIMITS_H */

/* Define to 1 if <sys/param.h> defines the MIN and MAX macros. */
#define HAVE_MINMAX_IN_SYS_PARAM_H 1

/* Define to 1 if you have the `mkostemp' function. */
#define HAVE_MKOSTEMP 1

/* Define to 1 if you have the `mkstemp' function. */
#define HAVE_MKSTEMP 1

/* Define to 1 if you have a working `mmap' system call. */
#define HAVE_MMAP 1

/* Define to 1 if you have the `mprotect' function. */
#define HAVE_MPROTECT 1

/* Define to 1 on MSVC platforms that have the "invalid parameter handler"
   concept. */
/* #undef HAVE_MSVC_INVALID_PARAMETER_HANDLER */

/* Define to 1 if you have the <netdb.h> header file. */
#define HAVE_NETDB_H 1

/* Define to 1 if you have the <netinet/in.h> header file. */
#define HAVE_NETINET_IN_H 1

/* Use libnettle */
/* #undef HAVE_NETTLE */

/* Define to 1 if you have the `nl_langinfo' function. */
#define HAVE_NL_LANGINFO 1

/* Define to 1 if you have the `openat' function. */
#define HAVE_OPENAT 1

/* Define to 1 if you have the `opendir' function. */
#define HAVE_OPENDIR 1

/* Define to 1 if libcrypto is used for MD5. */
/* #undef HAVE_OPENSSL_MD5 */

/* Define to 1 if you have the <openssl/md5.h> header file. */
/* #undef HAVE_OPENSSL_MD5_H */

/* Define to 1 if libcrypto is used for SHA1. */
/* #undef HAVE_OPENSSL_SHA1 */

/* Define to 1 if libcrypto is used for SHA256. */
/* #undef HAVE_OPENSSL_SHA256 */

/* Define to 1 if libcrypto is used for SHA512. */
/* #undef HAVE_OPENSSL_SHA512 */

/* Define to 1 if you have the <openssl/sha.h> header file. */
/* #undef HAVE_OPENSSL_SHA_H */

/* Define to 1 if getcwd works, except it sometimes fails when it shouldn't,
   setting errno to ERANGE, ENAMETOOLONG, or ENOENT. */
#define HAVE_PARTLY_WORKING_GETCWD 1

/* Define to 1 if you have the `pathconf' function. */
#define HAVE_PATHCONF 1

/* Define to 1 if you have the <paths.h> header file. */
/* #undef HAVE_PATHS_H */

/* Define to 1 if you have the `pipe' function. */
#define HAVE_PIPE 1

/* Define to 1 if you have the `pipe2' function. */
#define HAVE_PIPE2 1

/* Define to 1 if you have the `posix_spawn' function. */
#define HAVE_POSIX_SPAWN 1

/* Define to 1 if the system has the type `posix_spawnattr_t'. */
#define HAVE_POSIX_SPAWNATTR_T 1

/* Define to 1 if you have the `posix_spawn_file_actions_addchdir' function.
   */
/* #undef HAVE_POSIX_SPAWN_FILE_ACTIONS_ADDCHDIR */

/* Define to 1 if you have the `posix_spawn_file_actions_addchdir_np'
   function. */
#define HAVE_POSIX_SPAWN_FILE_ACTIONS_ADDCHDIR_NP 1

/* Define to 1 if the system has the type `posix_spawn_file_actions_t'. */
#define HAVE_POSIX_SPAWN_FILE_ACTIONS_T 1

/* Define to 1 if you have the `psl_latest' function. */
/* #undef HAVE_PSL_LATEST */

/* Define if you have the <pthread.h> header and the POSIX threads API. */
#define HAVE_PTHREAD_API 1

/* Define if the <pthread.h> defines PTHREAD_MUTEX_RECURSIVE. */
#define HAVE_PTHREAD_MUTEX_RECURSIVE 1

/* Define if the POSIX multithreading library has read/write locks. */
#define HAVE_PTHREAD_RWLOCK 1

/* Define if the 'pthread_rwlock_rdlock' function prefers a writer to a
   reader. */
/* #undef HAVE_PTHREAD_RWLOCK_RDLOCK_PREFER_WRITER */

/* Define to 1 if you have the <pwd.h> header file. */
#define HAVE_PWD_H 1

/* Define to 1 if you have the `raise' function. */
#define HAVE_RAISE 1

/* Define to 1 if you have the `random' function. */
#define HAVE_RANDOM 1

/* Define to 1 if you have the `RAND_egd' function. */
/* #undef HAVE_RAND_EGD */

/* Define to 1 if you have the `rawmemchr' function. */
/* #undef HAVE_RAWMEMCHR */

/* Define to 1 if you have the `readdir' function. */
#define HAVE_READDIR 1

/* Define to 1 if you have the `readlink' function. */
#define HAVE_READLINK 1

/* Define if the 'realloc' function is POSIX compliant. */
#define HAVE_REALLOC_POSIX 1

/* Define to 1 if you have the `realpath' function. */
#define HAVE_REALPATH 1

/* Define to 1 if you have the `rewinddir' function. */
#define HAVE_REWINDDIR 1

/* Define to 1 if the system has the type `sa_family_t'. */
#define HAVE_SA_FAMILY_T 1

/* Define to 1 if you have the <sched.h> header file. */
#define HAVE_SCHED_H 1

/* Define to 1 if you have the `sched_setparam' function. */
/* #undef HAVE_SCHED_SETPARAM */

/* Define to 1 if you have the `sched_setscheduler' function. */
/* #undef HAVE_SCHED_SETSCHEDULER */

/* Define to 1 if you have the <sdkddkver.h> header file. */
/* #undef HAVE_SDKDDKVER_H */

/* Define to 1 if you have the `secure_getenv' function. */
#define HAVE_SECURE_GETENV 1

/* Define to 1 if you have the `setdtablesize' function. */
/* #undef HAVE_SETDTABLESIZE */

/* Define to 1 if you have the `setegid' function. */
/* #undef HAVE_SETEGID */

/* Define to 1 if you have the `seteuid' function. */
/* #undef HAVE_SETEUID */

/* Define to 1 if you have the `shutdown' function. */
#define HAVE_SHUTDOWN 1

/* Define to 1 if you have the `sigaction' function. */
#define HAVE_SIGACTION 1

/* Define to 1 if you have the `sigaltstack' function. */
#define HAVE_SIGALTSTACK 1

/* Define to 1 if you have the `sigblock' function. */
/* #undef HAVE_SIGBLOCK */

/* Define to 1 if the system has the type `siginfo_t'. */
/* #undef HAVE_SIGINFO_T */

/* Define to 1 if you have the `siginterrupt' function. */
#define HAVE_SIGINTERRUPT 1

/* Define to 1 if 'sig_atomic_t' is a signed integer type. */
/* #undef HAVE_SIGNED_SIG_ATOMIC_T */

/* Define to 1 if 'wchar_t' is a signed integer type. */
/* #undef HAVE_SIGNED_WCHAR_T */

/* Define to 1 if 'wint_t' is a signed integer type. */
/* #undef HAVE_SIGNED_WINT_T */

/* Define to 1 if you have the `sigsetjmp' function. */
#define HAVE_SIGSETJMP 1

/* Define to 1 if the system has the type `sigset_t'. */
#define HAVE_SIGSET_T 1

/* Define to 1 if the system has the type `sig_atomic_t'. */
#define HAVE_SIG_ATOMIC_T 1

/* Define to 1 if you have the `sleep' function. */
#define HAVE_SLEEP 1

/* Define to 1 if you have the `snprintf' function. */
#define HAVE_SNPRINTF 1

/* Define if the return value of the snprintf function is the number of of
   bytes (excluding the terminating NUL) that would have been produced if the
   buffer had been large enough. */
#define HAVE_SNPRINTF_RETVAL_C99 1

/* Define if the string produced by the snprintf function is always NUL
   terminated. */
#define HAVE_SNPRINTF_TRUNCATION_C99 1

/* Define if struct sockaddr_in6 has the sin6_scope_id member */
#define HAVE_SOCKADDR_IN6_SCOPE_ID 1

/* Define to 1 if you have the <spawn.h> header file. */
#define HAVE_SPAWN_H 1

/* Define to 1 if stdbool.h conforms to C99. */
#define HAVE_STDBOOL_H 1

/* Define to 1 if you have the <stdint.h> header file. */
#define HAVE_STDINT_H 1

/* Define if <stdint.h> exists, doesn't clash with <sys/types.h>, and declares
   uintmax_t. */
#define HAVE_STDINT_H_WITH_UINTMAX 1

/* Define to 1 if you have the <stdio_ext.h> header file. */
#define HAVE_STDIO_EXT_H 1

/* Define to 1 if you have the <stdio.h> header file. */
#define HAVE_STDIO_H 1

/* Define to 1 if you have the <stdlib.h> header file. */
#define HAVE_STDLIB_H 1

/* Define to 1 if you have the `stpcpy' function. */
#define HAVE_STPCPY 1

/* Define to 1 if you have the `strcasecmp' function. */
#define HAVE_STRCASECMP 1

/* Define to 1 if you have the `strchrnul' function. */
#define HAVE_STRCHRNUL 1

/* Define to 1 if you have the `strdup' function. */
#define HAVE_STRDUP 1

/* Define to 1 if you have the `strerror_r' function. */
#define HAVE_STRERROR_R 1

/* Define to 1 if you have the <strings.h> header file. */
#define HAVE_STRINGS_H 1

/* Define to 1 if you have the <string.h> header file. */
#define HAVE_STRING_H 1

/* Define to 1 if you have the `strlcpy' function. */
#define HAVE_STRLCPY 1

/* Define to 1 if you have the `strncasecmp' function. */
#define HAVE_STRNCASECMP 1

/* Define to 1 if you have the `strndup' function. */
#define HAVE_STRNDUP 1

/* Define to 1 if you have the `strnlen' function. */
#define HAVE_STRNLEN 1

/* Define to 1 if you have the `strpbrk' function. */
#define HAVE_STRPBRK 1

/* Define to 1 if you have the `strptime' function. */
#define HAVE_STRPTIME 1

/* Define to 1 if you have the `strtok_r' function. */
#define HAVE_STRTOK_R 1

/* Define to 1 if you have the `strtol' function. */
#define HAVE_STRTOL 1

/* Define to 1 if you have the `strtoll' function. */
#define HAVE_STRTOLL 1

/* Define to 1 if the system has the type `struct addrinfo'. */
#define HAVE_STRUCT_ADDRINFO 1

/* Define to 1 if `l_type' is a member of `struct flock'. */
/* #undef HAVE_STRUCT_FLOCK_L_TYPE */

/* Define to 1 if `decimal_point' is a member of `struct lconv'. */
/* #undef HAVE_STRUCT_LCONV_DECIMAL_POINT */

/* Define to 1 if `sa_sigaction' is a member of `struct sigaction'. */
#define HAVE_STRUCT_SIGACTION_SA_SIGACTION 1

/* Define to 1 if the system has the type `struct sockaddr_in6'. */
#define HAVE_STRUCT_SOCKADDR_IN6 1

/* Define to 1 if `sa_len' is a member of `struct sockaddr'. */
/* #undef HAVE_STRUCT_SOCKADDR_SA_LEN */

/* Define to 1 if the system has the type `struct sockaddr_storage'. */
#define HAVE_STRUCT_SOCKADDR_STORAGE 1

/* Define to 1 if `ss_family' is a member of `struct sockaddr_storage'. */
#define HAVE_STRUCT_SOCKADDR_STORAGE_SS_FAMILY 1

/* Define to 1 if `st_atimensec' is a member of `struct stat'. */
/* #undef HAVE_STRUCT_STAT_ST_ATIMENSEC */

/* Define to 1 if `st_atimespec.tv_nsec' is a member of `struct stat'. */
/* #undef HAVE_STRUCT_STAT_ST_ATIMESPEC_TV_NSEC */

/* Define to 1 if `st_atim.st__tim.tv_nsec' is a member of `struct stat'. */
/* #undef HAVE_STRUCT_STAT_ST_ATIM_ST__TIM_TV_NSEC */

/* Define to 1 if `st_atim.tv_nsec' is a member of `struct stat'. */
#define HAVE_STRUCT_STAT_ST_ATIM_TV_NSEC 1

/* Define to 1 if `st_birthtimensec' is a member of `struct stat'. */
/* #undef HAVE_STRUCT_STAT_ST_BIRTHTIMENSEC */

/* Define to 1 if `st_birthtimespec.tv_nsec' is a member of `struct stat'. */
/* #undef HAVE_STRUCT_STAT_ST_BIRTHTIMESPEC_TV_NSEC */

/* Define to 1 if `st_birthtim.tv_nsec' is a member of `struct stat'. */
/* #undef HAVE_STRUCT_STAT_ST_BIRTHTIM_TV_NSEC */

/* Define to 1 if you have the `symlink' function. */
#define HAVE_SYMLINK 1

/* Define to 1 if you have the <sys/bitypes.h> header file. */
/* #undef HAVE_SYS_BITYPES_H */

/* Define to 1 if you have the <sys/cdefs.h> header file. */
#define HAVE_SYS_CDEFS_H 1

/* Define to 1 if you have the <sys/file.h> header file. */
#define HAVE_SYS_FILE_H 1

/* Define to 1 if you have the <sys/inttypes.h> header file. */
/* #undef HAVE_SYS_INTTYPES_H */

/* Define to 1 if you have the <sys/ioctl.h> header file. */
#define HAVE_SYS_IOCTL_H 1

/* Define to 1 if you have the <sys/mman.h> header file. */
#define HAVE_SYS_MMAN_H 1

/* Define to 1 if you have the <sys/param.h> header file. */
#define HAVE_SYS_PARAM_H 1

/* Define to 1 if you have the <sys/random.h> header file. */
#define HAVE_SYS_RANDOM_H 1

/* Define to 1 if you have the <sys/select.h> header file. */
#define HAVE_SYS_SELECT_H 1

/* Define to 1 if you have the <sys/single_threaded.h> header file. */
/* #undef HAVE_SYS_SINGLE_THREADED_H */

/* Define to 1 if you have the <sys/socket.h> header file. */
#define HAVE_SYS_SOCKET_H 1

/* Define to 1 if you have the <sys/stat.h> header file. */
#define HAVE_SYS_STAT_H 1

/* Define to 1 if you have the <sys/time.h> header file. */
#define HAVE_SYS_TIME_H 1

/* Define to 1 if you have the <sys/types.h> header file. */
#define HAVE_SYS_TYPES_H 1

/* Define to 1 if you have the <sys/uio.h> header file. */
#define HAVE_SYS_UIO_H 1

/* Define to 1 if you have the <sys/utime.h> header file. */
/* #undef HAVE_SYS_UTIME_H */

/* Define to 1 if you have the <sys/wait.h> header file. */
#define HAVE_SYS_WAIT_H 1

/* Define to 1 if the system has the 'tcgetattr' function. */
#define HAVE_TCGETATTR 1

/* Define to 1 if the system has the 'tcsetattr' function. */
#define HAVE_TCSETATTR 1

/* Define to 1 if you have the <termios.h> header file. */
#define HAVE_TERMIOS_H 1

/* Define to 1 if you have the `thrd_create' function. */
/* #undef HAVE_THRD_CREATE */

/* Define to 1 if you have the <threads.h> header file. */
#define HAVE_THREADS_H 1

/* Define to 1 if you have the `timegm' function. */
#define HAVE_TIMEGM 1

/* Define if struct tm has the tm_gmtoff member. */
#define HAVE_TM_GMTOFF 1

/* Define to 1 if you have the `towlower' function. */
#define HAVE_TOWLOWER 1

/* Define to 1 if the system has the type `uint32_t'. */
#define HAVE_UINT32_T 1

/* Define to 1 if the system has the type `uintptr_t'. */
#define HAVE_UINTPTR_T 1

/* Define to 1 if you have the <unistd.h> header file. */
#define HAVE_UNISTD_H 1

/* Define to 1 if the system has the type 'unsigned long long int'. */
#define HAVE_UNSIGNED_LONG_LONG_INT 1

/* Define to 1 if you have the `usleep' function. */
#define HAVE_USLEEP 1

/* Define to 1 if you have the `utime' function. */
#define HAVE_UTIME 1

/* Define to 1 if you have the `utimensat' function. */
#define HAVE_UTIMENSAT 1

/* Define to 1 if you have the <utime.h> header file. */
#define HAVE_UTIME_H 1

/* Define if uuid_create is available. */
/* #undef HAVE_UUID_CREATE */

/* Define if you have a global __progname variable */
/* #undef HAVE_VAR___PROGNAME */

/* Define to 1 if you have the `vasnprintf' function. */
/* #undef HAVE_VASNPRINTF */

/* Define to 1 if you have the `vasprintf' function. */
#define HAVE_VASPRINTF 1

/* Define to 1 if you have the `vfork' function. */
/* #undef HAVE_VFORK */

/* Define to 1 or 0, depending whether the compiler supports simple visibility
   declarations. */
/* #undef HAVE_VISIBILITY */

/* Define to 1 if you have the `vsnprintf' function. */
#define HAVE_VSNPRINTF 1

/* Define to 1 if you have the `waitid' function. */
#define HAVE_WAITID 1

/* Define to 1 if you have the <wchar.h> header file. */
#define HAVE_WCHAR_H 1

/* Define if you have the 'wchar_t' type. */
#define HAVE_WCHAR_T 1

/* Define to 1 if you have the `wcrtomb' function. */
#define HAVE_WCRTOMB 1

/* Define to 1 if you have the `wcslen' function. */
#define HAVE_WCSLEN 1

/* Define to 1 if you have the `wcsnlen' function. */
#define HAVE_WCSNLEN 1

/* Define to 1 if you have the <wctype.h> header file. */
#define HAVE_WCTYPE_H 1

/* Define to 1 if you have the `wcwidth' function. */
#define HAVE_WCWIDTH 1

/* Define to 1 if the compiler and linker support weak declarations of
   symbols. */
#define HAVE_WEAK_SYMBOLS 1

/* Define to 1 if you have the <winsock2.h> header file. */
/* #undef HAVE_WINSOCK2_H */

/* Define if you have the 'wint_t' type. */
#define HAVE_WINT_T 1

/* Define to 1 if you have the `wmempcpy' function. */
/* #undef HAVE_WMEMPCPY */

/* Define to 1 if fstatat (..., 0) works. For example, it does not work in AIX
   7.1. */
/* #undef HAVE_WORKING_FSTATAT_ZERO_FLAG */

/* Define to 1 if O_NOATIME works. */
#define HAVE_WORKING_O_NOATIME 0

/* Define to 1 if O_NOFOLLOW works. */
#define HAVE_WORKING_O_NOFOLLOW 0

/* Define if utimes works properly. */
/* #undef HAVE_WORKING_UTIMES */

/* Define to 1 if you have the <ws2tcpip.h> header file. */
/* #undef HAVE_WS2TCPIP_H */

/* Define to 1 if you have the <xlocale.h> header file. */
/* #undef HAVE_XLOCALE_H */

/* Define to 1 if the system has the type `_Bool'. */
#define HAVE__BOOL 1

/* Define to 1 if you have the `_fseeki64' function. */
/* #undef HAVE__FSEEKI64 */

/* Define to 1 if you have the `_ftelli64' function. */
/* #undef HAVE__FTELLI64 */

/* Define to 1 if you have the `_set_invalid_parameter_handler' function. */
/* #undef HAVE__SET_INVALID_PARAMETER_HANDLER */

/* Define to 1 if the compiler supports __builtin_expect,
   and to 2 if <builtins.h> does.  */
#define HAVE___BUILTIN_EXPECT 1
#ifndef HAVE___BUILTIN_EXPECT
# define __builtin_expect(e, c) (e)
#elif HAVE___BUILTIN_EXPECT == 2
# include <builtins.h>
#endif
    

/* Define to 1 if you have the `__fpurge' function. */
#define HAVE___FPURGE 1

/* Define to 1 if you have the `__freading' function. */
#define HAVE___FREADING 1

/* Define to 1 if you have the `__fsetlocking' function. */
#define HAVE___FSETLOCKING 1

/* Define to 1 if the compiler supports the keyword '__inline'. */
#define HAVE___INLINE 1

/* Define to 1 if you have the `__secure_getenv' function. */
/* #undef HAVE___SECURE_GETENV */

/* Define to 1 if you have the `__xpg_strerror_r' function. */
#define HAVE___XPG_STRERROR_R 1

/* Define as const if the declaration of iconv() needs const. */
#define ICONV_CONST 

/* Define to 1 if lseek does not detect pipes. */
/* #undef LSEEK_PIPE_BROKEN */

/* Define to 1 if 'lstat' dereferences a symlink specified with a trailing
   slash. */
#define LSTAT_FOLLOWS_SLASHED_SYMLINK 1

/* If malloc(0) is != NULL, define this to 1. Otherwise define this to 0. */
#define MALLOC_0_IS_NONNULL 1

/* Define to a substitute value for mmap()'s MAP_ANONYMOUS flag. */
/* #undef MAP_ANONYMOUS */

/* Define if the mbrtowc function does not return (size_t) -2 for empty input.
   */
#define MBRTOWC_EMPTY_INPUT_BUG 1

/* Define if the mbrtowc function may signal encoding errors in the C locale.
   */
#define MBRTOWC_IN_C_LOCALE_MAYBE_EILSEQ 1

/* Define if the mbrtowc function has the NULL pwc argument bug. */
/* #undef MBRTOWC_NULL_ARG1_BUG */

/* Define if the mbrtowc function has the NULL string argument bug. */
/* #undef MBRTOWC_NULL_ARG2_BUG */

/* Define if the mbrtowc function does not return 0 for a NUL character. */
/* #undef MBRTOWC_NUL_RETVAL_BUG */

/* Define if the mbrtowc function returns a wrong return value. */
/* #undef MBRTOWC_RETVAL_BUG */

/* Define if the mbrtowc function stores a wide character when reporting
   incomplete input. */
/* #undef MBRTOWC_STORES_INCOMPLETE_BUG */

/* Use GNU style printf and scanf.  */
#ifndef __USE_MINGW_ANSI_STDIO
# define __USE_MINGW_ANSI_STDIO 1
#endif


/* Define if the compilation of mktime.c should define 'mktime_internal'. */
#define NEED_MKTIME_INTERNAL 1

/* Define if the compilation of mktime.c should define 'mktime' with the
   native Windows TZ workaround. */
/* #undef NEED_MKTIME_WINDOWS */

/* Define if the compilation of mktime.c should define 'mktime' with the
   algorithmic workarounds. */
#define NEED_MKTIME_WORKING 1

/* Define to 1 if nl_langinfo is multithread-safe. */
#define NL_LANGINFO_MTSAFE 1

/* Define to 1 if open() fails to recognize a trailing slash. */
/* #undef OPEN_TRAILING_SLASH_BUG */

/* Define to be the name of the operating system. */
#define OS_TYPE "linux-gnu"

/* Name of package */
#define PACKAGE "wget"

/* Define to the address where bug reports for this package should be sent. */
#define PACKAGE_BUGREPORT "bug-wget@gnu.org"

/* Define to the full name of this package. */
#define PACKAGE_NAME "wget"

/* Define to the full name and version of this package. */
#define PACKAGE_STRING "wget 1.21.1"

/* Define to the one symbol short name of this package. */
#define PACKAGE_TARNAME "wget"

/* Define to the home page for this package. */
#define PACKAGE_URL ""

/* Define to the version of this package. */
#define PACKAGE_VERSION "1.21.1"

/* Define to the type that is the result of default argument promotions of
   type mode_t. */
#define PROMOTED_MODE_T mode_t

/* Define if the pthread_in_use() detection is hard. */
/* #undef PTHREAD_IN_USE_DETECTION_HARD */

/* Define to l, ll, u, ul, ull, etc., as suitable for constants of type
   'ptrdiff_t'. */
/* #undef PTRDIFF_T_SUFFIX */

/* Define to 1 if readlink fails to recognize a trailing slash. */
/* #undef READLINK_TRAILING_SLASH_BUG */

/* Define to 1 if readlink sets errno instead of truncating a too-long link.
   */
/* #undef READLINK_TRUNCATE_BUG */

/* Define to 1 if gnulib's dirfd() replacement is used. */
/* #undef REPLACE_DIRFD */

/* Define to 1 if gnulib's fchdir() replacement is used. */
/* #undef REPLACE_FCHDIR */

/* Define to 1 if stat needs help when passed a file name with a trailing
   slash */
/* #undef REPLACE_FUNC_STAT_FILE */

/* Define to 1 if utime needs help when passed a file name with a trailing
   slash */
/* #undef REPLACE_FUNC_UTIME_FILE */

/* Define if nl_langinfo exists but is overridden by gnulib. */
#define REPLACE_NL_LANGINFO 1

/* Define to 1 if open() should work around the inability to open a directory.
   */
/* #undef REPLACE_OPEN_DIRECTORY */

/* Define if gnulib uses its own posix_spawn and posix_spawnp functions. */
/* #undef REPLACE_POSIX_SPAWN */

/* Define to 1 if strerror(0) does not return a message implying success. */
/* #undef REPLACE_STRERROR_0 */

/* Define if vasnprintf exists but is overridden by gnulib. */
/* #undef REPLACE_VASNPRINTF */

/* Define to 1 if setlocale (LC_ALL, NULL) is multithread-safe. */
#define SETLOCALE_NULL_ALL_MTSAFE 1

/* Define to 1 if setlocale (category, NULL) is multithread-safe. */
#define SETLOCALE_NULL_ONE_MTSAFE 1

/* File name of the Bourne shell.  */
#if (defined _WIN32 && !defined __CYGWIN__) || defined __CYGWIN__ || defined __ANDROID__
/* Omit the directory part because
   - For native Windows programs in a Cygwin environment, the Cygwin mounts
     are not visible.
   - For 32-bit Cygwin programs in a 64-bit Cygwin environment, the Cygwin
     mounts are not visible.
   - On Android, /bin/sh does not exist. It's /system/bin/sh instead.  */
# define BOURNE_SHELL "sh"
#else
# define BOURNE_SHELL "/bin/sh"
#endif

/* Define to l, ll, u, ul, ull, etc., as suitable for constants of type
   'sig_atomic_t'. */
/* #undef SIG_ATOMIC_T_SUFFIX */

/* The size of `long', as computed by sizeof. */
#define SIZEOF_LONG 4

/* The size of `off_t', as computed by sizeof. */
#define SIZEOF_OFF_T 8

/* Define as the maximum value of type 'size_t', if the system doesn't define
   it. */
#ifndef SIZE_MAX
/* # undef SIZE_MAX */
#endif

/* Define to l, ll, u, ul, ull, etc., as suitable for constants of type
   'size_t'. */
/* #undef SIZE_T_SUFFIX */

/* If using the C implementation of alloca, define if you know the
   direction of stack growth for your system; otherwise it will be
   automatically deduced at runtime.
	STACK_DIRECTION > 0 => grows toward higher addresses
	STACK_DIRECTION < 0 => grows toward lower addresses
	STACK_DIRECTION = 0 => direction of growth unknown */
/* #undef STACK_DIRECTION */

/* Define to 1 if the `S_IS*' macros in <sys/stat.h> do not work properly. */
/* #undef STAT_MACROS_BROKEN */

/* Define to 1 if all of the C90 standard headers exist (not just the ones
   required in a freestanding environment). This macro is provided for
   backward compatibility; new code need not use it. */
#define STDC_HEADERS 1

/* Define to 1 if strerror_r returns char *. */
/* #undef STRERROR_R_CHAR_P */

/* Define to 1 if time_t is signed. */
#define TIME_T_IS_SIGNED 1

/* Define to 1 if the type of the st_atim member of a struct stat is struct
   timespec. */
#define TYPEOF_STRUCT_STAT_ST_ATIM_IS_STRUCT_TIMESPEC 1

/* Define to 1 if unlink() on a parent directory may succeed */
/* #undef UNLINK_PARENT_BUG */

/* Define to the prefix of C symbols at the assembler and linker level, either
   an underscore or empty. */
#define USER_LABEL_PREFIX 

/* Define if the combination of the ISO C and POSIX multithreading APIs can be
   used. */
/* #undef USE_ISOC_AND_POSIX_THREADS */

/* Define if the ISO C multithreading library can be used. */
/* #undef USE_ISOC_THREADS */

/* Define to 1 if you want to use the Linux kernel cryptographic API. */
#define USE_LINUX_CRYPTO_API 0

/* Define if the POSIX multithreading library can be used. */
#define USE_POSIX_THREADS 1

/* Define if references to the POSIX multithreading library should be made
   weak. */
#define USE_POSIX_THREADS_WEAK 1

/* Enable extensions on AIX 3, Interix.  */
#ifndef _ALL_SOURCE
# define _ALL_SOURCE 1
#endif
/* Enable general extensions on macOS.  */
#ifndef _DARWIN_C_SOURCE
# define _DARWIN_C_SOURCE 1
#endif
/* Enable general extensions on Solaris.  */
#ifndef __EXTENSIONS__
# define __EXTENSIONS__ 1
#endif
/* Enable GNU extensions on systems that have them.  */
#ifndef _GNU_SOURCE
# define _GNU_SOURCE 1
#endif
/* Enable X/Open compliant socket functions that do not require linking
   with -lxnet on HP-UX 11.11.  */
#ifndef _HPUX_ALT_XOPEN_SOCKET_API
# define _HPUX_ALT_XOPEN_SOCKET_API 1
#endif
/* Identify the host operating system as Minix.
   This macro does not affect the system headers' behavior.
   A future release of Autoconf may stop defining this macro.  */
#ifndef _MINIX
/* # undef _MINIX */
#endif
/* Enable general extensions on NetBSD.
   Enable NetBSD compatibility extensions on Minix.  */
#ifndef _NETBSD_SOURCE
# define _NETBSD_SOURCE 1
#endif
/* Enable OpenBSD compatibility extensions on NetBSD.
   Oddly enough, this does nothing on OpenBSD.  */
#ifndef _OPENBSD_SOURCE
# define _OPENBSD_SOURCE 1
#endif
/* Define to 1 if needed for POSIX-compatible behavior.  */
#ifndef _POSIX_SOURCE
/* # undef _POSIX_SOURCE */
#endif
/* Define to 2 if needed for POSIX-compatible behavior.  */
#ifndef _POSIX_1_SOURCE
/* # undef _POSIX_1_SOURCE */
#endif
/* Enable POSIX-compatible threading on Solaris.  */
#ifndef _POSIX_PTHREAD_SEMANTICS
# define _POSIX_PTHREAD_SEMANTICS 1
#endif
/* Enable extensions specified by ISO/IEC TS 18661-5:2014.  */
#ifndef __STDC_WANT_IEC_60559_ATTRIBS_EXT__
# define __STDC_WANT_IEC_60559_ATTRIBS_EXT__ 1
#endif
/* Enable extensions specified by ISO/IEC TS 18661-1:2014.  */
#ifndef __STDC_WANT_IEC_60559_BFP_EXT__
# define __STDC_WANT_IEC_60559_BFP_EXT__ 1
#endif
/* Enable extensions specified by ISO/IEC TS 18661-2:2015.  */
#ifndef __STDC_WANT_IEC_60559_DFP_EXT__
# define __STDC_WANT_IEC_60559_DFP_EXT__ 1
#endif
/* Enable extensions specified by ISO/IEC TS 18661-4:2015.  */
#ifndef __STDC_WANT_IEC_60559_FUNCS_EXT__
# define __STDC_WANT_IEC_60559_FUNCS_EXT__ 1
#endif
/* Enable extensions specified by ISO/IEC TS 18661-3:2015.  */
#ifndef __STDC_WANT_IEC_60559_TYPES_EXT__
# define __STDC_WANT_IEC_60559_TYPES_EXT__ 1
#endif
/* Enable extensions specified by ISO/IEC TR 24731-2:2010.  */
#ifndef __STDC_WANT_LIB_EXT2__
# define __STDC_WANT_LIB_EXT2__ 1
#endif
/* Enable extensions specified by ISO/IEC 24747:2009.  */
#ifndef __STDC_WANT_MATH_SPEC_FUNCS__
# define __STDC_WANT_MATH_SPEC_FUNCS__ 1
#endif
/* Enable extensions on HP NonStop.  */
#ifndef _TANDEM_SOURCE
# define _TANDEM_SOURCE 1
#endif
/* Enable X/Open extensions.  Define to 500 only if necessary
   to make mbstate_t available.  */
#ifndef _XOPEN_SOURCE
/* # undef _XOPEN_SOURCE */
#endif


/* Define to 1 if you want getc etc. to use unlocked I/O if available.
   Unlocked I/O can improve performance in unithreaded apps, but it is not
   safe for multithreaded apps. */
#define USE_UNLOCKED_IO 1

/* Define if the native Windows multithreading API can be used. */
/* #undef USE_WINDOWS_THREADS */

/* Version number of package */
#define VERSION "1.21.1"

/* Define to l, ll, u, ul, ull, etc., as suitable for constants of type
   'wchar_t'. */
/* #undef WCHAR_T_SUFFIX */

/* Define if the wcrtomb function does not work in the C locale. */
/* #undef WCRTOMB_C_LOCALE_BUG */

/* Define if the wcrtomb function has an incorrect return value. */
/* #undef WCRTOMB_RETVAL_BUG */

/* Define if WSAStartup is needed. */
/* #undef WINDOWS_SOCKETS */

/* Define to l, ll, u, ul, ull, etc., as suitable for constants of type
   'wint_t'. */
/* #undef WINT_T_SUFFIX */

/* Define WORDS_BIGENDIAN to 1 if your processor stores words with the most
   significant byte first (like Motorola and SPARC, unlike Intel). */
#if defined AC_APPLE_UNIVERSAL_BUILD
# if defined __BIG_ENDIAN__
#  define WORDS_BIGENDIAN 1
# endif
#else
# ifndef WORDS_BIGENDIAN
/* #  undef WORDS_BIGENDIAN */
# endif
#endif

/* Define to 1 if `lex' declares `yytext' as a `char *' by default, not a
   `char[]'. */
#define YYTEXT_POINTER 1

/* Number of bits in a file offset, on hosts where this is settable. */
/* #undef _FILE_OFFSET_BITS */

/* True if the compiler says it groks GNU C version MAJOR.MINOR.  */
#if defined __GNUC__ && defined __GNUC_MINOR__
# define _GL_GNUC_PREREQ(major, minor) \
    ((major) < __GNUC__ + ((minor) <= __GNUC_MINOR__))
#else
# define _GL_GNUC_PREREQ(major, minor) 0
#endif


/* Define to enable the declarations of ISO C 11 types and functions. */
/* #undef _ISOC11_SOURCE */

/* Define to 1 to make fseeko visible on some hosts (e.g. glibc 2.2). */
/* #undef _LARGEFILE_SOURCE */

/* Define for large files, on AIX-style hosts. */
/* #undef _LARGE_FILES */

/* Define to 1 on Solaris. */
/* #undef _LCONV_C99 */

/* The _Noreturn keyword of C11.  */
#ifndef _Noreturn
# if (defined __cplusplus \
      && ((201103 <= __cplusplus && !(__GNUC__ == 4 && __GNUC_MINOR__ == 7)) \
          || (defined _MSC_VER && 1900 <= _MSC_VER)) \
      && 0)
    /* [[noreturn]] is not practically usable, because with it the syntax
         extern _Noreturn void func (...);
       would not be valid; such a declaration would only be valid with 'extern'
       and '_Noreturn' swapped, or without the 'extern' keyword.  However, some
       AIX system header files and several gnulib header files use precisely
       this syntax with 'extern'.  */
#  define _Noreturn [[noreturn]]
# elif ((!defined __cplusplus || defined __clang__) \
        && (201112 <= (defined __STDC_VERSION__ ? __STDC_VERSION__ : 0)  \
            || _GL_GNUC_PREREQ (4, 7) \
            || (defined __apple_build_version__ \
                ? 6000000 <= __apple_build_version__ \
                : 3 < __clang_major__ + (5 <= __clang_minor__))))
   /* _Noreturn works as-is.  */
# elif _GL_GNUC_PREREQ (2, 8) || defined __clang__ || 0x5110 <= __SUNPRO_C
#  define _Noreturn __attribute__ ((__noreturn__))
# elif 1200 <= (defined _MSC_VER ? _MSC_VER : 0)
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn
# endif
#endif


/* Define to 1 in order to get the POSIX compatible declarations of socket
   functions. */
/* #undef _POSIX_PII_SOCKET */

/* Define if you want <regex.h> to include <limits.h>, so that it consistently
   overrides <limits.h>'s RE_DUP_MAX. */
#define _REGEX_INCLUDE_LIMITS_H 1

/* Define if you want regoff_t to be at least as wide POSIX requires. */
#define _REGEX_LARGE_OFFSETS 1

/* For standard stat data types on VMS. */
#define _USE_STD_STAT 1

/* Define to rpl_ if the getopt replacement functions and variables should be
   used. */
#define __GETOPT_PREFIX rpl_

/* Define to 1 if the system <stdint.h> predates C++11. */
/* #undef __STDC_CONSTANT_MACROS */

/* Define to 1 if the system <stdint.h> predates C++11. */
/* #undef __STDC_LIMIT_MACROS */

/* The _GL_ASYNC_SAFE marker should be attached to functions that are
   signal handlers (for signals other than SIGABRT, SIGPIPE) or can be
   invoked from such signal handlers.  Such functions have some restrictions:
     * All functions that it calls should be marked _GL_ASYNC_SAFE as well,
       or should be listed as async-signal-safe in POSIX
       <https://pubs.opengroup.org/onlinepubs/9699919799/functions/V2_chap02.html#tag_15_04>
       section 2.4.3.  Note that malloc(), sprintf(), and fwrite(), in
       particular, are NOT async-signal-safe.
     * All memory locations (variables and struct fields) that these functions
       access must be marked 'volatile'.  This holds for both read and write
       accesses.  Otherwise the compiler might optimize away stores to and
       reads from such locations that occur in the program, depending on its
       data flow analysis.  For example, when the program contains a loop
       that is intended to inspect a variable set from within a signal handler
           while (!signal_occurred)
             ;
       the compiler is allowed to transform this into an endless loop if the
       variable 'signal_occurred' is not declared 'volatile'.
   Additionally, recall that:
     * A signal handler should not modify errno (except if it is a handler
       for a fatal signal and ends by raising the same signal again, thus
       provoking the termination of the process).  If it invokes a function
       that may clobber errno, it needs to save and restore the value of
       errno.  */
#define _GL_ASYNC_SAFE


/* Attributes.  */
#ifdef __has_attribute
# define _GL_HAS_ATTRIBUTE(attr) __has_attribute (__##attr##__)
#else
# define _GL_HAS_ATTRIBUTE(attr) _GL_ATTR_##attr
# define _GL_ATTR_alloc_size _GL_GNUC_PREREQ (4, 3)
# define _GL_ATTR_always_inline _GL_GNUC_PREREQ (3, 2)
# define _GL_ATTR_artificial _GL_GNUC_PREREQ (4, 3)
# define _GL_ATTR_cold _GL_GNUC_PREREQ (4, 3)
# define _GL_ATTR_const _GL_GNUC_PREREQ (2, 95)
# define _GL_ATTR_deprecated _GL_GNUC_PREREQ (3, 1)
# define _GL_ATTR_diagnose_if 0
# define _GL_ATTR_error _GL_GNUC_PREREQ (4, 3)
# define _GL_ATTR_externally_visible _GL_GNUC_PREREQ (4, 1)
# define _GL_ATTR_fallthrough _GL_GNUC_PREREQ (7, 0)
# define _GL_ATTR_format _GL_GNUC_PREREQ (2, 7)
# define _GL_ATTR_leaf _GL_GNUC_PREREQ (4, 6)
# ifdef _ICC
#  define _GL_ATTR_may_alias 0
# else
#  define _GL_ATTR_may_alias _GL_GNUC_PREREQ (3, 3)
# endif
# define _GL_ATTR_malloc _GL_GNUC_PREREQ (3, 0)
# define _GL_ATTR_noinline _GL_GNUC_PREREQ (3, 1)
# define _GL_ATTR_nonnull _GL_GNUC_PREREQ (3, 3)
# define _GL_ATTR_nonstring _GL_GNUC_PREREQ (8, 0)
# define _GL_ATTR_nothrow _GL_GNUC_PREREQ (3, 3)
# define _GL_ATTR_packed _GL_GNUC_PREREQ (2, 7)
# define _GL_ATTR_pure _GL_GNUC_PREREQ (2, 96)
# define _GL_ATTR_returns_nonnull _GL_GNUC_PREREQ (4, 9)
# define _GL_ATTR_sentinel _GL_GNUC_PREREQ (4, 0)
# define _GL_ATTR_unused _GL_GNUC_PREREQ (2, 7)
# define _GL_ATTR_warn_unused_result _GL_GNUC_PREREQ (3, 4)
#endif


#if _GL_HAS_ATTRIBUTE (alloc_size)
# define _GL_ATTRIBUTE_ALLOC_SIZE(args) __attribute__ ((__alloc_size__ args))
#else
# define _GL_ATTRIBUTE_ALLOC_SIZE(args)
#endif

#if _GL_HAS_ATTRIBUTE (always_inline)
# define _GL_ATTRIBUTE_ALWAYS_INLINE __attribute__ ((__always_inline__))
#else
# define _GL_ATTRIBUTE_ALWAYS_INLINE
#endif

#if _GL_HAS_ATTRIBUTE (artificial)
# define _GL_ATTRIBUTE_ARTIFICIAL __attribute__ ((__artificial__))
#else
# define _GL_ATTRIBUTE_ARTIFICIAL
#endif

/* Avoid __attribute__ ((cold)) on MinGW; see thread starting at
   <https://lists.gnu.org/r/emacs-devel/2019-04/msg01152.html>.
   Also, Oracle Studio 12.6 requires 'cold' not '__cold__'.  */
#if _GL_HAS_ATTRIBUTE (cold) && !defined __MINGW32__
# ifndef __SUNPRO_C
#  define _GL_ATTRIBUTE_COLD __attribute__ ((__cold__))
# else
#  define _GL_ATTRIBUTE_COLD __attribute__ ((cold))
# endif
#else
# define _GL_ATTRIBUTE_COLD
#endif

#if _GL_HAS_ATTRIBUTE (const)
# define _GL_ATTRIBUTE_CONST __attribute__ ((__const__))
#else
# define _GL_ATTRIBUTE_CONST
#endif

#if 201710L < __STDC_VERSION__
# define _GL_ATTRIBUTE_DEPRECATED [[__deprecated__]]
#elif _GL_HAS_ATTRIBUTE (deprecated)
# define _GL_ATTRIBUTE_DEPRECATED __attribute__ ((__deprecated__))
#else
# define _GL_ATTRIBUTE_DEPRECATED
#endif

#if _GL_HAS_ATTRIBUTE (error)
# define _GL_ATTRIBUTE_ERROR(msg) __attribute__ ((__error__ (msg)))
# define _GL_ATTRIBUTE_WARNING(msg) __attribute__ ((__warning__ (msg)))
#elif _GL_HAS_ATTRIBUTE (diagnose_if)
# define _GL_ATTRIBUTE_ERROR(msg) __attribute__ ((__diagnose_if__ (1, msg, "error")))
# define _GL_ATTRIBUTE_WARNING(msg) __attribute__ ((__diagnose_if__ (1, msg, "warning")))
#else
# define _GL_ATTRIBUTE_ERROR(msg)
# define _GL_ATTRIBUTE_WARNING(msg)
#endif

#if _GL_HAS_ATTRIBUTE (externally_visible)
# define _GL_ATTRIBUTE_EXTERNALLY_VISIBLE __attribute__ ((externally_visible))
#else
# define _GL_ATTRIBUTE_EXTERNALLY_VISIBLE
#endif

/* FALLTHROUGH is special, because it always expands to something.  */
#if 201710L < __STDC_VERSION__
# define _GL_ATTRIBUTE_FALLTHROUGH [[__fallthrough__]]
#elif _GL_HAS_ATTRIBUTE (fallthrough)
# define _GL_ATTRIBUTE_FALLTHROUGH __attribute__ ((__fallthrough__))
#else
# define _GL_ATTRIBUTE_FALLTHROUGH ((void) 0)
#endif

#if _GL_HAS_ATTRIBUTE (format)
# define _GL_ATTRIBUTE_FORMAT(spec) __attribute__ ((__format__ spec))
#else
# define _GL_ATTRIBUTE_FORMAT(spec)
#endif

#if _GL_HAS_ATTRIBUTE (leaf)
# define _GL_ATTRIBUTE_LEAF __attribute__ ((__leaf__))
#else
# define _GL_ATTRIBUTE_LEAF
#endif

/* Oracle Studio 12.6 mishandles may_alias despite __has_attribute OK.  */
#if _GL_HAS_ATTRIBUTE (may_alias) && !defined __SUNPRO_C
# define _GL_ATTRIBUTE_MAY_ALIAS __attribute__ ((__may_alias__))
#else
# define _GL_ATTRIBUTE_MAY_ALIAS
#endif

#if 201710L < __STDC_VERSION__
# define _GL_ATTRIBUTE_MAYBE_UNUSED [[__maybe_unused__]]
#elif _GL_HAS_ATTRIBUTE (unused)
# define _GL_ATTRIBUTE_MAYBE_UNUSED __attribute__ ((__unused__))
#else
# define _GL_ATTRIBUTE_MAYBE_UNUSED
#endif
/* Earlier spellings of this macro.  */
#define _GL_UNUSED _GL_ATTRIBUTE_MAYBE_UNUSED
#define _UNUSED_PARAMETER_ _GL_ATTRIBUTE_MAYBE_UNUSED

#if _GL_HAS_ATTRIBUTE (malloc)
# define _GL_ATTRIBUTE_MALLOC __attribute__ ((__malloc__))
#else
# define _GL_ATTRIBUTE_MALLOC
#endif

#if 201710L < __STDC_VERSION__
# define _GL_ATTRIBUTE_NODISCARD [[__nodiscard__]]
#elif _GL_HAS_ATTRIBUTE (warn_unused_result)
# define _GL_ATTRIBUTE_NODISCARD __attribute__ ((__warn_unused_result__))
#else
# define _GL_ATTRIBUTE_NODISCARD
#endif

#if _GL_HAS_ATTRIBUTE (noinline)
# define _GL_ATTRIBUTE_NOINLINE __attribute__ ((__noinline__))
#else
# define _GL_ATTRIBUTE_NOINLINE
#endif

#if _GL_HAS_ATTRIBUTE (nonnull)
# define _GL_ATTRIBUTE_NONNULL(args) __attribute__ ((__nonnull__ args))
#else
# define _GL_ATTRIBUTE_NONNULL(args)
#endif

#if _GL_HAS_ATTRIBUTE (nonstring)
# define _GL_ATTRIBUTE_NONSTRING __attribute__ ((__nonstring__))
#else
# define _GL_ATTRIBUTE_NONSTRING
#endif

/* There is no _GL_ATTRIBUTE_NORETURN; use _Noreturn instead.  */

#if _GL_HAS_ATTRIBUTE (nothrow) && !defined __cplusplus
# define _GL_ATTRIBUTE_NOTHROW __attribute__ ((__nothrow__))
#else
# define _GL_ATTRIBUTE_NOTHROW
#endif

#if _GL_HAS_ATTRIBUTE (packed)
# define _GL_ATTRIBUTE_PACKED __attribute__ ((__packed__))
#else
# define _GL_ATTRIBUTE_PACKED
#endif

#if _GL_HAS_ATTRIBUTE (pure)
# define _GL_ATTRIBUTE_PURE __attribute__ ((__pure__))
#else
# define _GL_ATTRIBUTE_PURE
#endif

#if _GL_HAS_ATTRIBUTE (returns_nonnull)
# define _GL_ATTRIBUTE_RETURNS_NONNULL __attribute__ ((__returns_nonnull__))
#else
# define _GL_ATTRIBUTE_RETURNS_NONNULL
#endif

#if _GL_HAS_ATTRIBUTE (sentinel)
# define _GL_ATTRIBUTE_SENTINEL(pos) __attribute__ ((__sentinel__ pos))
#else
# define _GL_ATTRIBUTE_SENTINEL(pos)
#endif


/* To support C++ as well as C, use _GL_UNUSED_LABEL with trailing ';'.  */
#if !defined __cplusplus || _GL_GNUC_PREREQ (4, 5)
# define _GL_UNUSED_LABEL _GL_ATTRIBUTE_MAYBE_UNUSED
#else
# define _GL_UNUSED_LABEL
#endif


/* Define to empty if `const' does not conform to ANSI C. */
/* #undef const */

/* Define as 'access' if you don't have the eaccess() function. */
/* #undef eaccess */

/* Please see the Gnulib manual for how to use these macros.

   Suppress extern inline with HP-UX cc, as it appears to be broken; see
   <http://lists.gnu.org/archive/html/bug-texinfo/2013-02/msg00030.html>.

   Suppress extern inline with Sun C in standards-conformance mode, as it
   mishandles inline functions that call each other.  E.g., for 'inline void f
   (void) { } inline void g (void) { f (); }', c99 incorrectly complains
   'reference to static identifier "f" in extern inline function'.
   This bug was observed with Sun C 5.12 SunOS_i386 2011/11/16.

   Suppress extern inline (with or without __attribute__ ((__gnu_inline__)))
   on configurations that mistakenly use 'static inline' to implement
   functions or macros in standard C headers like <ctype.h>.  For example,
   if isdigit is mistakenly implemented via a static inline function,
   a program containing an extern inline function that calls isdigit
   may not work since the C standard prohibits extern inline functions
   from calling static functions.  This bug is known to occur on:

     OS X 10.8 and earlier; see:
     http://lists.gnu.org/archive/html/bug-gnulib/2012-12/msg00023.html

     DragonFly; see
     http://muscles.dragonflybsd.org/bulk/bleeding-edge-potential/latest-per-pkg/ah-tty-0.3.12.log

     FreeBSD; see:
     http://lists.gnu.org/archive/html/bug-gnulib/2014-07/msg00104.html

   OS X 10.9 has a macro __header_inline indicating the bug is fixed for C and
   for clang but remains for g++; see <http://trac.macports.org/ticket/41033>.
   Assume DragonFly and FreeBSD will be similar.  */
#if (((defined __APPLE__ && defined __MACH__) \
      || defined __DragonFly__ || defined __FreeBSD__) \
     && (defined __header_inline \
         ? (defined __cplusplus && defined __GNUC_STDC_INLINE__ \
            && ! defined __clang__) \
         : ((! defined _DONT_USE_CTYPE_INLINE_ \
             && (defined __GNUC__ || defined __cplusplus)) \
            || (defined _FORTIFY_SOURCE && 0 < _FORTIFY_SOURCE \
                && defined __GNUC__ && ! defined __cplusplus))))
# define _GL_EXTERN_INLINE_STDHEADER_BUG
#endif
#if ((__GNUC__ \
      ? defined __GNUC_STDC_INLINE__ && __GNUC_STDC_INLINE__ \
      : (199901L <= __STDC_VERSION__ \
         && !defined __HP_cc \
         && !(defined __SUNPRO_C && __STDC__))) \
     && !defined _GL_EXTERN_INLINE_STDHEADER_BUG)
# define _GL_INLINE inline
# define _GL_EXTERN_INLINE extern inline
# define _GL_EXTERN_INLINE_IN_USE
#elif (2 < __GNUC__ + (7 <= __GNUC_MINOR__) && !defined __STRICT_ANSI__ \
       && !defined _GL_EXTERN_INLINE_STDHEADER_BUG)
# if defined __GNUC_GNU_INLINE__ && __GNUC_GNU_INLINE__
   /* __gnu_inline__ suppresses a GCC 4.2 diagnostic.  */
#  define _GL_INLINE extern inline __attribute__ ((__gnu_inline__))
# else
#  define _GL_INLINE extern inline
# endif
# define _GL_EXTERN_INLINE extern
# define _GL_EXTERN_INLINE_IN_USE
#else
# define _GL_INLINE static _GL_UNUSED
# define _GL_EXTERN_INLINE static _GL_UNUSED
#endif

#if 4 < __GNUC__ + (6 <= __GNUC_MINOR__)
# if defined __GNUC_STDC_INLINE__ && __GNUC_STDC_INLINE__
#  define _GL_INLINE_HEADER_CONST_PRAGMA
# else
#  define _GL_INLINE_HEADER_CONST_PRAGMA \
     _Pragma ("GCC diagnostic ignored \"-Wsuggest-attribute=const\"")
# endif
  /* Suppress GCC's bogus "no previous prototype for 'FOO'"
     and "no previous declaration for 'FOO'"  diagnostics,
     when FOO is an inline function in the header; see
     <http://gcc.gnu.org/bugzilla/show_bug.cgi?id=54113>.  */
# define _GL_INLINE_HEADER_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wmissing-prototypes\"") \
    _Pragma ("GCC diagnostic ignored \"-Wmissing-declarations\"") \
    _GL_INLINE_HEADER_CONST_PRAGMA
# define _GL_INLINE_HEADER_END \
    _Pragma ("GCC diagnostic pop")
#else
# define _GL_INLINE_HEADER_BEGIN
# define _GL_INLINE_HEADER_END
#endif

/* Define to `int' if <sys/types.h> doesn't define. */
/* #undef gid_t */

/* Define to `__inline__' or `__inline' if that's what the C compiler
   calls it, or to nothing if 'inline' is not supported under any name.  */
#ifndef __cplusplus
/* #undef inline */
#endif

/* Define to long or long long if <stdint.h> and <inttypes.h> don't define. */
/* #undef intmax_t */

/* Work around a bug in Apple GCC 4.0.1 build 5465: In C99 mode, it supports
   the ISO C 99 semantics of 'extern inline' (unlike the GNU C semantics of
   earlier versions), but does not display it by setting __GNUC_STDC_INLINE__.
   __APPLE__ && __MACH__ test for Mac OS X.
   __APPLE_CC__ tests for the Apple compiler and its version.
   __STDC_VERSION__ tests for the C99 mode.  */
#if defined __APPLE__ && defined __MACH__ && __APPLE_CC__ >= 5465 && !defined __cplusplus && __STDC_VERSION__ >= 199901L && !defined __GNUC_STDC_INLINE__
# define __GNUC_STDC_INLINE__ 1
#endif

/* Define to a type if <wchar.h> does not define. */
/* #undef mbstate_t */

/* _GL_CMP (n1, n2) performs a three-valued comparison on n1 vs. n2, where
   n1 and n2 are expressions without side effects, that evaluate to real
   numbers (excluding NaN).
   It returns
     1  if n1 > n2
     0  if n1 == n2
     -1 if n1 < n2
   The naïve code   (n1 > n2 ? 1 : n1 < n2 ? -1 : 0)  produces a conditional
   jump with nearly all GCC versions up to GCC 10.
   This variant     (n1 < n2 ? -1 : n1 > n2)  produces a conditional with many
   GCC versions up to GCC 9.
   The better code  (n1 > n2) - (n1 < n2)  from Hacker's Delight § 2-9
   avoids conditional jumps in all GCC versions >= 3.4.  */
#define _GL_CMP(n1, n2) (((n1) > (n2)) - ((n1) < (n2)))


/* Define to the real name of the mktime_internal function. */
/* #undef mktime_internal */

/* Define to `int' if <sys/types.h> does not define. */
/* #undef mode_t */

/* Define to the type of st_nlink in struct stat, or a supertype. */
/* #undef nlink_t */

/* Define as a signed integer type capable of holding a process identifier. */
/* #undef pid_t */

/* Define as the type of the result of subtracting two pointers, if the system
   doesn't define it. */
/* #undef ptrdiff_t */

/* Define to rpl_re_comp if the replacement should be used. */
#define re_comp rpl_re_comp

/* Define to rpl_re_compile_fastmap if the replacement should be used. */
#define re_compile_fastmap rpl_re_compile_fastmap

/* Define to rpl_re_compile_pattern if the replacement should be used. */
#define re_compile_pattern rpl_re_compile_pattern

/* Define to rpl_re_exec if the replacement should be used. */
#define re_exec rpl_re_exec

/* Define to rpl_re_match if the replacement should be used. */
#define re_match rpl_re_match

/* Define to rpl_re_match_2 if the replacement should be used. */
#define re_match_2 rpl_re_match_2

/* Define to rpl_re_search if the replacement should be used. */
#define re_search rpl_re_search

/* Define to rpl_re_search_2 if the replacement should be used. */
#define re_search_2 rpl_re_search_2

/* Define to rpl_re_set_registers if the replacement should be used. */
#define re_set_registers rpl_re_set_registers

/* Define to rpl_re_set_syntax if the replacement should be used. */
#define re_set_syntax rpl_re_set_syntax

/* Define to rpl_re_syntax_options if the replacement should be used. */
#define re_syntax_options rpl_re_syntax_options

/* Define to rpl_regcomp if the replacement should be used. */
#define regcomp rpl_regcomp

/* Define to rpl_regerror if the replacement should be used. */
#define regerror rpl_regerror

/* Define to rpl_regexec if the replacement should be used. */
#define regexec rpl_regexec

/* Define to rpl_regfree if the replacement should be used. */
#define regfree rpl_regfree

/* Define to the equivalent of the C99 'restrict' keyword, or to
   nothing if this is not supported.  Do not define if restrict is
   supported only directly.  */
#define restrict __restrict__
/* Work around a bug in older versions of Sun C++, which did not
   #define __restrict__ or support _Restrict or __restrict__
   even though the corresponding Sun C compiler ended up with
   "#define restrict _Restrict" or "#define restrict __restrict__"
   in the previous line.  This workaround can be removed once
   we assume Oracle Developer Studio 12.5 (2016) or later.  */
#if defined __SUNPRO_CC && !defined __RESTRICT && !defined __restrict__
# define _Restrict
# define __restrict__
#endif

/* Define as an integer type suitable for memory locations that can be
   accessed atomically even in the presence of asynchronous signals. */
/* #undef sig_atomic_t */

/* Define to `unsigned int' if <sys/types.h> does not define. */
/* #undef size_t */

/* type to use in place of socklen_t if not defined */
/* #undef socklen_t */

/* Define as a signed type of the same size as size_t. */
/* #undef ssize_t */

/* Define to `int' if <sys/types.h> doesn't define. */
/* #undef uid_t */

/* Define to empty if the keyword `volatile' does not work. Warning: valid
   code using `volatile' can become incorrect without. Disable with care. */
/* #undef volatile */
