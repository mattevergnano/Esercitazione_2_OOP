#pragma once
template<typename F> requires std::floating_point<F>
class complex_number
{
    F re;
    F im;
public:
    complex_number() //costruttore di default
        : re(0), im(0)
    {}
    explicit complex_number(F n) //convertitore da reale a complesso
        : re(n), im(0)
    {
        std::cout << "converting constructor" << std::endl;
    }
    complex_number(F a, F b) //costruttore
        : re(a), im(b)
    {}
    F real(void) const{
        return re;
    }
    F imaginary(void) const{
        return im;
    }

    complex_number& operator+=(const complex_number& other){
        F a = re;
        F b = im;
        F c = other.re;
        F d = other.im;
        re = a + c;
        im = b + d;
        return *this;
    }
    complex_number operator+(const complex_number& other) const{
        complex_number ret = *this;
        ret += other;
        return ret;
    }
    complex_number& operator+=(const F& other){
        re = other+re;
        return *this;
    }
    complex_number operator+(const F& other) const{
        complex_number ret = *this;
        ret += other;
        return ret;
    }
    complex_number operator*=(const complex_number& other){
        F a = re;
        F b = im;
        F c = other.re;
        F d = other.im;
        re = a*c - b*d;
        im = a*d + b*c;
        return *this;
    }
    complex_number operator*(const complex_number& other) const{
        complex_number ret = *this;
        ret *= other;
        return ret;
    }
    complex_number& operator*=(const F& other){
        re = other*re;
        im = other*im;
        return *this;
    }
    complex_number operator*(const F& other) const{
        complex_number ret = *this;
        ret *= other;
        return ret;
    }
};

template<typename F> requires std::is_floating_point_v<F>
complex_number<F>
operator+(const F& f, const complex_number<F>& r)
{
    return r + f;
}

template<typename F> requires std::is_floating_point_v<F>
complex_number<F>
operator*(const F& f, const complex_number<F>& r)
{
    return r * f;
}

template<typename F>
complex_number<F> conjugate(const complex_number<F>& r) {
    return complex_number<F>(r.real(), -(r.imaginary()));
}
template<typename F>
std::ostream&
operator<<(std::ostream& os, const complex_number<F>& r){
    if(r.imaginary()>0)
        os << r.real() << "+" << r.imaginary() << "i";
    else if(r.imaginary()< 0)
        os << r.real() << "-" << -r.imaginary() << "i";
    else
        os << r.real();
    return os;
}