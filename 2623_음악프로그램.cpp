#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
#include<deque>
#include<stack>
#include<functional>
#include<vector>
#include<cmath>
#include<map>
using namespace std;
typedef long long ll;
int n, m, arr[1001], indegree[1001];
vector<int> v[1001];
queue<int> q;
vector<int> ans;
int main() {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int singer;
		cin >> singer;
		for (int j = 1; j <= singer; j++) cin >> arr[j];
		for (int j = 2; j <= singer; j++) {
			v[arr[j - 1]].push_back(arr[j]);
			indegree[arr[j]]++;
		}
	}
	for (int i = 1; i <= n; i++)
		if (!indegree[i]) q.push(i);
	while (!q.empty()) {
		int now = q.front();
		ans.push_back(now);
		q.pop();
		for (int i = 0; i < v[now].size(); i++) {
			int next = v[now][i];
			indegree[next]--;
			if (!indegree[next]) q.push(next);
		}
	}
	if (ans.size() == n)
		for (int i = 0; i < ans.size(); i++)
			printf("%d\n", ans[i]);
	else printf("0\n");
	return 0;
}