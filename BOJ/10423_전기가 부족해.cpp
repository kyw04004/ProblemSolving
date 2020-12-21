#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<functional>
using namespace std;
int n, m, k, sum, chk[1001];
vector<pair<int,int>> v[1001];
priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
int main()
{
	cin >> n >> m >> k;
	for (int i = 0; i < k; i++) {
		int p;
		cin >> p;
		pq.push({ 0, p });
	}
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
		v[b].push_back({ a,c });
	}
	while (!pq.empty()) {
		int cost = pq.top().first;
		int here = pq.top().second;
		pq.pop();
		if (chk[here]) continue;
		chk[here] = 1;
		sum += cost;
		for (int i = 0; i < v[here].size(); i++) {
			int next = v[here][i].first;
			int nextcost = v[here][i].second;
			if (!chk[next]) pq.push({ nextcost,next });
		}
	}
	cout << sum;
	return 0;
}