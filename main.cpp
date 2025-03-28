#include<iostream>
#include "complex_number.hpp"
using namespace std;


int main(void)
{
    using comp = complex_number<double>;
    double a = 4.454;
    comp b(6,3);
    comp c2(4,-2);
    comp c3;
    cout << a + b << endl;
    return 0;
}