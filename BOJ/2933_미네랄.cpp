#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
#include<functional>
using namespace std;
typedef long long ll;
int r, c, n, Stick[105], chk[105][105];
char Map[105][105];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
void bfs() {
	queue<pair<int, int>> q;
	for (int i = 1; i <= c; i++)
		if (Map[r][i] == 'x') q.push({r,i});
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (chk[nx][ny]||nx<1 || nx>r || ny<1 || ny>c) continue;
			if (Map[nx][ny] == 'x') {
				chk[nx][ny] = 1;
				q.push({ nx,ny });
			}
		}
	}
}
void Drop() {
	memset(chk, 0, sizeof(chk));
	bfs(); // 떨어져야할 클러스터 체크
	priority_queue<pair<int,int>, vector<pair<int, int>>, less<pair<int, int>>> pq;
	for (int i = 1; i <= r; i++) // 떨어질 클러스터 저장
		for (int j = 1; j <= c; j++)
			if (Map[i][j] == 'x' && chk[i][j] == 0)
				pq.push({ i,j });
	if (pq.size() == 0) return; // 떨어질거 없으면 고만해라
	int len = 105;
	for (int j = 1; j <= c; j++) { // 떨어질 거리재기
		int exist = 0;
		int x , y;
		for (int i = 1; i <= r; i++) {
			if (Map[i][j] == 'x' && chk[i][j] == 0) {
				exist = 1;
				x = i, y = j;
			}
		}
		if (exist) {
			int l = 1;
			while (1) {
				if (Map[x + l][y] == '.') l++; 
				else break;
			}
			len = min(len, l-1);
		}
	}
	while (!pq.empty()) { // 떨궈
		int x = pq.top().first;
		int y = pq.top().second;
		pq.pop();
		Map[x + len][y] = 'x';
		Map[x][y] = '.';
	}
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> r >> c;
	for (int i = 1; i <= r; i++)
		for (int j = 1; j <= c; j++)
			cin >> Map[i][j];
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> Stick[i];
	for (int i = 1; i <= n; i++) {
		int h = r - Stick[i] + 1;
		if (i%2 == 1) {
			for (int j = 1; j <= c; j++) {
				if (Map[h][j] == 'x') {
					Map[h][j] = '.';
					Drop();
					break;
				}
			}
		}
		else {
			for (int j = c; j >= 1; j--) {
				if (Map[h][j] == 'x') {
					Map[h][j] = '.';
					Drop();
					break;
				}
			}
		}
	}
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++)
			cout << Map[i][j];
		cout << '\n';
	}
	return 0;
}