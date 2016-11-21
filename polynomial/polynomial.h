#ifndef POLYNOMIAL_H_
#define POLYNOMIAL_H_
#include<vector>
using namespace std;
class polynomial
{
    int degree;
    vector<double> coefficient; //I am using vector, because I can later expand the size of the array
    public:
    polynomial(int);
    polynomial(const polynomial&);
    void load();
    void write();
    void add(polynomial&);
};
#endif
