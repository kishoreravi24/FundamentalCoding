//Function to find the minimum number of swaps required to sort the array. 
int minSwaps(vector<int>&nums)
{
    // Code here
    std::vector<std::pair<int,int>> temp(nums.size());
    int swaps=0;
    for(int i=0;i<nums.size();i++){
        temp[i]=std::make_pair(nums[i],i);
    }
    std::vector<bool> visited(temp.size(),false);
    
    std::sort(temp.begin(),temp.end());
    for(int i=0;i<temp.size();i++){
        if(visited[i]||temp[i].second==i){
            continue;
        }
        
        int cycleSwaps=0;
        int j=i;
        while(!visited[j]){
            visited[j]=true;
            j=temp[j].second;
            cycleSwaps++;
        }
        
        if(cycleSwaps>0){
            swaps+=(cycleSwaps-1);
        }
    }
    return swaps;
}