
// using BFS. // time:O(V+2E)- 2E because sum of all adj vertices=sum of degree=2E
// space: O(V)
#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[], int u, int v)
{
	adj[u].push_back(v);
	adj[v].push_back(u);
}

bool isCyclicConnected(vector<int> adj[], int s, int V, vector<bool>& visited)
{
	vector<int> parent(V, -1);
	queue<int> q;

	visited[s] = true;
	q.push(s);

	while (!q.empty()) {
		int u = q.front();
		q.pop();

		for (auto v : adj[u]) {
			if (!visited[v]) {
				visited[v] = true;
				q.push(v);
				parent[v] = u;
			}
			else if (parent[u] != v)
				return true;
		}
	}
	return false;
}

bool isCyclicDisconnected(vector<int> adj[], int V)
{
	vector<bool> visited(V, false);

	for (int i = 0; i < V; i++)
		if (!visited[i] && isCyclicConnected(adj, i, V, visited))
			return true;
	return false;
}

int main()
{
	int V = 4;
	vector<int> adj[V];
	addEdge(adj, 0, 1);
	addEdge(adj, 1, 2);
	addEdge(adj, 2, 0);
	addEdge(adj, 2, 3);

	if (isCyclicDisconnected(adj, V))
		cout << "Yes";
	else
		cout << "No";

	return 0;
}



// by DFS // time:O(v+E)
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

	// for disconnected graphs
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
