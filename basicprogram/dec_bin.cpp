// basic like decimal to binary and vice versa

class Solution {
public:
    int convertBin(int x, int arr[]){
        int i=0;
        while(x!=0){
            arr[i]=x%2;
            i++;
            x=x/2;
        }
        return i;
    }
    int convertDec(int x_arr[],int x_arr_i){
        int decimal = 0;
    
        for (int i = x_arr_i - 1; i >= 0; i--) {
            decimal = decimal << 1 | x_arr[i];
        }
        // std::cout<<decimal<<" ";
    
        return decimal;
    }
    int setSetBit(int x, int y, int l, int r) {
        int x_arr[11];
        int x_arr_i = convertBin(x,x_arr);
        
        int y_arr[11];
        int y_arr_i = convertBin(y,y_arr);
        
        // std::cout<<x_arr_i<<"\n";
        // for(int j=x_arr_i-1;j>=0;j--){
        //     std::cout<<x_arr[j];
        // }
        
        int z = x_arr_i-y_arr_i;
        for(int j=(z+y_arr_i)-1;j>=y_arr_i;j--){
            y_arr[j]=0;
        }
        // std::cout<<"\n";
        // for(int j=(z+y_arr_i)-1;j>=0;j--){
        //     std::cout<<y_arr[j];
        // }
        // std::cout<<"\n";
        
        for(int i=l-1;i<r;i++){
            if(x_arr[i]==0){
                x_arr[i]=y_arr[i];
            }
        }
        
        // std::cout<<x_arr_i<<"\n";
        // for(int j=x_arr_i-1;j>=0;j--){
        //     std::cout<<x_arr[j];
        // }
        // std::cout<<"\n";
    
        
        int res = convertDec(x_arr,x_arr_i);
        // std::cout<<"\n"<<res<<" ";

        return res;
    }
}; 