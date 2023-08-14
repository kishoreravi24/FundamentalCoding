/*

int arr[] eg: 1 2 4
 1 2 4 + 1
 125 , put this in array
 1 2 5

 another example:
 3
 9 9 9
 o/p:
 1 0 0 0

*/

#include<bits/stdc++.h>
class Solution {
public:
    std::vector<int> increment(std::vector<int> arr, int N) {
    	int carry = 1;
    	for(int i=N-1;i>=0;i--){
    		int sum = arr[i]+carry;
    		arr[i] = sum%10;
    		carry = sum/10;
    	}

    	if(carry>0){
    		arr.insert(arr.begin(),carry);
    	}
    	return arr;
    }
};

/*

1 2 4
sum = 4+1
sum = 5
arr[i] = 5 // 1 2 5
carry = 5/10 // 0

sum = 2+0
sum = 2
arr[i] = 2
carry = 0

sum = 1+0
sum = 1
arr[i] = 1
carry = 0

so // 1 2 5


9 9 9
sum = 10
arr[i] = 0
carry = 1

sum = 10
arr[i] = 0
carry = 1

sum = 10
arr[i] = 0
carry = 1

o/p: 0 0 0

carry > 0
so add remain carry in begin of arr
1 0 0 0 

*/