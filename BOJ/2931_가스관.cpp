#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <stack>
#include <map>
#include <set>
#include <stack>
#include <queue>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
int R, C;
int dx[4] = { 0,0,-1,1 }; // 오 왼 위 아래
int dy[4] = { 1,-1,0,0 };
char board[26][26];
char block[7] = { '+', '|', '-', '1', '2', '3', '4'};
P mLocation;
pair<P, char> ans;
bool canBlock(char block, int x, int y) {
	if (block == '|') { 
		if ((board[x - 1][y] == '|' || board[x - 1][y] == '+' || board[x - 1][y] == '1' || board[x - 1][y] == '4' || board[x - 1][y] == 'Z') &&
			(board[x + 1][y] == '|' || board[x + 1][y] == '+' || board[x + 1][y] == '2' || board[x + 1][y] == '3' || board[x + 1][y] == 'Z'))
			return true;
		else return false;
	}
	if (block == '-') {
		if ((board[x][y - 1] == '-' || board[x][y - 1] == '+' || board[x][y - 1] == '1' || board[x][y - 1] == '2' || board[x][y - 1] == 'Z') &&
			(board[x][y + 1] == '-' || board[x][y + 1] == '+' || board[x][y + 1] == '3' || board[x][y + 1] == '4' || board[x][y + 1] == 'Z'))
			return true;
		else return false;
	}
	if (block == '+') {
		if ((board[x - 1][y] == '|' || board[x - 1][y] == '+' || board[x - 1][y] == '1' || board[x - 1][y] == '4' || board[x - 1][y] == 'Z') &&
			(board[x + 1][y] == '|' || board[x + 1][y] == '+' || board[x + 1][y] == '2' || board[x + 1][y] == '3' || board[x + 1][y] == 'Z') &&
			(board[x][y - 1] == '-' || board[x][y - 1] == '+' || board[x][y - 1] == '1' || board[x][y - 1] == '2' || board[x][y - 1] == 'Z') &&
			(board[x][y + 1] == '-' || board[x][y + 1] == '+' || board[x][y + 1] == '3' || board[x][y + 1] == '4' || board[x][y + 1] == 'Z'))
			return true;
		else return false;
	}
	if (block == '1') {
		if ((board[x + 1][y] == '|' || board[x + 1][y] == '+' || board[x + 1][y] == '2' || board[x + 1][y] == '3' || board[x + 1][y] == 'Z') &&
			(board[x][y + 1] == '-' || board[x][y + 1] == '+' || board[x][y + 1] == '3' || board[x][y + 1] == '4' || board[x][y + 1] == 'Z'))
			return true;
		return false;

	}
	if (block == '2') {
		if ((board[x - 1][y] == '|' || board[x - 1][y] == '+' || board[x - 1][y] == '1' || board[x - 1][y] == '4' || board[x - 1][y] == 'Z') &&
			(board[x][y + 1] == '-' || board[x][y + 1] == '+' || board[x][y + 1] == '3' || board[x][y + 1] == '4' || board[x][y + 1] == 'Z'))
			return true;
		return false;

	}
	if (block == '3') {
		if ((board[x - 1][y] == '|' || board[x - 1][y] == '+' || board[x - 1][y] == '1' || board[x - 1][y] == '4' || board[x - 1][y] == 'Z') &&
			(board[x][y - 1] == '-' || board[x][y - 1] == '+' || board[x][y - 1] == '1' || board[x][y - 1] == '2' || board[x][y - 1] == 'Z'))
			return true;
		return false;

	}
	if (block == '4') {
		if ((board[x + 1][y] == '|' || board[x + 1][y] == '+' || board[x + 1][y] == '2' || board[x + 1][y] == '3' || board[x + 1][y] == 'Z') &&
			(board[x][y - 1] == '-' || board[x][y - 1] == '+' || board[x][y - 1] == '1' || board[x][y - 1] == '2' || board[x][y - 1] == 'Z'))
			return true;
		return false;
	}
}
bool bfs(int num) {
	queue<P> q;
	int cnt = 0, chk[26][26] = { 0, };
	ans = { {-1,-1}, ' ' };
	chk[mLocation.first][mLocation.second] = 1;
	for (int i = 0; i < 4; i++) {
		int nx = mLocation.first + dx[i];
		int ny = mLocation.second + dy[i];
		if (board[nx][ny] == '.' || nx < 1 || nx > R || ny < 1 || ny > C) continue;
		char c = board[nx][ny];
		if (((i == 0) && (c == '-' || c == '+' || c == '3' || c == '4')) ||
			((i == 1) && (c == '-' || c == '+' || c == '1' || c == '2')) ||
			((i == 2) && (c == '|' || c == '+' || c == '1' || c == '4')) ||
			((i == 3) && (c == '|' || c == '+' || c == '2' || c == '3'))) {
			chk[nx][ny] = 1;
			q.push({ nx, ny });
			break;
		}
	}
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		char c = board[x][y];
		q.pop();
		if (c == '-' || c == '+' || c == '3' || c == '4') { // 왼쪽가기
			if (!(chk[x][y - 1] || board[x][y - 1] == '|' || board[x][y - 1] == '3' || board[x][y - 1] == '4')) {
				if (board[x][y - 1] == '.') {
					if (cnt == 1 || block[num] == '|' || block[num] == '3' || block[num] == '4') {
						if (!(ans.first.first == -1 && ans.first.second == -1)) board[ans.first.first][ans.first.second] = '.';
						return false;
					}
					if (canBlock(block[num], x, y - 1)) {
						board[x][y - 1] = block[num];
						ans = { {x, y - 1}, block[num] };
						cnt++;
					}
					else return false;
				}
				chk[x][y - 1] = 1;
				q.push({ x, y - 1 });
			}
		}
		if (c == '-' || c == '+' || c == '1' || c == '2') { // 오른쪽 가기
			if (!(chk[x][y + 1] || board[x][y + 1] == '|' || board[x][y + 1] == '1' || board[x][y + 1] == '2')) {
				if (board[x][y + 1] == '.') {
					if (cnt == 1 || block[num] == '|' || block[num] == '1' || block[num] == '2') {
						if (!(ans.first.first == -1 && ans.first.second == -1)) board[ans.first.first][ans.first.second] = '.';
						return false;
					}
					if (canBlock(block[num], x, y + 1)) {
						board[x][y + 1] = block[num];
						ans = { {x, y + 1}, block[num] };
						cnt++;
					}
					else return false;
				}
				chk[x][y + 1] = 1;
				q.push({ x, y + 1 });
			}
		}
		if (c == '|' || c == '+' || c == '2' || c == '3') { // 위로 가기
			if (!(chk[x - 1][y] || board[x - 1][y] == '-' || board[x - 1][y] == '2' || board[x - 1][y] == '3')) {
				if (board[x - 1][y] == '.') {
					if (cnt == 1 || block[num] == '-' || block[num] == '2' || block[num] == '3') {
						if (!(ans.first.first == -1 && ans.first.second == -1)) board[ans.first.first][ans.first.second] = '.';
						return false;
					}
					if (canBlock(block[num], x - 1, y)) {
						board[x - 1][y] = block[num];
						ans = { {x - 1, y}, block[num] };
						cnt++;
					}
					else return false;
				}
				chk[x - 1][y] = 1;
				q.push({ x - 1, y });
			}
		}
		if (c == '|' || c == '+' || c == '1' || c == '4') { // 아래로 가기
			if (!(chk[x + 1][y] || board[x + 1][y] == '-' || board[x + 1][y] == '1' || board[x + 1][y] == '4')) {
				if (board[x + 1][y] == '.') {
					if (cnt == 1 || block[num] == '-' || block[num] == '1' || block[num] == '4') {
						if (!(ans.first.first == -1 && ans.first.second == -1)) board[ans.first.first][ans.first.second] = '.';
						return false;
					}
					if (canBlock(block[num], x + 1, y)) {
						board[x + 1][y] = block[num];
						ans = { {x + 1, y}, block[num] };
						cnt++;
					}
					else return false;
				}
				chk[x + 1][y] = 1;
				q.push({ x + 1, y });
			}
		}
	}
	return true;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> R >> C;
	for (int i = 1; i <= R; i++)
		for (int j = 1; j <= C; j++) {
			cin >> board[i][j];
			if (board[i][j] == 'M') mLocation = { i, j };
		}
	for (int i = 0; i < 7; i++) {
		if (bfs(i)) {
			cout << ans.first.first << ' ' << ans.first.second << ' ' << ans.second;
			break;
		}
	}
	return 0;
}