#ifndef COMPLEX_TESTS_H_INCLUDED
#define COMPLEX_TESTS_H_INCLUDED


#include <cmath>
#include <algorithm>

#include "complex_number.h"

#ifndef TEST_ASSERT
#define TEST(x)                         \
   if (!(x)) std::cerr << "check "           \
                  << #x << " "          \
                  << " failed in file " \
                  << __FILE__           \
                  << " at line "        \
                  << __LINE__ << std::endl;
#else
#define TEST(x) assert(x);
#endif

#define EXCEPT_EQ(x,y) TEST((x) == (y));
#define EXCEPT_NQ(x,y) TEST((x) != (y));
#define EXCEPT_NAN(x)  TEST((x) != (x));
#define EXCEPT_INF(x)  TEST((x) == 1.0/0.0 || (x) == -1.0/0.0);
#define EXCEPT_PINF(x) TEST((x) == 1.0/0.0);
#define EXCEPT_NINF(x) TEST((x) == -1.0/0.0);
#define EXCEPT_APPR(x,y,eps) \
     TEST(((x-y)/std::max(x.abs(),y.abs())).abs() < eps);

void test_assign();// =, *=, +=
void test_operators();// *, +, -, /, == , != ... etc
void test_complex_methods();// re(), im(), abs(), sqr_abs(), inv()
void test_io();//  input/output

#endif // COMPLEX_TESTS_H_INCLUDED
