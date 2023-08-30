#include<bits/stdc++.h>
int main(){
	std::vector<std::vector<int>> intervals = {{1,4},{3,5},{6,8},{8,9},{10,12}};
	std::vector<std::vector<int>> res;
	//sort
	std::sort(intervals.begin(),intervals.end());

	int firstInterval = intervals[0][0];
	int secondInterval = intervals[0][1];

	for(int i=1;i<intervals.size();i++){
		int comingFirstInterval = intervals[i][0];
		int comingSecondInterval = intervals[i][1];
		if(firstInterval>comingFirstInterval && secondInterval<=comingFirstInterval){
			secondInterval = comingFirstInterval;
		}else{
			res.push_back({firstInterval,secondInterval});
			firstInterval = comingFirstInterval;
			secondInterval = comingSecondInterval;
		}
	}
	res.push_back({firstInterval,secondInterval});

	for(auto index:res){
		for(int i=0;i<index.size();i++){
			std::cout<<index[i][0]<<" "<<index[i][1]<<"\n";
		}
	}
}