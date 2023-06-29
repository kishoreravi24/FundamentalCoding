#include<bits/stdc++.h>
class HashTable{
    private:
        std::vector<std::list<std::pair<int,std::string>>> buckets;
        int numBuckets;
        
        int hashFunction(int key){
            return key%numBuckets;
        }
    public:
        HashTable(int size):numBuckets(size){
            buckets.resize(numBuckets);
        }
        
        void insert(int key,std::string s){
            int hash_key = hashFunction(key);
            buckets[hash_key].push_back(std::make_pair(key,s));
        }
        
        std::string get(int key){
            int hash_key = hashFunction(key)
            for(auto x:buckets[hash_key]){
                if(x.first == key){
                    return x.second;
                }
            }
            return "";
        }
        
        void remove(int key){
            int hash_key = hashFunction(key);
            auto& bucket = buckets[hash_key];
            for(auto it=buckets.begin();it!=buckets.end();++it){
                if(it->first == key){
                    bucket.erase(it);
                    return;
                }
            }
        }
};
int main(){
    HashTable hashtable(10);
    
    hashtable.insert(1,"apple");
    hashtable.insert(2,"orange");
    hashtable.insert(3,"bannana");
    
    std::cout<<hashtable.get(1);
    
    hashtable.remove(1);
    
    hashtable.insert(1,"grape");
    
    std::cout<<hashtable.get(1);
    
    return 0;
    
}