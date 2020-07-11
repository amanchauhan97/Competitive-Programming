#include<bits/stdc++.h>
using namespace std;

unordered_set<string> newSubseq;

void generateAllSubseq(string s,char *op,int i,int j)
{
    if(i == s.size())
    {
        op[j] = '\0';
        newSubseq.insert(op);
        return;
    }
    op[j] = s[i];
    generateAllSubseq(s,op,i+1,j+1);
    generateAllSubseq(s,op,i+1,j);
    return;
}

int main()
{
    string s;
    cin >> s;
    char op[s.size()+1];
    generateAllSubseq(s,op,0,0);

    unordered_set<string> :: iterator itr;
    for(itr = newSubseq.begin() ; itr != newSubseq.end() ; itr++)
      cout << *itr << " , ";
    cout << endl;
}
