#include <bits/stdc++.h>
using namespace std;

void APUtil(vector<int> adj[], int u, bool visited[], int disc[], int low[], int& time, stack<int>& s)
{

	
	disc[u] = low[u] = ++time;
	s.push(u);
	visited[u] = true;

	for (auto v : adj[u]) {

		if (disc[v]==0) {
			APUtil(adj, v, visited, disc, low, time, s);

			low[u] = min(low[u], low[v]);

		
		}

		else if (visited[v]==true)
			low[u] = min(low[u], disc[v]);
	}
	
	int w = 0;
	if (low[u] == disc[u]) 
	{ 
		while (s.top() != u) 
		{ 
			w = s.top(); 
			cout << w << " "; 
			visited[w] = false; 
			s.pop(); 
		} 
		w = s.top(); 
		cout << w << "\n"; 
		visited[w] = false; 
		s.pop(); 
	}

}

void AP(vector<int> adj[], int V)
{
	int disc[V] = { 0 };
	int low[V] = { 0 };
	bool visited[V] = { false };
	int time = 0;
	stack<int>s;

	for (int u = 0; u < V; u++)
		if (disc[u]==0)
			APUtil(adj, u, visited, disc, low, time, s);

}

void addEdge(vector<int> adj[], int u, int v)
{
	adj[u].push_back(v);
}

int main()
{
	cout << "SCC in the graph \n"; 
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
