#include<bits/stdc++.h>
using namespace std;

#define MAX_SIZE 100005

void multiply(int res[],int n,int &sz)
{
    int carry = 0;
    for(int i=0;i<sz;i++)
    {
        int prd = res[i] * n + carry;
        res[i] = prd % 10;
        carry = prd / 10;
    }
    while(carry != 0)
    {
        res[sz] = carry%10;
        carry = carry/10;
        sz++;
    }
}

int main()
{
    int n;
    cin >> n;
    int res[MAX_SIZE];
    int sz = 1;
    res[0] = 1;
    for(int i=2; i<=n ; i++)
    {
        multiply(res,i,sz);
    }
    for(int i=sz-1 ; i>=0 ; i--)
            cout << res[i] << " ";
    cout << endl;
}
