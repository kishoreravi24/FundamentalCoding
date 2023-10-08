#include<bits/stdc++.h>
class Solution{
public:
  int search(std::vector<int> &nums,int target){
    if(nums.empty()){
      return -1;
    }
    int start = 0, end = nums.size()-1;
    while(start<end){
      int mid = end+(end-start)/2;
      if(nums[mid]>nums[end]){
        start = mid+1;
      }else{
        end = mid;
      }
    }
    int pivot = start;
    if(pivot&&target>=nums[0]&&target<=nums[pivot-1]){
      start = 0;
      end = pivot-1;
    }else{
      start = pivot;
      end = nums.size()-1;
    }

    while(start<=end){
      int mid = start+(end-start)/2;
      if(nums[mid]==target){
        return mid;
      }
      if(target>nums[mid]){
        start = mid+1;
      }else{
        end = mid;
      }
    }
    return -1;
  }
}
