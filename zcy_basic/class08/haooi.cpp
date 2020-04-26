#include<iostream>
#include<string>
using namespace std;

void Honoi(int n, string from, string to, string help) {
	if(n == 1) 	{
		cout <<	 "move " << n << " from " << from << " to " << to << endl;
	} else {
		Honoi(n-1, from, help, to);	
		cout <<	 "move " << n << " from " << from << " to " << to << endl;
		Honoi(n-1, help, to, from);
	}
}


int main() {
	string from = "from";
	string to = "to";
	string help = "help";
	Honoi(3, from, to, help);
}
