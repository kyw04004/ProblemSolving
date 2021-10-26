#include<iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int N;
char board[7][7];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
vector<pair<int, int>> teacher, object;
bool canHide;
int main(void) {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++) {
			cin >> board[i][j];
			if (board[i][j] == 'T') teacher.push_back({ i,j });
			if (board[i][j] == 'X') object.push_back({ i,j });
		}
	for (int i = 0; i < object.size()-2; i++) {
		for (int j = i + 1; j < object.size() - 1; j++) {
			for (int k = j + 1; k < object.size(); k++) {
				bool canSee = false;
				board[object[i].first][object[i].second] = 'O';
				board[object[j].first][object[j].second] = 'O';
				board[object[k].first][object[k].second] = 'O';
				for (int T = 0; T < teacher.size(); T++) {
					int x = teacher[T].first;
					int y = teacher[T].second;
					for (int d = 0; d < 4; d++) {
						int nx = x + dx[d];
						int ny = y + dy[d];
						while (nx>=1&&nx<=N&&ny>=1&&ny<=N) {
							if (board[nx][ny] == 'O') break;
							if (board[nx][ny] == 'S') {
								canSee = true;
								break;
							}
							nx += dx[d];
							ny += dy[d];
						}
					}
				}
				board[object[i].first][object[i].second] = 'X';
				board[object[j].first][object[j].second] = 'X';
				board[object[k].first][object[k].second] = 'X';
				if (canSee == false) canHide = true;
			}
		}
 	}
	if (canHide) cout << "YES";
	else cout << "NO";
	return 0;
}