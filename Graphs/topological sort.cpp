#include <bits/stdc++.h>
using namespace std;


int main()
{
    
    int n, m;
    cin>>n>>m;
    
    vector<vector<int>> a(n);
    vector<int>in(n, 0);
    
    int x, y;
    
    for(int i=0;i<m;i++)
    {
        cin>>x>>y;
        
        a[x].push_back(y);
        in[y]++;
    }
    
    queue<int>p;
    
    for(int i=0;i<n;i++)
    {
        if(in[i]==0)
        p.push(i);
    }
    
    int c=0;
    
    while(!p.empty())
    {
        c++;
        int x = p.front();
        p.pop();
       
        cout<<x<<endl;
 
        vector<int> :: iterator it;
        
        for(it=a[x].begin();it!=a[x].end();it++)
        {
            in[*it]--;
            
            if(in[*it]==0)
            p.push(*it);
        }
    }
}

// input
// 4 3
// 0 1
// 1 2
// 2 3

//output
// 0
// 1
// 2
// 3

// input
// 3 3
// 0 1
// 1 2
// 2 0

//output
// 

// input
// 4 4
// 0 1
// 1 2
// 2 3
// 3 1

//output
// 0 (all elements will not appear as here a cycle is formed)