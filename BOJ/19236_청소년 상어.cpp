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
vector<vector<P>> input;
int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8] = { 0, -1,-1,-1,0,1,1,1 };
int Max;
vector<vector<P>> fishMove(vector<vector<P>> comBoard) {
	for (int num = 1; num <= 16; num++) {
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				if (comBoard[i][j].first == num) {
					int cnt = 0;
					int d = comBoard[i][j].second;
					int nx = i + dx[d];
					int ny = j + dy[d];
					while (nx < 0 || nx > 3 || ny < 0 || ny > 3 || comBoard[nx][ny].first == -1) {
						if (cnt == 8) break;
						d += 1;
						d %= 8;
						cnt++;
						nx = i + dx[d];
						ny = j + dy[d];
					}
					if (cnt == 8) continue;
					comBoard[i][j].second = d;
					P temp = comBoard[nx][ny];
					comBoard[nx][ny] = comBoard[i][j];
					comBoard[i][j] = temp;
					i = 5, j = 5;
				}
			}
		}
	}
	return comBoard;
}
void dfs(int x, int y, int sum, int d, vector<vector<P>> board) {
	Max = max(Max, sum);
	board = fishMove(board);
	for (int j = 1; j <= 3; j++) {
		int nx = x + j * dx[d];
		int ny = y + j * dy[d];
		if (nx < 0 || nx > 3 || ny < 0 || ny > 3) return;
		if (board[nx][ny].first == 0) continue;
		P temp = board[x][y];
		P temp2 = board[nx][ny];
		int nextSum = sum + board[nx][ny].first;
		board[x][y] = { 0, 0 };
		board[nx][ny].first = -1;
		dfs(nx, ny, nextSum, board[nx][ny].second, board);
		board[x][y] = temp;
		board[nx][ny] = temp2;
	}
	return;
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	input = { {{0,0}, {0,0}, {0,0}, {0,0}},
	{{0,0}, {0,0}, {0,0}, {0,0}},
	{{0,0}, {0,0}, {0,0}, {0,0}},
	{{0,0}, {0,0}, {0,0}, {0,0}}};
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++) {
			int num, d;
			cin >> num >> d;
			input[i][j] = { num, d - 1 };
		}
	Max = input[0][0].first;
	input[0][0].first = -1;
	dfs(0, 0, Max, input[0][0].second, input);
	cout << Max;
	return 0;
}