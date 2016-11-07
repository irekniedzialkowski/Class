#ifndef POLYNOMIAL_H_
#define POLYNOMIAL_H_
#include<vector>
using namespace std;
class polynomial
{
    int degree;
    double *coefficient;
    public:
    polynomial(int);
    polynomial(const polynomial&);
    ~polynomial();
    void load();
    void write();
    polynomial operator+(polynomial&);
};
#endif
