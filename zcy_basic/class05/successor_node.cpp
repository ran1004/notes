#include<iostream>
using namespace std;

struct node {
	int val;
	node *left;
	node *right;
	node *parent;

	node(int val) {
		this->val = val;
		parent = NULL;	
		left = NULL;
		right = NULL;
	}
};


class Solution {
public:	
	node *FindSuccessorNode(node *cur) {
		if(cur->right != NULL) {
			cur = cur->right;
			while(cur->left != NULL)
				cur = cur->left;
			return cur;
		} else if(cur->parent 
			&& cur->parent->left == cur) {
			return cur->parent;
		} else {
			node *p = cur->parent;		
			while(p && p->right == cur) {
				cur = p;	
				p = cur->parent;
			}
			return p;
		}
	}

	void Inorder(node *cur) {
		if(cur == NULL)	
			return;
		Inorder(cur->left);
		cout << cur->val << endl;
		Inorder(cur->right);
	}
};


int main() {
	node *n1 = new node(1);		
	node *n2 = new node(2);		
	node *n3 = new node(3);		
	node *n4 = new node(4);		
	node *n5 = new node(5);		
	node *n6 = new node(6);		
	node *n7 = new node(7);		

	n1->left = n2, n1->right = n3;
	n2->left = n4, n2->right = n5;
	n5->left = n6, n5->right = n7;

	n1->parent = NULL;
	n2->parent = n1;	
	n3->parent = n1;
	n4->parent = n2;
	n5->parent = n2;
	n6->parent = n5;
	n7->parent = n5;

	cout << Solution().FindSuccessorNode(n7)->val << endl;

	delete n1;
	delete n2;
	delete n3;
	delete n4;
	delete n5;
	delete n6;
	delete n7;

}
