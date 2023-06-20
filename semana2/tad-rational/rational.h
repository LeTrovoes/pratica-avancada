#ifndef RATIONAL_H
#define RATIONAL_H

typedef struct rationalNumber RationalNumber;

RationalNumber *rational_new(int numerator, int denominator);
RationalNumber *rational_sum(RationalNumber *a, RationalNumber *b);
RationalNumber *rational_subtract(RationalNumber *a, RationalNumber *b);
RationalNumber *rational_multiply(RationalNumber *a, RationalNumber *b);
RationalNumber *rational_divide(RationalNumber *a, RationalNumber *b);
RationalNumber *rational_simplify(RationalNumber *n);
void rational_print(RationalNumber *n);
void rational_free(RationalNumber *n);

#endif
