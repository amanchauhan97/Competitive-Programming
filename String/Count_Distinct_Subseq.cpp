#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    vector<int> lastOcurr(256 , -1);
    vector<int> dp(s.size()+1,0);
    dp[0]=1;
    for(int i=1;i<=s.size();i++)
    {
        dp[i] = 2*dp[i-1];
        if(lastOcurr[s[i-1]] != -1)
          dp[i] -= dp[lastOcurr[s[i-1]]];
        lastOcurr[s[i-1]] = i-1;
    }
    cout << "Total distinct subseq : " << dp[s.size()] << endl;
}
