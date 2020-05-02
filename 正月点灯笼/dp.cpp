#include<iostream>
#include<vector>
using namespace std;

int dp[1010];

int main() {
	vector<int> v = {1, 2, 4, 1, 7, 8, 3};	
	dp[1] = 1;
	for(int i = 2; i <= 7; i++) {
		dp[i] = max(dp[i-1], dp[i-2] + v[i-1]);
	}
	for(int i = 0 ; i < 8; i++)
		cout << dp[i] << " ";
	cout << endl;
	
	return 0;
}
