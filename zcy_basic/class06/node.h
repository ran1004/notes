#ifndef NODE_H
#define NODE_H
#include<list>

using namespace std;

class Edge;

class Node {
public:
	int value;
	int in;
	int out;
	list<Node *> nexts;
	list<Edge *> edges;

	Node(int val) {
		value = val;	
		in = 0;
		out = 0;
	}		
};


#endif
