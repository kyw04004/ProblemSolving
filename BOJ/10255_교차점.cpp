#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
typedef long long ll;
int t;
struct Line {
	int cx;
	int cy;
	int dx;
	int dy;
};
int check(int s, int ax, int ay, int bx, int by, int cx, int cy, int dx, int dy) {
	if (ax == bx && bx == cx && cx == dx) {
		int aminy = min(ay, by);
		int cmaxy = max(cy, dy);
		int cminy = min(cy, dy);
		int amaxy = max(ay, by);
		if (s==1 && (aminy > cmaxy || amaxy < cminy)) return false;
		if (s == 2 && (cmaxy > aminy && amaxy > cminy)) return true;
	}
	else {
		int aminx = min(ax, bx);
		int cmaxx = max(cx, dx);
		int cminx = min(cx, dx);
		int amaxx = max(ax, bx);
		if (s==1 && (aminx > cmaxx || amaxx < cminx)) return false;
		if (s == 2 && (cmaxx > aminx && amaxx > cminx)) return true;
	}
	if(s==1) return true;
	if (s == 2) return false;
}
int ccw(int ax, int ay, int bx, int by, int cx, int cy) {
	int x = ax * by + bx * cy + cx * ay;
	x -= ay * bx + by * cx + cy * ax;
	if (x > 0) return 1;
	else if (x == 0) return 0;
	else return -1;
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> t;
	while (t--) {
		int ans = 0, cnt=0;
		int ax, ay, bx, by;
		int xl, yt, xr, yb;
		Line line[4];
		cin >> xl >> yb >> xr >> yt;
		cin >> ax >> ay >> bx >> by;
		line[0].cx = xl, line[0].cy = yt;
		line[0].dx = xl, line[0].dy = yb;
		line[1].cx = xl, line[1].cy = yb;
		line[1].dx = xr, line[1].dy = yb;
		line[2].cx = xr, line[2].cy = yb;
		line[2].dx = xr, line[2].dy = yt;
		line[3].cx = xr, line[3].cy = yt;
		line[3].dx = xl, line[3].dy = yt;
		for (int i = 0; i < 4; i++) {
			int cx = line[i].cx, cy = line[i].cy;
			int dx = line[i].dx, dy = line[i].dy;
			int ccw1 = ccw(ax, ay, bx, by, cx, cy);
			int ccw2 = ccw(ax, ay, bx, by, dx, dy);
			int ccw3 = ccw(cx, cy, dx, dy, ax, ay);
			int ccw4 = ccw(cx, cy, dx, dy, bx, by);
			if (ccw1*ccw2 <= 0 && ccw3*ccw4 <= 0 && check(1, ax, ay, bx, by, cx, cy, dx, dy)) {
				ans += 1;
				if (ccw1 * ccw2 == 0 && ccw3 * ccw4 <= 0) cnt++;
			}
			if (!ccw1 && !ccw2 && !ccw3 && !ccw4 && check(2, ax, ay, bx, by, cx, cy, dx, dy)) {
				ans = 4;
				cnt = 0;
				break;
			}
		}
		cout << (ans - (cnt/2)) << '\n';
	}
	return 0;
}