class Solution {
public:	
	// Function to check if array has 2 elements
	// whose sum is equal to the given value
	bool hasArrayTwoCandidates(int arr[], int n, int x) {
	    // code here
	    std::unordered_set<int> hash_table;
	    for(int i=0;i<n;i++){
	        int diff = x-arr[i];
	        if(hash_table.find(diff)!=hash_table.end()){
	            return true;
	        }else{
	            hash_table.insert(arr[i]);
	        }
	    }
	    return false;
	}
};