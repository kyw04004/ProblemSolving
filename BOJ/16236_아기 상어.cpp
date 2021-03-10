#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<functional>
#include<stack>
#include<map>
using namespace std;
typedef long long ll;
int n, arr[22][22], chk[22][22], shark = 2, eat, ans;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
priority_queue<pair<int, pair<int, int>>,
	vector<pair<int, pair<int, int>>>,
	greater<pair<int, pair<int, int>>>> pq;
void bfs() {
	while (!pq.empty()) {
		int cnt = pq.top().first;
		int x = pq.top().second.first;
		int y = pq.top().second.second;
		pq.pop();
		if (arr[x][y] > 0 && arr[x][y] < shark) {
			eat++;
			if (eat == shark) shark++, eat = 0;
			arr[x][y] = 0;
			ans += cnt;
			cnt = 0;
			memset(chk, 0, sizeof(chk));
			while (!pq.empty()) pq.pop();
		}
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx<1 || nx > n || ny < 1 || ny > n) continue;
			if (arr[nx][ny] > 0 && arr[nx][ny] > shark) continue;
			if (chk[nx][ny]) continue;
			chk[nx][ny] = 1;
			pq.push({ cnt + 1, {nx, ny} });
		}
	}
	return;
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 9) {
				chk[i][j] = 1;
				arr[i][j] = 0;
				pq.push({ 0,{i,j} });
			}
		}
	bfs();
	cout << ans;
	return 0;
}