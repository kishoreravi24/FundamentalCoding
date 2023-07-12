class Solution 
{
    public:
    void swap(int *a,int *b){
        int temp = *a;
        *a = *b;
        *b = temp;
    }
    int partition(std::vector<int>& nums,int low,int high){
        int pivot = nums[high];
        int i = low-1;
        
        for(int j=low;j<high;j++){
            if(nums[j]<=pivot){
                i++;
                swap(&nums[i],&nums[j]);
            }
        }
        swap(&nums[i+1],&nums[high]);
        return(i+1);
    }
    int quickSort(std::vector<int>& nums,int low,int high){
        int pi;
        if(low<high){
            pi=partition(nums,low,high);
            
            quickSort(nums,low,pi-1);
            quickSort(nums,pi+1,high);
        }
        return pi;
    }
	int minSwaps(vector<int>&nums)
	{
	    // Code here
	    minSwaps(nums,0,nums.size()-1)
	    return quickSort(nums,0,nums.size()-1);
	}
};