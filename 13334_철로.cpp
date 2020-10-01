#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<map>
#include<vector>
#include<queue>
#include<functional>
using namespace std;
typedef long long ll;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
priority_queue<int, vector<int>, greater<int>> cnt;
int ans;
int main() {
	int n, len;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int a, b;
		cin >> a >> b;
		pq.push({max(a,b), min(a,b)});
	}
	cin >> len;
	while (!pq.empty()) {
		int com = pq.top().first;
		cnt.push(pq.top().second);
		pq.pop();
		while (!cnt.empty()) {
			if (cnt.top() < com - len) cnt.pop();
			else {
				int l = cnt.size();
				ans = max(ans, l);
				break;
			}
		}
	}
	cout << ans;
	return 0;
}