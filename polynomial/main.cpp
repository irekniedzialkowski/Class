#include <iostream>
#include <vector>
#include <algorithm>
#include "polynomial.h"

using namespace std;

int main()
{
    polynomial  a(6), b(3);
    a.load();
    b.load();
    a.write();
    b.add(a);
    b.write();
}

