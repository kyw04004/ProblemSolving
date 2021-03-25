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
int n, m, Map[9][9], ans = 100, Com[9][9];
vector<pair<int, pair<int,int>>> cctv;
vector<int> seq;
void checkright(int x, int y) {
	while (1) {
		y += 1;
		if (y > m) break;
		if (Com[x][y] != 6) Com[x][y] = 9;
		else break;
	}
}
void checkleft(int x, int y) {
	while (1) {
		y -= 1;
		if (y < 1) break;
		if (Com[x][y] != 6) Com[x][y] = 9;
		else break;
	}
}
void checkup(int x, int y) {
	while (1) {
		x -= 1;
		if (x < 1) break;
		if (Com[x][y] != 6) Com[x][y] = 9;
		else break;
	}
}
void checkdown(int x, int y) {
	while (1) {
		x += 1;
		if (x > n) break;
		if (Com[x][y] != 6) Com[x][y] = 9;
		else break;
	}
}
void monitoring(int x, int y, int cctvnum, int dir) {
	if (cctvnum == 1) {
		if (dir == 1) checkright(x, y);
		if (dir == 2) checkleft(x, y);
		if (dir == 3) checkup(x, y);
		if (dir == 4) checkdown(x, y);
	}
	if (cctvnum == 2) {
		if (dir == 1 || dir == 3) {
			checkright(x, y);
			checkleft(x, y);
		}
		if (dir == 2 || dir == 4) {
			checkup(x, y);
			checkdown(x, y);
		}
	}
	if (cctvnum == 3) {
		if (dir == 1) {
			checkup(x, y);
			checkright(x, y);
		}
		if (dir == 2) {
			checkright(x, y);
			checkdown(x, y);
		}
		if (dir == 3) {
			checkleft(x, y);
			checkdown(x, y);
		}
		if (dir == 4) {
			checkleft(x, y);
			checkup(x, y);
		}
	}
	if (cctvnum == 4) {
		if (dir == 1) {
			checkup(x, y);
			checkleft(x, y);
			checkright(x, y);
		}
		if (dir == 2) {
			checkup(x, y);
			checkright(x, y);
			checkdown(x, y);
		}
		if (dir == 3) {
			checkleft(x, y);
			checkright(x, y);
			checkdown(x, y);
		}
		if (dir == 4) {
			checkup(x, y);
			checkdown(x, y);
			checkleft(x, y);
		}
	}
	if (cctvnum == 5) {
		checkup(x, y);
		checkdown(x, y);
		checkright(x, y);
		checkleft(x, y);
	}
}
void go(int depth) {
	if (seq.size() == cctv.size()) {
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				Com[i][j] = Map[i][j];
		for (int i = 0; i < seq.size(); i++)
			monitoring(cctv[i].second.first, cctv[i].second.second, cctv[i].first, seq[i]);
		int sum = 0;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				if (Com[i][j] == 0) sum++;
		ans = min(ans, sum);
		return;
	}
	for (int i = 1; i <= 4; i++) {
		seq.push_back(i);
		go(depth + 1);
		seq.pop_back();
	}
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			cin >> Map[i][j];
			if (1 <= Map[i][j] && Map[i][j] <= 5)
				cctv.push_back({ Map[i][j], {i,j} });
		}
	go(0);
	cout << ans;
	return 0;
}