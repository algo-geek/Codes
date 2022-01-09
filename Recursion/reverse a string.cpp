#include <bits/stdc++.h>
using namespace std;

void revstr(string s)
{
    if(s.size()==0)
    return;
    
    string r=s.substr(1);
    //cout<<r<<endl;
    revstr(r);
    cout<<s[0]<<endl;
}

int main()
{
    string s;
    cin>>s;
    revstr(s);
}