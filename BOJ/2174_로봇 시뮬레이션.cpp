#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
#include<deque>
#include<stack>
#include<functional>
#include<vector>
#include<cmath>
#include<map>
using namespace std;
typedef long long ll;
int a, b, n, m;
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
pair<pair<int, int>, char> arr[101];
pair<pair<int, char>, int > com[101];
int main() {
	cin >> a >> b >> n >> m;
	for (int i = 1; i <= n; i++) {
		int x, y;
		char d;
		cin >> x >> y >> d;
		arr[i] = { {x,y},d };
	}
	for (int i = 1; i <= m; i++) {
		int r, cnt;
		char c;
		cin >> r >> c >> cnt;
		com[i] = { {r,c},cnt };
	}
	for (int i = 1; i <= m; i++) {
		int r = com[i].first.first, cnt = com[i].second;
		char c = com[i].first.second;
		char d = arr[r].second;
		int ds;
		if (d == 'N') ds = 0;
		if (d == 'E') ds = 1;
		if (d == 'S') ds = 2;
		if (d == 'W') ds = 3;
		if (c == 'L' || c == 'R') {
			if (c == 'L') ds += 3 * cnt;
			if (c == 'R') ds += cnt;
			ds %= 4;
			if (ds == 0) arr[r].second = 'N';
			if (ds == 1)  arr[r].second = 'E';
			if (ds == 2)  arr[r].second = 'S';
			if (ds == 3) arr[r].second = 'W';
		}
		if (c == 'F') {
			for (int k = 1; k <= cnt; k++) {
				arr[r].first.first += dx[ds];
				arr[r].first.second += dy[ds];
				if (arr[r].first.first > a || arr[r].first.first < 1 ||
					arr[r].first.second > b || arr[r].first.second < 1) {
					printf("Robot %d crashes into the wall", r);
					return 0;
				}
				for (int j = 1; j <= n; j++) {
					if (r == j) continue;
					if ((arr[r].first.first == arr[j].first.first) &&
						(arr[r].first.second == arr[j].first.second)) {
						printf("Robot %d crashes into robot %d", r, j);
						return 0;
					}
				}
			}
		}
	}
	printf("OK");
	return 0;
}