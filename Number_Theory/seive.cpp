#include<bits/stdc++.h>
using namespace std;

#define MAX_SIZE 100001

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

int main()
{
    seive();
    for(int i=0;i<prime.size();i++)
      cout << prime[i] << " ";
    cout << endl;
}
