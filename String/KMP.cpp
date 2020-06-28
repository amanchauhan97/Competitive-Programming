#include<bits/stdc++.h>
using namespace std;

void Create_LPS(string pattern,vector<int> &lps)
{
    int j=0;
    for(int i=1;i<pattern.size();)
    {
        if(pattern[i] == pattern[j])
        {
            lps[i] = j+1;
            j++;
            i++;
        }
        else
        {
            if(j!=0)
                j = lps[j-1];
            else
            {
                lps[i] = 0;
                i++;
            }
            
        }
        
    }
}

void KMP(string text,string pattern)
{
    vector<int> lps(pattern.size(),0);
    Create_LPS(pattern,lps);
    int j=0;
    for(int i=0;i<text.size();)
    {
        if(text[i] == pattern[j])
        {
            j++;
            i++;
        }
        if(j == pattern.size())
        {
            cout << "Pattern found at index : " << i-j << endl;
            j=0;
            i++;
        }
        else if(i!=text.size() && text[i] != pattern[j])
        {
            if(j!=0)
                j=lps[j-1];
            else
            {
                i++;
            }         
        }
    }
}

int main()
{
    string pattern , text;
    cin >> text >> pattern;
    KMP(text,pattern);
}