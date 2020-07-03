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

void BST_To_DLL(node *root,node **head)
{
    if(root == NULL)
      return;

    static node *prev = NULL;

    BST_To_DLL(root->left,head);

    if(prev == NULL)
      *head = root;
    else
    {
        root->left = prev;
        prev->right = root;
    }

    prev = root;

    BST_To_DLL(root->right,head);
}

void displayDLL(node *head)
{
    cout << "DLL : ";
    while(head)
    {
      cout << head->data << " ";
      head = head->right;
    }
    cout << endl;
}

int main()
{
    node *root = NULL;
    root = insert(root);
    inorder(root);
    cout << endl;
    node *head = NULL;
    BST_To_DLL(root,&head);
    displayDLL(head);
    return 0;
}
