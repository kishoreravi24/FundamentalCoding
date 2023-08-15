class Solution {
public:
    // Function to count the frequency of all elements from 1 to N in the array.
    void frequencyCount(vector<int>& arr, int N, int P) {
        std::map<int, int> hashMap;
        for (int i = 0; i < N; i++) {
            if(arr[i]<=P){
                hashMap[arr[i]]++;
            }
        }
        
        for(int i=1;i<=N;i++){
            if(hashMap.find(i)!=hashMap.end()){
                arr[i-1]=hashMap[i];
            }else{
                arr[i-1]=0;
            }
        }
    }
};