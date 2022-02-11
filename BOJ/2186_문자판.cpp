#include<iostream>
#include<map>
#include<queue>
#include<cstring>
#include<string>
#include<algorithm>
#include<functional>
#include<vector>
#include<stack>
using namespace std;
typedef long long ll;
int N, M, K, dp[81][101][101], ans;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
char board[101][101];
string str;
int go(int depth, int x, int y) {
	if (depth == str.size()) return 1;
	int& ret = dp[depth][x][y];
	if (ret != -1) return ret;
	ret = 0;
	for(int i=0;i<4;i++)
		for (int j = 1; j <= K; j++) {
			int nx = x + j * dx[i];
			int ny = y + j * dy[i];
			if (nx < 1 || nx > N || ny < 1 || ny > M) continue;
			if (board[nx][ny] != str[depth]) continue;
			ret += go(depth + 1, nx, ny);
		}
	return ret;
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	memset(dp, -1, sizeof(dp));
	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			cin >> board[i][j];
	cin >> str;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			if (board[i][j] == str[0])
				ans += go(1, i, j);
	cout << ans;
	return 0;
}