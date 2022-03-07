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
int N, M, K;
int board[22][22];
int dx[4] = { 0,1, 0,-1 }; //µ¿³²¼­ºÏ
int dy[4] = { 1,0,-1,0 };
int Top = 1, Down = 6, Right = 3, Left = 4, Front = 5, Back = 2;
void roll(int d) {
	if (d == 0) { //µ¿
		int temp = Left;
		Left = Down;
		Down = Right;
		Right = Top;
		Top = temp;
	}
	if (d == 2) { //¼­
		int temp = Left;
		Left = Top;
		Top = Right;
		Right = Down;
		Down = temp;
	}
	if (d == 1) { //³²
		int temp = Top;
		Top = Back;
		Back = Down;
		Down = Front;
		Front = temp;
	}
	if (d == 3) { //ºÏ
		int temp = Top;
		Top = Front;
		Front = Down;
		Down = Back;
		Back = temp;
	}
	
}
int bfs(int x,int y, int val) {
	int chk[22][22] = {};
	queue<pair<int, int>> q;
	int cnt = 0;
	chk[x][y] = 1;
	q.push({ x,y });
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		cnt++;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 1 || nx > N || ny < 1 || ny > M) continue;
			if (chk[nx][ny] || board[nx][ny] != val) continue;
			chk[nx][ny] = 1;
			q.push({ nx,ny });
		}
	}
	return cnt;
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++) cin >> board[i][j];
	int d = 0, sum = 0;
	int x = 1, y = 1;
	for (int i = 1; i <= K; i++) {
		x += dx[d];
		y += dy[d];
		roll(d);
		if (x < 1 || x > N || y < 1 || y > M) {
			d = (d + 2) % 4;
			x += 2 * dx[d];
			y += 2 * dy[d];
			roll(d);
			roll(d);
		}
		sum += board[x][y] * bfs(x, y, board[x][y]);
		if (Down > board[x][y]) d = (d + 1) % 4;
		else if (Down < board[x][y]) d = (d - 1 + 4) % 4;
	}
	cout << sum;
	return 0;
}