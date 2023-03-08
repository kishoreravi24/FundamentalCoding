class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> vector(n);
        for(int i=1;i<=n;i++){
            if(i%3 ==0 && i%5==0){
                vector.at(i-1)="FizzBuzz";
            } else if(i%3==0) {
                vector.at(i-1)="Fizz";
            } else if(i%5==0) {
                vector.at(i-1)="Buzz";
            } else {
                vector.at(i-1)=to_string(i);
            }
        }
        return vector;
    }
};