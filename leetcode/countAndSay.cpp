#include<bits/stdc++.h>
int main(){
    std::deque<std::pair<int,int>> q;
    int val = 11;
    int n = 4;
    while(--n){
        int x = val;
        int temp = x%10;
        int count = 1;
        x/=10;
        if(x==0){
            q.push_front({count,temp});
        }else{
            while(x!=0){
                if(temp==x%10){
                    count++;
                    x/=10;
                }else{
                    q.push_front({count,temp});
                    temp=x%10;
                    x/=10;
                    count=1;
                }
            }
            q.push_front({count,temp});
        }
        std::string s="";
        while(!q.empty()){
            std::cout<<q.front().first<<" "<<q.front().second<<"\n";
            s+=std::to_string(q.front().first);
            s+=std::to_string(q.front().second);
            q.pop_front();
        }
        val=std::stoi(s);
    }
    std::cout<<val;
    return 0;
}

//or

class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) {
            return "1";
        }
        
        string prevTerm = countAndSay(n - 1);
        string currentTerm = "";
        
        int count = 1;
        char currentChar = prevTerm[0];
        
        for (int i = 1; i < prevTerm.size(); ++i) {
            if (prevTerm[i] == currentChar) {
                count++;
            } else {
                currentTerm += to_string(count) + currentChar;
                count = 1;
                currentChar = prevTerm[i];
            }
        }
        
        currentTerm += to_string(count) + currentChar;
        
        return currentTerm;
    }
};
