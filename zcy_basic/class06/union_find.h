#ifndef UNION_FIND_H
#define UNION_FIND_H
#include<iostream>
#include<map>
#include<list>
using namespace std;

template <typename T>
class UnionFind {
public:	
	class Node {
	public:
		T value;	
		Node(T v) {
			value = v;	
		}
	};

	class UnionSet {
	public:	
		map<T, Node> nodes;
		map<Node, Node> parents;
		map<Node, int> size_map;

		//Intialize
		UnionSet(list<T> values) {
			for(T value : values) {
				Node node = new Node(value);	
				nodes.insert(value, node);
				parents.insert(node, node);
				size_map.insert(node, 1);
			}
		}

		Node FindFather(Node cur) {
			Node f = *parents.find(cur);	
			if(f != *parents.find(f))
				parents[cur] = FindFather(f);
			else
				return cur;
		}

		bool IsSameSet(T a, T b) {
			if(nodes.find(a) == nodes.end()
				|| nodes.find(b) == nodes.end())	
					return false;
			return FindFather(*nodes.find(a))
					== FindFather(*nodes.find(b));
		}

		void Union(T a, T b) {
			if(nodes.find(a) == nodes.end()
				|| nodes.find(b) == nodes.end())	
					return;
			Node a_head = FindFather(*nodes.find(a));
			Node b_head = FindFather(*nodes.find(b));
			if(a_head != b_head) {
				int a_size = *size_map.find(a_head);
				int b_size = *size_map.find(b_head);
				if(a_size >= b_size) {
					parents.insert(b_head, a_head);	
					size_map[a_head] = a_size+b_size;
					size_map.erase(b_head);
				} else {
					parents.insert(a_head, b_head);	
					size_map[b_head] = a_size+b_size;
					size_map.erase(a_head);
				
				}
			}
		}
	};


};


#endif

