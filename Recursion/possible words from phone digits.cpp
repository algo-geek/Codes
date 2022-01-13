#include <bits/stdc++.h>
using namespace std;

string a[]={"", "./", "abc", "def", "ghi", "jkl", "mno", "prqs", "tuv", "xyz"};

void keypad(string s, string ans)
{
    if(s.size()==0)
    {cout<<ans<<endl;
    return;}
    
    char ch=s[0];//2
    string code=a[ch-'0'];// a[2] // to change char to integer
    string ros=s.substr(1);//3
    
    for(int i=0;i<code.size();i++)// abc
    keypad(ros, ans+code[i]);
    
}

int main()
{  
    keypad("23", "");
}