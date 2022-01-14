#include <bits/stdc++.h>
using namespace std;

int main()
{
     int n;
    cin>>n;
    
    vector<int>a(n);
        
    for(int i=0;i<n;i++)
    cin>>a[i];
    
    int s=0;
    
    map<int, int>c;
    
    for(int i=0;i<n;i++)
    {
        s+=a[i];
        c[s]++;
    }
    
    int r=0;
    
    map<int, int> :: iterator it;
    
    for(it=c.begin();it!=c.end();it++)
    {
        int a=it->second;
        r += (a*(a-1))/2;
        
        if(it->first==0)
        r+=it->second;
    }
    
    cout<<r<<endl;
}