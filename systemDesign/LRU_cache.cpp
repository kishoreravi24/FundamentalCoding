// design the class in the most optimal way

class LRUCache {
    private:
        int capacity;
        std::unordered_map<int,int> hash_table;
        std::list<int> tracker;
    public:
        LRUCache(int capacity){
            this->capacity = capacity;
        }
        
        int GET(int key){
            if(hash_table.find(key)!=hash_table.end()){
                tracker.remove(key);
                tracker.push_front(key);
                return hash_table.at(key);
            }else{
                return -1;
            }
        }
        
        void SET(int key, int val) {
            if (hash_table.find(key) == hash_table.end()) {
                if (hash_table.size() >= capacity) {
                    int removal_key = tracker.back();
                    tracker.pop_back();
                    hash_table.erase(removal_key);
                }
                hash_table[key] = val;
                tracker.push_front(key);
            } else {
                hash_table[key] = val;
                tracker.remove(key);
                tracker.push_front(key);
            }
        }
};


