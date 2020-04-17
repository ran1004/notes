#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class cmp {
public:
	bool operator()(int a, int b) {
		return a>b;	
	} 
};

class Solution {
public: 
	int MinCostCutGoldBar(vector<int> &v) {
		int cost = 0;
		if(v.size() == 0)
			return 0;
		if(v.size() == 1)
			return v[0];
		priority_queue<int, vector<int>, cmp> heap;
		for(int i=0; i<v.size(); i++)
			heap.push(v[i]);
		while(heap.size() > 1) {
			int a = heap.top();	
			heap.pop();
			int b = heap.top();
			heap.pop();
			cost += a+b;
			heap.push(a+b);
		}

		return cost;
	}
};

int main() {
	vector<int> v = {10, 20, 30};	
	cout << Solution().MinCostCutGoldBar(v)	<< endl;	
}
