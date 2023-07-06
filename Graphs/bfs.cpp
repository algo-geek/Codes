#include <bits/stdc++.h>
using namespace std;

const int n=100002;
vector<int>a[n];
bool b[n];

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
    
    queue<int>p;
    p.push(1);
    b[1]=true;
    
    
    while(!p.empty())
    {
        int node = p.front();
        p.pop();
       
        cout<<node<<endl;
 
        vector<int> :: iterator it;
        
        for(it=a[node].begin();it!=a[node].end();it++)
        {
            if(!b[*it])
            {
                b[*it]=1;
                p.push(*it);
            }
        }
    }
    
    
}

//1st version // time: O(V+E)
#include<bits/stdc++.h> 
using namespace std; 

void BFS(vector<int> adj[], int V, int s) 
{ 
	bool visited[V]; 
	for(int i = 0; i < V; i++) 
		visited[i] = false; 

	queue<int>  q;
	
	visited[s] = true; 
	q.push(s); 

	// V component of time complexity 
	while(q.empty()==false) 
	{ 
		int u = q.front(); 
		q.pop();
		cout << u << " "; 

		// E component of time complexity
		for(int v:adj[u]){
		    if(visited[v]==false){
		        visited[v]=true;
		        q.push(v);
		    }
		} 
	} 
} 

void addEdge(vector<int> adj[], int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main() 
{ 
	int V=5;
	vector<int> adj[V];
	addEdge(adj,0,1); 
	addEdge(adj,0,2); 
	addEdge(adj,1,2); 
	addEdge(adj,2,3); 
	addEdge(adj,1,3);
	addEdge(adj,3,4);
	addEdge(adj,2,4);

	cout << "Following is Breadth First Traversal: "<< endl; 
	BFS(adj,V,0); 

	return 0; 
} 

//2nd version
#include<bits/stdc++.h> 
using namespace std; 

void BFS(vector<int> adj[], int s, bool visited[]) 
{ 	queue<int>  q;
	
	visited[s] = true; 
	q.push(s); 

	while(q.empty()==false) 
	{ 
		int u = q.front(); 
		q.pop();
		cout << u << " "; 
		 
		for(int v:adj[u]){
		    if(visited[v]==false){
		        visited[v]=true;
		        q.push(v);
		    }
		} 
	} 
}

void BFSDin(vector<int> adj[], int V){
    bool visited[V]; 
	for(int i = 0;i<V; i++) 
		visited[i] = false;
		
    for(int i=0;i<V;i++){
        if(visited[i]==false)
            BFS(adj,i,visited);
    }
}

void addEdge(vector<int> adj[], int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main() 
{ 
	int V=7;
	vector<int> adj[V];
	addEdge(adj,0,1); 
	addEdge(adj,0,2); 
	addEdge(adj,2,3); 
	addEdge(adj,1,3); 
	addEdge(adj,4,5);
	addEdge(adj,5,6);
	addEdge(adj,4,6);

	cout << "Following is Breadth First Traversal: "<< endl; 
	BFSDin(adj,V); 

	return 0; 
} 

