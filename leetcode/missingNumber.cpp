class Solution{
  public:
    int missingNumber(vector<int>& array, int n) {
        // Your code goes here
        int sum = 0;
        for(int index:array){
          sum+=index;
        }

        int currSum = 0;
        for(int i=1;i<=n;i++){
          currSum+=i;
        }

        return std::abs(sum-currSum);
    }
};