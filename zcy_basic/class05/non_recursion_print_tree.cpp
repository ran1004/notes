#include<iostream>
#include<stack>
using namespace std;

struct node {
	int val;
	node *left;
	node *right;
	node() {
		left = NULL;	
		right = NULL;
	}
};


class Solution {
public:
	void NonRecurisonPreorder(node *root) {
		stack<node *> s;
		if(root == NULL)
			return;
		s.push(root);
		while(!s.empty()) {
			node *tmp = s.top();		
			s.pop();
			cout << tmp->val << endl;
			if(tmp->right != NULL)
				s.push(tmp->right);
			if(tmp->left != NULL)
				s.push(tmp->left);
		}
	}
	
	void NonRecurisonInorder(node *root) {
		if(root == NULL)		
			return;
		stack<node *>s;
		while(!s.empty() || root) {
			if(root != NULL) {
				s.push(root);	
				root = root->left;
			}
			else {
				root = s.top();
				cout << root->val << endl;
				s.pop();
				root = root->right;
			}
		}
	}

	/* two stack */
	void NonRecurisonPostorder(node *cur) {
		if(cur == NULL)			
			return;
		stack<node *> s;	
		stack<node *> help;
		s.push(cur);
		while(!s.empty()) {
			cur = s.top();				
			help.push(cur);
			s.pop();
			if(cur->left != NULL)
				s.push(cur->left);
			if(cur->right != NULL)
				s.push(cur->right);
		}

		while(!help.empty()) {
			cout << help.top()->val << endl;	
			help.pop();
		}
	}

	/* magic */
	void NonRecurisonPostorder2(node *cur) {
		if(cur == NULL)
			return;
		stack<node *> s;
		s.push(cur);
		node *last = NULL;
		while(!s.empty()) {
			cur = s.top();
			if(cur->left && last!= cur->left && last!= cur->right)	
				s.push(cur->left);
			else if(cur->right && last!=cur->right)
				s.push(cur->right);
			else {
				cout << cur->val << endl;	
				s.pop();
				last = cur;
			}
		}
		cout << endl;
	}

};



int main() {
	node *n1 = new node;
	n1->val = 1;
	node *n2 = new node;
	n2->val = 2;
	node *n3 = new node;
	n3->val = 3;
	node *n4 = new node;
	n4->val = 4;
	node *n5 = new node;
	n5->val = 5;
	node *n6 = new node;
	n6->val = 6;
	node *n7 = new node;
	n7->val = 7;

	n1->left = n2;	
	n1->right = n3;
	n2->left = n4; 
	n2->right = n5;

	n5->left = n6;
	n5->right = n7;

	Solution().NonRecurisonPostorder2(n1);

}


