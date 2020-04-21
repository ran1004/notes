#ifndef NODE_H
#define NODE_H
#include<list>
#include"edge.h"

using namespace std;

class Node {
public:
	int value;
	int in;
	int out;
	list<Node> nexts;
	list<Edge> edges;

	Node(int val) {
		value = val;	
		in = 0;
		out = 0;
	}		
};


#endif
