#include<bits/stdc++.h>
class Solution{
public:
  std::vector<std::vector<int>> generatePascal(int numRows){
   std::vector<std::vector<int>> ans(numRows);
   for(int i=0;i<numRows;i++){
    ans[i] = std::vector<int>(i+1,1);
    for(int j=1;j<i;j++){
      ans[i][j] = ans[i-1][j-1]+ans[i-1][j];
    }
   }
   return ans;
  }
}
