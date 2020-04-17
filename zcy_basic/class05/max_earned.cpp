#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct node {
	node(int a, int b) {
		cost = a;	
		profit = b;
	}
	int cost;
	int profit;
};



class cmp1 {
public:
	bool operator()(node a, node b) {
		return a.cost > b.cost;
	}
};

class cmp2 {
public:
	bool operator()(node a, node b) {
		return a.profit <= b.profit;
	}
};

class Solution {
public:
	int GetMaxEarned(vector<node> &arr, int m, int k) {
		priority_queue<node, vector<node>, cmp1> h1;
		priority_queue<node, vector<node>, cmp2> h2;
		for(int i=0; i<arr.size(); i++)
			h1.push(arr[i]);
/*			
		for(int i=0; i<arr.size(); i++)
		{
			cout << h1.top().cost << ", " << h1.top().profit << endl;	
			h1.pop();
		}
*/
		while(k != 0) {
			while(h1.size() && h1.top().cost <= m) {
				h2.push(h1.top());		
				h1.pop();
			}	

			m += h2.top().profit;
			h2.pop();
			k--;
		}	

		return m;
	}
};

int main() {
	vector<int> cost = {7, 5, 3};	
	vector<int> profit = {7, 3, 2};	
	vector<node> arr;
	for(int i=0; i<cost.size(); i++)
		arr.push_back(node(cost[i], profit[i]));

	cout << Solution().GetMaxEarned(arr, 3, 2) << endl;
}


