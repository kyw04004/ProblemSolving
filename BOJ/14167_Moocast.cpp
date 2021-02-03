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
int n, ans = 2e9, chk[1005];
pair<int, int> arr[1005];
vector<int> edge;
queue<int> q;
bool possible(int len, int cnt) {
	memset(chk, 0, sizeof(chk));
	q.push(0);
	while (!q.empty()) {
		int now = q.front();
		int x1 = arr[now].first;
		int y1 = arr[now].second;
		q.pop();
		for (int i = 0; i < n; i++) {
			if (now == i) continue;
			if (chk[i]) continue;
			int x2 = arr[i].first;
			int y2 = arr[i].second;
			int dx = abs(x1 - x2);
			int dy = abs(y1 - y2);
			if (len >= dx * dx + dy * dy) {
				chk[i] = 1;
				cnt += 1;
				q.push(i);
			}
		}
	}
	if (cnt == n) return true;
	else return false;
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i].first >> arr[i].second;
	for (int i = 0; i < n; i++) {
		int M = 0;
		int x1 = arr[i].first;
		int y1 = arr[i].second;
		for (int j = 0; j < n; j++) {
			if (i == j) continue;
			int x2 = arr[j].first;
			int y2 = arr[j].second;
			int dx = abs(x1 - x2);
			int dy = abs(y1 - y2);
			edge.push_back(dx*dx + dy * dy);
		}
	}
	sort(edge.begin(), edge.end());
	int left = 0, right = edge.size() - 1;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (possible(edge[mid], 0)) {
			ans = edge[mid];
			right = mid - 1;
		}
		else left = mid + 1;
	}
	cout << ans;
	return 0;
}