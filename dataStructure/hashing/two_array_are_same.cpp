class Solution{
    public:

    //Function to check if two arrays are equal or not.
    bool check(vector<ll> A, vector<ll> B, int N) {
        //code here
        unordered_map<ll, int> countA, countB;
    
        for (auto x : A) {
            countA[x]++;
        }
    
        for (auto x : B) {
            countB[x]++;
        }
    
        return countA == countB;
        
    }
};