#include<bits/stdc++.h>
int main(){
    std::vector<int> nums={1,3,4,2,2};
    int t = 5;
    int l = 0;
    int r = nums.size()-1;
    while(l<=r){
        int mid = l+(r-l)/2;
        if(mid==t){
            std::cout<<mid;
            return 0;
        }
        if(nums[mid]<t){
            l=mid+1;
        }else{
            r=mid-1;
        }
    }
    std::cout<<r;
}
