#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin>>n>>k;
    
    vector<int>a(n);
        
    for(int i=0;i<n;i++)
    cin>>a[i];
    
    map<int, int>f;
    
    for(int i=0;i<n;i++)
    {
        int presentSize=f.size();
        
        if(f[a[i]]==0 && presentSize==k)// reaching k+1 th element
        break;
        else
        f[a[i]]++;
        
    }
    
    vector<pair<int, int>>r;
    
    map<int, int> :: iterator it;
    
    for(it=f.begin();it!=f.end();it++)
    {
        if(it->second != 0)
        r.push_back(make_pair(it->second, it->first));
    }
    
    sort(r.begin(), r.end(), greater<pair<int, int>>());
    
    vector<pair<int, int>> :: iterator x;
    
    for(x=r.begin();x!=r.end();x++)
    {
        cout<<x->second<<" "<<x->first<<endl;
    }
    
}