#include <bits/stdc++.h>
using namespace std;

bool isCycle(int src, vector<vector<int>> &a, vector<bool> &v, int parent)
{
    v[src]=true;
    
    for(auto i:a[src])
    {
        if(i!=parent)
        {
            if(v[i])
            return true;
            
            if(!v[i] && isCycle(i, a, v, src))
            return true;
        }
    }
    
    return false;
}

int main()
{
    int n, m;
    cin>>n>>m;
    
    vector<vector<int>> a(n);
    
    int x, y;
    
    for(int i=0;i<m;i++)
    {
        cin>>x>>y;
        
        a[x].push_back(y);
        a[y].push_back(x);
    }
    
    bool c=false;
    
    vector<bool>v(n, false);
    
    for(int i=0;i<n;i++)
    {
        if(!v[i] && isCycle(i, a, v, -1))
        {
            c=true;
        }
    }
    
    if(c)
    cout<<"cycle present"<<endl;
    else
    cout<<"not cycle"<<endl;
}