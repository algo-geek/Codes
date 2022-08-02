#include<bits/stdc++.h>
using namespace std;
struct node {
    int u;
    int v;
    int wt; 
    node(int first, int second, int weight) {
        u = first;
        v = second;
        wt = weight;
    }
};

int main(){
    int N=4,m=5;
    vector<node> edges; 
	edges.push_back(node(0,1,1));
	edges.push_back(node(0,2,4));
	edges.push_back(node(1,2,-3));
	edges.push_back(node(2,3,3));
	edges.push_back(node(1,3,2));
    int src=0;
    // don't use INT_MAX--> error due to integer overflow
    int inf = 10000000; 
    vector<int> dist(N, inf); 
    dist[src] = 0; 
    for(int i = 1;i<=N-1;i++) {
        for(auto it: edges) {
            if(dist[it.u] + it.wt < dist[it.v]) {
                dist[it.v] = dist[it.u] + it.wt; 
            }
        }
    }

    int fl = 0; 
    for(auto it: edges) {
        if(dist[it.u] + it.wt < dist[it.v]) {
            cout << -1; 
            fl = 1; 
            break; 
        }
    }
    
    if(!fl) {
        for(int i = 0;i<N;i++) {
            cout << dist[i]<<" ";
        }
    }
    return 0;
}