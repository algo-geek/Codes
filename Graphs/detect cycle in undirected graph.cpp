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

// by DFS
#include<bits/stdc++.h> 
using namespace std; 

bool DFSRec(vector<int> adj[], int s,bool visited[], int parent) 
{ 	
    visited[s]=true;
    
    for(int u:adj[s]){
        if(visited[u]==false){
            if(DFSRec(adj,u,visited,s)==true)
                {return true;}}
        else if(u!=parent)
            {return true;}
    }
    return false;
}

bool DFS(vector<int> adj[], int V){
    bool visited[V]; 
	for(int i=0;i<V; i++) 
		visited[i] = false;
		
    for(int i=0;i<V;i++){
        if(visited[i]==false)
            if(DFSRec(adj,i,visited,-1)==true)
                return true;
    }
    return false;
}

void addEdge(vector<int> adj[], int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main() 
{ 
	int V=6;
	vector<int> adj[V];
	addEdge(adj,0,1); 
	addEdge(adj,1,2); 
	addEdge(adj,2,4); 
	addEdge(adj,4,5); 
	addEdge(adj,1,3);
	addEdge(adj,2,3);

	if(DFS(adj,V))
	    cout<<"Cycle found";
	else
	    cout<<"No cycle found";

	return 0; 
} 
