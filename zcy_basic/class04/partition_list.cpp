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

	node* partitionList02(node *list, int pivot) {
		node *less, *equal, *large;
		node *p = list;
		less = equal = large = NULL;
		while(p != NULL) {
			if(p->val < pivot)	
				less = less? less : p;
			else if (p->val > pivot)
				large = large? large : p;
			else
				equal = equal? equal : p;

			p = p->next;
		}

	 	node *tmp_less, *tmp_equal, *tmp_large;
		tmp_less = less, tmp_equal = equal, tmp_large = large;
		p = list;
		while(p != NULL) {
			if(p == less || p == equal || p == large) {
				p = p->next;		
				continue;
			}			

			if(p->val < pivot && tmp_less) {
				tmp_less->next = p;	
				tmp_less = tmp_less->next;
			}
			else if(p->val > pivot && tmp_large) {
				tmp_large->next = p;	
				tmp_large = tmp_large->next;
			}
			else if(p->val == pivot && tmp_equal) {
				tmp_equal->next = p;		
				tmp_equal= tmp_equal->next;
			}				

			p = p->next;
		}

		if(tmp_less) tmp_less->next = NULL;
		if(tmp_equal) tmp_equal->next = NULL;
		if(tmp_large) tmp_large->next = NULL;

/*
		p = less;
		while(p) {
			cout << p->val << " ";	
			p = p->next;
		}
		cout << endl;
			
		p = equal;
		while(p) {
			cout << p->val << " ";	
			p = p->next;
		}
		cout << endl;

		p = large;
		while(p) {
			cout << p->val << " ";	
			p = p->next;
		}
		cout << endl;
*/
		
		if(less && equal && large)  
		{ // both don't empty
			tmp_less->next = equal;	
			tmp_equal->next = large;
			return less;
		}
		else if(!less && equal && large)
		{ // less is empty
			tmp_equal->next = large;
			return equal;
		}
		else if(less && !equal && large) 
		{ // equal is empty
			tmp_less->next= large;	
			return less;
		}
		else if(less && equal && !large)
		{ // large is empty
			tmp_less->next = equal;	
			return less;
		}
		else
			return list;

#if 0 
//error
		p = less;
		node *tmp = p;
		while(p != NULL && p->next != NULL) {
			p = p->next;
			if(p->val < pivot) {
				tmp->next = p;
				tmp = tmp->next;
				cout << tmp->val << " ";
			}
		}

		cout << endl;

		p = equal;
		tmp = p;
		while(p != NULL && p->next != NULL) {
			p = p->next;
			if(p->val == pivot) {
				tmp->next = p;
				tmp = tmp->next;
				cout << tmp->val << " ";
			}
		}

		cout << endl;
	
		p = large;
		tmp = p;
		while(p != NULL && p->next != NULL) {
			p = p->next;
			if(p->val > pivot) {
				tmp->next = p;
				tmp = tmp->next;
				cout << tmp->val << " ";
			}
		}
		
		cout << endl;

#endif

	}	
};
	
int main() {
	vector<int> arr = {3, 5, 2, 2, 6, 1};
	//vector<int> arr = {7, 3, 4, 6, 0, 4};
	
	node *list[6];
	for(int i=0; i<6; i++) {
		list[i] = new node;
		list[i]->val = arr[i];
	}

	for(int i=0; i<5; i++)
		list[i]->next = list[i+1];
	list[5] = NULL;

	Solution sol;
	node *p = sol.partitionList02(list[0], 4);
	while(p) 
		cout << p->val << " ", p = p->next;
	cout << endl;

	for(int i=0; i<arr.size(); i++)
		delete list[i];
}

