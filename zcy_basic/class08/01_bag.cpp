#include<iostream> 
#include<vector>
using namespace std;

int max(int &a, int &b) {
	return a>b? a : b;
}


class Solution {
public:
	int process1(vector<int> &v, vector<int> &w,
			int i, int weight ,int bag) {
		if(weight > bag)
			return -1000000;
		if(i == v.size())
			return 0;

		return max(process1(v, w, i+1, weight, bag),
			v[i]+process1(v, w, i+1, weight+w[i], bag));			
	}

	int process2(vector<int> &v, vector<int> &w, const int bag) {
		int dp[v.size()+1][bag+1];
		for(int i=0; i<v.size()+1; i++)
			for(int j=0; j<bag+1; j++)
				dp[i][j] = 0;

		for(int i=v.size()-1; i>=0; i--) {
			for(int j=bag; j>=0; j--) {
				dp[i][j] = dp[i+1][j];	
				if(j+w[i] <= bag)
				dp[i][j] = max(dp[i+1][j], v[i]+dp[i+1][j+w[i]]);
			}
			for(int j=0; j<=bag; j++)
				cout << dp[i][j] << " ";
			cout << endl;
		}
		return dp[0][0];
	}

	int process3(vector<int> v, vector<int> w, int bag) {
		int dp[bag+1];
		for(int i=0; i<bag+1; i++)
			dp[i] = 0;
		for(int i=v.size()-1; i>=0; i--) {
			for(int j=0; j<=bag; j++) {
				dp[j] = dp[j];						
				if(j+w[i] <= bag)
				dp[j] = max(dp[j], v[i]+dp[j+w[i]]);
				// dp[i][j] = max(dp[i][j+1], v[i]+dp[i+1][j+w[i]])
			} 
		}

		return dp[0];
	}
};



int main() {
	vector<int> v = {2, 4, 3};		
	vector<int> w = {1, 2, 1};		
	//cout << Solution().process1(v, w, 0, 0, 3) << endl;
	cout << Solution().process2(v, w, 3) << endl;
	cout << "----------" << endl;
	cout << Solution().process3(v, w, 3) << endl;
}
