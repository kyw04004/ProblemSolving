#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
#include <functional>
#include <queue>
using namespace std;
typedef pair<pair<int, int>, pair<int, int>> e;
//RLUD
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
int dp[26][26][4], N, Board[26][26];
int bfs() {
	priority_queue<e, vector<e>, greater<e>> pq;
	pq.push({ {0,0}, {0,0} });
	pq.push({ {0,3}, {0,0} });
	while (!pq.empty()) {
		int sum = pq.top().first.first;
		int d = pq.top().first.second;
		int x = pq.top().second.first;
		int y = pq.top().second.second;
		pq.pop();
		if (x == N - 1 && y == N - 1) return sum;
		if (sum > dp[x][y][d]) continue;
		for (int i = 0; i < 4; i++) {
			if (d % 2 == 0 && i == d + 1) continue;
			if (d % 2 == 1 && i == d - 1) continue;
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (Board[nx][ny] || nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
			if (d == i && dp[nx][ny][i] > sum + 100) {
				dp[nx][ny][i] = sum + 100;
				pq.push({ {sum + 100, i},{nx,ny} });
			}
			else if (dp[nx][ny][i] > sum + 600) {
				dp[nx][ny][i] = sum + 600;
				pq.push({ {sum + 600, i},{nx,ny} });
			}
		}
	}
}
int solution(vector<vector<int>> board) {
	N = board.size();
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			Board[i][j] = board[i][j];
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			for (int k = 0; k < 4; k++)
				dp[i][j][k] = 1e9;
	int answer = bfs();
	return answer;
}