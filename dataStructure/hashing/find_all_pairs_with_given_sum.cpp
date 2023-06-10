vector<pair<int,int>> allPairs(int A[], int B[], int N, int M, int X)
{
    // Your code goes here   
    std::unordered_set<int> set;
    std::vector<std::pair<int,int>> vect;
    for(int i=0;i<N;i++){
        set.insert(A[i]);
    }
    for(int j=0;j<M;j++){
        int diff = X-B[j];
        if(set.find(diff)!=set.end()){
            vect.push_back({diff,B[j]});
        }
    }
    std::sort(vect.begin(),vect.end());
    return vect;
}