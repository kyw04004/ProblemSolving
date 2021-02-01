//´ÜÀýÁ¡
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
int V, E, schk[10005], point[10005], S, cnt;
vector<int> v[10005];
int dfs(int now, int root) {
	schk[now] = ++S;
	int num = S;
	int child = 0;
	for (int i = 0; i < v[now].size(); i++) {
		int next = v[now][i];
		if (!schk[next]) {
			child++;
			int low = dfs(next, 0);
			num = min(num, low);
			if (!root && low >= schk[now]) point[now] = 1;
		}
		else num = min(num, schk[next]);
	}
	if (root && child > 1) point[now] = 1;
	return num;
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> V >> E;
	for (int i = 0; i < E; i++) {
		int a, b; cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for (int i = 1; i <= V; i++)
		if (!schk[i]) dfs(i, 1);
	for (int i = 1; i <= V; i++)
		if (point[i]) cnt++;
	cout << cnt << '\n';
	for (int i = 1; i <= V; i++)
		if (point[i]) cout << i << ' ';
	return 0;
}