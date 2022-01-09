#include <bits/stdc++.h>
using namespace std;

string moveallX(string s)
{
    if(s.size()==0)
    return "";
    
    char ch=s[0];
    string ans = moveallX(s.substr(1));
    
    if(ch=='x')
    {
        return (ans+ch);
    }
    return (ch+ans);
    
}

int main()
{
    string s;
    cin>>s;//abxxcxdexf
    cout<<moveallX(s);
}
