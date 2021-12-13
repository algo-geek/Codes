#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    
    int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
    
    int r=0;
    
    for(int i=0;i<n;i++)
    {
        int minh=INT_MAX;
        
        for(int j=i;j<n;j++)
        {
            minh=min(a[j], minh);
            int l=j-i+1;
            r=max(r, l*minh);
        }
    }
    
    cout<<r<<endl;
}