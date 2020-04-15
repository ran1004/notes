#include<iostream>
#include<vector>
using namespace std;

struct node {
	int val;
	node *next;
	node *random;
};

class Solution {
public:
	node *CopyListWithRandom(node *list) {
		vector<int> arr;
		node *p = list;
		while(p != NULL) {
			if(p->random)
				arr.push_back(p->random->val);
			else
				arr.push_back(0);
			p = p->next;
		}
/*	
		for(int i=0; i<arr.size(); i++)
			cout << arr[i] << " ";
		cout << endl;		
*/
		int n = arr.size();
		node *newlist = new node[n];
		for(int i=0; i<n-1; i++) {
			newlist[i].next = &newlist[i+1];	
			newlist[i].val = i+1;
		}
				
		newlist[n-1].next = NULL;
		newlist[n-1].val = n;
		for(int i=0; i<n; i++)
			if(arr[i])
				newlist[i].random = &newlist[arr[i]-1];
			else
				newlist[i].random = NULL;

		return &newlist[0];
	}

	node *CopyListWithRandom02(node *list) {
		node *p = list;	
		while(p != NULL) {
			node *tmp = p->next;	
			p->next = new node;
			p->next->val = p->val;
			p->next->next = tmp;
			p = tmp;
		}

		p = list;
		while(p != NULL) {
			node *tmp = p->next;	
			if(p->random)
				tmp->random = p->random->next;
			else
				tmp->random = NULL;

			p = tmp->next;
		}
/*
		p = list;
		while(p != NULL) {
			if(p->random)	
				cout << p->val << ", " << p->random->val << endl;
			else
				cout << p->val << endl;
			
			p = p->next;	
		}

		return NULL;
*/

		// split list
		p = list;	
		node *ret = p->next;
		while(p != NULL) {
			p->next = p->next->next;	
			p = p->next->next;
		}
		
		return ret;
	}
};

int main() {

	node *n1 = new node;
	node *n2 = new node;
	node *n3 = new node;
	n1->val = 1;
	n2->val = 2;
	n3->val = 3;
	n1->next = n2;
	n2->next = n3;
	n3->next = NULL;
	n1->random = n3;
	n2->random = n1;
	n3->random = NULL;

//	cout << n1 << endl;

	Solution sol;	
	node *p = sol.CopyListWithRandom02(n1);

//	cout << p << endl;
//
	while(p != NULL) {
		if(p->random)
			cout << p->val << "," << p->random->val << endl;
		else
			cout << p->val << endl;

		p = p->next;
	}

	delete n1;
	delete n2;
	delete n3;

}

