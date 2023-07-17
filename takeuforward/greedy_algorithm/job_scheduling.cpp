class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    void checkJobAllot(std::vector<int> &jobAllot,int profit,int deadLine,int n){
        if(jobAllot[deadLine]==-1){
            jobAllot[deadLine] = profit;
        }else{
            deadLine--;
            while(deadLine!=0){
                if(jobAllot[deadLine]==-1){
                    jobAllot[deadLine]=profit;
                    break;
                }
                deadLine--;
            }   
        }
    }
    std::vector<int> JobScheduling(Job arr[], int n) {
        std::vector<std::pair<int, std::pair<int, int>>> scheduler;
        std::vector<int> res;
        std::vector<int> jobAllot(n+1,-1);
        int maxDeadline=0;
        for(int i=0;i<n;i++){
            scheduler.push_back(std::make_pair(arr[i].profit, std::make_pair(arr[i].id, arr[i].dead)));
            maxDeadline = std::max(maxDeadline,arr[i].dead);
        }
        jobAllot.resize(maxDeadline,-1);
        std::sort(scheduler.rbegin(), scheduler.rend());
        for(int i=0;i<n;i++){
            int deadLine = scheduler[i].second.second;
            int profit = scheduler[i].first;
            checkJobAllot(jobAllot,profit,deadLine,n);
        }
        int count=0,sum=0;
        for(int i=1;i<=n;i++){
            if(jobAllot[i]!=-1){
                count++;
                sum+=jobAllot[i];
            }
        }
        res.push_back(count);
        res.push_back(sum);
        return res;
    }
};