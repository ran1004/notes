#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct job {
	int val;
	int begin;
	int end;
	job (int x, int y, int z): val(x), begin(y), end(z) {};
};

struct {
	bool operator() (job a, job b) {
		return a.end < b.end;	
	}
} cmp;

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
	std::sort(JOB.begin(), JOB.end(), cmp);	
	
	//for(job n : JOB) {
		//cout << n.end << " ";	
	//cout << endl;
	
	int opt[8];
	for(int i = 0; i < 8; i++) {
		int j = i;
		while(j>=0 && JOB[j].end > JOB[i].begin) {
			j--;
		}
		opt[i] = j+1;
	}
	//vector<int> opt = {0, 0, 0, 1, 0, 2, 3, 5};

	int dp[9];
	dp[0] = 0;
	for(int i = 1; i <= 8; i++) {
		dp[i] = max(dp[i-1], JOB[i-1].val+dp[opt[i-1]]);
	}
	for(int n : dp)
		cout << n << " ";
	cout << endl;
	return 0;

}
