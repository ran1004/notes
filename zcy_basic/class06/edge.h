#ifndef EDGE_H
#define EDGE_H
#include"node.h"
using namespace std;

class Edge {
public:
	int weight;
	Node *from;
	Node *to;
	Edge();
	Edge(int weight, Node *from, Node *to) {
		this->weight = weight;	
		this->from = from;
		this->to = to;
	}
};

#endif;
