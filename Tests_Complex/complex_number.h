#ifndef COMPLEX_NUMBER_H_INCLUDED
#define COMPLEX_NUMBER_H_INCLUDED

#include <iostream>
#include <cmath>

class complex{
public:
    complex(double _re=0, double _im=0):re{_re}, im{_im}{}
    ~complex(){};

    enum FIELD_ERR{INVERSE_ZERO};

    void operator = (const complex& c){
        re = c.re;
        im = c.im;
    }

    double get_re(){return re;};
    double get_im(){return im;};

    void set_re(double _re){
        re = _re;
    }

    void set_im(double _im){
        im = _im;
    }

    complex operator + (const complex& c) const{
        return complex(re + c.re, im + c.im);
    }

    complex& operator += (const complex& c){
        re += c.re;
        im += c.im;
        return *this;
    }

    complex operator - (const complex& c) const{
        return complex(re - c.re, im - c.im);
    }

    complex& operator -= (const complex& c){
        re -= c.re;
        im -= c.im;
        return *this;
    }

    complex& operator += (double d){
        re += d;
        return *this;
    }

    complex operator + (double d) const{
        return complex(re +d, im);
    }

    complex& operator -= (double d){
        re -= d;
        return *this;
    }

    complex operator - (double d) const{
        return complex(re -d, im);
    }

    complex& operator *= (const complex& c){
        double re_c{re};
        re = re*c.re - im*c.im;
        im = re_c*c.im + im*c.re;
        return *this;
    }

    complex operator * (const complex& c) const{
        return complex(re*c.re - im*c.im, re*c.im + im*c.re);
    }

    complex& operator *= (double d){
        re *= d;
        im *= d;
        return *this;
    }

    complex operator * (double d) const{
        return complex(re*d, im*d);
    }

    complex operator - () const{
        return complex(-re,-im);
    }

    complex& operator + (){
        return *this;
    }

    complex operator / (double d) const{
        if(d == 0)throw INVERSE_ZERO;
        return complex(re/d, im/d);
    }

    complex& operator /= (double d){
        if(d == 0)throw INVERSE_ZERO;
        im/=d;
        re/=d;
        return *this;
    }

    complex operator / (complex& c) const{
        complex w{0.,0.};
        if((c.re == 0) && (c.im == 0))throw INVERSE_ZERO;
        w = ((*this)*(c.inv()))/(c.sqr_abs());
        return w;
    }

    bool operator == (const complex& c) const{
        return ((re == c.re) && (im == c.im));
    }

    bool operator == (double d) const{
        return ((re == d) && (im == 0));
    }

    bool operator != (const complex& c) const{
        return ((re != c.re) || (im != c.im));
    }

    bool operator != (double d) const{
        return ((re != d) || (im != 0));
    }

    complex& operator /= (complex& c){
        if((c.re == 0) && (c.im == 0))throw INVERSE_ZERO;
        *this = ((*this)*(c.inv()))/(c.sqr_abs());
        return *this;
    }

    double abs()const{
        return sqrt(re*re + im*im);
    }

    double sqr_abs()const{
        return re*re + im*im;
    }

    complex inv() const{
        return complex(re,-im);
    }

    friend complex operator + (double d, const complex& c){
        return complex(c.re + d, c.im);
    }

    friend complex operator - (double d, const complex& c){
        return complex(c.re - d, c.im);
    }

    friend complex operator * (double d, const complex& c){
        return complex(c.re *d, c.im*d);
    }

    friend complex operator / (double d, const complex& c){
        if(d == 0)throw INVERSE_ZERO;
        return complex(c.re /d, c.im/d);
    }

    friend complex operator + (const complex& c, double d){
        return complex(c.re + d, c.im);
    }

    friend complex operator - (const complex& c, double d){
        return complex(c.re - d, c.im);
    }

    friend complex operator * (const complex& c, double d){
        return complex(c.re *d, c.im*d);
    }

    friend complex operator / (const complex& c, double d){
        if(d == 0)throw INVERSE_ZERO;
        return complex(c.re /d, c.im/d);
    }

    friend std::ostream& operator << (std::ostream &stream, complex c){
        stream<<"("<<c.re<<","<<c.im<<")";
        return stream;
    }

    friend std::istream& operator >> (std::istream &stream, complex& c){
        stream>>c.re>>c.im;
        return stream;
    }

private:
    double re{};
    double im{};

};


#endif // COMPLEX_NUMBER_H_INCLUDED
