#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
#include<map>
#include<vector>
#include<queue>
#include<stack>
using namespace std;
int N;
pair<int,int> seat[21][21];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
struct student {
	int num;
	int like[4];
};
struct candicate {
	int like;
	int empty;
	int x;
	int y;
};
bool compare(candicate a, candicate b) {
	if (a.like != b.like) return a.like > b.like;
	if (a.empty != b.empty) return a.empty > b.empty;
	if (a.x != b.x) return a.x < b.x;
	if (a.y != b.y) return a.y < b.y;
}
vector<student> v;
int main(void) {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N;
	for (int i = 0; i < N * N; i++) {
		int num, like[4];
		cin >> num;
		for (int j = 0; j < 4; j++) cin >> like[j];
		v.push_back({ num, {like[0], like[1], like[2], like[3]} });
	}
	for (int i = 0; i < v.size(); i++) {
		int num = v[i].num;
		vector<candicate> c;
		for (int x = 1; x <= N; x++) {
			for (int y = 1; y <= N; y++) {
				if (seat[x][y].first) continue;
				int like = 0, empty=0;
				for (int k = 0; k < 4; k++) {
					int nx = x + dx[k];
					int ny = y + dy[k];
					if (nx < 1 || nx > N || ny < 1 || ny > N) continue;
					if (!seat[nx][ny].first) empty++;
					for (int kk = 0; kk < 4; kk++)
						if (seat[nx][ny].first == v[i].like[kk]) like++;
				}
				c.push_back({ like, empty, x, y });
			}
		}
		sort(c.begin(), c.end(), compare);
		seat[c[0].x][c[0].y] = { num,i };
	}
	int sum = 0;
	for (int x = 1; x <= N; x++) {
		for (int y = 1; y <= N; y++) {
			int cnt = 0;
			for (int k = 0; k < 4; k++) {
				int nx = x + dx[k];
				int ny = y + dy[k];
				if (nx < 1 || nx > N || ny < 1 || ny > N) continue;
				for (int kk = 0; kk < 4; kk++)
					if (seat[nx][ny].first == v[seat[x][y].second].like[kk]) cnt++;
			}
			if (cnt == 1) sum += 1;
			if (cnt == 2) sum += 10;
			if (cnt == 3) sum += 100;
			if (cnt == 4) sum += 1000;
		}
	}
	cout << sum;
	return 0;
}
