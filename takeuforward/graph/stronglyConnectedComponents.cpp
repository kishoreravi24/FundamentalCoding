#include <bits/stdc++.h>

class Solution {
public:
    std::stack<int> st;  // Moved the stack declaration outside of the functions
    std::vector<int> reverse_adj[100];  // Increased the size of reverse_adj to a fixed value

    void topologicalSort(std::vector<int> adj[], std::vector<bool> &visited, int start) {
        visited[start] = true;
        for (auto i : adj[start]) {
            if (!visited[i]) {
                topologicalSort(adj, visited, i);
            }
        }
        st.push(start);
    }

    std::vector<int>* transposeG(std::vector<std::vector<int>>& edges) {
        for (auto edge : edges) {
            int u = edge[0];
            int v = edge[1];
            reverse_adj[v].push_back(u);
        }
        return reverse_adj;
    }

    void checkDfs(std::vector<int> reverse_adj[], std::vector<bool> &visited, int node, std::vector<int> &res) {
        visited[node] = true;
        for (auto index : reverse_adj[node]) {
            if (!visited[index]) {
                checkDfs(reverse_adj, visited, index, res);
            }
        }
        res.push_back(node);

    void solve(std::vector<std::vector<int>>& edges, int v, std::vector<int> adj[]) {
        std::vector<bool> visited(v, false);

        for (int i = 0; i < v; i++) {
            if (!visited[i]) {
                topologicalSort(adj, visited, i);
            }
        }

        std::vector<int>* reverse_adj = transposeG(edges);

        visited.assign(v, false);
        std::vector<int> res;
        while (!st.empty()) {
            int node = st.top();
            st.pop();
            if (!visited[node]) {
                checkDfs(reverse_adj, visited, node, res);
            }
        }

        for (auto index : res) {
            std::cout << index << " ";
        }
        return;
    }

    void scc(std::vector<std::vector<int>>& edges) {
        int n = edges.size(); 
        std::vector<int> adj[n];
        for (auto index : edges) {
            int u = index[0];
            int v = index[1];
            adj[u].push_back(v);
        }
        solve(edges, n, adj);
    }
};

int main() {
    std::vector<std::vector<int>> edges = {{0, 1}, {1, 2}, {2, 0}, {1, 3}, {3, 4}, {4, 5}, {5, 3}, {5, 6}};
    Solution obj;
    obj.scc(edges);
    return 0;
}
