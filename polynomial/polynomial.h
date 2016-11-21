#ifndef POLYNOMIAL_H_
#define POLYNOMIAL_H_
#include<vector>
using namespace std;
class polynomial
{
    int degree;
    vector<double> coefficient; //I am using vector, because I can later expand the size of the array
    double *coefficient;
    public:
    polynomial(int);
    polynomial(const polynomial&);
    ~polynomial();
    void load();
    void write();
    polynomial operator+(polynomial&);
    polynomial& operator=(const polynomial&);
};
#endif
