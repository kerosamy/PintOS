// fixed_point.h
#ifndef FIXED_POINT_H
#define FIXED_POINT_H

#include <stdint.h>

typedef int64_t fixed_point_t;

// Define scaling factor: 2^14 for 17.14 fixed-point representation
#define F (1 << 14)

// from int to fixed point
#define int_to_fp(n) ((n) * F)

// from fixed point to int (round toward zero)
#define fp_to_int_zero(x) ((x) / F)

// from fixed point to int (round to nearest)
#define fp_to_int_nearest(x) (((x) >= 0) ? (((x) + F / 2) / F) : (((x) - F / 2) / F))

// operations
#define add_fp(x, y) ((x) + (y))
#define sub_fp(x, y) ((x) - (y))
#define add_mixed(x, n) ((x) + (n) * F)
#define sub_mixed(x, n) ((x) - (n) * F)
#define mul_fp(x, y) (((int64_t)(x)) * (y) / F)
#define mul_mixed(x, n) ((x) * (n))
#define div_fp(x, y) (((int64_t)(x)) * F / (y))
#define div_mixed(x, n) ((x) / (n))

#endif /* FIXED_POINT_H */
