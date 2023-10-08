class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        // storing the coordinates of zero
        std::vector<std::pair<int,int>> zeroStorage;
        int storageSpec = 0;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                storageSpec = matrix[i].size();
                if(matrix[i][j]==0){
                    zeroStorage.push_back({i,j});
                }
            }
        }

        for(int k=0;k<zeroStorage.size();k++){
            int current_i = zeroStorage[k].first;
            int current_j = zeroStorage[k].second;

           for(int i=0;i<matrix.size();i++){
               for(int j=0;j<matrix[i].size();j++){
                   if(i==current_i||j==current_j){
                       matrix[i][j] =0;
                   }
               }
           }
        }
    }
};
