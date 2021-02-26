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
int n, m, dstx,dsty,chk[15][15][15][15];
char arr[15][15];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
struct Element{
	int cnt;
	int rx;
	int ry;
	int bx;
	int by;
};
queue <Element> q;
int bfs() {
	while (!q.empty()) {
		int cnt = q.front().cnt;
		int rx = q.front().rx;
		int ry = q.front().ry;
		int bx = q.front().bx;
		int by = q.front().by;
		q.pop();
		if (cnt >= 10) return -1;
		for (int i = 0; i < 4; i++) {
			int nrx = rx;
			int nry = ry;
			int nbx = bx;
			int nby = by;
			int rcnt = 0;
			int bcnt = 0;
			while (arr[nrx + dx[i]][nry + dy[i]] != '#') {
				rcnt++;
				nrx += dx[i];
				nry += dy[i];
				if (dstx == nrx && dsty == nry) break;
			}
			while (arr[nbx + dx[i]][nby + dy[i]] != '#') {
				bcnt++;
				nbx += dx[i];
				nby += dy[i];
				if (dstx == nbx && dsty == nby) break;
			}
			if (nbx == dstx && nby == dsty) continue;
			if (nrx == dstx && nry == dsty) return cnt + 1;
			if (nrx == nbx && nry == nby) {
				if (rcnt > bcnt) nrx -= dx[i], nry -= dy[i];
				else nbx -= dx[i], nby -= dy[i];
			}
			if (chk[nrx][nry][nbx][nby]) continue;
			chk[nrx][nry][nbx][nby] = 1;
			q.push({cnt+1,nrx,nry,nbx,nby});
		}
	}
	return -1;
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	int rx, ry, bx, by;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 'R') rx = i, ry = j;
			if (arr[i][j] == 'B') bx = i, by = j;
			if (arr[i][j] == 'O') dstx = i, dsty = j;
		}
	chk[rx][ry][bx][by] = 1;
	q.push({0,rx,ry,bx,by});
	cout << bfs();
	return 0;
}