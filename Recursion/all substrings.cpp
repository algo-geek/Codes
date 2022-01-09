#include <bits/stdc++.h>
using namespace std;

void subseq(string s, string ans)
{
    if(s.size()==0)
    {cout<<ans<<endl;// c "" //
    return;}
    
    char ch=s[0];//a b c
    string ros=s.substr(1);//bc c
    
    subseq(ros, ans);
    subseq(ros, ans+ch);
}

int main()
{
    subseq("ABC", "");
}