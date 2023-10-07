#include<bits/stdc++.h>
void generateSubarrary(std::vector<int> nums,std::vector<int> subarrays,std::vector<int> &ans,int index){
  if(index == nums.size()){
    int sum = 0;
    for(int ind:subarrays){
     sum+=ind;
    }
    ans.push_back(sum);
    return;
  }

  subarrays.push_back(nums[index]);
  generateSubarrary(nums,subarrays,ans,index+1);
  subarrays.pop_back();
  generateSubarrary(nums,subarrays,ans,index+1);
  return;
}
int main(){
  std::vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
  std::vector<int> subarrays;
  std::vector<int> ans;
  generateSubarrary(nums,subarrays,ans,0);
  std::sort(ans.begin(),ans.end());
  std::cout<<ans[ans.size()-1];
  return 0;
}

//or

#include<bits/stdc++.h>
int main(){
  std::vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
  int curr_sum = nums[0];
  int max_sum = nums[0];

  for(int i=0;i<n;i++){
    curr_sum = std::max(nums[i],curr_sum+nums[i]);
    max_sum = std::max(max_sum,curr_sum);
  }
  std::cout<<max_sum;
}

