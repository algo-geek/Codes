// O(v+e) time & O(v) space
// dfs
bool dfs(int root, vector<vector<int>>& graph, vector<int>& col, int color){
    col[root]=color;
    for(auto i:graph[root]){
        if( (col[i]==-1 && !dfs(i,graph,col,1-color)) || (col[i]==color) )return false;
    }
    return true;
}
bool isBipartite(vector<vector<int>>& graph) {
    int n=graph.size();
    vector<int>col(n,-1);
    for(int i=0;i<n;i++)
    {
        if(col[i]==-1){
            if(!dfs(i, graph, col, 0))return false;
        }
    }
    return true;
}

// bfs
bool isBipartite(int V, vector<vector<int>> &edges) {
    vector<int> color(V, -1);
    vector<vector<int>> adj = constructadj(V,edges);
    queue<int> q;
    // Iterate through all vertices to handle disconnected graphs
    for(int i = 0; i < V; i++) {
        // If the vertex is uncolored, start BFS from it
        if(color[i] == -1) {
            // Assign first color (0) to the starting vertex
            color[i] = 0;
            q.push(i);

            while(!q.empty()) {
                int u = q.front();
                q.pop();
                // Traverse all adjacent vertices
                for(auto &v : adj[u]) {
                    // If the adjacent vertex is uncolored,
                    // assign alternate color
                    if(color[v] == -1) {
                        color[v] = 1 - color[u];
                        q.push(v);
                    }
                    // If the adjacent vertex has the same color,
                    // graph is not bipartite
                    else if(color[v] == color[u]) {
                        return false;
                    }
                }
            }
        }
    }    
    return true;
}

