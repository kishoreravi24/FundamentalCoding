#include<bits/stdc++.h>
#define v 5
class Solution{
public:
    void displayPath(std::vector<int> path){
        for(auto index : path){
            std::cout << index << " ";
        }
        return;
    }

    bool isValid(int i, std::vector<int> path, int graph[][v], int source){
        // Check if there is an edge between the last vertex in the path and the new vertex
        if(graph[path[source - 1]][i] == 0){
            return false; // No edge exists, so not a valid addition
        }
    
        // Check if the new vertex is already present in the current path
        for(int j = 0; j < source; j++){
            if(path[j] == i){
                return false; // New vertex is already visited, not a valid addition
            }
        }
        return true; // Both conditions met, it's a valid addition
    }

    bool checkCycle(int source, std::vector<int> &path, int graph[][v]){
        // Check if source meets the last vertex (needs to return to starting vertex)
        if(source == v && graph[path[source - 1]][path[0]] == 1){
            return true;
        }

        // Check if the edge in the path is valid to have or not
        for(int i = 1; i < v; i++){
            if(isValid(i, path, graph, source)){
                path[source] = i;
                if(checkCycle(source + 1, path, graph)){
                    return true;
                }
                path[source] = -1;
            }
        }
        return false;
    }

    bool hamiltonianCycle(int graph[][v]){
        // Path
        std::vector<int> path(v, -1);
        path[0] = 0; // Starting path visited

        if(checkCycle(1, path, graph) == false){
            std::cout << "No path found";
            return false;
        }

        displayPath(path);
        return true;
    }
};

int main(){
    Solution obj;
    int graph[][v] = {
                       {0, 1, 0, 1, 0},
                       {1, 0, 1, 1, 1},
                       {0, 1, 0, 0, 1},
                       {1, 1, 0, 0, 1},
                       {0, 1, 1, 1, 0},
                    };
    obj.hamiltonianCycle(graph);
    return 0;
}
