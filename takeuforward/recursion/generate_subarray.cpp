class Solution
{
public:
    void generateSubSet(std::vector<int> arr,std::vector<int> subset,int x){
        for(int num:subset){
            std::cout<<num<<" ";
        }
        std::cout<<"\n";
        for(int i=x;i<arr.size();i++){
            subset.push_back(arr[i]);
            generateSubSet(arr,subset,i+1);
            subset.pop_back();
        }
    }
    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
        std::vector<int> subset;
        generateSubSet(arr,subset,0);
    }
}; 
 