#include<iostream>
using namespace std;

class node
{
    public:
    node *left;
    node *right;
    node *p; //parent
    int key;
    node();
    node(int);
    bool operator==(int);
    operator=(node);
    //friend ostream& operator<<(ostream&, node&);
    friend istream& operator>>(istream&, node&);
    friend class Tree;
};
class Tree
{
    public:
    node *T_root;
    Tree();
    Tree_root(node*);
    Tree_insert(node*);
    Write(node*);
    node* Tree_minimum(node*);
    node* Tree_maximum(node*);
    node* Tree_minimum();
    node* Tree_maximum();
    node* True_Succesor(node*);
    void Transplant(node*,node*);
    void Tree_delete(node*);
};
