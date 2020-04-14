#include<iostream>
#include<stack>
using namespace std;

struct node {
	int  val;
	node *next;
};

class Solution {
public:
	node* reverseList(node *list) {
		node *p1, *p2;	
		p1 = list;
		p2 = p1->next;
		p1->next = NULL;
		while(p2 != NULL) {
			node *tmp = p2->next;
			p2->next = p1;
			p1 = p2;
			p2 = tmp;
		}

		return p1;
	}

	bool isPailndrome01(node *list) {
		stack<node *> s;	
		node *tmp = list;
		while(tmp != NULL) {
			s.push(tmp);	
			tmp = tmp->next;
		}
		
		int n = s.size();
		for(int i=0; i<n; i++) {
			if(list->val != s.top()->val)	
				return false;
			s.pop();
			list = list->next;
		}
	
		return true;
	}

	bool isPailndrome02(node *list) {
		node *sp, *qp;		 			
		sp = qp = list;
		while(qp != NULL && qp->next != NULL) {
			qp = qp->next->next;
			sp = sp->next;
		}		
		//cout << sp->val << endl;
		node *right = reverseList(sp);	
		node *left  = list;
		while(left && right) {
			if(left->val != right->val)	
				return false;
			cout << left->val << "," << right->val << endl;
			left  = left->next;
			right = right->next; 
		}

		return true;
	}

};



int main() {
	node *arr[10];
	for(int i=0; i<10; i++) {
		arr[i] = new node;
	}
	for(int i=0; i<9; i++)	
		arr[i]->next = arr[i+1];
	arr[9]->next = NULL;

	for(int i=0; i<5; i++)	
		arr[i]->val = i+1;

	for(int i=5; i<10; i++)	
		arr[i]->val = 10-i;
		
	//node *list = arr[0];
	//while(list) {
		//cout << list->val << endl;	
		//list = list->next;
	//}

	arr[8]->next = NULL;
	
	Solution sol;

	bool ans = sol.isPailndrome02(arr[0]);
	if(ans)
		cout << "1";
	else
		cout << "2";	

	for(int i=0; i<arr.size(); i++)
		delete arr[i];
		
}
