#include<iostream>
#include<cstdlib>
#include<time.h>
using namespace std;

struct node {
	int num;
	struct node* next;	
	node() {
		this->next = NULL;	
	}
};

typedef struct node node;

 
class Solution {
public:
	node* IsLoop(node *list) {
		node *qq, *sq;		
		qq = sq = list;
		while(qq != NULL && qq->next != NULL) {
			qq = qq->next->next;		
			sq = sq->next;	
			if(sq == qq) {
				qq = list;	
				while(sq != qq) {
					sq = sq->next;
					qq = qq->next;
				}

				return qq;
			}
		}
		
		return NULL;
	}
	
	
};


int main() {
	node *arr[10];	
	for(int i=0; i<10; i++)
		arr[i] = new node, arr[i]->num = i;			
	for(int i=0; i<9; i++)	
		arr[i]->next = arr[i+1];	
	
	arr[9]->next = arr[4];

	Solution sol;
	sol.f2();
	node * ans = sol.IsLoop(arr[0]);
	if(ans)
		cout << ans->num << endl;
	else
		cout << "not Loop !" << endl;

	for(int i=0; i<10; i++)
		delete arr[i];
}
