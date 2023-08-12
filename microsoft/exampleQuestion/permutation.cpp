#include<bits/stdc++.h>
void generatePermute(std::vector<int> &nums,std::vector<std::vector<int>> &result,int startIndex){
    if(startIndex == nums.size()){
        result.push_back(nums);
        return;
    }
    for(int i=startIndex;i<nums.size();i++){
        std::swap(nums[startIndex],nums[i]);
        generatePermute(nums,result,startIndex+1);
        std::swap(nums[i],nums[startIndex]);
    }
}
void permute(std::vector<int> nums){
    std::vector<std::vector<int>> result;
    int startIndex = 0;
    generatePermute(nums,result,startIndex);
    for(auto index:result){
        for(auto ans:index){
            std::cout<<ans<<" ";
        }
        std::cout<<"\n";
    }
    return;
}
int main(){
    std::vector<int> nums={1,2,3};
    permute(nums);
    return 0;
}