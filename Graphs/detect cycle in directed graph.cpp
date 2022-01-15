#include <bits/stdc++.h>
using namespace std;

bool isCycle(int src, vector<vector<int>> &a, vector<bool> &v, vector<int> &stack)
{
    stack[src]=true;
    
    if(!v[src])
    v[src]=true;
    
    for(auto i:a[src])
    {
            if(!v[i] && isCycle(i, a, v, stack))
            return true;
            
            if(stack[i])
            return true;
    }
    stack[src]=false;
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

    }
    
    bool c=false;
    
    vector<bool>v(n, 0);
    vector<int>stack(n, 0);
    
    for(int i=0;i<n;i++)
    {
        if(!v[i] && isCycle(i, a, v, stack))
        {
            c=true;
        }
    }
    
    if(c)
    cout<<"cycle present"<<endl;
    else
    cout<<"not cycle"<<endl;
}

//input
// 4 3
// 0 1
// 1 2
// 2 1

//output
// cycle present

//input
// 4 2
// 0 1
// 2 3

//output
// not cycle