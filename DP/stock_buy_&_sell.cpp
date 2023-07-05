class Solution{
public:
    //Function to find the days of buying and selling stock for max profit.
    std::vector<std::vector<int>> res;
    std::vector<vector<int>> checkStockPrices(std::vector<int> A,int n, int start,int max,int buy,int sell){
        if(start>n){
            if(sell==-1){
                res.push_back(std::vector<int>{buy,start-1});
            }
            return res;
        }
        if(buy==-1){
            buy=start;
        }
        if(std::max(A[start],max)!=max){
            max=std::max(A[start],max);
        }else{
            sell=start-1;
        }
        if(buy!=-1&&sell!=-1){
            res.push_back(std::vector<int>{buy,sell});
            buy=start;
            sell=-1;
        }
        
        return checkStockPrices(A,n,start+1,max,buy,sell);
    }
    vector<vector<int> > stockBuySell(vector<int> A, int n){
        // code here
        int max=INT_MIN;
        checkStockPrices(A,n,0,max,-1,-1);
        return res;
    }
};

or


class Solution{
public:
    //Function to find the days of buying and selling stock for max profit.
    vector<vector<int> > stockBuySell(vector<int> A, int n){
        // code here
     vector<vector<int>>answer;
        for(int i=1;i<n;i++){
            if(A[i] > A[i-1]){
                answer.push_back({i-1,i});
            }
        }
        return answer;
    }
};