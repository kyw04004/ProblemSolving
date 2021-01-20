#include <string>
#include <vector>
using namespace std;
bool correct(string u) {
	int open = 0, close = 0;
	for (int i = 0; i < u.size(); i++) {
		if (u[i] == '(') open++;
		if (u[i] == ')') close++;
		if (close > open) return false;
	}
	return true;
}
string go(string p) {
	if (p.size() == 0) return p;
	int open = 0, close = 0;
	int index;
	for (index = 0; index < p.size(); index++) {
		if (p[index] == '(') open++;
		if (p[index] == ')') close++;
		if (open == close) break;
	}
	string u = p.substr(0, index + 1);
	string v = p.substr(index + 1);
	if (correct(u)) return u + go(v);
	else {
		string empty = "(";
		empty += go(v);
		empty += ")";
		u = u.substr(1,u.size()-2);
		for (int i = 0; i < u.size(); i++) {
			if (u[i] == '(') u[i] = ')';
			else u[i] = '(';
		}
		return empty + u;
	}
}
string solution(string p) {
	if (p.size() == 0) return p;
	string answer = go(p);
	return answer;
}