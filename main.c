/* ============================================================
 *  main.c  –  fully interactive demo of the functions61 library
 *  Every value is typed by the user; nothing is hardcoded.
 *
 *  Compile:
 *      gcc main.c functions61.c -o demo61 -lm
 *  Run:
 *      ./demo61
 * ============================================================ */

#include "functions61.h"
#include <time.h>

/* ── small helpers ─────────────────────────────────────────── */
static void banner(const char *title)
{
    print61("\n╔══════════════════════════════════════════╗\n");
    print61("  %s\n", title);
    print61("╚══════════════════════════════════════════╝\n");
}

static void divider(void)
{
    print61("------------------------------------------\n");
}

/* ============================================================
 *  MAIN
 * ============================================================ */
int main(void)
{
    print61("\n==========================================\n");
    print61("   Welcome to the functions61 Demo\n");
    print61("==========================================\n");
    print61("You will be asked to enter values for each\n");
    print61("section. All processing uses your inputs.\n");

    /* ══════════════════════════════════════════
     *  1. ARITHMETIC  (add61 sub61 mul61 div61)
     * ══════════════════════════════════════════ */
    banner("1. Arithmetic  [ add / sub / mul / div ]");

    double a, b;
    print61("  Enter first number  (a): ");
    scan61("%lf", &a);
    print61("  Enter second number (b): ");
    scan61("%lf", &b);

    divider();
    print61("  add61 (%g + %g)  = %g\n",   a, b, add61(a, b));
    print61("  sub61 (%g - %g)  = %g\n",   a, b, sub61(a, b));
    print61("  mul61 (%g * %g)  = %g\n",   a, b, mul61(a, b));

    if (b == 0.0)
        print61("  div61 : skipped  (you entered b = 0)\n");
    else
        print61("  div61 (%g / %g)  = %g\n", a, b, div61(a, b));

    /* ══════════════════════════════════════════
     *  2. SQRT & POWER
     * ══════════════════════════════════════════ */
    banner("2. Square Root & Power  [ sqrt61 / pow61 ]");

    double sqrtInput;
    print61("  Enter a non-negative number for sqrt61: ");
    scan61("%lf", &sqrtInput);

    double base, exponent;
    print61("  Enter base for pow61     : ");
    scan61("%lf", &base);
    print61("  Enter exponent for pow61 : ");
    scan61("%lf", &exponent);

    divider();
    if (sqrtInput < 0.0)
        print61("  sqrt61: cannot compute – input is negative.\n");
    else
        print61("  sqrt61(%.4g)         = %.6f\n", sqrtInput, sqrt61(sqrtInput));
    print61("  pow61(%.4g, %.4g)    = %.6f\n", base, exponent, pow61(base, exponent));

    /* ══════════════════════════════════════════
     *  3. ABSOLUTE VALUES  (int & float)
     * ══════════════════════════════════════════ */
    banner("3. Absolute Values  [ abs61 / fabs61 ]");

    int intVal;
    print61("  Enter an integer (can be negative): ");
    scan61("%d", &intVal);

    double floatVal;
    print61("  Enter a float   (can be negative): ");
    scan61("%lf", &floatVal);

    divider();
    print61("  abs61 (%d)     = %d\n",   intVal,   abs61(intVal));
    print61("  fabs61(%.4g)  = %.4f\n",  floatVal, fabs61(floatVal));

    /* ══════════════════════════════════════════
     *  4. TRIGONOMETRY  (sin cos tan)
     * ══════════════════════════════════════════ */
    banner("4. Trigonometry  [ sin61 / cos61 / tan61 ]");

    double degrees;
    print61("  Enter angle in DEGREES: ");
    scan61("%lf", &degrees);

    double PI      = 3.14159265358979323846;
    double radians = degrees * PI / 180.0;

    divider();
    print61("  Angle: %.4g deg  =  %.6f rad\n", degrees, radians);
    print61("  sin61 = %.6f\n", sin61(radians));
    print61("  cos61 = %.6f\n", cos61(radians));
    if ((int)degrees % 180 == 90)
        print61("  tan61 = undefined at this angle\n");
    else
        print61("  tan61 = %.6f\n", tan61(radians));

    /* ══════════════════════════════════════════
     *  5. CEIL & FLOOR
     * ══════════════════════════════════════════ */
    banner("5. Rounding  [ ceil61 / floor61 ]");

    double roundInput;
    print61("  Enter a decimal number (e.g. 4.7): ");
    scan61("%lf", &roundInput);

    divider();
    print61("  Input    : %.6f\n", roundInput);
    print61("  ceil61   : %.0f\n", ceil61(roundInput));
    print61("  floor61  : %.0f\n", floor61(roundInput));

    /* ══════════════════════════════════════════
     *  6. STRING FUNCTIONS
     * ══════════════════════════════════════════ */
    banner("6. Strings  [ strlen61 / strcpy61 / strcat61 / strcmp61 ]");

    char str1[128], str2[128], combined[256];

    print61("  Enter first  string (no spaces): ");
    scan61("%127s", str1);
    print61("  Enter second string (no spaces): ");
    scan61("%127s", str2);

    char copyBuf[128];
    strcpy61(copyBuf, str1);

    strcpy61(combined, str1);
    strcat61(combined, str2);

    int cmpResult = strcmp61(str1, str2);

    divider();
    print61("  strlen61(\"%s\")  = %zu\n",  str1, strlen61(str1));
    print61("  strlen61(\"%s\")  = %zu\n",  str2, strlen61(str2));
    print61("  strcpy61  copy of str1 -> \"%s\"\n", copyBuf);
    print61("  strcat61  str1+str2    -> \"%s\"\n",  combined);
    print61("  strcmp61 result = %d  ", cmpResult);
    if      (cmpResult < 0) print61("(str1 < str2 lexicographically)\n");
    else if (cmpResult > 0) print61("(str1 > str2 lexicographically)\n");
    else                    print61("(str1 == str2 – identical)\n");

    /* ══════════════════════════════════════════
     *  7. MEMORY ALLOCATION
     * ══════════════════════════════════════════ */
    banner("7. Memory  [ malloc61 / free61 ]");

    int arrSize;
    print61("  How many integers to allocate? ");
    scan61("%d", &arrSize);

    if (arrSize <= 0) {
        print61("  Invalid size – skipping.\n");
    } else {
        int *dynArr = (int *)malloc61((size_t)arrSize * sizeof(int));
        if (dynArr != NULL) {
            print61("  Enter %d integer values:\n", arrSize);
            for (int i = 0; i < arrSize; i++) {
                print61("    [%d]: ", i);
                scan61("%d", &dynArr[i]);
            }
            divider();
            print61("  Stored  : ");
            for (int i = 0; i < arrSize; i++) print61("%d ", dynArr[i]);
            print61("\n");
            free61(dynArr);
            print61("  free61  : memory released.\n");
        }
    }

    /* ══════════════════════════════════════════
     *  8. RANDOM NUMBERS
     * ══════════════════════════════════════════ */
    banner("8. Random Numbers  [ srand61 / rand61 ]");

    unsigned int seed;
    int count, rangeMax;
    print61("  Enter seed value (e.g. 42): ");
    scan61("%u", &seed);
    print61("  How many numbers to generate? ");
    scan61("%d", &count);
    print61("  Upper bound N  (rand %% N):   ");
    scan61("%d", &rangeMax);

    srand61(seed);
    divider();
    print61("  %d random numbers in [0, %d):\n  ", count, rangeMax);
    for (int i = 0; i < count; i++) {
        print61("%d ", (rangeMax > 0) ? rand61() % rangeMax : rand61());
    }
    print61("\n");

    /* ══════════════════════════════════════════
     *  9. FILE I/O  (fopen61 fclose61 putc61 getc61)
     * ══════════════════════════════════════════ */
    banner("9. File I/O  [ fopen61 / fclose61 / putc61 / getc61 ]");

    char filename[128];
    char fileContent[512];

    print61("  Enter filename to create (e.g. out.txt): ");
    scan61("%127s", filename);
    print61("  Enter text to write (no spaces):         ");
    scan61("%511s", fileContent);

    FILE *fp = fopen61(filename, "w");
    if (fp == NULL) {
        perror61("fopen61 write");
    } else {
        size_t flen = strlen61(fileContent);
        for (size_t i = 0; i < flen; i++)
            putc61((unsigned char)fileContent[i], fp);
        putc61('\n', fp);
        fclose61(fp);
        print61("  Written to \"%s\" using putc61.\n", filename);
    }

    fp = fopen61(filename, "r");
    if (fp == NULL) {
        perror61("fopen61 read");
    } else {
        print61("  Read back via getc61: \"");
        int ch;
        while ((ch = getc61(fp)) != EOF && ch != '\n')
            putc61(ch, stdout);
        print61("\"\n");
        fclose61(fp);
    }

    /* ══════════════════════════════════════════
     *  10. perror61  demo
     * ══════════════════════════════════════════ */
    banner("10. Error Handling  [ perror61 ]");
    print61("  Opening an invalid path to trigger perror61...\n");
    FILE *badFp = fopen61("/no_such_dir/no_file.txt", "r");
    if (badFp == NULL)
        perror61("  perror61 demo");
    else
        fclose61(badFp);

    /* ══════════════════════════════════════════
     *  DONE
     * ══════════════════════════════════════════ */
    banner("All 30 functions exercised with your input!");
    print61("  Exiting via exit61...\n\n");

    exit61(EXIT_SUCCESS);
    return 0;
}
