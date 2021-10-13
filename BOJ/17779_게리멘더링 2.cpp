#include<iostream>
#include<queue>
#include<string>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<functional>
#include<stack>
#include<vector>
#include<map>
using namespace std;
typedef long long ll;
typedef pair<int, int> p;
int N, A[21][21], ans = 1e9;
int calc(int x, int y, int d1, int d2) {
	int sum[6] = {};
	int chk[21][21] = {};
	for (int i = 0; i <= d1; i++) chk[x + i][y - i] = 1;
	for (int i = 0; i <= d2; i++) chk[x + i][y + i] = 1;
	for (int i = 0; i <= d2; i++) chk[x + d1 + i][y - d1 + i] = 1;
	for (int i = 0; i <= d1; i++) chk[x + d2 + i][y + d2 - i] = 1;

	for (int i = 1; i < x + d1; i++)
		for (int j = 1; j <= y; j++) {
			if (chk[i][j]) break;
			sum[1] += A[i][j];
		}

	for (int i = 1; i <= x + d2; i++)
		for (int j = N; j >= y + 1; j--) {
			if (chk[i][j]) break;
			sum[2] += A[i][j];
		}

	for (int i = x + d1; i <= N; i++)
		for (int j = 1; j < y - d1 + d2; j++) {
			if (chk[i][j]) break;
			sum[3] += A[i][j];
		}

	for (int i = x + d2 + 1; i <= N; i++)
		for (int j = N; j >= y - d1 + d2; j--) {
			if (chk[i][j]) break;
			sum[4] += A[i][j];
		}

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			sum[5] += A[i][j];
	sum[5] -= (sum[1] + sum[2] + sum[3] + sum[4]);

	vector<int> v;
	for (int i = 1; i <= 5; i++)
		v.push_back(sum[i]);
	sort(v.begin(), v.end());
	return (v[4] - v[0]);
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			cin >> A[i][j];
	for (int x = 1; x <= N; x++) 
		for (int y = 1; y <= N; y++) 
			for (int d1 = 1; d1 <= 20; d1++) {
				if (x + d1 + 1 > N || d1 + 1 > y) break;
				for (int d2 = 1; d2<=20 ; d2++) {
					if (x + d1 + d2 > N || y + d2 > N) break;
					ans = min(ans, calc(x,y,d1,d2));
				}
			}
	cout << ans;
	return 0;
}