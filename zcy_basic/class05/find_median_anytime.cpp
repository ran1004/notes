#include<iostream>
#include<queue>
#include<vector>
using namespace std;

struct cmp {
	bool operator()(int a, int b) {
		return a>b;	
	}
};

class MyVector {
public:
	priority_queue<int> h1 ; // big root pile
	priority_queue<int, vector<int>, cmp> h2; // small root pile

	void push(int X) {
		if(!h1.size() || X < h1.top())
			h1.push(X);
		else
			h2.push(X);
		if(h1.size() > h2.size()+1) {
			h2.push(h1.top());	
			h1.pop();
		}
		if(h2.size() > h1.size()+1) {
			h1.push(h2.top());	
			h2.pop();
		}
	}
	
	int pop(void) {
		if(!h1.size())
			return 0;
		if(!h2.size()) 
			return h1.top();
		if((h1.size()+h2.size()) & 1) 
			return h1.size()>h2.size()? h1.top() : h2.top();	
		else
			return (h1.top()+h2.top()) >> 1;
	}
};


int main() {

#if 0
	priority_queue<int, vector<int>, cmp> heap;
	heap.push(4);
	heap.push(2);
	heap.push(5);
	heap.push(1);
	heap.push(6);
	while(heap.size()) {
		cout << heap.top() << ", " << heap.size() << endl;	
		heap.pop();
	}
#endif

	MyVector my_vector;	
	my_vector.push(5);
	my_vector.push(4);
	my_vector.push(2);
	my_vector.push(1);
	my_vector.push(7);
	my_vector.push(8);
	cout << my_vector.pop() << endl;
}
