// snake and ladders
// https://practice.geeksforgeeks.org/problems/snake-and-ladder-problem4816/1?page=1&category[]=Graph&curated[]=1&sortBy=submissions

#include<bits/stdc++.h>
int startGame(int moves[],int n){
	//step vist
	std::vector<bool> visited(n,false);

	//queue for trade the moves
	std::queue<std::pair<int,int>> q;

	q.push(std::make_pair(0,0));

	while(!q.empty()){
		int move = q.front().first;
		int distance = q.front().second;
		q.pop();
		if(visited[move]==true){
			continue;
		}

		if(move==n-1){
			return distance;
		}

		visited[move]=true;

		for(int i=move+1;i<=move+6&&i<n;i++){
			//checking snake or ladder
			if(moves[i]!=-1){
				q.push(std::make_pair(moves[i],distance+1));
			}else{
				q.push(std::make_pair(i,distance+1));
			}
		}
	}
	return -1;
}
int main(){
	int n=30;
	int moves[n];
	for(int i=0;i<n;i++){
		moves[i]=-1;
	}

	//ladders
	moves[3]=22;
	moves[5]=8;
	moves[11]=26;
	moves[20]=29;

	//snakes
	moves[17]=4;
	moves[19]=7;
	moves[27]=1;
	moves[21]=9;

	std::cout<<startGame(moves,n)<<" ";
}