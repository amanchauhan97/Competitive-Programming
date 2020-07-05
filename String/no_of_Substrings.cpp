#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;

    int cta=0 , ctb=0 , ctc=0;

    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='a')
          cta = (1 + 2*cta);
        else if(s[i] == 'b')
          ctb = (cta + 2*ctb);
        else
          ctc = (ctb + 2*ctc);
    }
    cout << "Total substrings = " << ctc << endl;
}
