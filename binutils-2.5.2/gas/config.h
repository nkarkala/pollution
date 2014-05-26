/* config.h.  Generated automatically by make.  */
#ifndef GAS_VERSION
#define GAS_VERSION "2.5.2"

/* conf.  Generated automatically by configure.  */
/* conf.in.  Generated automatically from configure.in by autoheader.  */

/* Define if using alloca.c.  */
/* #undef C_ALLOCA */

/* Define to one of _getb67, GETB67, getb67 for Cray-2 and Cray-YMP systems.
   This function is required for alloca.c support on those systems.  */
/* #undef CRAY_STACKSEG_END */

/* Define if you have alloca, as a function or macro.  */
#define HAVE_ALLOCA 1

/* Define if you have <alloca.h> and it should be used (not on Ultrix).  */
#define HAVE_ALLOCA_H 1

/* Define as __inline if that's what the C compiler calls it.  */
/* #undef inline */

/* If using the C implementation of alloca, define if you know the
   direction of stack growth for your system; otherwise it will be
   automatically deduced at run-time.
	STACK_DIRECTION > 0 => grows toward higher addresses
	STACK_DIRECTION < 0 => grows toward lower addresses
	STACK_DIRECTION = 0 => direction of growth unknown
 */
/* #undef STACK_DIRECTION */

/* Should gas use high-level BFD interfaces?  */
#define BFD_ASSEMBLER 1

/* Some assert/preprocessor combinations are incapable of handling
   certain kinds of constructs in the argument of assert.  For example,
   quoted strings (if requoting isn't done right) or newlines.  */
/* #undef BROKEN_ASSERT */

/* If we aren't doing cross-assembling, some operations can be optimized,
   since byte orders and value sizes don't need to be adjusted.  */
#define CROSS_COMPILE 1

/* Some gas code wants to know these parameters.  */
#define TARGET_ALIAS "sslittle-na-sstrix"
#define TARGET_CPU "sslittle"
#define TARGET_CANONICAL "sslittle-na-sstrix"
#define TARGET_OS "sstrix"
#define TARGET_VENDOR "na"

/* Sometimes the system header files don't declare malloc and realloc.  */
/* #undef NEED_DECLARATION_MALLOC */

/* Sometimes the system header files don't declare free.  */
/* #undef NEED_DECLARATION_FREE */

/* Sometimes errno.h doesn't declare errno itself.  */
/* #undef NEED_DECLARATION_ERRNO */

/* #undef MANY_SEGMENTS */

/* Needed only for sparc configuration */
/* #undef sparcv9 */

/* Define if you have the remove function.  */
/* #undef HAVE_REMOVE */

/* Define if you have the unlink function.  */
#define HAVE_UNLINK 1

/* Define if you have the <errno.h> header file.  */
#define HAVE_ERRNO_H 1

/* Define if you have the <memory.h> header file.  */
#define HAVE_MEMORY_H 1

/* Define if you have the <stdarg.h> header file.  */
#define HAVE_STDARG_H 1

/* Define if you have the <stdlib.h> header file.  */
#define HAVE_STDLIB_H 1

/* Define if you have the <string.h> header file.  */
#define HAVE_STRING_H 1

/* Define if you have the <strings.h> header file.  */
#define HAVE_STRINGS_H 1

/* Define if you have the <sys/types.h> header file.  */
#define HAVE_SYS_TYPES_H 1

/* Define if you have the <unistd.h> header file.  */
#define HAVE_UNISTD_H 1

/* Define if you have the <varargs.h> header file.  */
/* #undef HAVE_VARARGS_H */
#endif /* GAS_VERSION */
