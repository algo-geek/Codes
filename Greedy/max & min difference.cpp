#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    
    vector<int>a(n);
        
    for(int i=0;i<n;i++)
    cin>>a[i];
    
    sort(a.begin(), a.end());
    
    long long int max=0, min=0;
    
    for(int i=0;i<n/2;i++)
    {
        max += (a[i+n/2] - a[i]);
        min += (a[2*i+1] - a[2*i]);
    }
    
    cout<<max<<" "<<min<<endl;
}