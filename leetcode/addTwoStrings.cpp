class Solution {
public:
    string addStrings(string num1, string num2) {
        int i = num1.size()-1;
        int j = num2.size()-1;
        int carry = 0;
        std::string res;
        while(i>=0||j>=0||carry){
            int digit1 = (i>=0)? num1[i]-'0' : 0;
            int digit2 = (j>=0)? num2[j]-'0' : 0;
            int sum = digit1 + digit2 + carry;
            carry = sum / 10;
            res.push_back((char)('0'+sum%10));
            i--;
            j--;
        }
        std::reverse(res.begin(),res.end());
        return res;
    }
};