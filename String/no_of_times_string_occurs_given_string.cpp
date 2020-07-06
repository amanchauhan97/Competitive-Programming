#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s1,s2;
    cin >> s1 >> s2;

    int n1 = s1.size();
    int n2 = s2.size();

    int dp[n1+1][n2+1];
    memset(dp,0,sizeof(dp));

    for(int i=0;i<=n1;i++)
      dp[i][0] = 1;

    for(int i=1;i<=n1;i++)
    {
        for(int j=1;j<=n2;j++)
        {
            if(s1[i-1] == s2[j-1])
            {
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
            }
            else
              dp[i][j] = dp[i-1][j];
        }
    }

    cout << "ans = " << dp[n1][n2] << endl;
}
