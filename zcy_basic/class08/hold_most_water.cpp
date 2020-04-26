#include<iostream>
#include<vector>
using namespace std;


int min(int &a, int &b) {
	return a > b ? b : a;
}


int HoldMostWater(vector<int> arr) {
	if(arr.size() < 3)		
		return 0;
	int l = 0, r = arr.size()-1, base, ret = 0;
	int l_max = arr[0], r_max = arr[r];
	int isleft = 1;
	while(l + 1 < r) {
		base = min(l_max, r_max);
		if(isleft) {
			if(base > arr[++l])		
				ret += base-arr[l];
			l_max = arr[l] > l_max ? arr[l] : l_max;
			isleft = 0;
		} else {
			if(base > arr[--r])	
				ret += base-arr[r];
			r_max = arr[r] > r_max ? arr[r] : r_max;
			isleft = 1;
		}	
	}	

	return ret;
}


int main() {
	vector<int>	arr = {3, 1, 2, 4};		
	cout << HoldMostWater(arr) << endl;
}
