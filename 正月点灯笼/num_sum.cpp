#include<iostream>
#include<vector>
using namespace std;

bool dp[1010][1010];
const int target = 13;

int main() {
	vector<int>	nums = {3, 32, 4, 12, 5, 2};		
	if(nums[0] <= target)
		dp[1][nums[0]] = true;
	for(int i = 0; i <= nums.size(); i++)
		dp[i][0] = true;
	for(int i = 2; i <= nums.size(); i++) {
		for(int j = 0; j <= target; j++) {
			dp[i][j] = dp[i-1][j];
			if(j >= nums[i-1])
				dp[i][j] = dp[i][j] || dp[i-1][j-nums[i-1]];
		}	
	}

	for(int i = 0; i <= nums.size(); i++) {
		for(int j = 0; j <= target; j++)	
			cout << dp[i][j] << " ";
		cout << endl;
	}

	cout  << dp[nums.size()][10] << endl;
	cout  << dp[nums.size()][11] << endl;
	cout  << dp[nums.size()][12] << endl;
	cout  << dp[nums.size()][13] << endl;
	
}
