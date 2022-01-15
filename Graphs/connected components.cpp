#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> a(n);
vector<bool>v;
vector<int>compo;

int getComp(int idx)
{
    if(v[idx])
    {
        return 0;
    }
    v[idx]=true;
    int ans=1;
    
    for(auto i:a[idx])
    {
        if(!v[i])
        {
            ans+=getComp(i);
            v[i]=true;
        }
    }
    
    return ans;
}

int main()
{
    
    cin>>n>>m;
    
    a=vector<vector<int>>(n);
    v=vector<bool>(n);
    
    int x, y;
    
    for(int i=0;i<m;i++)
    {
        cin>>x>>y;
        
        a[x].push_back(y);
        a[y].push_back(x);

    }
    
    for(int i=0;i<n;i++)
    {
        if(!v[i])
        {
            compo.push_back(getComp(i));
        }
    }
    
    for(auto i:compo)// to print sizes of components found
    {
        cout<<i<<" ";
    }
}

//input
// 5 3
// 0 1
// 2 3
// 0 4

//output
// 3 2