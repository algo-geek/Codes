#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin>>n>>k;
    
    vector<int>a(n);
        
    for(int i=0;i<n;i++)
    cin>>a[i];
    
    int s=0, r=INT_MAX;
    
    for(int i=0;i<k;i++)
    s+=a[i];
    
    r=min(r, s);
    
    for(int i=1;i<n-k+1;i++)
    {
        s-=a[i-1];
        s+=a[i+k-1];
        
        r=min(r, s);
    }
    
    cout<<r<<endl;
}