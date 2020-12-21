#include<iostream>
#include<vector>
#include<string>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<queue>
using namespace std;
typedef long long ll;
int n, chk[31][31];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
double ans,arr[4];
void dfs(int x, int y, int t, double p) {
	if (t == 0) {
		ans += p;
		return;
	}
	chk[x][y] = 1;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (!chk[nx][ny]) {
			dfs( nx,ny,t - 1, p * arr[i]);
			chk[nx][ny] = 0;
		}
	}
}
int main() {
	cin >> n;
	for (int i = 0; i < 4; i++) {
		cin >> arr[i];
		arr[i] *= 0.01;
	}
	dfs(15, 15, n, 1.0);
	printf("%.10lf", ans);
	return 0;
}