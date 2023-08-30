#include <bits/stdc++.h> 
vector<int> nextPermutation(vector<int> &permutation, int n)
{
    //Find inversion point
    int k,l;
    for(k=n-2;k>=0;k--){
        if(permutation[k]<permutation[k+1]){
            break;
        }
    }
    if(k<0){
        std::reverse(permutation.begin(),permutation.end());
        return permutation;
    }else{
        //end of perm to inversion point
        for(l=n-1;l>k;l--){
            if(permutation[l]>permutation[k]){
                break;
            }
        }
        //swap the inversion point and perm value
        std::swap(permutation[l],permutation[k]);
        //reverse it
        std::reverse(permutation.begin()+k+1,permutation.end());
        return permutation;
    }
}