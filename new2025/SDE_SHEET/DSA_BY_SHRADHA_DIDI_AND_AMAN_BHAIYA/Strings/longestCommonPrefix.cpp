#include<bits/stdc++.h>
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        std::sort(strs.begin(),strs.end());
        std::string first = strs[0];
        std::string last = strs[strs.size()-1];
        std::string res = "";
        for(int i=0;i<std::min(first.size(),last.size());i++){
        	if(first[i]!=last[i]){
        		return res;
        	}
        	res+=first[i];
        }
        return res;
    }
};