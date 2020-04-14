#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	void rotatePrintMatrix(vector<vector<int> > &arr) {
		int n = arr.size();
		for(int i=0; i<n/2; i++) {
			for(int j=i; j<n-i-1; j++) {
				int tmp = arr[i][j];	
				arr[i][j] = arr[n-j-1][i];
				arr[n-j-1][i] = arr[n-i-1][n-j-1];
				arr[n-i-1][n-j-1] = arr[j][n-i-1];
				arr[j][n-i-1] = tmp;
			}
		}
	}

	void printMatrixZigZag(vector<vector<int> > &arr) {
		int row = arr.size();			
		int col = arr[0].size();
		int cnt = row+col;
		for(int i=1; i<cnt; i++) {
			if(i&1) {
				int x, y;
				if(i <= row) x = i-1, y = 0;
				else x = row-1, y = i-row;
				while(x>=0 && y<=col-1) 
					cout << arr[x--][y++] << "\t";
			} else {
				int x, y;		
				if(i <= col) x = 0, y = i-1;
				else x = i-col, y = col-1;
				while(x<=row-1 && y>=0)
					cout << arr[x++][y--] << "\t";
			}
			cout << endl;
	 	}	
	}
};

void show(vector<vector<int> > &arr) {
	for(int i=0; i<arr.size(); i++) {
		for(int j=0; j<arr[0].size(); j++)
			cout << arr[i][j] << "\t";	
		cout << endl;
	}
} 

int main() {
	const int row = 4;
	const int col = 4;
	vector<vector<int> > arr(row, vector<int>(col));
	int cnt = 1;
	for(int i=0; i<row; i++)
		for(int j=0; j<col; j++)
			arr[i][j] = cnt++;
	show(arr);
	//Solution sol;
	//sol.rotatePrintMatrix(arr);
	//cout << endl;
	//show(arr);
	//sol.printMatrixZigZag(arr);	
}
