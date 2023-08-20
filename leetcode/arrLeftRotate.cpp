#include<bits/stdc++.h>
/*

To performe the left rotate in array
in 0(n),0(1) : time and space complexity

Base condition:
	* number of times rotate can be greater than the array size
	* if the given rotate d is zero return the same array
	
calculate the cycles with gcd , where a is size of the array & b is the rotating times
* cycle start from 0 -- cycleCount from gcd
* current indexValue, current arrayValue
* next Value = (current+d)%n
* swap current arrayValue and next arrayValue
* update current = next
* check current indexValue !=i

*/
class Solution{
    public:
    
    //Function to rotate an array by d elements in counter-clockwise direction. 
    int gcd(int a,int b){
        if(b==0){
            return a;
        }else{
            gcd(b,a%b);
        }
    }
    void rotateArr(int arr[], int d, int n){
        // code here
        d = n-(d%n);
        if(d==0){
            return;
        }
        
        int cycleCount = gcd(n,d);
        
        for(int i=0;i<cycleCount;i++){
            int currentIndexValue = i;
            int currentArrayValue = arr[i];
            
            do{
                int nextIndexValue = (currentIndexValue+d)%n;
                std::swap(currentArrayValue,arr[nextIndexValue]);
                currentIndexValue = nextIndexValue;
            }while(currentIndexValue!=i);
        }
        return;
    }
};
