class Solution{
    public:
    
    //Function to rotate an array by d elements in counter-clockwise direction. 
    int gcd(int a,int b){
        if(b==0){
            return a;
        }else{
            gcd(b,a%b);
        }
    }
    void rotateArr(int arr[], int d, int n){
        // code here
        d = n-(d%n);
        if(d==0){
            return;
        }
        
        int cycleCount = gcd(n,d);
        
        for(int i=0;i<cycleCount;i++){
            int currentIndexValue = n-i-1;
            int currentArrayValue = arr[i];
            
            do{
                int nextIndexValue = (currentIndexValue+d)%n;
                std::swap(currentArrayValue,arr[nextIndexValue]);
                currentIndexValue = nextIndexValue;
            }while(currentIndexValue!=n-i-1);
        }
        return;
    }
};