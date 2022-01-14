#include <bits/stdc++.h>
using namespace std;

const int n=100002;
vector<int>a[n];
bool b[n];

void dfs(int node)
{
    //preorder
    b[node]=1;
    // cout<<node<<" ";
    
    //inorder
     vector<int> :: iterator it;
        
        for(it=a[node].begin();it!=a[node].end();it++)
        {
            if(!b[*it])
            {
                dfs(*it);
            }
        }
        
        //postorder
        cout<<node<<" ";
    
}

int main()
{
    for(int i=0;i<n;i++)
    b[i]=0;
    
    int n, m;
    cin>>n>>m;
    
    int x, y;
    
    for(int i=0;i<m;i++)
    {
        cin>>x>>y;
        
        a[x].push_back(y);
        a[y].push_back(x);
    }
    
   dfs(1);
    
}