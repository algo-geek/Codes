

// backtracking
// time: O(m^V). // There are total O(m^V) combination of colors. 
// space: O(V). // Recursive Stack of graphColoring(…) function will require O(V) space.
#include <bits/stdc++.h>
using namespace std;

#define V 4

/* A utility function to check if the current color assignment is safe for vertex v i.e. checks
  whether the edge exists or not (i.e, graph[v][i]==1). If exist then checks whether the color to
  be filled in the new vertex(c is sent in the parameter) is already used by its adjacent
  vertices(i-->adj vertices) or not (i.e, color[i]==c) */ 
bool isSafe(int v, bool graph[V][V], int color[], int c)
{
	for(int i = 0; i < V; i++)
		if (graph[v][i] && c == color[i])
			return false;
			
	return true;
}

bool graphColoringUtil(bool graph[V][V], int m, int color[], int v)
{
	if (v == V)
		return true;

	for(int c = 1; c <= m; c++)
	{
		if (isSafe(v, graph, color, c))
		{
			color[v] = c;

			if (graphColoringUtil(graph, m, color, v + 1) == true)
				return true;

			color[v] = 0;
		}
	}

	return false;
}

void printSolution(int color[])
{
	cout << "Solution Exists:"
		<< " Following are the assigned colors"
		<< "\n";
	for(int i = 0; i < V; i++)
		cout << " " << color[i] << " ";
		
	cout << "\n";
}

bool graphColoring(bool graph[V][V], int m)
{
	
	// Initialize all color values as 0.
	// This initialization is needed for
	// correct functioning of isSafe()
	int color[V];
	for(int i = 0; i < V; i++)
		color[i] = 0;

	// Call graphColoringUtil() for vertex 0
	if (graphColoringUtil(graph, m, color, 0) == false)
	{
		cout << "Solution does not exist";
		return false;
	}

	printSolution(color);
	return true;
}

int main()
{
	
	/* Create following graph and test
	whether it is 3 colorable
	(3)---(2)
	| / |
	| / |
	| / |
	(0)---(1)
	*/
	bool graph[V][V] = { { 0, 1, 1, 1 },
						{ 1, 0, 1, 0 },
						{ 1, 1, 0, 1 },
						{ 1, 0, 1, 0 }, };
						
	// at max Number of colors 
	int m = 3;
	graphColoring(graph, m);
	return 0;
}

// graph
//time: O(V + E).
//space: O(V) for visited list
#include <bits/stdc++.h>
using namespace std;

class node
{
public:
	int color = 1;
	set<int> edges;
};

int canPaint(vector<node>& nodes, int n, int m)
{
	vector<int> visited(n + 1, 0);
	int maxColors = 1;

	for (int sv = 1; sv <= n; sv++)
	{

		if (visited[sv])
			continue;

		visited[sv] = 1;
		queue<int> q;
		q.push(sv);

		while (!q.empty())
		{

			int top = q.front();
			q.pop();

			for (auto it = nodes[top].edges.begin(); it != nodes[top].edges.end(); it++)
			{

				//If the color of the adjacent node is same, increase it by 1
				if (nodes[top].color == nodes[*it].color)
					nodes[*it].color += 1;

				maxColors = max(maxColors, max(nodes[top].color, nodes[*it].color));
				if (maxColors > m)
					return 0;

				if (!visited[*it]) 
                {
					visited[*it] = 1;
					q.push(*it);
				}
			}
		}
	}

	return 1;
}

int main()
{
	
	int n = 4;
	bool graph[n][n] = {
	{ 0, 1, 1, 1 },
	{ 1, 0, 1, 0 },
	{ 1, 1, 0, 1 },
	{ 1, 0, 1, 0 }};
	int m = 3; 

	// The zeroth position is just
	// dummy (1 to n to be used)
	vector<node> nodes(n + 1);

	for (int i = 0; i < n; i++)
	{
		for(int j =0;j<n;j++)
		{
			if(graph[i][j])
			{
				// Connect the undirected graph
				nodes[i].edges.insert(i);
				nodes[j].edges.insert(j);
			}
		}
	}

		cout << canPaint(nodes, n, m);
		cout << "\n";
	
	return 0;
}
