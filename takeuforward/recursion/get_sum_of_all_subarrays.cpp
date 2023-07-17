class Solution
{
public:
    void generateSubSet(std::vector<int> arr,std::vector<int> &subset,std::vector<int> &res,int x){
        int sum=0;
        for(int num:subset){
            sum+=num;
        }
        res.push_back(sum);
        for(int i=x;i<arr.size();i++){
            subset.push_back(arr[i]);
            generateSubSet(arr,subset,res,i+1);
            subset.pop_back();
        }
    }
    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
        std::vector<int> subset;
        std::vector<int> res;
        generateSubSet(arr,subset,res,0);
        return res;
    }
};