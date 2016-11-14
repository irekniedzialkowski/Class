#include <iostream>
#include <vector>
#include <algorithm>
#include "polynomial.h"

using namespace std;

int main()
{
    polynomial  a(6), b(3),c(3);
    c.load();
    b.load();
    a.load();
    a=b=b+a+c;
    a.write();
}

