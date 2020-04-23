#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int process01(vector<int> &v, vector<int> &w, int bag) {
		vector<vector<int> > dp(v.size()+1, vector<int>(bag+1));
		for(int i=0; i<v.size(); i++)
			for(int j=0; j<=bag; j++) {
				dp[i+1][j] = dp[i][j];
				if(j-w[i] >= 0)
					dp[i+1][j] = max(dp[i][j], v[i]+dp[i+1][j-w[i]]); 
			}

		return dp[v.size()][bag];
	}

	int process02(vector<int> &v, vector<int> &w, int bag) {
			vector<int> dp(bag+1, 0);
			for(int i=0; i<v.size(); ++i) 
				for(int j=0; j<=bag; j++) {
					dp[j] = dp[j];
					if(j-w[i] >= 0)
						dp[j] = max(dp[j], v[i]+dp[j-w[i]]);
				}
			 
			 return dp[bag];
	}
};



int main() {
	vector<int> v = {1, 3, 2};
	vector<int> w = {1, 3, 3};
	cout << Solution().process02(v, w, 5) << endl;
}
