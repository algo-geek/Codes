#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

int main()
{
    string s = "abcdefghijklmno";
    cout<<'a'-'A'<<endl;
    
    for(int i=0;i<s.size();i++)
    {
        if(s[i]>='a' && s[i]<='z')
        s[i]-=32;
    }
    
    cout<<s<<endl;
    
       for(int i=0;i<s.size();i++)
    {
        if(s[i]>='A' && s[i]<='Z')
        s[i]+=32;
    }
    
    cout<<s<<endl;


    // method 2
    
    // string s = "abcdefghijklmno";
    // transform(s.begin(), s.end(), s.begin(), ::toupper);
    // cout<<s<<endl;
    //  transform(s.begin(), s.end(), s.begin(), ::tolower);
    //  cout<<s<<endl;

}