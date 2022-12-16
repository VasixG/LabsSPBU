#include <iostream>
#include <assert.h>
#include <sstream>
#include "complex_tests.h"

void test_assign(){

    complex x{1,2}, y{3,4}, w{0.0/0.0, 0.0/0.0}, z{1.0/0.0, -2.0/0.0};
    complex x_2 = x;
    double a = 5, b = 0;

    EXCEPT_NQ(x,y);
    EXCEPT_EQ(x_2,x);

    x_2+=y;
    EXCEPT_EQ(x_2, complex(4,6));

    x_2-=y;
    EXCEPT_EQ(x_2, x);

    x_2*=y;

    EXCEPT_EQ(x_2, complex(-5, 10));

    x_2/=y;
    EXCEPT_APPR(x_2, x, 0.001);

    complex x_3 = x, c_4 = x;

    x_3+=a;
    EXCEPT_EQ(x_3, complex(6,2));

    x_3-=a;
    EXCEPT_EQ(x_3, x);


    x_3*=a;

    EXCEPT_EQ(x_3, complex(5, 10));

    x_3/=a;
    EXCEPT_APPR(x_3, x, 0.001);

    x_3+=b;
    EXCEPT_EQ(x_3, complex(1,2));

    x_3-=b;
    EXCEPT_EQ(x_3, x);


    x_3*=b;

    EXCEPT_EQ(x_3, complex(0, 0));

    EXCEPT_NAN(w.get_re());
    EXCEPT_NAN(w.get_im());

    EXCEPT_INF(z.get_re());
    EXCEPT_NINF(z.get_im());
}

void test_operators(){
    complex x{1, 2}, y{-1, 2}, z = x;
    double a = 5;

    EXCEPT_EQ(x+y,complex(0,4));
    EXCEPT_EQ(x-y,complex(2,0));
    EXCEPT_EQ(-y,complex(1,-2));
    EXCEPT_EQ(+y,y);
    EXCEPT_EQ((y!=x),1);
    EXCEPT_EQ((y==(x-2.)),1);
    EXCEPT_EQ(x/y*y == x, 1);

    EXCEPT_EQ(x*a, complex(5,10));
    EXCEPT_EQ(a*x, complex(5,10));

    EXCEPT_EQ(x+a, complex(6,2));
    EXCEPT_EQ(a+x, complex(6,2));

    EXCEPT_EQ(x/a, complex(0.2,0.4));
}

void test_complex_methods(){
    complex x{1,2}, y{3, 4}, z{2,0}, w{0,0};

    EXCEPT_EQ(z.inv()==2, 1);
    EXCEPT_EQ(x.inv(), complex(1,-2));
    EXCEPT_EQ(y.abs(), 5);
    EXCEPT_EQ(x.sqr_abs(), 5);
    EXCEPT_EQ(w.abs(), 0);
}
void test_io(){


    std::stringstream str;

    complex x{1,-2};

    str << x;

    EXCEPT_EQ(str.str(), "(1,-2)");

    complex y{};

    std::stringstream str2;

    str2<<x.get_re()<<x.get_im();

    str2>>y;

    EXCEPT_EQ(y,x);
}
