#include<bits/stdc++.h>
int main(){
 std::vector<int> arr={2,7,11,15}
 int target = 9;

 std::unordered_map<int,int> hashMap;
 for(int i=0;i<arr.size();i++){
   int newNum = target-arr[i];
   if(hashMap.count(newNum)>0){
     return {hashMap[newNum],i};
   }else{
    	hashMap[arr[i]]=i;
   }
 }
}
