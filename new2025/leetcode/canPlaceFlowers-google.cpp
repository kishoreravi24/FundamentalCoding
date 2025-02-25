class Solution {
public:
    bool canPlaceFlowers(vector<int>& arr, int n) {
        if(n==0){
            return true;
        }
        if(arr.size()==1){
            return (arr[0]==0&&n<=1);
        }
        for(int i=0;i<arr.size();i++){
            if(arr[i]==0){
                bool leftSide = (i==0||arr[i-1]==0);
                bool rightSide = (i==arr.size()-1||arr[i+1]==0);

                if(leftSide&&rightSide){
                    n--;
                    arr[i]=1;
                    if(n==0) return true;
                }
            }
        }
        return n<=0;
    }
};