#include <iostream>
#include "Binary_Tree.h"

using namespace std;

int main()
{
    node x(5),y(6),z(1),t(2);
    Tree T;
    T.Tree_insert(&x);
    T.Tree_insert(&y);
    T.Tree_insert(&z);
    T.Tree_insert(&t);
    T.Write(T.T_root);
    node *c;
    T.Tree_delete(&x);
    c=T.T_root;
    cout<<c->key;
}
