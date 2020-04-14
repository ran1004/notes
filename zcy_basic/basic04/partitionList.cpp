#include<iostream> 
#include<vector>
using namespace std;

void swap(int &a, int &b) {
	int tmp = a;
	a = b;
	b = tmp;
}


void partition(vector<int> &arr, int pivot) {
	int L, R, cur;
	L = -1, R = arr.size(), cur = 0;
	while(cur < R) {
		if(arr[cur] < pivot)	
			swap(arr[++L], arr[cur++]);
		else if(arr[cur] > pivot)
			swap(arr[--R], arr[cur]);
		else
			cur++;
	}
}

struct node {
	int val;
	node *next;
};

class Solution {
public:
	void partitionList(node *list, int pivot) {
		vector<int>	arr;		
		node *p = list;
		while(p != NULL) {
			arr.push_back(p->val);
			p = p->next;			
		}
		
		partition(arr, pivot);
		p = list;
		int cnt = 0;
		while(p != NULL) {
			p->val = arr[cnt++];
			p = p->next;			
		}
	}
};
	
int main() {
	vector<int> arr = {3, 5, 2, 4, 6, 1};
	node *list[6];
	for(int i=0; i<6; i++) {
		list[i] = new node;
		list[i]->val = arr[i];
	}

	for(int i=0; i<5; i++)
		list[i]->next = list[i+1];
	list[5] = NULL;

	Solution sol;
	sol.partitionList(list[0], 3);
	node *p = list[0];
	while(p) 
		cout << p->val << " ", p = p->next;
	cout << endl;

	for(int i=0; i<list.size(); i++)
		delete list[i];
}

