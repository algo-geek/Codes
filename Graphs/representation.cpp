#include <bits/stdc++.h>
using namespace std;

vector<int>a[100002];

int main()
{
    int n, m;
    cin>>n>>m;
    
    vector<vector<int>> adj(n+1, vector<int>(n+1,0));
    
    int x, y;
    
    for(int i=0;i<n;i++)
    {
        cin>>x>>y;
        
        adj[x][y]=1;
        adj[y][x]=1;
    }
    
    cout<<"adjacency matrix of above graph:"<<endl;
    
    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<n+1;j++)
        {
            cout<<adj[i][j]<<" ";
        }
        
        cout<<endl;
    }
    
    if(adj[3][7]==1)
    cout<<"there is an edge between 3 & 7"<<endl;
    else
    cout<<"no edge"<<endl;
    
    cout<<endl;
    
    for(int i=0;i<m;i++)
    {
        cin>>x>>y;
        
        a[x].push_back(y);
        a[y].push_back(x);
    }
    
    cout<<"adjacency list:"<<endl;
    
    for(int i=1;i<n+1;i++)
    {
        cout<<i<<" -> ";
        for(int j:a[i])
        {
            cout<<j<<" ";
        }
        
        cout<<endl;
    }
}
