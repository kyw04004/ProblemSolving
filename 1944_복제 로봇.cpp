#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
#include<functional>
#include<vector>
using namespace std;
pair<int, int> location[251];
int n, m, V, chk2[255], sum, ok;
int K[55][55];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
char map[55][55];
vector<pair<int, int>> v[255];
queue <pair<pair<int, int>, pair<int, int>>> q;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
void bfs(int st) {
	queue <pair<pair<int, int>, int>> q;
	q.push({ {location[st].first,location[st].second},0 });
	int chk[55][55] = { 0, };
	chk[location[st].first][location[st].second] = 1;
	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int cnt = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < n&&ny >= 0 && ny < n && map[nx][ny] != '1' && !chk[nx][ny]) {
				chk[nx][ny] = 1;
				if (map[nx][ny] == '0' ) q.push({ {nx,ny},cnt + 1 });
				if (map[nx][ny] == 'K' ) v[st].push_back({ K[nx][ny],cnt + 1 });
			}

		}
	}
}
void prim()
{
	pq.push({ 0,1 });
	while (!pq.empty())
	{
		int cost = pq.top().first;
		int here = pq.top().second;
		pq.pop();
		if (chk2[here] == 1) continue;
		chk2[here] = 1;
		sum += cost;
		for (int i = 0; i < v[here].size(); i++)
		{
			int next = v[here][i].first;
			int nextcost = v[here][i].second;
			if (chk2[next] == 0)
				pq.push({ nextcost, next });
		}
	}
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'S' || map[i][j] == 'K') {
				map[i][j] = 'K';
				V++, K[i][j] = V;
				location[V].first = i, location[V].second = j;
			}
		}
	for(int i=1;i<=V;i++)
		bfs(i);
	prim();
	for (int i = 1; i <= V; i++)
		if (chk2[i] == 0) ok = 1;
	if (ok) cout << "-1";
	else cout << sum;
	return 0;
}