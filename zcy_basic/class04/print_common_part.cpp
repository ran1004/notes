#include<iostream>
#include<set>
using namespace std;

struct node {
	int val;
	node *next;
};


class Solution {
public:
	// use set
	node *IsLoop(node *list) {
		set<node *>map;				
		node *p = list;
		while(p != NULL) {
			if(map.find(p) != map.end()) 
				return p;
			map.insert(p);	
			p = p->next;
		}

		return NULL;
	}

	void PrintCommonPart(node *list1, node *list2) {
		node *loop1 = IsLoop(list1);
		node *loop2 = IsLoop(list2);

		if(list1 == list2 && loop1 == loop2) {
			// list1 = list2 	
			node *p = list1;
			while(p != loop1) {
				cout << p->val << " ";	
				p = p->next;
			}
			
			if(loop1 != NULL) {
				cout << p->val << " ";	
				p = p->next;
				while(p != loop1) {
					cout << p->val << " ";	
					p = p->next;
				}
			}
			
			return;
		}

		// as long as one is not a loop
		if(!loop1 || !loop2) 
			return;
		
		if(loop1 == loop2 && list1 != list2) {
			int n1, n2;		
			n1 = n2 = 0;
			node *p = list1;
			while(p != loop1) 
				n1++, p = p->next;
			p = list2;
			while(p != loop2) 
				n2++, p = p->next;
			int diff = n1>n2? n1-n2 : n2-n1;
			node *p1, *p2;
			p1 = list1, p2 = list2;
			while(p1 != p2) {
				if(diff && n1 < n2)	{
					p2 = p2->next;	
					diff--;
				}	
				else if(diff && n1 > n2) {
					p1 = p1->next;	
					diff--;
				}
				else {
					p1 = p1->next;	
					p2 = p2->next;
				}
			}
			
			p = p1;
			while(p != loop1->next) {
				cout << p->val << " ";				
				p = p->next;
			}
				
			p = loop1->next;
			while(p != loop1) {
				cout << p->val << " ";				
				p = p->next;
			}

			return;

		}

		// if(list1 != list2 && loop1 != loop2)
		node *p = loop1->next;
		while(p != loop1) {
			if(p == loop2) {
				cout << p->val << " ";
				p = p->next;
				while(p != loop2) {
					cout << p->val << " ";	
					p = p->next;
				}
				
				return;
			}
			p = p->next;
		}
		
		return;
	}

};

int main() {
	node *n1 = new node;	
	node *n2 = new node;	
	node *n3 = new node;	
	node *n4 = new node;	
	node *n5 = new node;	
	node *n6 = new node;	
	node *n7 = new node;	
	n1->val = 1;
	n2->val = 2;
	n3->val = 3;
	n4->val = 4;
	n5->val = 5;
	n6->val = 6;
	n7->val = 7;
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;
	n5->next = n3;
	n6->next = n7;	
	n7->next = n5;

	Solution sol;	
	sol.PrintCommonPart(n1, n6);
	//bool is_loop = sol.IsLoop(n1);
	//if(is_loop)
		//cout << "loop !" << endl;
	//else
		//cout << "no loop !" << endl;
}

