#include<bits/stdc++.h>
//Design a calendar
bool checkBeforeMeeting(std::vector<std::pair<int,int>> meetings,std::vector<std::pair<int,bool>> result, int start,int end){
    for(int i=0;i<meetings.size();i++){
        int meet_end = meetings[i].second;
        bool phase = result[i].second;
        if(start>=meet_end&&phase == true){
            return true;
        }
    }
    return false;
}
int main(){
    std::vector<std::vector<int>> calendar = {{10, 20},
                                              {15, 25},
                                              {20, 30}};
    std::vector<std::pair<int,int>> meetings;
    std::vector<std::pair<int,bool>> result;
    for(int i=0;i<calendar.size();i++){
        // list all bookings
        if(meetings.size()==0){
            meetings.push_back({calendar[i][0],calendar[i][1]});
            result.push_back({i,true});
        }else{
            bool phase = checkBeforeMeeting(meetings,result,calendar[i][0],calendar[i][1]);
            result.push_back({i,phase});
        }
    }
    std::vector<bool> finalResult;
    for(auto it:result){
        finalResult.push_back(it.second);
    }
    for(auto it:finalResult){
        if(it==true){
            std::cout<<"true"<<" ";
        }else{
            std::cout<<"false"<<" ";
        }
    }
}