std::vector<int> vect;
void count_distinct(int a[],int start,int k,int size){
    if(k>size){
        return;
    }
    std::unordered_set<int> hash_table;
    for(int i=start;i<k;i++){
        if(hash_table.find(a[i])==hash_table.end()){
            hash_table.insert(a[i]);
        }
    }
    vect.push_back(hash_table.size());
    count_distinct(a,start+1,k+1,size);
}
vector<int> count_ele(int a[],int n,int k){
    count_distinct(a,0,k,size);
    //print vect;
}