class Solution {
public:
    int compress(vector<char>& chars) {
      std::map<char,int> map;
      std::string s;
      for(int i=0;i<chars.size();i++){
          if(map.find(chars[i])!=map.end()){
              map[chars[i]]++;
          }else{
            map[chars[i]]=1;
          }
      }
      for(auto index:map){
          std::cout<<index.second<<" "<<index.first<<"\n";
          if(index.second==1){
            s+=index.first;
          }else{
            s+=index.first;
            s+=to_string(index.second);
          }
      }
      int i=0;
      for(char val:s){
          chars[i++]=val;
      }
      std::cout<<s<<" ";
      return s.length();
    }
};

// failed for this

// chars =
// ["a","a","a","b","b","a","a"]
// Use Testcase
// Stdout
// 5 a
// 2 b
// a5b2 
// Output
// ["a","5","b","2"]
// Expected
// ["a","3","b","2","a","2"]


class Solution {
public:
    int compress(vector<char>& chars) {
        std::vector<std::pair<char,int>> res;
        char prev = chars[0];
        int count=1;
        std::string s;
        for(int i=1;i<chars.size();i++){
            if(prev==chars[i]){
                count++;
            }else{
                res.push_back(std::make_pair(prev,count));
                count=1;
                prev=chars[i];
            }
        }
        res.push_back(std::make_pair(prev,count));
        for(auto index:res){
            if(index.second==1){
                s+=index.first;
            }else{
                s+=index.first;
                s+=to_string(index.second);
            }
        }
        std::cout<<s<<" ";
        int i=0;
        for(char val:s){
            chars[i++]=val;
        }
        return s.length();
    }
};