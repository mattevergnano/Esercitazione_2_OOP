#include<iostream>
#include "complex_number.hpp"
using namespace std;


int main(void)
{
    using comp = complex_number<double>;
    double a = 4.454;
    comp b(6,3);
    comp c1(1);
    comp c2(4,-2);
    comp c3;
    cout << 4.454 + b << endl;
    return 0;
}