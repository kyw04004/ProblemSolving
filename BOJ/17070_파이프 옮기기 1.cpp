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
int N, board[17][17];
p d[3]; //가로,세로,대각선
int bfs() {
	int cnt = 0;
	queue<pair<p, int>> q;
	q.push({ {1,2}, 0 });
	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int state = q.front().second;
		q.pop();
		if (x == N && y == N) {
			cnt++;
			continue;
		}
		for (int ns = 0; ns < 3; ns++) {
			if (state == 0 && ns == 1) continue;
			if (state == 1 && ns == 0) continue;
			int nx = x + d[ns].first;
			int ny = y + d[ns].second;
			if (nx < 1 || nx > N || ny < 1 || ny > N) continue;
			if (board[nx][ny]) continue;
			if (ns == 2 && (board[nx-1][ny] || board[nx][ny-1])) continue;
			q.push({ {nx,ny},ns });
		}
	}
	return cnt;
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	d[0] = { 0,1 }, d[1] = {1,0}, d[2] = { 1,1 };
	cin >> N;
	for (int i = 1; i <= N; i++)
		for(int j = 1; j <= N; j++)
		cin >> board[i][j];
	cout << bfs();
	return 0;
}