#include <iostream>
#include <vector>
#include <algorithm>
#include "polynomial.h"
using namespace std;
polynomial::polynomial(int n)
{
    this->degree=n;
    this->coefficient.resize(n+1);
}
polynomial::polynomial(const polynomial &A)
{
    this->degree=A.degree;
    this->coefficient.resize(A.degree+1);
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

void polynomial::add(polynomial &A)
{
	int maximum= max(degree,A.degree);
    int minimum = min(degree,A.degree);
 	this->coefficient.resize(maximum+1);
 	if(degree<A.degree)
    {
        for(int i=0;i<=maximum;++i)
        coefficient[i]+=A.coefficient[i];
    }
    else for(int i=0; i<=minimum; ++i)
    {
        coefficient[i]+=A.coefficient[i];
    }
    this->degree=maximum;
}
