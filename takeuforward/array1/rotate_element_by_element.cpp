#include<bits/stdc++.h>
int main(){
    std::vector<std::vector<int>> nums={{1,2,3,4},
                                        {5,6,7,8},
                                        {9,10,11,12},
                                        {13,14,15,16}};
    
    //Transpose
    for(int i=0;i<nums.size();i++){
        for(int j=i;j<nums[0].size();j++){
            std::swap(nums[i][j],nums[j][i]);
        }
    }
    
    for (int i = 0; i < nums.size(); i++) {
        for (int j = 0, k = nums.size() - 1; j < k; j++, k--) {
            std::swap(nums[j][i],nums[k][i]);
        }
    }
    
    for(int i=0;i<nums.size();i++){
        for(int j=0;j<nums[0].size();j++){
            std::cout<<nums[i][j]<<" ";
        }
        std::cout<<"\n";
    }
    return 0;
}