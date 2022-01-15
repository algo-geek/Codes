#include <bits/stdc++.h>
using namespace std;

const int n=100006;
vector<int>parent(n);
vector<int>size(n);

void make_set(int v)
{
    parent[v]=v;
    size[v]=1;
}

int find_set(int v)
{
    if(v==parent[v])
    {
        return v;
    }
    return parent[v]=find_set(parent[v]);
}

void union_set(int a, int b)
{
    a=find_set(a);
    b=find_set(b);
    
    if(a!=b)
    {
        if(size[a]<size[b])
        {
            swap(a, b);
        }
        parent[b]=a;
        size[a]+=size[b];
        
    }
}

int main()
{
    for(int i=0;i<n;i++)
    {
        make_set(i);
    }
    
    int n, m;
    cin>>n>>m;

    vector<vector<int>>edges;
    
    int x, y;
    
    for(int i=0;i<m;i++)
    {
        cin>>x>>y;
        
        edges.push_back({x, y});

    }
    
    bool cyc=false;
    
    for(auto i:edges)
    {
        int u=i[0];
        int v=i[1];
        
        int c=find_set(u);
        int d=find_set(v);
        
        if(c==d)
        cyc=true;
        else
        union_set(u, v);
    }
    
    if(cyc)
    cout<<"cycle"<<endl;
    else
    cout<<"not cycle"<<endl;
}

// input
// 4 4
// 0 1
// 1 2
// 2 3
// 3 0

//cycle

// input
// 4 2
// 0 1
// 2 3

// not cycle