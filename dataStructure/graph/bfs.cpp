vector<int> bfsOfGraph(int V, vector<int> adj[]) {
    vector<bool> visited(V, false);
    queue<int> q;
    vector<int> result;

    int start = 0;
    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        result.push_back(u);

        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }

    return result;
}