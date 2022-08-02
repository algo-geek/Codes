#include <bits/stdc++.h>
using namespace std;

void APUtil(vector<int> adj[], int u, bool visited[], int disc[], int low[], int& time, int parent[])
{

	visited[u] = true;
	disc[u] = low[u] = ++time;

	for (auto v : adj[u]) {

		if (!visited[v]) {
			parent[v]=u;
			APUtil(adj, v, visited, disc, low, time, parent);

			low[u] = min(low[u], low[v]);

			if (low[v] > disc[u]) 
			cout << u <<" " << v << endl; 
		}

		else if (v != parent[u])
			low[u] = min(low[u], disc[v]);
	}

}

void AP(vector<int> adj[], int V)
{
	int disc[V] = { 0 };
	int low[V];
	bool visited[V] = { false };
	int parent[V] = { -1 };
	int time = 0;

	for (int u = 0; u < V; u++)
		if (!visited[u])
			APUtil(adj, u, visited, disc, low, time, parent);

}

void addEdge(vector<int> adj[], int u, int v)
{
	adj[u].push_back(v);
	adj[v].push_back(u);
}

int main()
{
	cout << "Bridges in first graph \n"; 
	int V = 5;
	vector<int> adj[V]; 
	addEdge(adj, 1, 0); 
	addEdge(adj, 0, 2); 
	addEdge(adj, 2, 1); 
	addEdge(adj, 0, 3); 
	addEdge(adj, 3, 4); 
	AP(adj, V);

	return 0;
}
