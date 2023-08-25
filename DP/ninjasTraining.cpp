#include<bits/stdc++.h>
int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
    std::map<int,std::pair<int,int>> hash;
    for(int i=0;i<n;i++){
    	
    }
}
int main(){
	int n;
	std::cin>>n;
	std::vector<std::vector<int>> points;
	for(int i=0;i<n;i++){
		std::vector<int> temp;
		for(int j=0;j<n;j++){
			int x;
			std::cin>>x;
			temp.push_back(x);
		}
		points[i].push_back(temp);
	}

	ninjaTraining(n,points);
}