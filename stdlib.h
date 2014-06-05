/* Copyright (c) Microsoft Corporation. All rights reserved. */
/***
 * stdlib.h - declarations/definitions for commonly used library functions
 *
 * Purpose:
 *      Required library functions as per ANSI C.
 * BUGBUG:
 *      Incomplete
 *
 ***/

#ifndef _INC_STDLIB
#define _INC_STDLIB

#define __NEEDS_SIZE_T 1
#define __NEEDS_WCHAR_T 1
#define __NEEDS_EXTERN_C 1
#include <__defs.h>

#include <sal.h>

/* missing div_t, ldiv_t */

/* Definition of the argument values for the exit() function */

#define EXIT_SUCCESS    0
#define EXIT_FAILURE    1

#define RAND_MAX 32767

/* missing MB_CUR_MAX */

#ifndef _STRICT_ISO_COMPLIANCE
/* Minimum and maximum macros */
#define __max(a,b)  (((a) > (b)) ? (a) : (b))
#define __min(a,b)  (((a) < (b)) ? (a) : (b))
#endif

/* Function prototypes */

/* missing atof, atol, strtod, */
EXTERN_C int __cdecl atoi(const char *);
EXTERN_C INT32 __cdecl strtol(const char *nptr, char **endptr, int base);
EXTERN_C UINT32 __cdecl strtoul(const char *nptr, char **endptr, int base);
#ifndef _STRICT_ISO_COMPLIANCE
EXTERN_C INT64 __cdecl _atoi64(const char *);
EXTERN_C INT64 __cdecl _strtoi64(const char *nptr, char **endptr, INT base);
EXTERN_C UINT64 __cdecl _strtoui64(const char *nptr, char **endptr, INT base);
EXTERN_C UINT __cdecl atoh(const char *); /* non-ISO */
#endif

/* 7.10.2 pag 153 "Pseudo-random sequence generation functions */
EXTERN_C int __cdecl rand(void);
EXTERN_C void __cdecl srand(unsigned int seed);

EXTERN_C void * __cdecl calloc(size_t num, size_t size);
EXTERN_C void __cdecl free(_In_opt_ void *);
EXTERN_C void * __cdecl malloc(_In_ size_t size);
EXTERN_C void * __cdecl realloc(void *ptr, size_t size);

/* missing abort */
EXTERN_C int __cdecl atexit(void (__cdecl *)(void));
EXTERN_C void __cdecl exit(INT);
/*missing getenv, system, bsearch, qsort */

EXTERN_C int __cdecl abs(int);
/* missing div, labs, ldiv */

/* missing mblen, mbtowc, wctomb */
EXTERN_C size_t __cdecl mbstowcs(wchar_t *wcstr, const char *mbstr, size_t count);
/* missing wcstombs */

#endif  /* _INC_STDLIB */
