/*
 * math.c
 *
 * Arithmetic, compare and logical instructions
 *
 */

#include "ztypes.h"

/*
 * add
 *
 * Add two operands
 *
 */

#ifdef __STDC__
void add (zword_t a, zword_t b)
#else
void add (a, b)
zword_t a, b;
#endif
{

    store_operand (a + b);

}/* add */

/*
 * subtract
 *
 * Subtract two operands
 *
 */

#ifdef __STDC__
void subtract (zword_t a, zword_t b)
#else
void subtract (a, b)
zword_t a, b;
#endif
{

    store_operand (a - b);

}/* subtract */

/*
 * multiply
 *
 * Multiply two operands
 *
 */

#ifdef __STDC__
void multiply (zword_t a, zword_t b)
#else
void multiply (a, b)
zword_t a, b;
#endif
{

    store_operand (a * b);

}/* multiply */

/*
 * divide
 *
 * Divide two operands
 *
 */

#ifdef __STDC__
void divide (zword_t a, zword_t b)
#else
void divide (a, b)
zword_t a, b;
#endif
{

    store_operand (a / b);

}/* divide */

/*
 * remainder
 *
 * Modulus divide two operands
 *
 */

#ifdef __STDC__
void remainder (zword_t a, zword_t b)
#else
void remainder (a, b)
zword_t a, b;
#endif
{

    store_operand (a % b);

}/* remainder */

/*
 * shift
 *
 * Shift +/- n bits
 *
 */

#ifdef __STDC__
void shift (zword_t a, zword_t b)
#else
void shift (a, b)
zword_t a;
zword_t b;
#endif
{

    if ((short) b > 0)
        store_operand (a << (short) b);
    else
        store_operand (a >> abs ((short) b));

}/* shift */


/*
 * arith_shift
 *
 * Aritmetic shift +/- n bits
 *
 */

#ifdef __STDC__
void arith_shift (zword_t a, zword_t b)
#else
void arith_shift (a, b)
zword_t a;
zword_t b;
#endif
{

    if ((short) b > 0)
        store_operand (a << (short) b);
    else
        if ((short) a > 0)
            store_operand (a >> abs ((short) b));
        else
            store_operand (~((~a) >> abs ((short) b)));

}/* arith_shift */

/*
 * or
 *
 * Logical OR
 *
 */

#ifdef __STDC__
void or (zword_t a, zword_t b)
#else
void or (a, b)
zword_t a, b;
#endif
{

    store_operand (a | b);

}/* or */

/*
 * not
 *
 * Logical NOT
 *
 */

#ifdef __STDC__
void not (zword_t a)
#else
void not (a)
zword_t a;
#endif
{

    store_operand (~a);

}/* not */

/*
 * and
 *
 * Logical AND
 *
 */

#ifdef __STDC__
void and (zword_t a, zword_t b)
#else
void and (a, b)
zword_t a, b;
#endif
{

    store_operand (a & b);

}/* and */

/*
 * zrandom
 *
 * Return random number between 1 and operand
 *
 */

#ifdef __STDC__
void zrandom (zword_t a)
#else
void zrandom (a)
zword_t a;
#endif
{

    if (a == 0)
        store_operand (0);
    else if (a & 0x8000) { /* (a < 0) - used to set seed with #RANDOM */
        srand ((unsigned int) abs (a));
        store_operand (0);
    } else /* (a > 0) */
        store_operand (((zword_t) rand () % a) + 1);

}/* zrandom */

/*
 * test
 *
 * Jump if operand 2 bit mask not set in operand 1
 *
 */

#ifdef __STDC__
void test (zword_t a, zword_t b)
#else
void test (a, b)
zword_t a, b;
#endif
{

    conditional_jump (((~a) & b) == 0);

}/* test */

/*
 * compare_zero
 *
 * Compare operand against zero
 *
 */

#ifdef __STDC__
void compare_zero (zword_t a)
#else
void compare_zero (a)
zword_t a;
#endif
{

    conditional_jump (a == 0);

}/* compare_zero */

/*
 * compare_je
 *
 * Jump if operand 1 is equal to any other operand
 *
 */

#ifdef __STDC__
void compare_je (int count, zword_t *operand)
#else
void compare_je (count, operand)
int count;
zword_t *operand;
#endif
{
    int i;

    for (i = 1; i < count; i++)
        if (operand[0] == operand[i]) {
            conditional_jump (TRUE);
            return;
        }
    conditional_jump (FALSE);

}/* compare_je */

/*
 * compare_jl
 *
 * Jump if operand 1 is less than operand 2
 *
 */

#ifdef __STDC__
void compare_jl (zword_t a, zword_t b)
#else
void compare_jl (a, b)
zword_t a, b;
#endif
{

    conditional_jump ((short) a < (short) b);

}/* compare_jl */

/*
 * compare_jg
 *
 * Jump if operand 1 is greater than operand 2
 *
 */

#ifdef __STDC__
void compare_jg (zword_t a, zword_t b)
#else
void compare_jg (a, b)
zword_t a, b;
#endif
{

    conditional_jump ((short) a > (short) b);

}/* compare_jg */
