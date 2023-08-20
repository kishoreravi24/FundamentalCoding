class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::vector<std::vector<int>> res;
        int n = nums.size();
        for(int i=0;i<n-2;i++){
            for(int j=i+1;j<n-1;j++){
                for(int k=j+1;k<n;k++){
                    if(i!=j&&i!=k&&j!=k){
                        if(nums[i]+nums[j]+nums[k]==0){
                            std::vector<int> triples = {nums[i],nums[j],nums[k]};
                            std::sort(triples.begin(),triples.end());
                            if (std::find(res.begin(), res.end(), triples) == res.end()) {
                                res.push_back(triples);
                            }
                        }
                    }
                }
            }
        }
        return res;
    }
};

//or  Two pointer

for(int i=0;i<n;i++){
    int low = i+1;
    int high = n-1;

    while(low<high){
        int sum = num[i]+num[low]+num[high];
        if(sum>0){
            high--;
        }else if(sum<0)}{
            low++;
        }else{
            res.push_back({num[i],num[low],num[high]});
            int least_low = num[low];
            int least_high = num[high];
            /*
                how avoid the duplicates
                1 1 2 2 3
                low = 0 , num[low]=1,least_low=1
                low = 1, num[low]=1,least_low=1 // this one is not going to line number 31
            */
            while(low<high&&num[low]==least_low){
                low++;
            }
            while(low<high&&num[high]==least_high){
                high--;
            }
        }
    }
}