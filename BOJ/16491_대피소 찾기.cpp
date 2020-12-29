#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
typedef long long ll;
int n;
pair<int, int> SP[11],EP[11];
struct Line {
	int ax;
	int ay;
	int bx;
	int by;
}line[11];
vector<int> v;
int ccw(int ax, int ay, int bx, int by, int cx, int cy) {
	int x = ax * by + bx * cy + cx * ay;
	x -= ay * bx + by * cx + cy * ax;
	if (x > 0) return 1;
	else if (x == 0) return 0;
	else return -1;
}
bool check(int ax, int ay, int bx, int by, int cx, int cy, int dx, int dy) {
	if (ax == bx && bx == cx && cx == dx) {
		int aminy = min(ay, by);
		int cmaxy = max(cy, dy);
		int cminy = min(cy, dy);
		int amaxy = max(ay, by);
		if (aminy > cmaxy || amaxy < cminy) return false;
	}
	else {
		int aminx = min(ax, bx);
		int cmaxx = max(cx, dx);
		int cminx = min(cx, dx);
		int amaxx = max(ax, bx);
		if (aminx > cmaxx || amaxx < cminx) return false;
	}
	return true;
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> SP[i].first >> SP[i].second;
	for (int i = 1; i <= n; i++) cin >> EP[i].first >> EP[i].second;
	for (int i = 1; i <= n; i++) line[i].ax = SP[i].first, line[i].ay = SP[i].second;
	for (int i = 1; i <= n; i++) v.push_back(i);
	do {
		int ok = 0;
		for (int i = 1; i <= n; i++)
			line[i].bx = EP[v[i - 1]].first, line[i].by = EP[v[i - 1]].second;
		for (int i = 1; i <= n-1; i++) {
			int ax = line[i].ax, ay = line[i].ay;
			int bx = line[i].bx, by = line[i].by;
			for (int j = i + 1; j <= n; j++) {
				int cx = line[j].ax, cy = line[j].ay;
				int dx = line[j].bx, dy = line[j].by;
				int ccw1 = ccw(ax, ay, bx, by, cx, cy);
				int ccw2 = ccw(ax, ay, bx, by, dx, dy);
				int ccw3 = ccw(cx, cy, dx, dy, ax, ay);
				int ccw4 = ccw(cx, cy, dx, dy, bx, by);
				if (ccw1*ccw2 <= 0 && ccw3*ccw4 <= 0 && check(ax, ay, bx, by, cx, cy, dx, dy)) {
					ok = 1;
					i = n + 1, j = n + 1;
				}
			}
		}
		if (ok == 0) {
			for (int i = 0; i < v.size(); i++)
				cout << v[i] << '\n';
			break;
		}
	} while (next_permutation(v.begin(), v.end()));
	return 0;
}