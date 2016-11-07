#include <iostream>
#include <vector>
#include <algorithm>
#include "polynomial.h"
using namespace std;
polynomial::polynomial(int n)
{
    this->degree=n;
    this->coefficient=new double [n+1];
}
polynomial::~polynomial()
{
    delete [] this->coefficient;
}
polynomial::polynomial(const polynomial &A)
{
    this->degree=A.degree;
    this->coefficient=new double[degree +1];
    for(int i=0; i<degree;++i)
        coefficient[i]=A.coefficient[i];
}
void polynomial::load()
{
    for(int i=degree; i>=0;--i)
    {
        cout<<'a'<<i<<'=';
        cin>>coefficient[i];
    }
}
void polynomial::write()
{
    int flag=0;
    for(int i=degree;i>-1;--i)
    {
        if(coefficient[i]==0) continue;
        if(flag && coefficient[i]>0)
            cout<<'+';
        if(coefficient[i]!=1 || i==0)
            cout<<coefficient[i];
        if(i==0) break;
        else if(i==1) cout<<'x';
        else cout<<"x^"<<i;
        ++flag;
    }
    cout<<endl;
}

polynomial polynomial::operator+(polynomial &A)
{
	int maximum= max(this->degree,A.degree);
    int minimum = min(this->degree,A.degree);
    polynomial C(maximum);
    for(int i=0; i<=minimum;++i)
    C.coefficient[i]+=this->coefficient[i]+A.coefficient[i];
 	if(degree<A.degree)
    {
        for(int i=minimum+1;i<=maximum;++i)
        C.coefficient[i]+=A.coefficient[i];
    }
    else for(int i=minimum+1; i<=maximum; ++i)
    {
        C.coefficient[i]+=this->coefficient[i];
    }
    if(maximum>this->degree)
    {
    this->degree=maximum;
    delete [] this->coefficient;
    this->coefficient=new double[maximum+1];
    }
    return C;
}
