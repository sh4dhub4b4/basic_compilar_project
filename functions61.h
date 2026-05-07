#ifndef FUNCTIONS61_H
#define FUNCTIONS61_H

/* ============================================================
 *  functions61.h
 *  Custom-named wrapper library (suffix: 61)
 *  Wraps standard C library functions under project-specific names.
 * ============================================================ */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdarg.h>

/* ── Arithmetic ──────────────────────────────────────────── */
double add61  (double a, double b);
double sub61  (double a, double b);
double mul61  (double a, double b);
double div61  (double a, double b);   /* terminates on divide-by-zero */

/* ── Math (wrappers around <math.h>) ─────────────────────── */
double sqrt61 (double x);
double pow61  (double base, double exp);
double fabs61 (double x);
double sin61  (double radians);
double cos61  (double radians);
double tan61  (double radians);
double ceil61 (double x);
double floor61(double x);

/* ── Integer absolute value (<stdlib.h>) ─────────────────── */
int    abs61  (int x);

/* ── I/O ─────────────────────────────────────────────────── */
int    print61 (const char *fmt, ...);            /* printf  */
int    scan61  (const char *fmt, ...);            /* scanf   */
void   perror61(const char *msg);                 /* perror  */

/* ── File I/O ────────────────────────────────────────────── */
FILE  *fopen61 (const char *path, const char *mode);
int    fclose61(FILE *stream);
int    getc61  (FILE *stream);
int    putc61  (int c, FILE *stream);

/* ── String (<string.h>) ─────────────────────────────────── */
size_t strlen61(const char *s);
char  *strcpy61(char *dst, const char *src);
char  *strcat61(char *dst, const char *src);
int    strcmp61(const char *s1, const char *s2);

/* ── Memory (<stdlib.h>) ─────────────────────────────────── */
void  *malloc61(size_t size);
void   free61  (void *ptr);

/* ── Random (<stdlib.h>) ─────────────────────────────────── */
int    rand61  (void);
void   srand61 (unsigned int seed);

/* ── Program control ─────────────────────────────────────── */
void   exit61  (int status);

#endif /* FUNCTIONS61_H */
