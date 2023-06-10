int NumberofElementsInIntersection(int a[], int b[], int n, int m) {
    // Your code goes here
    std::unordered_set<int> set(a,a+n);
    int count = 0;
    for(int i=0;i<m;i++){
        if(set.find(b[i])!=set.end()){
            count++;
            set.erase(b[i]); // to fix duplicate element in array a
        }
    }
    return count;
}