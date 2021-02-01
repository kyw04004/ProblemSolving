//´ÜÀý¼±
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
int V, E, schk[100005], S, cnt;
vector<int> v[100005];
vector<pair<int,int>> edge;
int dfs(int now, int parent) {
	schk[now] = ++S;
	int num = S;
	for (int i = 0; i < v[now].size(); i++) {
		int next = v[now][i];
		if (next == parent) continue;
		if (!schk[next]) {
			int low = dfs(next, now);
			num = min(num, low);
			if (low > schk[now])
				edge.push_back({min(now,next),max(now,next)});
		}
		else num = min(num, schk[next]);
	}
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
	dfs(1, 0);
	sort(edge.begin(), edge.end());
	cout << edge.size() << '\n';
	for (int i = 0; i < edge.size(); i++)
		cout << edge[i].first << ' ' << edge[i].second << '\n';
	return 0;
}