#include<bits/stdc++.h>
using namespace std;

#define MAX_SIZE 10001

vector<bool> isprime(MAX_SIZE,true);
vector<int> prime;
vector<int> spf(MAX_SIZE);

void seive()
{
    isprime[0] = isprime[1] = false;
    for(int i=2;i<MAX_SIZE;i++)
    {
        if(isprime[i])
        {
            prime.push_back(i);
            spf[i] = i;
        }
        for(int j=0;j<prime.size() && i*prime[j]<MAX_SIZE && prime[j]<=spf[i];j++)
        {
            isprime[i*prime[j]] = false;
            spf[i*prime[j]] = prime[j];
        }
    }
}

int Power(int a,int n,int mod)
{
    if(n==0)
      return 1;
    int p = Power(a,n/2,mod);
    p = (p*p)%mod;
    if(n&1)
      p = (p*a)%mod;
    return p;
}

void GetLCM(vector<int> arr,int mod)
{
    unordered_map<int,int> factors;
    for(int i=0;i<arr.size();i++)
    {
        int n=arr[i];
        unordered_map<int,int> temp;
        while(n>1)
        {
            int factor = spf[n];
            temp[factor]++;
            n = n/factor;
        }
        for(auto it : temp)
          factors[it.first] = max(factors[it.first],it.second);
    }
    int lcm = 1;
    for(auto it : factors)
    {
        int x = Power(it.first , it.second , mod);
        lcm = (lcm * x % mod);
    }
    cout << "LCM = " << lcm << endl;
}
int main()
{
    seive();
    int n,mod;
    cin >> n >> mod;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
      cin >> arr[i];
    GetLCM(arr,mod);
}
