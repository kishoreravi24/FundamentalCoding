#include <bits/stdc++.h> 

int mcc(std::vector<int> arr,int n){
    std::vector<std::vector<int>> m(n,std::vector<int>(n,0));
    for(int L=2;L<n;L++){
        for(int i=0;i<n-L;i++){
            int j=i+L;
            m[i][j]=INT_MAX;
            for(int k=i+1;k<j;k++){
                int cost = m[i][k]+m[k][j]+arr[i]*arr[k]*arr[j];
                if(cost<m[i][j]){
                    m[i][j]=cost;
                }
            }
        }
    }
    return m[0][n-1];
}
int matrixMultiplication(vector<int> &arr, int n)
{
    // Write your code here.
    return mcc(arr,n);
}