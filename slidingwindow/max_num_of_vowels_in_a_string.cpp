class Solution {
public:
    int slideWindow(std::string s, int k,int size,std::vector<char> vowels){
        int currCount=0;
        for(int i=0;i<k;i++){
            currCount+=std::count(vowels.begin(),vowels.end(),s[i]);
        }
        int maxCount = currCount;
        for(int i=k;i<size;i++){
            currCount+=std::count(vowels.begin(),vowels.end(),s[i]);
            currCount-=std::count(vowels.begin(),vowels.end(),s[i-k]);
            if(currCount>maxCount){
                maxCount=currCount;
            }
        }
        return maxCount;
    }
    int maxVowels(string s, int k) {
        std::vector<char> vowels={'a','e','i','o','u'};
        return slideWindow(s,k,s.length(),vowels);
    }
};