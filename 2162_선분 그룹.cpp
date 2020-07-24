#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
int n, chk[3001], cnt, Max  = 1, cnt2;
vector<int> v[3001];
queue <int> q;
struct line {
	int x1, y1, x2, y2;
}arr[3001];

void bfs(int now) {
	cnt2 = 1;
	chk[now] = 1;
	q.push(now);
	while (!q.empty()) {
		int here = q.front();
		q.pop();
		for (int i = 0; i < (int)v[here].size(); i++) {
			int next = v[here][i];
			if (!chk[next]) {
				chk[next] = 1;
				cnt2++;
				if (cnt2 > Max) Max = cnt2;
				q.push(next);
			}
		}
	}
}

bool check(line a, line b) {
	int ax = a.x1, ay = a.y1;
	int bx = a.x2, by = a.y2;
	int cx = b.x1, cy = b.y1;
	int dx = b.x2, dy = b.y2;
	if (ax == bx && ax == cx && ax == dx) {
		int maxy = max(ay, by);
		int miny = min(cy, dy);
		if (maxy < miny) return false;
		int maxy2 = max(cy, dy);
		int miny2 = min(ay, by);
		if (maxy2 < miny2) return false;
	}
	else {
		int maxx = max(ax, bx);
		int minx = min(cx, dx);
		if (maxx < minx) return false;
		int maxx2 = max(cx, dx);
		int minx2 = min(ax, bx);
		if (maxx2 < minx2) return false;
	}
	return true;
}

int ccw(int x1, int y1, int x2, int y2, int x3, int y3) {
	int com = (x2 - x1)*(y3 - y1);
	com -= (x3 - x1)*(y2 - y1);
	if (com > 0) return 1;
	if (com < 0 ) return -1;
	else return 0;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
		scanf("%d %d %d %d", &arr[i].x1, &arr[i].y1, &arr[i].x2, &arr[i].y2);
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			int ax = arr[i].x1, ay = arr[i].y1;
			int bx = arr[i].x2, by = arr[i].y2;
			int cx = arr[j].x1, cy = arr[j].y1;
			int dx = arr[j].x2, dy = arr[j].y2;
			int line1 = ccw(ax, ay, bx, by, cx, cy) * ccw(ax, ay, bx, by, dx, dy);
			int line2 = ccw(cx, cy, dx, dy, ax, ay) * ccw(cx, cy, dx, dy, bx, by);
			if (line1 <= 0 && line2 <= 0 && check(arr[i], arr[j])) {
				v[i].push_back(j); v[j].push_back(i);
			}
		}
	}

	for (int i = 0; i < n; i++)
		if (!chk[i]) {
			cnt++; bfs(i);
		}

	cout << cnt << '\n' << Max;

	return 0;
}