#include<bits/stdc++.h>
using namespace std;

int getCount(string s1,string s2,int n1,int n2)
{
    if((n1==0 && n2==0) || n2==0)
      return 1;
    if(n1==0)
      return 0;
    if(s1[n1-1] == s2[n2-1])
      return getCount(s1,s2,n1-1,n2-1) + getCount(s1,s2,n1-1,n2);
    else
      return getCount(s1,s2,n1-1,n2);
}

int main()
{
    string s1,s2;
    cin >> s1 >> s2;

    int ct = getCount(s1,s2,s1.size(),s2.size());

    cout << "ans = " << ct << endl;
}
