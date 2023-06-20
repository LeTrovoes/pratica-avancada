#include "stdio.h"
#include "stdlib.h"
#include "rational.h"

struct rationalNumber
{
    int numerator;
    int denominator;
};

int greatest_common_divisor(int a, int b);

RationalNumber *rational_new(int numerator, int denominator)
{
    RationalNumber *result = (RationalNumber *)malloc(sizeof(struct rationalNumber));
    result->numerator = numerator;
    result->denominator = denominator;
    return result;
}

RationalNumber *rational_sum(RationalNumber *a, RationalNumber *b)
{
    // (N1*D2 + N2*D1) / (D1*D2)
    int numerator = a->numerator * b->denominator + b->numerator * a->denominator;
    int denominator = a->denominator * b->denominator;
    return rational_new(numerator, denominator);
}

RationalNumber *rational_subtract(RationalNumber *a, RationalNumber *b)
{
    // (N1*D2 - N2*D1) / (D1*D2)
    int numerator = a->numerator * b->denominator - b->numerator * a->denominator;
    int denominator = a->denominator * b->denominator;
    return rational_new(numerator, denominator);
}

RationalNumber *rational_multiply(RationalNumber *a, RationalNumber *b)
{
    // (N1*N2) / (D1*D2)
    int numerator = a->numerator * b->numerator;
    int denominator = a->denominator * b->denominator;
    return rational_new(numerator, denominator);
}

RationalNumber *rational_divide(RationalNumber *a, RationalNumber *b)
{
    // (N1*D2) / (N2*D1)
    int numerator = a->numerator * b->denominator;
    int denominator = b->numerator * a->denominator;
    return rational_new(numerator, denominator);
}

RationalNumber *rational_simplify(RationalNumber *n)
{
    int gcd = greatest_common_divisor(n->numerator, n->denominator);
    return rational_new(n->numerator / gcd, n->denominator / gcd);
}

void rational_print(RationalNumber *n)
{
    printf("%d / %d", n->numerator, n->denominator);
}

void rational_free(RationalNumber *n)
{
    if (n == NULL)
        return;
    free(n);
}

int greatest_common_divisor(int a, int b)
{
    if (b == 0)
        return a;
    return greatest_common_divisor(b, a % b);
}
