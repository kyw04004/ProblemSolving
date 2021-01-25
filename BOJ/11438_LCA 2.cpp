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
int n, m, depth[100005],parent[100005][18];
vector<int> v[100005];
void dfs(int now, int dep) {
	depth[now] = dep;
	for (int i = 0; i < v[now].size(); i++) {
		int next = v[now][i];
		if (!depth[next]) {
			parent[next][0] = now;
			dfs(next, dep + 1);
		}
	}
}
int LCA(int a, int b) {
	if (depth[a] > depth[b]) swap(a, b); // a의 깊이가 더 작게
	for (int i = 17; i >= 0; i--) // 두 노드의 깊이를 같게
		if (depth[a] <= depth[parent[b][i]])
			b = parent[b][i];
	if (a == b) return a;
	//a,b의 조상을 맨 위에서부터 확인하면서 공통조상이 달라지는 최초지점 탐색
	for (int i = 17; i >= 0; i--)
		if (parent[a][i] != parent[b][i]) {
			a = parent[a][i];
			b = parent[b][i];
		}
	return parent[a][0];
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i < n; i++) {
		int a, b; cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	dfs(1, 1); // 각 노드의 깊이구하기
	//i번 노드는 2^j번째 조상은 2^(j-1)번째 조상의 2^(j-1)번째 조상
	for (int j = 1; j <= 17; j++)
		for (int i = 1; i <= n; i++)
			parent[i][j] = parent[parent[i][j - 1]][j - 1];
	cin >> m;
	for (int i = 1; i <= m; i++) {
		int a, b; cin >> a >> b;
		cout << LCA(a, b) << '\n';
	}
	return 0;
}