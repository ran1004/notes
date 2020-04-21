#include"graph.h"
#include<set>
#include<stack>
using namespace std;

void dfs(Node *cur) {
	if(cur == NULL)
		return;
	ser<Node *> set;
	stack<Node *> stack;
	set.insert(cur);
	stack.push(cur);
	while(!stack.empty()) {
		cur = stack.top();	
		stack.pop();
		cout << cur->value << " ";
		for(Node *p : cur->nodes) {
			if(set.find(p) == set.end()) {
				set.insert(p);	
				stack.push(p);
			}	
		}
	}

	cout << endl;
}
