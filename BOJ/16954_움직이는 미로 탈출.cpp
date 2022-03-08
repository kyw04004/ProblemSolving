#include<iostream>
#include<map>
#include<queue>
#include<cstring>
#include<string>
#include<algorithm>
#include<functional>
#include<vector>
#include<stack>
#include<cmath>
using namespace std;
typedef unsigned long long ll;
char board[9][10][10], chk[9][9][9];
int dx[9] = {0,0,0,-1,1,1,-1,-1,1};
int dy[9] = {0,1,-1,0,0,1,-1,1,-1};
void down() {
	for(int t=1;t<=8;t++) 
		for (int i = 8; i >= 1; i--)
			for (int j = 1; j <= 8; j++) {
				if (board[t - 1][i][j] == '#')
					board[t][i + 1][j] = '#';
				board[t][i][j] = '.';
			}
}
int bfs() {
	queue<pair<pair<int, int>,int>> q, com;
	q.push({ { 8,1 }, 0 });
	chk[0][8][1] = 1;
	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int t = q.front().second;
		q.pop();
		if (x == 1 && y == 8) return 1;
		for (int i = 0; i < 9; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 1 || nx > 8 || ny < 1 || ny > 8) continue;
			if (board[t > 8? 8 : t][nx][ny] == '#')  continue;
			if (board[t + 1 > 8? 8 : t + 1][nx][ny] == '#')  continue;
			if (chk[t + 1 > 8 ? 8 : t + 1][nx][ny]) continue;
			chk[t + 1 > 8 ? 8 : t + 1][nx][ny] = 1;
			q.push({ {nx,ny}, t + 1 > 8 ? 8 : t + 1 });
		}
	}
	return 0;
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	for (int i = 1; i <= 8; i++)
		for (int j = 1; j <= 8; j++)
			cin >> board[0][i][j];
	down();
	cout << bfs();
	return 0;
}