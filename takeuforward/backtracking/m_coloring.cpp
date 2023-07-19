bool matColoring(std::vector<std::vector<int>>& mat, std::vector<int>& vect, int node, int col, int m) {
    for (int i = 0; i < mat.size(); i++) {
        if (i != node && mat[node][i] == 1 && vect[i] == col) {
            return false;
        }
    }
    return true;
}

bool solve(std::vector<std::vector<int>>& mat, std::vector<int>& vect, int m, int node) {
    if (node == mat.size()) {
        return true;
    }
    for (int i = 1; i <= m; i++) {
        if (matColoring(mat, vect, node, i, m)) {
            vect[node] = i;
            if (solve(mat, vect, m, node + 1)) {
                return true;
            }
            vect[node] = 0;
        }
    }
    return false;
}

std::string graphColoring(std::vector<std::vector<int>>& mat, int m) {
    int n = mat.size();
    std::vector<int> vect(n, 0);
    if (solve(mat, vect, m, 0)) {
        return "YES";
    } else {
        return "NO";
    }
}
