int superDigit(const string & n, int k) {
    int r = 0;
    for (char v : n) {
        r += (v - '0') * k;
        if (10 <= r) {
            r %= 9;
            if (0 == r) r = 9;
        }
    }
    return r;
}

or

#include<bits/stdc++.h>
std::string getSuperDigit(std::string n){
    if(n.length()==1){
        return n;
    }
    long long int count=0;
    for(int i=0;i<n.length();i++){
        count+=std::stoi(std::string(1,n[i]));
    }
    return getSuperDigit(std::to_string(count));
}
int main(){
    std::string s;
    std::cin>>s;
    int k=100000;
    
    int digitSum = 0;
    for (char c : s) {
        digitSum += (c - '0');
    }

    // Multiply 'digitSum' by 'k'
    digitSum *= k;
    int x =  std::stoi(getSuperDigit(std::to_string(digitSum)));
    std::cout<<x;
}