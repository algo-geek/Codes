#include <bits/stdc++.h>
using namespace std;

void permutations(string s, string ans)
{
    if(s.size()==0)
    {cout<<ans<<endl;
    return;}
    
    for(int i=0;i<s.size();i++)// 0 // 1 // 2
    {
        char ch=s[i];// A // B // C
        string ros=s.substr(0, i)+s.substr(i+1);//BC // 
        
        permutations(ros, ans+ch);

    }
    
}

int main()
{
    permutations("ABC", "");
}