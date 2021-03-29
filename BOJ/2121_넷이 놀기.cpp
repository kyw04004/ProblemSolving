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
int n, g, s, cnt;
map <pair<int, int>, int> m;
pair<int, int> dot[500005];
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n >> g >> s;
	for (int i = 1; i <= n; i++) {
		cin >> dot[i].first >> dot[i].second;
		m[{dot[i].first, dot[i].second}] = 1;
	}
	for (int i = 1; i <= n; i++) {
		int sx = dot[i].first, sy = dot[i].second;
		if (m[{sx + g, sy}] && m[{sx + g, sy + s}] && m[{sx, sy + s}]) cnt++;
	}
	cout << cnt;
	return 0;
}