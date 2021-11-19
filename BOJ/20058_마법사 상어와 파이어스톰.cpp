#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
#include<map>
#include<vector>
#include<queue>
#include<stack>
using namespace std;
int N, Q, A[65][65], chk[65][65], Max;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
int bfs(int x, int y) {
	int area = 1;
	queue<pair<int, int>> q;
	chk[x][y] = 1;
	q.push({ x,y });
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 1 || nx > (1 << N) || ny < 1 || ny > (1 << N)) continue;
			if (!chk[nx][ny] && A[nx][ny]) {
				chk[nx][ny] = 1;
				area+=1;
				q.push({ nx,ny });
			}
		}
	}
	return area;
}
void rotate(int sx, int ex, int sy, int ey) {
	int val[260];
	while (ex - sx >= 1) {
		int cnt = 0;
		for (int i = sy; i <= ey; i++)
			val[cnt++] = A[sx][i];
		for (int i = sx + 1; i <= ex; i++)
			val[cnt++] = A[i][ey];
		for (int i = ey - 1; i >= sy; i--)
			val[cnt++] = A[ex][i];
		for (int i = ex - 1; i >= sx + 1; i--)
			val[cnt++] = A[i][sy];
		cnt = 0;
		for (int i = sx; i <= ex; i++)  A[i][ey] = val[cnt++];
		for (int i = ey - 1; i >= sy; i--) A[ex][i] = val[cnt++];
		for (int i = ex - 1; i >= sx; i--)  A[i][sy] = val[cnt++];
		for (int i = sy + 1; i <= ey - 1; i++)  A[sx][i] = val[cnt++];
		sx++, ex--, sy++, ey--;
	}
}
void zoning(int sx, int ex, int sy, int ey, int len, int L) {
	if (len == L) {
		rotate(sx, ex, sy, ey);
		return;
	}
	zoning(sx, sx + len / 2 - 1, sy, sy + len / 2 - 1, len / 2, L);
	zoning(sx, sx + len / 2 - 1, sy + len / 2, ey, len / 2, L);
	zoning(sx + len / 2, ex, sy, sy + len / 2 - 1, len / 2, L);
	zoning(sx + len / 2, ex, sy + len / 2, ey, len / 2, L);
}
void decrease(int x, int y) {
	int cnt = 0;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 1 || nx >(1 << N) || ny < 1 || ny >(1 << N)) continue;
		if (A[nx][ny]) cnt++;
	}
	if (cnt < 3) chk[x][y] = 1;
}
int main(void) {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N >> Q;
	for (int i = 1; i <= (1 << N); i++)
		for (int j = 1; j <= (1 << N); j++)
			cin >> A[i][j];
	for (int i = 1; i <= Q; i++) {
		int L; cin >> L;
		zoning(1, 1 << N, 1, 1 << N, 1 << N, 1 << L);
		for (int x = 1; x <= (1 << N); x++)
			for (int y = 1; y <= (1 << N); y++)
				if (A[x][y]) decrease(x, y);
		for (int x = 1; x <= (1 << N); x++)
			for (int y = 1; y <= (1 << N); y++)
				if (chk[x][y]) A[x][y]--;
		memset(chk, 0, sizeof(chk));
	}
	int sum = 0;
	for (int i = 1; i <= (1 << N); i++)
		for (int j = 1; j <= (1 << N); j++)
			sum += A[i][j];
	for (int i = 1; i <= (1 << N); i++)
		for (int j = 1; j <= (1 << N); j++)
			if (A[i][j] && !chk[i][j]) Max = max(Max, bfs(i, j));
	cout << sum << '\n';
	cout << Max;
	return 0;
}
