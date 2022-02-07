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
int board[6][6], c[6][6], ans = 1e9;
int piece;
pair<int, int> pos[6];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
bool stick() {
	int cnt = 0;
	int chk[6][6] = {};
	queue<pair<int, int>> q;
	for (int i = 1; i <= 5; i++)
		for (int j = 1; j <= 5; j++)
			if (c[i][j] > 0) {
				chk[i][j] = 1;
				q.push({ i,j });
				i = 6, j = 6;
			}
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		cnt++;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 1 || nx > 5 || ny < 1 || ny > 5) continue;
			if (chk[nx][ny] || c[nx][ny] == 0) continue;
			chk[nx][ny] = 1;
			q.push({ nx,ny });
		}
	}
	if (cnt == piece) return true;
	else return false;
}
void make_all_case(int depth, int sum) {
	if (depth > piece) {
		if (stick()) ans = min(ans, sum);
		return;
	}
	for (int i = 1; i <= 5; i++) {
		for (int j = 1; j <= 5; j++) {
			if (c[i][j]) continue;
			int dis = abs(i - pos[depth].first) + abs(j - pos[depth].second);
			c[i][j] = depth;
			make_all_case(depth + 1, sum + dis);
			c[i][j] = 0;
		}
	}
	return;
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	for (int i = 1; i <= 5; i++)
		for (int j = 1; j <= 5; j++) {
			char c; cin >> c;
			if (c == '*') pos[++piece] = {i,j}, board[i][j] = piece;
			else board[i][j] = 0;
		}
	make_all_case(1, 0);
	cout << ans;
	return 0;
}