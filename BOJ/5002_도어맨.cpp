#include<iostream>
#include<vector>
#include<queue>
#include<string>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<functional>
#include<stack>
#include<stdio.h>
using namespace std;
typedef long long ll;
int X, M, W, cnt;
string line;
int main() {
	cin >> X >> line;
	for (int i = 0; i < line.size(); i++) {
		if (line[i] == 'M') M++;
		else W++;
		if (abs(M - W) <= X) {
			cnt++;
		}
		else {
			if (M > W) {
				if (i + 1 < line.size() && line[i + 1] == 'W') W++, i++, cnt += 2;
				else break;
			}
			else {
				if (i + 1 < line.size() && line[i + 1] == 'M') M++, i++, cnt += 2;
				else break;
			}
		}
	}
	cout << cnt;
	return 0;
}