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
typedef unsigned long long ll;
int N, M, board[1001][1001], num = 2, area[1000001], chk[1000001];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
int bfs(int x, int y) {
	int cnt = 1;
	queue<pair<int, int>> q;
	board[x][y] = num;
	q.push({x,y});
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 1 || nx > N || ny < 1 || ny > M) continue;
			if (board[nx][ny]) continue;
			board[nx][ny] = num;
			cnt++;
			q.push({ nx,ny });
		}
	}
	return cnt;
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++) {
			char place; cin >> place;
			if (place == '1') board[i][j] = 1;
		}
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++) {
			if (board[i][j] == 0)
				area[num++] = bfs(i, j);
		}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (board[i][j] == 1) {
				stack<int> s;
				int sum = 1;
				for (int k = 0; k < 4; k++) {
					int nx = i + dx[k];
					int ny = j + dy[k];
					if (nx < 1 || nx > N || ny < 1 || ny > M) continue;
					if (chk[board[nx][ny]]) continue;
					s.push(board[nx][ny]);
					chk[board[nx][ny]] = 1;
					sum += area[board[nx][ny]];
				}
				cout << sum % 10;
				while (!s.empty()) {
					chk[s.top()] = 0;
					s.pop();
				}
			}
			else cout << '0';
		}
		cout << '\n';
	}
	return 0;
}