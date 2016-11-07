#include <iostream>
#include <vector>
#include <algorithm>
#include "polynomial.h"

using namespace std;

int main()
{
    polynomial  a(6), b(3);
    b.load();
    a.load();
    b=b+a;
    b.write();
}

