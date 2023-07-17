class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    void getPlatformCheck(std::vector<std::pair<int,int>> &platforms,int train_arrival,int train_depature){
        for(int i=0;i<platforms.size();i++){
            if(train_arrival>platforms[i].second){
                platforms[i]=std::make_pair(train_arrival,train_depature);
                return;
            }
        }
        platforms.push_back({train_arrival,train_depature});
    }
    int findPlatform(int arr[], int dep[], int n)
    {
    	// Your code here
    	std::vector<std::pair<int,int>> trains;
    	std::vector<std::pair<int,int>> platforms;
    	for(int i=0;i<n;i++){
    	    trains.push_back({arr[i],dep[i]});
    	}
    	std::sort(trains.begin(),trains.end());
    	for(int i=0;i<n;i++){
    	    if(!platforms.empty()){
    	        int train_arrival = trains[i].first;
    	        int train_depature = trains[i].second;
    	        getPlatformCheck(platforms,train_arrival,train_depature);
    	    }else{
    	        platforms.push_back(trains[i]);
    	    }
    	}
    	return platforms.size();
    }
};