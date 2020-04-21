#ifndef GRAPH_H
#define GRAPH_H
#include<map>
#include<set>
#include"node.h"
#include"edge.h"

using namespace std;

class Graph {
public:
	map<int, Node> nodes;
	map<int, Edge> edges;
};

Graph *CreateGraph(int matrix[][3], int n);

#endif
