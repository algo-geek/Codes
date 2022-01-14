#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin>>n>>k;
    
    vector<int>a(n);
        
    for(int j=0;j<n;j++)
    cin>>a[j];
    
    priority_queue<int, vector<int>> p;
    
    for(int j=0;j<n;j++)
    p.push(a[j]);
    
    int s=0, c=0;
    
    while(!p.empty())
    {
        s+=p.top();
        p.pop();
        
        c++;
        
        if(s>=k)
        break;
        
    }
    
    if(s<k)
    cout<<"-1"<<endl;
    else
    cout<<c<<endl;
    
}