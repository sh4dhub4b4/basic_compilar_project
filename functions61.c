/* ============================================================
 *  functions61.c
 *  Implementation of all custom-named wrappers (suffix: 61).
 *  Compile with:  gcc -c functions61.c -o functions61.o -lm
 * ============================================================ */

#include "functions61.h"

/* ── Arithmetic ──────────────────────────────────────────── */

/* Add two numbers */
double add61(double a, double b)
{
    return a + b;
}

/* Subtract two numbers (a - b) */
double sub61(double a, double b)
{
    return a - b;
}

/* Multiply two numbers */
double mul61(double a, double b)
{
    return a * b;
}

/* Divide two numbers (a / b).
   Terminates with an error message if b == 0. */
double div61(double a, double b)
{
    if (b == 0.0) {
        fprintf(stderr, "[div61] Error: division by zero.\n");
        exit(EXIT_FAILURE);
    }
    return a / b;
}

/* ── Math wrappers ───────────────────────────────────────── */

/* Square root – aborts if x < 0 */
double sqrt61(double x)
{
    if (x < 0.0) {
        fprintf(stderr, "[sqrt61] Error: cannot take square root of a negative number.\n");
        exit(EXIT_FAILURE);
    }
    return sqrt(x);
}

/* x raised to the power of exp */
double pow61(double base, double exponent)
{
    return pow(base, exponent);
}

/* Absolute value of a floating-point number */
double fabs61(double x)
{
    return fabs(x);
}

/* Absolute value of an integer */
int abs61(int x)
{
    return abs(x);
}

/* Sine of an angle given in radians */
double sin61(double radians)
{
    return sin(radians);
}

/* Cosine of an angle given in radians */
double cos61(double radians)
{
    return cos(radians);
}

/* Tangent of an angle given in radians */
double tan61(double radians)
{
    return tan(radians);
}

/* Ceiling: smallest integer >= x */
double ceil61(double x)
{
    return ceil(x);
}

/* Floor: largest integer <= x */
double floor61(double x)
{
    return floor(x);
}

/* ── I/O ─────────────────────────────────────────────────── */

/* Formatted print to stdout (variadic, mirrors printf) */
int print61(const char *fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    int result = vprintf(fmt, args);
    va_end(args);
    return result;
}

/* Formatted read from stdin (variadic, mirrors scanf) */
int scan61(const char *fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    int result = vscanf(fmt, args);
    va_end(args);
    return result;
}

/* Print a system error message */
void perror61(const char *msg)
{
    perror(msg);
}

/* ── File I/O ────────────────────────────────────────────── */

/* Open a file; returns NULL on failure */
FILE *fopen61(const char *path, const char *mode)
{
    return fopen(path, mode);
}

/* Close a file stream; returns 0 on success, EOF on error */
int fclose61(FILE *stream)
{
    return fclose(stream);
}

/* Read one character from a stream; returns EOF on end/error */
int getc61(FILE *stream)
{
    return getc(stream);
}

/* Write one character to a stream; returns the character or EOF on error */
int putc61(int c, FILE *stream)
{
    return putc(c, stream);
}

/* ── String ──────────────────────────────────────────────── */

/* Length of a string (excluding the null terminator) */
size_t strlen61(const char *s)
{
    return strlen(s);
}

/* Copy src into dst; returns dst */
char *strcpy61(char *dst, const char *src)
{
    return strcpy(dst, src);
}

/* Append src to dst; returns dst */
char *strcat61(char *dst, const char *src)
{
    return strcat(dst, src);
}

/* Lexicographic comparison: <0, 0, or >0 */
int strcmp61(const char *s1, const char *s2)
{
    return strcmp(s1, s2);
}

/* ── Memory ──────────────────────────────────────────────── */

/* Allocate `size` bytes; returns NULL on failure */
void *malloc61(size_t size)
{
    void *ptr = malloc(size);
    if (ptr == NULL) {
        fprintf(stderr, "[malloc61] Error: memory allocation failed for %zu bytes.\n", size);
    }
    return ptr;
}

/* Deallocate a previously malloc61-allocated block */
void free61(void *ptr)
{
    free(ptr);
}

/* ── Random ──────────────────────────────────────────────── */

/* Returns a pseudo-random integer in [0, RAND_MAX] */
int rand61(void)
{
    return rand();
}

/* Seed the random number generator */
void srand61(unsigned int seed)
{
    srand(seed);
}

/* ── Program control ─────────────────────────────────────── */

/* Terminate the program with the given status code */
void exit61(int status)
{
    exit(status);
}
