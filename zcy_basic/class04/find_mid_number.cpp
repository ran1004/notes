#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	bool findMidNumber(vector<vector<int> > &arr, int num) {
		int row = arr.size();			
		int col = arr[0].size();
		int x, y;
		x = 0, y = col-1;
		while(x<row && y>=0) {
			cout << arr[x][y] << " ";
			if(num > arr[x][y])		
				x++;
			else if(num < arr[x][y])
				y--;
			else
				return true;
		}

		return false;
	}
};

void show(vector<vector<int> > &arr) {
	for(int i=0; i<arr.size(); i++) {
		for(int j=0; j<arr[0].size(); j++)	
			cout << arr[i][j] << " ";
		cout << endl;
	}
}


int main() {		
	const int row = 4;
	const int col = 4;
	vector<vector<int> > arr = { 
								 {0, 1, 2 ,5}, 
								 {2, 3, 4 ,7},
								 {4, 4, 4, 8}, 
								 {5, 7, 7, 9} 
							   };
	show(arr);
	Solution sol;
	bool find = sol.findMidNumber(arr, 6);
	if(find)		
		cout << "Find!" << endl;
	else
		cout << "No Find!" << endl;
}
