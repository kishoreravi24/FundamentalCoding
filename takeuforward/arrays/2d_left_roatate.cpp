#include<bits/stdc++.h>
int main(){
    std::vector<std::vector<int>> nums={{1,2,3},
                                        {4,5,6},
                                        {7,8,9}};
    
    std::reverse(nums.begin(),nums.end());
    for(int i=0;i<nums.size();i++){
        for(int j=i+1;j<nums[0].size();j++){
            std::swap(nums[i][j],nums[j][i]);
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