class Solution {
public:
    void checkDfs(std::vector<std::vector<int>> graph,int start,std::vector<std::vector<int>> &res,std::vector<bool> &visited,std::vector<int> &currentPath){
        visited[start]=true;
        currentPath.push_back(start);
        if(start==graph.size()-1){
            res.push_back(currentPath);
        }
        for(auto index:graph[start]){
            if(!visited[index]){
                checkDfs(graph,index,res,visited,currentPath);
            }
        }
        currentPath.pop_back();
        visited[start]=false;
        return;
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        std::vector<bool> visited(n,false);
        
        std::vector<std::vector<int>> res;
        std::vector<int> currentPath;
        checkDfs(graph,0,res,visited,currentPath);
        return res;
    }
};