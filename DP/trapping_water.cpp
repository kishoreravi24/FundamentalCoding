class Solution {
public:
    // Function to find the trapped water between the blocks.
    long long waterBlock(int arr[], int n, long long res, int G, int start) {
        if (start >= n-1) {
            return res;
        }
        if (G != 0 && G != arr[start]) {
            res += std::abs(arr[start] - G);
        }
        if (arr[start] > G) {
            G = arr[start];
        }
        return waterBlock(arr, n, res, G, start + 1);
    }

    long long trappingWater(int arr[], int n) {
        long long res = 0;
        int G = arr[0];
        return waterBlock(arr, n, res, G, 1);
    }
};

or

class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int arr[], int n){
        // code here
        long long res=0;
        int leftMax[n];
        int rightMax[n];
        
        leftMax[0]=arr[0];
        rightMax[n-1]=arr[n-1];
        
        for(int i=1;i<n;i++){
            leftMax[i]=std::max(leftMax[i-1],arr[i]);
        }
        
        for(int i=n-2;i>=0;i--){
            rightMax[i]=std::max(rightMax[i+1],arr[i]);
        }
        
        for(int i=0;i<n;i++){
            int water =std::min(leftMax[i],rightMax[i])-arr[i];
            res+=water;
        }
        return res;
    }
};