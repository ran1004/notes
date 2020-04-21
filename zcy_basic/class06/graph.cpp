#include"graph.h"

Graph *CreateGraph(int matrix[][3], int n) {
	Graph *graph = new Graph;
	for(int i=0; i<n; i++)  {
		int weight = matrix[i][0];
		int from = matrix[i][1];	
		int to = matrix[i][2];
		if(graph->nodes.find(from) == graph->nodes.end())
			graph->nodes[from] = new Node(from);
		if(graph->nodes.find(to) == graph->nodes.end())
			graph->nodes[to] = new Node(to);

		Node *from_node = graph->nodes[from];
		Node *to_node = graph->nodes[to];

		Edge *new_edge = new Edge(Weight, from_node, to_node);
		from_node->nexts.push_back(to_node);
		from_node->out++;
		from_node->edges.push_back(new_edge);
		to_node->in++;
		graph->edges.insert(new_edge);
	}

	return graph;
}
