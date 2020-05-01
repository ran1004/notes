#include<iostream>
#include<vector>
using namespace std;

int dp[1010][1010];

struct job {
	int val;
	int begin;
	int end;
	job (int x, int y, int z): val(x), begin(y), end(z) {};
};

int main() {
	job j1(5, 1, 4);
	job j2(1, 3, 5);
	job j3(8, 0, 6);
	job j4(4, 4, 7);
	job j5(6, 3, 8);
	job j6(3, 5, 9);
	job j7(2, 6, 10);
	job j8(4, 8, 11);
	vector<job> JOB= {j1, j2, j3, j4, j5, j6, j7, j8};

	for(int i = 0;  i < JOB.size(); i++) {
		dp[JOB[i].end][JOB[i].begin] = JOB[i].val;	
	}

	//for(int i = 0; i <= 11; i++) {
		//for(int j = 0; j <= 11; j++) 
			//cout << dp[i][j] << " ";
		//cout << endl;
	//}

	for(int i = 0; i <= 11; i++) {
		for(int j = i; j >= 0; j--) {
			for(int k = j; k <= i; k++) {
				dp[i][j] = max(dp[i][j], dp[k][j]+dp[i][k]);		
			}	
		}	
	}

	cout << dp[11][0] << endl;
	return 0;
	
}
