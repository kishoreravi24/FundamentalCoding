#include<bits/stdc++.h>
void solve(std::vector<int> &candidates,int index,int target,std::vector<int> &helper){
    //Base case
    if(target==0){
        for(auto index:helper){
            std::cout<<index<<" ";
        }
        std::cout<<"\n";
        return;
    }

    if(index==candidates.size()||target<0){
        return;
    }

    helper.push_back(candidates[index]);
    solve(candidates,index,target-candidates[index],helper);
    helper.pop_back();
    solve(candidates,index+1,target,helper);
    return;
}
int combinationSum(std::vector<int> &candidates,int target){
	std::vector<int> helper;
	solve(candidates,0,target,helper);
    return 0;
}
int main(){
	int target;
	std::cin>>target;
	std::vector<int> candidates={2,3,6,7};
	combinationSum(candidates,target);
    return 0;
}