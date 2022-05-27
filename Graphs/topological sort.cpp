// BFS (Kahn's Algo)
#include<bits/stdc++.h> 
using namespace std; 

void topologicalSort(vector<int> adj[], int V) 
{ 
    vector<int> in_degree(V, 0); 
  
    for (int u = 0; u < V; u++) { 
        for (int x:adj[u]) 
            in_degree[x]++; 
    } 
  
    queue<int> q; 
    for (int i = 0; i < V; i++) 
        if (in_degree[i] == 0) 
            q.push(i); 

  
    while (!q.empty()) { 
        int u = q.front(); 
        q.pop(); 
        cout<<u<<" "; 
  
        for (int x: adj[u]) 
            if (--in_degree[x] == 0) 
                q.push(x); 
    } 
}

void addEdge(vector<int> adj[], int u, int v){
    adj[u].push_back(v);
}

int main() 
{ 
	int V=5;
	vector<int> adj[V];
	addEdge(adj,0, 2); 
    addEdge(adj,0, 3); 
    addEdge(adj,1, 3); 
    addEdge(adj,1, 4); 
    addEdge(adj,2, 3);  
  
    cout << "Following is a Topological Sort of\n"; 
    topologicalSort(adj,V);

	return 0; 
} 

// DFS
#include<bits/stdc++.h>
using namespace std;

void DFSRec(vector<int> adj[], int u, stack<int> &st, bool visited[])
{
    visited[u]=true;

    for(int v:adj[u])
    {
        if(visited[v]==false)
        {
            DFSRec(adj, v, st, visited);
        }
    }
    st.push(u);
}

void topologicalSort(vector<int> adj[], int V)
{
    bool visited[V];
    for(int i=0;i<V;i++)
        visited[i]=false;

    stack<int>st;

    for(int i=0;i<V;i++){
        if(visited[i]==false)
            DFSRec(adj,i,st,visited);
    }

    while(!st.empty())
    {
        int u=st.top();
        st.pop();
        cout<<u<<" ";
    }
}

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
}

int main()
{
    int V=5;
    vector<int>adj[V];
    addEdge(adj,0,1);
    addEdge(adj,1,3);
    addEdge(adj,2,3);
    addEdge(adj,3, 4); 
    addEdge(adj,2, 4);

    topologicalSort(adj,V);

    return 0;
}


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


