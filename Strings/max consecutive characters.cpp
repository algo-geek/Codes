#include<bits/stdc++.h>
using namespace std;

int maxPower(string s) {
        
        int n=s.size();
        int c=1;
        int x=0, t=0;
        
        for(int i=0;i<n-1;i++)
        {
            if(s[i]==s[i+1])
            {
                c++;
            }
            else
            {
                c=1;
            }
            
            x=c;
            if(x>t)
            {
                t=x;
            }
        }
        if(n==1)
            return t+1;
        else
            return t;       
        
    }

int main()
{
    string s;
    cin>>s;

    cout<<maxPower(s)<<endl;

}    