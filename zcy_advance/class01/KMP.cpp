#include<iostream>
#include<string>
using namespace std;


int *getNextArray(string &m) {
	if(m.length() == 0)	
		return NULL;
	int *next = new int[m.length()];
	next[0] = -1;
	next[1] = 0;
	int pos = 2;
	int cn = 0;
	while(pos < m.length()) {
		if(m[pos - 1] == m[cn])	
			next[pos++] = ++cn;
		else if(cn > 0)
			cn = next[cn];
		else
			next[pos++] = 0;
	}
	return next;
}


int getIndexOf(string &s, string &m) {
	if(!s.length() || !m.length() || s.length() < m.length())	
		return -1;
	int *next = getNextArray(m);
	int si = 0 , mi = 0;
	while(si < s.length() && mi < m.length()) {
		if(s[si] == m[mi]) {
			si++;	
			mi++;
		} else if(next[mi] == -1)	
			si++;
		else {
			mi = next[mi];
		}
	}
	return mi == m.length() ? si-mi : -1;
}


int main(){
	string s = "nihao";
	string m = "ao";
	cout << getIndexOf(s, m) << endl;
}
