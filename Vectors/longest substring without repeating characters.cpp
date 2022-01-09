#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin>>s;
    
    vector<int>v(256, -1);
    
    int l=0, st=-1;
    
    for(int i=0;i<s.size();i++)
    {
        if(v[s[i]]>st)
        st=v[s[i]];
        
        v[s[i]]=i;
        l=max(l, i-st);
    }
    
    cout<<l<<endl;
}