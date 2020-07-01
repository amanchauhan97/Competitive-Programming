#include<bits/stdc++.h>
using namespace std;

class node
{
    public:
    int data;
    node *left , *right;

    node(int d)
    {
        data = d;
        left = right = NULL;
    }
};

node *insert(node *root)
{
    int d;
    cin >> d;
    if(d==-1)
        return NULL;
    root = new node(d);
    root->left = insert(root);
    root->right = insert(root);
    return root;
}

void inorder(node *root)
{
    if(root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main()
{
    node *root = NULL;
    root = insert(root);
    inorder(root);
    cout << endl;
    return 0;
}