#include<bits/stdc++.h>
using namespace std;

int power(int a,int n,int mod)
{
    if(n==0)
      return 1;
    int p = power(a , n/2 , mod);
    p = (p * p) % mod;
    if(n&1)
      p = (p * a) % mod;
    return p;
}

int main()
{
    int a,n,mod;
    cin >> a >> n >> mod;
    cout << power(a,n,mod) << endl;
}
