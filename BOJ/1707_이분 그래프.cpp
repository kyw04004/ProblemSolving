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
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int k; cin >> k;
	while (k--) {
		int v, e; cin >> v >> e;
		int chk[20005] = {};
		queue<pair<int,int>> q;
		vector<vector<int>> graph;
		graph.resize(v + 1);
		for (int i = 0; i < e; i++) {
			int a, b; cin >> a >> b;
			graph[a].push_back(b);
			graph[b].push_back(a);
		}
		int ans = 1;
		for (int i = 1; i <= v; i++) {
			if (chk[i] || !ans) continue;
			chk[i] = 1;
			q.push({ i,1 });
			while (!q.empty()) {
				int now = q.front().first;
				int color = q.front().second;
				q.pop();
				for (int i = 0; i < graph[now].size(); i++) {
					int next = graph[now][i];
					if (!chk[next]) {
						if (color == 1) {
							chk[next] = 2;
							q.push({ next, 2 });
						}
						else {
							chk[next] = 1;
							q.push({ next, 1 });
						}
					}
					else if (chk[next] == color) ans = 0;
				}
			}
		}
		if (ans) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}