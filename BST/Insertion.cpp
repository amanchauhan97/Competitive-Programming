#include<bits/stdc++.h>
using namespace std;

class BST
{
    int data;
    BST *left , *right;
public:
    BST()
    {
        data = 0;
        left = right = NULL;
    }
    BST(int val)
    {
        data = val;
        left = right = NULL;
    }
    BST *insert_node(BST *root, int val)
    {
        if(!root)
            return new BST(val);
        if(root->data > val)
            root->left = insert_node(root->left , val);
        else
            root->right = insert_node(root->right , val);
        return root;
    }
    void inorder(BST *root)
    {
        if(!root)
            return;
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
};

int main()
{
    int n;
    cout << "Enter number of nodes : " ;
    cin >> n;
    BST *root = NULL;
    BST b;
    while(n--)
    {
        int d;
        cin >> d;
        root = b.insert_node(root , d);
    }
    b.inorder(root);
    cout << endl;
}
