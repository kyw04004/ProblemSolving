#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<functional>
using namespace std;
priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
int n, m, parent[1001], sum, chk = 1;
char MF[1001];
int find(int x) {
	if (parent[x] == x) return x;
	return parent[x] = find(parent[x]);
}
void merge(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y) return;
	parent[y] = x;
}
bool isUnion(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y) return true;
	else return false;
}
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> MF[i];
		parent[i] = i;
	}
	for (int i = 1; i <= m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		if (MF[a] != MF[b]) pq.push({ c,{a,b} });
	}
	while (!pq.empty()) {
		if (!isUnion(pq.top().second.first, pq.top().second.second)) {
			sum += pq.top().first;
			merge(pq.top().second.first, pq.top().second.second);
		}
		pq.pop();
	}
	for (int i = 2; i <= n; i++)
		if (!isUnion(i - 1, i)) chk = 0;
	if(chk) cout << sum;
	else cout << "-1";
	return 0;
}
