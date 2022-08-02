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
	
	// if cyclic return false	
    if (DFSRec(adj, 0, visited, -1)==true)
        return false;
 
    // checking for connectivity---
    // If we find a vertex which is not reachable from 0
    // (not marked by DFSRec(), it means graph is disconnected and we return false
    for (int u = 0; u < V; u++)
        if (!visited[u])
           return false;
           
    return true;
}

void addEdge(vector<int> adj[], int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main() 
{ 
	int V=5;
	vector<int> adj[V];
	addEdge(adj,1,0); 
	addEdge(adj,0,2); 
	addEdge(adj,2,1); 
	addEdge(adj,0,3); 
	addEdge(adj,3,4); 

	if(DFS(adj,V))
	    cout<<"Tree";
	else
	    cout<<"Not tree";

	return 0; 
} 