#include<bits/stdc++.h>
int main(){
  std::vector<int> nums = {1,2,3,4};
  std::vector<int> ans;
  for(int i=0;i<nums.size();i++){
    int count = 1;
    for(int j=0;j<nums.size();j++){
      if(j!=i){
        count*=nums[j];
      }
    }
    ans.push_back(count);
  }
  for(auto ind:ans){
    std::cout<<ind<<" ";
  }
  return 0;
}

//or

#include<bits/stdc++.h>
int main(){
  std::vector<int> nums = {1,2,3,4};
  int n = nums.size();
  std::vector<int> leftSide(n,1);
  std::vector<int> rightSide(n,1);

  for(int i=1;i<n;i++){
    leftSide[i] = leftSide[i-1]*nums[i-1];
  }

  for(int i=n-2;i>=0;i--){
    rightSide[i] = rightSide[i+1]*nums[i+1];
  }

  for(int i=0;i<n;i++){
    nums[i] = (leftSide[i]*rightSide[i]);
  }

  for(int n:nums){
    std::cout<<n<<" ";
  }
  std::cout<<"\n";
}

