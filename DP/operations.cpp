#include <iostream>
using namespace std;

int getCount(int dp[], int inc, int x, int n, int count) {
    if (x == n) {
        return count;  // Return the count when x reaches n
    }
    
    if (x < n) {
        int y[100];  // Define y array to store values

        // For multiplication
        for (int i = 0; i < inc; i++) {
            if (x * dp[i] != dp[i] && x * dp[i] < n) {
                y[i] = x * dp[i];
                count++;  // Increment count for each valid multiplication
            }
        }

        // For addition
        y[inc] = x + 1;
        count++;  // Increment count for addition operation

        // Recursively call getCount for each value in y
        for (int i = 0; i <= inc; i++) {
            count = getCount(dp, inc + 1, y[i], n, count);
        }

        return count;  // Return the final count
    }
    
    return -1;  // Return -1 if x > n (error condition)
}

int main() {
    int n = 8;
    int dp[100] = {1};  // Initialize dp array with size and initial value
    
    if (n == 1) {
        cout << 0 << endl;  // Return 0 if n is 1
    } else {
        int result = getCount(dp, 0, 1, n, 0);  // Start count from 0
        cout << result << endl;  // Print the result
    }

    return 0;
}


or

class Solution
{
  public:
    int minOperation(int n)
    {
        int cnt=0;
        while(n)
        {
           if(n%2)
           n--;
           else
           n=n/2;
           
           cnt++;
        }
        return cnt;
    }
};