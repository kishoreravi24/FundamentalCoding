#include<iostream>
#include<climits>
#include<vector>
#include<algorithm>
#define v 4
int solveTsp(int graph[][v],int source){

    // cities without source
    std::vector<int> cities;
    for(int i=0;i<v;i++){
        if(i!=source){
            cities.push_back(i);
        }
    }

    int min_path = INT_MAX;
    // iterate through all possiblites with permutations
    do{
        int current_pathweight = 0;
        int k = source;
        for(int i=0;i<cities.size();i++){
            //add weight of the edge
            current_pathweight+= graph[k][cities[i]];
            //move to next vertex
            k=cities[i];
        }
        //to complete the graph add weight of the source
        current_pathweight+=graph[k][source];
        min_path = std::min(min_path,current_pathweight);
    }while(std::next_permutation(cities.begin(),cities.end()));

    return min_path;
}
int main(){
    // 4 x 4 std::vector<std::vector<int>> distances(cities,std::vector<int>(cities,0));

    int graph[][v] =   { { 0, 10, 15, 20 },
                       { 10, 0, 35, 25 },
                       { 15, 35, 0, 30 },
                       { 20, 25, 30, 0 } };

    int minDistances = solveTsp(graph,0);
    std::cout<<minDistances<<"\n";
}