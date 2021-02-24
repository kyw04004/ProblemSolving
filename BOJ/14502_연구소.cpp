#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<cmath>
#include<queue>
#include<functional>
#include<stack>
#include<map>
#include<bitset>
using namespace std;
typedef long long ll;
int n, m, board[9][9], Copy[9][9], Max;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
vector<pair<int, int>> zero, virus;
queue<pair<int, int>> q;
void bfs() {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			Copy[i][j] = board[i][j];
	for (int i = 0; i < virus.size(); i++)
		q.push({ virus[i].first, virus[i].second });
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (Copy[nx][ny] || nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			Copy[nx][ny] = 1;
			q.push({ nx, ny });
		}
	}
	int cnt = 0;
	for (int a = 0; a < n; a++)
		for (int b = 0; b < m; b++)
			if (Copy[a][b] == 0) cnt++;
	Max = max(Max, cnt);
	return;
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
			if (board[i][j] == 0) zero.push_back({ i,j });
			if (board[i][j] == 2) virus.push_back({ i,j });
		}
	for (int i = 0; i < (zero.size() - 2); i++) {
		board[zero[i].first][zero[i].second] = 1;
		for (int j = i + 1; j < (zero.size() - 1); j++) {
			board[zero[j].first][zero[j].second] = 1;
			for (int k = j + 1; k < zero.size(); k++) {
				board[zero[k].first][zero[k].second] = 1;
				bfs();
				board[zero[k].first][zero[k].second] = 0;
			}
			board[zero[j].first][zero[j].second] = 0;
		}
		board[zero[i].first][zero[i].second] = 0;
	}
	cout << Max;
	return 0;
}