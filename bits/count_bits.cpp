class Solution {
public:
    void getCount(std::vector<int>& ans,int n){
        if(n==-1){
            return;
        }
        std::bitset<sizeof(n)*8> decimalToBinary(n);
        std::string s = decimalToBinary.to_string();
        int val = std::count(s.begin(),s.end(),'1');
        ans.push_back(val);
        getCount(ans,--n);
    }
    vector<int> countBits(int n) {
        std::vector<int> ans;
        getCount(ans,n);
        std::reverse(ans.begin(),ans.end());
        return ans;
    }
};