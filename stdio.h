/* Copyright (c) Microsoft Corporation. All rights reserved. */
/***
 * stdio.h - definitions/declarations for standard I/O routines
 *
 * Purpose:
 *      This file defines the structures, values, macros, and functions
 *      used by the level 2 I/O ("standard I/O") routines.
 * Reference:
 *      ISO/IEC 9899 : 1990 (E) "Programming languages -- C "
 *      Section 7.9 "Input/output <stdio.h>" pagg 124.
 *
 ***/

#ifndef _INC_STDIO
#define _INC_STDIO

#define __NEEDS_SIZE_T 1
#define __NEEDS_EXTERN_C 1
#define __NEEDS_NULL 1
#include <__defs.h>

/* FILE type and predefined file handles
 */
typedef struct _FILE FILE, *PFILE;

EXTERN_C FILE * __cdecl __stdfile(int);
#define stdin  (__stdfile(0))
#define stdout (__stdfile(1))
#define stderr (__stdfile(2))

/* File position
 */
typedef UINT64 fpos_t;

/* Constants for setvbuf
 */
#define _IOFBF  0
#define _IOLBF  1
#define _IONBF  2

/* Implied by setbuf
 */
#define BUFSIZ 1024

/* No more input on stream
 */
#define EOF (-1)

/* Guaranteed simultaneous open files
 */
#define FOPEN_MAX 64

/* Recommended size of a char (not wchar) array for filenames
 */
#define FILENAME_MAX 256

/* Minimum size of a char (not wchar) array for use with tmpnam
 */
#define L_tmpnam FILENAME_MAX

/* Minimum number of unique filenames from tmpnam
 */
#define TMP_MAX (26*26)

/* Seek method constants
 */
#define SEEK_CUR    1
#define SEEK_END    2
#define SEEK_SET    0


#if 0

/* Function prototypes, exactly as they appear in the standard
 */
/* SECTION 7.9.4 pagg 127
 */

/* returns 0 iff success */
int remove(const char *filename);

/* returns 0 iff success */
int rename(const char *old, const char *new);

/* returns NULL iff failure */
FILE *tmpfile(void);

/* (interpretation) returns NULL iff failure */
char *tmpnam(char *s);

/* SECTION 7.9.5 pagg 128
 */

/* returns 0 if success, EOF if failure */
int fclose(FILE *stream);

/* returns 0 if success, EOF if failure */
int fflush(FILE *stream);

/* returns NULL iff failure */
FILE *fopen(const char *filename,
            const char *mode);

/* returns NULL iff failure */
FILE *freopen(const char *filename,
              const char *mode,
              FILE *stream);

/* no return value */
void setbuf(FILE *stream,
            char *buf);

/* returns 0 iff success */
int setvbuf(FILE *stream,
            char *buf,
            int mode,
            size_t size);

/* SECTION 7.9.6 pagg 131
 */

/* returns number of characters transmitted, < 0 if failure */
int fprintf(FILE *stream,
            const char *format,
            ...);

/* returns EOF iff total failure, else number of items assigned [>=0] */
int fscanf(FILE *stream,
           const char *format,
           ...);

/* returns number of characters transmitted, < 0 if failure */
int printf(const char *format,
           ...);

/* returns EOF iff total failure, else number of items assigned [>=0] */
int scanf(const char *format,
          ...);

/* returns number of chars written into S, not counting terminating 0 */
int sprintf(char *s,
            const char *format,
            ...);

/* returns EOF iff total failure, else number of items assigned [>=0] */
int sscanf(const char *s,
           const char *format,
           ...);

#ifdef _INC_STDARG /* mandatory pre-inclusion of stdarg.h */

/* returns number of characters transmitted, < 0 if failure */
int vfprintf(FILE *stream,
             const char *format,
             va_list arg);

/* returns number of characters transmitted, < 0 if failure */
int vprintf(const char *format,
            va_list arg);

/* returns number of chars written into S, not counting terminating 0 */
int vsprintf(char *s,
             const char *format,
             va_list arg);
#endif

/* SECTION 7.9.7 pagg 141
 */

/* returns EOF iff error or end-of-file (see feof, ferror) */
int fgetc(FILE *stream);

/* returns NULL iff failure */
char *fgets(char *s,
            int n,
            FILE *stream);

/* returns EOF iff write error, C  if success */
int fputc(int c,
          FILE *stream);

/* returns EOF iff write error, else >=0 */
int fputs(const char *s,
          FILE *stream);

/* returns EOF iff error or end-of-file (see feof, ferror) */
#define getc(_s_) fgetc(_s_)

/* returns EOF iff error or end-of-file (see feof, ferror) */
int getchar(void);

/* returns NULL iff failure */
char *gets(char *s);

/* returns EOF iff write error, C  if success */
#define putc(_c_,_s_) fputc(_c_,_s_)

/* returns EOF iff write error, C  if success */
int putchar(int c);

/* returns EOF iff write error, else >=0 */
int puts(const char *s);

/* returns EOF iff failure */
int ungetc(int c,
           FILE *stream);

/* SECTION 7.9.8 pagg 144
 */

/* returns number of elements read.
 * A return of 0 is error unless NMEMB was 0
 */
size_t fread(void *ptr,
             size_t size,
             size_t nmemb,
             FILE *stream);

/* returns number of elements written.
 * A return < NMEMB is error.
 */
size_t fwrite(const void *ptr,
              size_t size,
              size_t nmemb,
              FILE *stream);

/* SECTION 7.9.9 pagg 145
 */

/* returns 0 iff success */
int fgetpos(FILE *stream,
            fpos_t *pos);

/* returns 0 iff success */
int fseek(FILE *stream,
          long int offset,
          int whence);

/* returns 0 iff success */
int fsetpos(FILE *stream,
            const fpos_t *pos);

/* return the current fpos_t (truncated) iff success, -1L otherwise */
long int ftell(FILE *stream);

/* no return value */
void rewind(FILE *stream);

/* SECTION 7.9.10 pagg 147
 */

/* no return value */
void clearerr(FILE *stream);

/* returns !0 iff end-of-file */
int feof(FILE *stream);

/* returns !0 iff file is in error */
int ferror(FILE *stream);

/* no return value */
void perror(const char *s);

#endif


/*
 * Function prototypes that we actually implement,
 * and how they map onto our type system
 */

#if 0
rename
tmpfile
tmpnam
#endif

EXTERN_C INT __cdecl remove(const char *filename);

/* returns 0 if success, EOF if failure */
EXTERN_C INT __cdecl fclose(FILE *stream);

/* returns 0 if success, EOF if failure */
EXTERN_C INT __cdecl fflush(FILE *stream);

/* returns NULL iff failure */
EXTERN_C FILE* __cdecl fopen(const char *filename,
                            const char *mode);

/* returns NULL iff failure */
EXTERN_C FILE*  __cdecl freopen(const char *filename,
                               const char *mode,
                               FILE *stream);

/* no return value */
EXTERN_C void __cdecl setbuf(FILE *stream,
                            char *buf);

#if 0
setvbuf
#endif

/* returns < 0 iff error */
EXTERN_C INT __cdecl fprintf(FILE *stream,
                            const char *format,
                            ...);

/* returns EOF iff total failure, else number of items assigned [>=0] */
EXTERN_C INT __cdecl fscanf(FILE *stream,
                           const char *format,
                           ...);

/* returns < 0 iff error */
EXTERN_C INT __cdecl printf(const char *format,
                           ...);

/* returns EOF iff total failure, else number of items assigned [>=0] */
EXTERN_C INT __cdecl scanf(const char *format,
                          ...);

/* returns number of chars written into S, not counting terminating 0 */
EXTERN_C INT __cdecl sprintf(char *s,
                            const char *format,
                            ...);

/* returns EOF iff total failure, else number of items assigned [>=0] */
EXTERN_C INT __cdecl sscanf(const char *s,
                           const char *format,
                           ...);

/* mandatory pre-inclusion of stdarg.h */
#ifdef _INC_STDARG

/* returns < 0 iff error */
EXTERN_C INT __cdecl vfprintf(FILE *stream,
                             const char *format,
                             va_list arg);

/* returns < 0 iff error */
EXTERN_C INT __cdecl vprintf(const char *format,
                            va_list arg);

/* returns number of chars written into S, not counting terminating 0 */
EXTERN_C INT __cdecl vsprintf(char *s,
                             const char *format,
                             va_list arg);
#endif

/* returns EOF iff error or end-of-file (see feof, ferror) */
EXTERN_C int __cdecl fgetc(FILE *stream);

/* returns NULL iff failure */
EXTERN_C char * __cdecl fgets(char * s,
                               int n,
                               FILE *stream);

/* returns EOF iff write error, C  if success */
EXTERN_C int __cdecl fputc( int c, FILE *stream);

/* returns EOF iff write error, else >=0 */
EXTERN_C int __cdecl fputs(const char *s,
                          FILE *stream);

/* returns EOF iff error or end-of-file (see feof, ferror) */
#define getc(_stream_) fgetc(_stream_)

/* returns EOF iff error or end-of-file (see feof, ferror) */
EXTERN_C INT __cdecl getchar(void);

/* returns NULL iff failure */
EXTERN_C char * __cdecl gets(char * s);

/* returns EOF iff write error, C  if success */
#define putc(_c_,_stream_) fputc(_c_,_stream_)

/* returns EOF iff write error, C  if success */
EXTERN_C int __cdecl putchar(int c);

/* returns EOF iff write error, else >=0 */
EXTERN_C int __cdecl puts( const char *s);

/* returns EOF iff failure */
EXTERN_C INT __cdecl ungetc(INT c,
                           FILE *stream);

/* returns number of elements read.
 * A return of 0 is error unless NMEMB was 0
 */
EXTERN_C size_t __cdecl fread(void *ptr,
                             size_t size,
                             size_t nmemb,
                             FILE *stream);

/* returns number of elements written.
 * A return < NMEMB is error.
 */
EXTERN_C size_t __cdecl fwrite(const void *ptr,
                              size_t size,
                              size_t nmemb,
                              FILE *stream);

#if 0
fgetpos
#endif

/* returns 0 iff success */
EXTERN_C INT __cdecl fseek(FILE *stream,
                          UINT offset,
                          int whence);

#if 0
fsetpos
#endif

/* return the current fpos_t (truncated) iff success, -1L otherwise */
EXTERN_C INT32 __cdecl ftell(FILE *stream);

/* no return value */
EXTERN_C void __cdecl rewind(FILE *stream);

/* no return value */
EXTERN_C void __cdecl clearerr(FILE *stream);

/* returns !0 iff end-of-file */
EXTERN_C INT __cdecl feof(FILE *stream);

/* returns !0 iff file is in error */
EXTERN_C INT __cdecl ferror(FILE *stream);

#if 0
perror
#endif

#ifndef _STRICT_ISO_COMPLIANCE
/* Other non-standard things usually found here. Sigh.
 */
EXTERN_C INT __cdecl _snprintf(char *s,
                               size_t count,
                               const char *format,
                               ...);

#ifdef _INC_STDARG /* mandatory pre-inclusion of stdarg.h */
EXTERN_C INT __cdecl _vsnprintf(char *s,
                                size_t count,
                                const char *format,
                                va_list arg);
#endif
#endif

#endif  /* _INC_STDIO */
