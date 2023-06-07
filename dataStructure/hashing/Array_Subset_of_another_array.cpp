string isSubset(int a1[], int a2[], int n, int m) {
    
    int size = sizeof(a1)/sizeof(a1[0]);
    int count = 0;
    std::string s="Yes";
    std::unordered_set<int> hash_table(a1,a1+size);
    
    for(int i=0;i<m;i++){
        if(hash_table.find(a2[i])!=hash_table.end()){
            count++;
        }
    }
    if(count==m){
        return s;
    }else{
        s="No";
        return s;
    }
}