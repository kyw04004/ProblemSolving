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
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
using namespace std;
typedef long long ll;
int t;
vector <vector<int>> v;
int main() {
	cin >> t;
	while (t--) {
		queue<int> q;
		int n, k, price[1005], d;
		int dp[1005] = { 0, };
		int indegree[1005] = { 0, };
		cin >> n >> k;
		v.clear();
		v.resize(n + 1);
		for (int i = 1; i <= n; i++) cin >> price[i];
		for (int i = 1; i <= k; i++) {
			int a, b;
			cin >> a >> b;
			v[a].push_back(b);
			indegree[b]++;
		}
		cin >> d;
		for (int i = 1; i <= n; i++)
			if (!indegree[i]) {
				dp[i] = price[i];
				q.push(i);
			}
		while (!q.empty()) {
			int here = q.front();
			q.pop();
			for (int i = 0; i < v[here].size(); i++) {
				int next = v[here][i];
				indegree[next]--;
				dp[next] = max(dp[next], dp[here] + price[next]);
				if (!indegree[next]) q.push(next);
			}
		}
		cout << dp[d] << "\n";
	}
	return 0;
}