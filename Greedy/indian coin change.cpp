#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, x;
    cin>>n>>x;
    
    vector<int>a(n);
        
    for(int i=0;i<n;i++)
    cin>>a[i];
    
    sort(a.begin(), a.end(), greater<int>());
    
    int r=0;
    
    for(int i=0;i<n;i++)
    {
        r+=(x/a[i]);
        x-= x/a[i] * a[i];
    }
    
    cout<<r<<endl;
    
}