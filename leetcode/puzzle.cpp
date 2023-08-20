class Solution{
  public:

    long long int solve(int i,std::vector<long long int> nums,int n){
        long long int res=1;
        for(int j=0;j<n;j++){
            if(j!=i){
                res*=nums[j];
            }
        }
        return res;
    }
    vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
       
        //code here        
        std::vector<long long int> res;
        for(int i=0;i<n;i++){
            res.push_back(solve(i,nums,n));
        }
        return res;
    }
};

//or

class Solution {
public:
    vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
        vector<long long int> leftProducts(n, 1);
        vector<long long int> rightProducts(n, 1);
        vector<long long int> res(n, 1);

        // Calculate left products
        long long int leftProduct = 1;
        for (int i = 0; i < n; i++) {
            leftProducts[i] = leftProduct;
            leftProduct *= nums[i];
        }

        // Calculate right products
        long long int rightProduct = 1;
        for (int i = n - 1; i >= 0; i--) {
            rightProducts[i] = rightProduct;
            rightProduct *= nums[i];
        }

        // Calculate final results
        for (int i = 0; i < n; i++) {
            res[i] = leftProducts[i] * rightProducts[i];
        }

        return res;
    }
};
