#include<bits/stdc++.h>
std::vector<std::vector<int>> res;
int subSequence(int arr[],int n,std::vector<int> &subarr,int index){
    if(index == n){
        res.push_back(subarr);
        return 0;
    }
    
    //Take the value
    subarr.push_back(arr[index]);
    subSequence(arr,n,subarr,index+1);
    //Not take the value
    subarr.pop_back();
    subSequence(arr,n,subarr,index+1);
    return 0;
}
int main(){
    int arr[] = {1,2,3,4};
    int n = sizeof(arr)/sizeof(arr[0]);
    std::vector<int> subarr;
    subSequence(arr,n,subarr,0);
    for(auto index: res){
        for(auto it: index){
            std::cout<<it<<" ";
        }
        std::cout<<"\n";
    }
    
/*


1 2 3 4 
1 2 3 
1 2 4 
1 2 
1 3 4 
1 3 
1 4 
1 
2 3 4 
2 3 
2 4 
2 
3 4 
3 
4 



*/
    return 0;
}