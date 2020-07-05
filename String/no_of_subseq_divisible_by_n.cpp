#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    int n;
    cin >> s >> n;

    vector<vector<int> > dp(s.size() , vector<int>(n,0));

    dp[0][(int)((s[0]-'0')%n)]++;
    for(int i=1;i<s.size();i++)
    {
        dp[i][(int)((s[i]-'0')%n)]++;

        for(int j=0;j<n;j++)
        {
            // exclude s[i]
            dp[i][j] += dp[i-1][j];
            // include s[i]
            dp[i][(int)((j*10 + (s[i]-'0'))%n)] += dp[i-1][j];
        }
    }

    cout << "Number of subsequences divisible by " << n << " = " << dp[s.size()-1][0] << endl;
}
