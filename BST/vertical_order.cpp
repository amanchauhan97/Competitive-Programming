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
    void verical_order(BST* root)
    {
        map<int,vector<int> > m;
        queue<pair<BST* , int> > q;
        q.push(make_pair(root,0));
        int ct = 0;
        while(!q.empty())
        {
            pair<BST*,int> temp = q.front();
            ct = temp.second;
            m[ct].push_back((temp.first)->data);
            q.pop();
            if((temp.first)->left)
                q.push(make_pair((temp.first)->left,ct-1));
            if((temp.first)->right)
                q.push(make_pair((temp.first)->right,ct+1));
        }
        map<int,vector<int> > :: iterator itr;
        for(itr = m.begin() ; itr != m.end() ; itr++)
        {
            vector<int> v = itr->second;
            for(int i=0;i<v.size();i++)
                cout << v[i] << " ";
            cout << endl;
        }
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
    b.verical_order(root);
}
