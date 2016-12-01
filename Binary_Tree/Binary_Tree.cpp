#include<iostream>
#include "Binary_Tree.h"
using namespace std;
node::node()
{
    this->p=NULL;
    this->left=NULL;
    this->right=NULL;
    this->key=0;
}
node::node(int n)
{
    this->p=NULL;
    this->left=NULL;
    this->right=NULL;
    this->key=n;
}
istream& operator>>(istream &in, node &n)
{
    in>>n.key;
    return in;
}
node::operator=(node x)
{
    key=x.key;
}
bool node::operator==(int n)
{
    if(key!=0 && n!=0) return  1;
    else if(key==0 && n==0) return 1;
    else return 0;
}
Tree::Tree()
{
    T_root=NULL;
}

Tree::Tree_root(node *x)
{
    T_root=x;
}
Tree::Tree_insert(node *z)
{
    node *y=NULL;
    node *x=T_root;
    while(x!=NULL)
    {
        y=x;
        if(z->key<x->key)
            x=x->left;
        else x=x->right;
    }
    z->p=y;
    if(y==NULL)
        T_root=z;
    else if(z->key<y->key)
        y->left=z;
    else y->right=z;
}
Tree::Write(node *x)
{
    if(x!=NULL)
    {
        Write(x->left);
        cout<<x->key<<" ";
        Write(x->right);
    }
}
node* Tree::Tree_minimum(node *x)
{
    while(x->left!=NULL)
        x=x->left;
    return x;
}
node* Tree::Tree_maximum(node *x)
{
    while(x->right!=NULL)
        x=x->right;
    return x;
}
node* Tree::Tree_minimum()
{
    return Tree_minimum(T_root);
}
node* Tree::Tree_maximum()
{
    return Tree_maximum(T_root);
}
node* Tree::True_Succesor(node *x)
{
    if(x->right!=NULL)
        return Tree_minimum(x->right);
    node *y=x->p;
    while(y!=NULL && x==y->right)
    {
        x=y;
        y=x->p;
    }
    return y;
}
void Tree::Transplant(node *u,node *v)
{
    if(u->p==NULL)
        T_root=v;
    else if(u==u->p->left)
        u->p->left=v;
    else u->p->right=v;
    if(v!=NULL)
        v->p=u->p;
}
void Tree::Tree_delete(node *z)
{
    if(z->left==NULL)
        Transplant(z,z->right);
    else if(z->right==NULL)
        Transplant(z,z->left);
    else
    {
        node *y=Tree_minimum(z->right);
        if(y->p!=z)
        {
            Transplant(y,y->right);
            y->right=z->right;
            y->right->p=y;
        }
        Transplant(z,y);
        y->left=z->left;
        y->left->p=y;
    }
}
