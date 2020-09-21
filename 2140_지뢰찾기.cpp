#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int n,sum;
int Map[101][101];
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			char c;
			cin >> c;
			Map[i][j] = c - '0';
		}
	for (int i = 1; i <= n; i++) {
		sum += Map[1][i];
		sum += Map[i][1];
		sum += Map[n][i];
		sum += Map[i][n];
	}
	sum /= 3;
	if(n>=4) sum += (n - 4)*(n - 4);
	sum -= (Map[1][1] + Map[1][n] + Map[n][1] + Map[n][n]);
	if (n <= 2) sum = 0;
	if (n == 3) {
		if (Map[1][1] == 1) sum = 1;
		else sum = 0;
	}
	cout << sum;
	return 0;
}
