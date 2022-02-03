#include<iostream>
#include<map>
#include<queue>
#include<cstring>
#include<string>
#include<algorithm>
#include<functional>
#include<vector>
#include<stack>
using namespace std;
typedef long long ll;
map<vector<int>, int> m;
int sum;
int bfs(vector<int> v) {
	sort(v.begin(), v.end());
	m[v] = 1;
	queue<vector<int>> q;
	q.push(v);
	while (!q.empty()) {
		vector<int> v[3];
		vector<int> now = q.front();
		q.pop();
		if (now[0] == now[2]) return 1;
		//case1 a, c
		v[0].push_back(now[0] + now[0]);
		v[0].push_back(now[1]);
		v[0].push_back(now[2] - now[0]);
		//case2 b, c
		v[1].push_back(now[0]);
		v[1].push_back(now[1] + now[1]);
		v[1].push_back(now[2] - now[1]);
		//case3 a, b
		v[2].push_back(now[0] + now[0]);
		v[2].push_back(now[1] - now[0]);
		v[2].push_back(now[2]);
		for (int i = 0; i < 3; i++) {
			sort(v[i].begin(), v[i].end());
			if (!m[v[i]]) {
				m[v[i]] = 1;
				q.push(v[i]);
			}
		}
	}
	return 0;
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	vector<int> v;
	for (int i = 0; i < 3; i++) {
		int num; cin >> num;
		v.push_back(num);
		sum += num;
	}
	if (sum % 3 != 0) cout << 0;
	else cout << bfs(v);
	return 0;
}