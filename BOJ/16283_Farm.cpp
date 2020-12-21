#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<functional>
using namespace std;
int a, b, n, w, ansi,ansj, fault;
int main() {
	cin >> a >> b >> n >> w;
	for (int i = 1; i <= 1000; i++) {
		for (int j = 1; j <= 1000; j++) {
			if (a*i + b * j == w && i + j == n) {
				if(ansi==0 && ansj==0) ansi = i, ansj = j;
				else fault = 1;
			}
		}
		if (i == 1000)
			if (ansi == 0 && ansj == 0) fault = 1;
	}
	if (fault == 1) cout << "-1";
	else cout << ansi << " " << ansj;
	return 0;
}