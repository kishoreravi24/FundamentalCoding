#include<bits/stdc++.h>
void towerOfHanoi(int n,char from_rod,char aux_rod,char to_rod){
    if(n == 1){
        std::cout << "Move disk 1 from " << from_rod << " to " << to_rod << "\n";
        return;
    }
	towerOfHanoi(n-1,from_rod,aux_rod,to_rod);
	std::cout<<"Move disk "<<n<<" from "<<from_rod<<" to "<<to_rod<<"\n";
	towerOfHanoi(n-1,aux_rod,to_rod,from_rod);
	return;
}
int main(){
	int n;
	std::cin>>n;
	towerOfHanoi(n,'A','B','C');
	return 0;
}