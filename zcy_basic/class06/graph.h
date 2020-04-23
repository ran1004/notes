#ifndef GRAPH_H
#define GRAPH_H
#include<map>
#include<set>
#include"edge.h"
#include"node.h"

using namespace std;

class Graph {
public:
	map<int, Node *> nodes;
	set<Edge *> edges;
};

Graph *CreateGraph(int matrix[][3], int n);

void SortedTopology(Graph *graph);

#endif
