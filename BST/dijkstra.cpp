#include <bits/stdc++.h> 
using namespace std; 
#define V 4

vector<int>dijkstra(int graph[V][V], int src)
{
    vector<int>d(V,INT_MAX);
    d[src]=0;
    vector<bool>f(V,false);

    for(int i=0;i<V-1;i++)
    {
        int u=-1;
        if(!f[i] && (u==-1 || d[i]<d[u]))
        {
            u=i;
        }
        f[u]=true;

        for(int i=0;i<V;i++)
        {
            if(graph[u][i]!=0 && f[i]==false)
            {
                d[i]=min(d[i],d[u]+graph[u][i]);
            }
        }
    }
    return d;
}

int main() 
{ 
	int graph[V][V] = { { 0, 50, 100, 0}, 
						{ 50, 0, 30, 200 }, 
						{ 100, 30, 0, 20 }, 
						{ 0, 200, 20, 0 },}; 

	for(int x: dijkstra(graph,0)){
	    cout<<x<<" ";
	} 

	return 0; 
} 