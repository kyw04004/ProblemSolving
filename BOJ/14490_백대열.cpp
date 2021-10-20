#include<iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
string str;
int a, b;
int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> str;
	int turn = 1;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == ':') {
			turn = 2;
			continue;
		}
		if (turn == 1) a *= 10, a += str[i] - '0';
		else b *= 10, b += str[i] - '0';
	}
	int m = gcd(a, b);
	cout << a / m << ':' << b / m;
	return 0;
}