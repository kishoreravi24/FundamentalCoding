#include<bits/stdc++.h>
int main(){
  std::vector<int> A = {3,4,1,4,2};

  //phase 1: find intersection
  int fast = A[0];
  int slow = A[0];

  do{
    slow = A[slow];
    fast = A[A[fast]];
  }while(fast!=slow);
  
  //phase2 find the number
  fast = A[0];
  while(fast!=slow){
    slow=A[slow];
    fast=A[fast];
  }

  return slow;
}