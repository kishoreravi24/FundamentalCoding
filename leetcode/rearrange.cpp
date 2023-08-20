class Solution{
public:

	void rearrange(int arr[], int n) {

	    // Taking the postive elements and store it in postive array
	    int pos[n],k=0;
	    for(int i=0;i<n;i++){
	        if(arr[i]>=0){
	            pos[k]=arr[i];
	            k++;
	        }
	    }
	    
	    // Taking the negative elements and store it in negative array
	    int neg[n],m=0;
	    for(int i=0;i<n;i++){
	        if(arr[i]<0){
	            neg[m]=arr[i];
	            m++;
	        }
	    }
        
        int start=0;
        int end=0;
        int counter = 0;
        while(start<k&&end<m){
            arr[counter++] = pos[start++];
            arr[counter++] = neg[end++];
        }
        
        // if element left in positive array
        while(start<k){
            arr[counter++] = pos[start++];
        }
        
        // if element left in negative array
        while(end<m){
            arr[counter++] = neg[end++];
        }
	}
};