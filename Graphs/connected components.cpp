#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> a(n);
vector<bool>v;
vector<int>compo;

int getComp(int idx)
{
    if(v[idx])
    {
        return 0;
    }
    v[idx]=true;
    int ans=1;
    
    for(auto i:a[idx])
    {
        if(!v[i])
        {
            ans+=getComp(i);
            v[i]=true;
        }
    }
    
    return ans;
}

int main()
{
    
    cin>>n>>m;
    
    a=vector<vector<int>>(n);
    v=vector<bool>(n);
    
    int x, y;
    
    for(int i=0;i<m;i++)
    {
        cin>>x>>y;
        
        a[x].push_back(y);
        a[y].push_back(x);

    }
    
    for(int i=0;i<n;i++)
    {
        if(!v[i])
        {
            compo.push_back(getComp(i));
        }
    }
    
    for(auto i:compo)// to print sizes of components found
    {
        cout<<i<<" ";
    }
}

//input
// 5 3
// 0 1
// 2 3
// 0 4

//output
// 3 2

// By BFS
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
		 
		for(int v:adj[u]){
		    if(visited[v]==false){
		        visited[v]=true;
		        q.push(v);
		    }
		} 
	} 
}

int BFSDin(vector<int> adj[], int V){
    bool visited[V]; int count=0;
	for(int i = 0;i<V; i++) 
		visited[i] = false;
		
    for(int i=0;i<V;i++){
        if(visited[i]==false)
            {
                BFS(adj,i,visited);
                count++;
            }
    }

    return count;
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

	cout << "Number of islands: "<<BFSDin(adj,V); 

	return 0; 
} 

//By DFS
#include<bits/stdc++.h> 
using namespace std; 

void DFSRec(vector<int> adj[], int s, bool visited[]) 
{ 	
    visited[s]=true;
    
    for(int u:adj[s]){
        if(visited[u]==false)
            DFSRec(adj,u,visited);
    }
}

int DFS(vector<int> adj[], int V){
    int count=0;
    bool visited[V]; 
	for(int i = 0;i<V; i++) 
		visited[i] = false;
		
    for(int i=0;i<V;i++){
        if(visited[i]==false)
            {
                DFSRec(adj,i,visited);
                count++;
            }
    }
    return count;
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
	addEdge(adj,3,4);

	cout << "Number of connected components: "<< DFS(adj,V); 

	return 0; 
} 

