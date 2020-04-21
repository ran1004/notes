#incldue"graph.h"
#include<iostream>
#include<queue>
#include<set>
using namespace std; 

void bfs(Node *cur) {
	if(cur == NULL)
		return;
	queue<Node *> q;
	set<Node *> s;
	q.push(cur);
	s.insert(cur);
	while(!q.empty()) {
		cur = q.front();	
		q.pop();
		cour << cur->value << " ";
		for(Node *p : cur->nodes) 
			if(s.find(p) == s.end()) {
				s.insert(q);
				q.push(q);
			}
	}

	cout << endl;
}




