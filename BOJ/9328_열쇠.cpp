#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
#include<map>
using namespace std;
int h, w, chk[105][105];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
char board[105][105];
int bfs() {
	queue<pair<int, int>> q;
	int Max = 0;
	q.push({ 0,0 });
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx > h + 1 || ny < 0 || ny > w + 1) continue;
			if (chk[nx][ny] || board[nx][ny] == '*') continue;
			if ('A' <= board[nx][ny] && board[nx][ny] <= 'Z') continue;

			if (board[nx][ny] == '.') {
				chk[nx][ny] = 1;
				q.push({ nx,ny });
			}

			else if (board[nx][ny] == '$') {
				Max++;
				board[nx][ny] = '.';
				chk[nx][ny] = 1;
				q.push({ nx,ny });
			}

			else if ('a' <= board[nx][ny] && board[nx][ny] <= 'z') {
				for (int a = 1; a <= h; a++)
					for (int b = 1; b <= w; b++)
						if (board[nx][ny] - 'a' == board[a][b] - 'A')
							board[a][b] = '.';
				board[nx][ny] = '.';
				while (!q.empty()) q.pop();
				memset(chk, 0, sizeof(chk));
				q.push({ 0,0 });
				break;
			}
		}
	}
	return Max;
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		memset(chk, 0, sizeof(chk));
		cin >> h >> w;
		for (int i = 1; i <= h; i++)
			for (int j = 1; j <= w; j++)
				cin >> board[i][j];
		for (int j = 0; j <= w + 1; j++)
			board[0][j] = '.', board[h + 1][j] = '.';
		for (int i = 0; i <= h + 1; i++)
			board[i][0] = '.', board[i][w + 1] = '.';
		string key;
		cin >> key;
		if (key != "0")
			for (int i = 0; i < key.size(); i++)
				for (int x = 1; x <= h; x++)
					for (int y = 1; y <= w; y++)
						if (board[x][y] - 'A' == key[i] - 'a')
							board[x][y] = '.';
		cout << bfs() << '\n';
	}
	return 0;
}