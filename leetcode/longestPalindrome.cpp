class Solution {
public:
    int longestPalindrome(string s) {
        std::unordered_map<char,int> hashMap;
        for(char c:s){
            hashMap[c]++;
        }
        int palindromeLength = 0;
        bool isOdd = false;
        for(auto index:hashMap){
            int count = index.second;
            if(count%2==0){
                palindromeLength+=count;
            }else{
                palindromeLength+=count-1;
                isOdd = true;
            }
        }

        if(isOdd){
            palindromeLength+=1;
        }
        return palindromeLength;
    }
};