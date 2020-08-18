#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
typedef long long ll;
ll n,m,arr[505][505],Max, chk[505][505];
ll dx[4] = { 0,0,-1,1 };
ll dy[4] = { 1,-1,0,0 };
void go(int x, int y, ll sum, int depth) {
	if (depth == 4) {
		if (sum > Max) Max = sum;
		return;
	}
	for (int i = 0; i < 4; i++) {
		ll nx = x + dx[i];
		ll ny = y + dy[i];
		if (chk[nx][ny] || nx < 1 || nx > n || ny < 1 || ny > m) continue;
		chk[nx][ny] = 1;
		go(nx, ny, sum + arr[nx][ny], depth + 1);
		chk[nx][ny] = 0;
		if (depth == 2) {
			for (int j = 0; j < 4; j++) {
				if (i == j) continue;
				ll nnx = x + dx[j];
				ll nny = y + dy[j];
				if (chk[nx][ny] || chk[nnx][nny]||nnx < 1 || nnx > n || nny < 1 || nny > m) continue;
				chk[nnx][nny] = 1;
				chk[nx][ny] = 1;
				go(nx, ny, sum + arr[nx][ny] + arr[nnx][nny], depth + 2);
				chk[nnx][nny] = 0;
				chk[nx][ny] = 0;
			}
		}
	}
}
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> arr[i][j];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			chk[i][j] = 1;
			go(i, j, arr[i][j], 1);
			chk[i][j] = 0;
		}
	cout << Max;
	return 0;
}