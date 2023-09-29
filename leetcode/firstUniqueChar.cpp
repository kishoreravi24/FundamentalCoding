class Solution {
public:
    int firstUniqChar(string s) {
        std::unordered_map<char,int> map;
        for(char c:s){
            map[c]++;
        }
        int count = 0;
        for(char c:s){
            if(map[c]==1){
                return count;
            }
            count++;
        }
        return -1;
    }
};