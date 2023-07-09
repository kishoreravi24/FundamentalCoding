#include<bits/stdc++.h>
int main(){
	//convert decimal to binary
	unsigned int a = 10;
	std::bitset<sizeof(a)*8> decimalToBinary(a);
	std::string s = decimalToBinary.to_string();
	std::cout<<s;

	//convert binary to decimal
	std::string s = "1010";
	std::bitset<sizeof(s)*8> binaryToDecimal(s);
	unsigned int b = binaryToDecimal.to_ulong();
	std::cout<<b;


	// other way decimal to binary
	int decimal = 10,i=0;
	int a[];
	while(decimal--){
		a[i++]=decimal%2;
		decimal/=2;
	}

	// other way binary to decimal
	int temp = 1010,base=1;
	while(temp){
		int last_digit = temp%10;
		temp/=10;

		dec_value+=last_digit*base;
		base=base*2;
	}

}