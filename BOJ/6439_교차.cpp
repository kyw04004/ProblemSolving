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
	cin >> t;
	while (t--) {
		int ans = 0;
		int ax, ay, bx, by;
		int xl, yt, xr, yb;
		Line line[4];
		cin >> ax >> ay >> bx >> by;
		cin >> xl >> yt >> xr >> yb;
		if (xl > xr) swap(xl, xr);
		if (yb > yt) swap(yb, yt);
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
			int ccw1 = ax * by + bx * cy + cx * ay;
			ccw1 -= ay * bx + by * cx + cy * ax;
			if (ccw1 > 0) ccw1 = 1;
			if (ccw1 < 0) ccw1 = -1;
			int ccw2 = ax * by + bx * dy + dx * ay;
			ccw2 -= ay * bx + by * dx + dy * ax;
			if (ccw2 > 0) ccw2 = 1;
			if (ccw2 < 0) ccw2 = -1;
			int ccw3 = cx * dy + dx * ay + ax * cy;
			ccw3 -= cy * dx + dy * ax + ay * cx;
			if (ccw3 > 0) ccw3 = 1;
			if (ccw3 < 0) ccw3 = -1;
			int ccw4 = cx * dy + dx * by + bx * cy;
			ccw4 -= cy * dx + dy * bx + by * cx;
			if (ccw4 > 0) ccw4 = 1;
			if (ccw4 < 0) ccw4 = -1;
			if (ccw1*ccw2 <= 0 && ccw3*ccw4 <= 0 && check(ax, ay, bx, by, cx, cy, dx, dy)) ans = 1;
			if (max(ax,bx)<=xr && max(ay,by)<=yt && xl <= min(ax,bx) && yb <= min(ay,by)) ans = 1;
		}
		if (ans) cout << "T" << '\n';
		else cout << "F" << '\n';
	}
	return 0;
}