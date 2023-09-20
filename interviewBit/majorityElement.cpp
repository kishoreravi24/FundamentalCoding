int Solution::majorityElement(const vector<int> &A) {
    int n = A.size();
    int ele = 0;
    int count = 0;
    for(int i=0;i<n;i++){
        if(count==0){
            ele = A[i];
        }
        if(ele == A[i]){
            count++;
        }else{
            count--;
        }
    }
    return ele;
}
