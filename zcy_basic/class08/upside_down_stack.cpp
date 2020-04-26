#include<iostream>
#include<stack>
using namespace std;

class Solution {
public:
	int RemoveLastOneInStack(stack<int> &s) {
		int res = s.top();
		s.pop();
		if(s.empty())	
			return res;
		int last = RemoveLastOneInStack(s);
		s.push(res);
		return last;
	}

	void UpsideDownStack(stack<int> &s) {
		if(s.empty())
			return;
		int last = RemoveLastOneInStack(s);
		UpsideDownStack(s);
		s.push(last);
	}
};


int main() {
	stack<int> s;
	s.push(1);
	s.push(2);
	s.push(3);
	
	Solution sol;
	sol.UpsideDownStack(s);
	//cout << sol.RemoveLastOneInStack(s) << endl;
	 while(!s.empty()) {
		cout << s.top() << endl;	
		s.pop();
	}

}
