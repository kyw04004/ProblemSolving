#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
typedef long long ll;
int n, m;
double ans = 1e5;
struct Sinchon{
	double ax;
	double ay;
	double bx;
	double by;
};
struct Anam {
	double cx;
	double cy;
	double dx;
	double dy;
};
Sinchon sinchon[2001];
Anam anam[2001];
double inner(double ax, double ay, double bx, double by) {
	return ax * bx + ay * by;
}
double perpendicular(double ax, double ay, double bx, double by, double cx, double cy) {
	double inner1 = inner(cx - ax, cy - ay, bx - ax, by - ay);
	double inner2 = inner(cx - bx, cy - by, ax - bx, ay - by);
	if (inner1 < 0 || inner2 < 0) return -1;
	double ccw = ax * by + bx * cy + cx * ay;
	ccw -= ay * bx + by * cx + cy * ax;
	return abs(ccw) / sqrt(pow(bx-ax,2)+pow(by-ay,2));
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 0; i < n; i++) 
		cin >> sinchon[i].ax >> sinchon[i].ay >> sinchon[i].bx >> sinchon[i].by;
	for (int i = 0; i < m; i++)
		cin >> anam[i].cx >> anam[i].cy >> anam[i].dx >> anam[i].dy;
	for (int i = 0; i < n; i++) {
		double ax = sinchon[i].ax, ay = sinchon[i].ay;
		double bx = sinchon[i].bx, by = sinchon[i].by;
		for (int j = 0; j < m; j++) {
			double cx = anam[j].cx, cy = anam[j].cy;
			double dx = anam[j].dx, dy = anam[j].dy;
			double dist1 = sqrt(pow(ax - cx, 2) + pow(ay - cy, 2));
			dist1 = min(dist1, sqrt(pow(ax - dx, 2) + pow(ay - dy, 2)));
			dist1 = min(dist1, sqrt(pow(bx - cx, 2) + pow(by - cy, 2)));
			dist1 = min(dist1, sqrt(pow(bx - dx, 2) + pow(by - dy, 2)));
			double dist2 = perpendicular(ax, ay, bx, by, cx, cy);
			if (dist2 >= 0) dist1 = min(dist1, dist2);
			dist2 = perpendicular(ax, ay, bx, by, dx, dy);
			if (dist2 >= 0) dist1 = min(dist1, dist2);
			dist2 = perpendicular(cx, cy, dx, dy, ax, ay);
			if (dist2 >= 0) dist1 = min(dist1, dist2);
			dist2 = perpendicular(cx, cy, dx, dy, bx, by);
			if (dist2 >= 0) dist1 = min(dist1, dist2);
			ans = min(ans, dist1);
		}
	}
	cout << fixed;
	cout.precision(6);
	cout << ans << '\n';
	return 0;
}