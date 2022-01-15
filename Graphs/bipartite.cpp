#include <bits/stdc++.h>
using namespace std;

int n, m;
bool bipart;
vector<vector<int>> a(n);
vector<bool>v;
vector<int>color;

void Color(int idx, int curr)// curr is the color i wish to give
{
    if(color[idx]!=-1 && color[idx]!=curr)// if it is colored & it is not colored by curr
    {
        bipart=false;
        return;
    }
    color[idx]=curr;
    
    if(v[idx])
    {
        return;
    }
    v[idx]=true;
    
    for(auto i:a[idx])
    {
        Color(i, curr xor 1);// if color is 0, neighbour will be 1, else neighbour will be 0
    }
}

int main()
{
    cin>>n>>m;
    bipart=true;
    
    a=vector<vector<int>>(n);
    v=vector<bool>(n, false);
    color=vector<int>(n, -1);
    
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
            Color(i, 0);
        }
    }
    
    if(bipart)
    cout<<"graph is bipartite"<<endl;
    else
    cout<<"graph is not bipartite"<<endl;
}

//input
// 3 3
// 0 1
// 1 2
// 2 0

//output
// not bipartite

//input
// 4 4
// 0 1
// 1 2
// 2 3
// 3 0

//output
// bipartite