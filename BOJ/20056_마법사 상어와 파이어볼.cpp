#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
#include<map>
#include<vector>
#include<queue>
using namespace std;
int N, M, K;
struct element {
	int m;
	int s;
	int d;
};
vector<element> fire[51][51];
int dx[8] = {-1,-1,0,1,1,1,0,-1};
int dy[8] = { 0,1,1,1,0,-1,-1,-1 };
int main(void) {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N >> M >> K;
	for (int i = 0; i < M; i++) {
		int r, c, m, s, d;
		cin >> r >> c >> m >> s >> d;
		fire[r][c].push_back({ m,s,d });
	}
	for (int i = 0; i < K; i++) {
		vector<element> newFire[51][51];
		for (int x = 1; x <= N; x++) 
			for (int y = 1; y <= N; y++) 
				for (int j = 0; j < fire[x][y].size(); j++) {
					int m = fire[x][y][j].m;
					int s = fire[x][y][j].s;
					int d = fire[x][y][j].d;
					int nx = (x + s * dx[d] + N * 1000) % N;
					int ny = (y + s * dy[d] + N * 1000) % N;
					if (!nx) nx = N;
					if (!ny) ny = N;
					newFire[nx][ny].push_back({ m,s,d });
				}
		for (int x = 1; x <= N; x++) 
			for (int y = 1; y <= N; y++)
				if (newFire[x][y].size() > 1) {
					int odd = 0, even = 0;
					int sumM = 0, sumS = 0, cnt = newFire[x][y].size();
					for (int j = 0; j < cnt; j++) {
						int m = newFire[x][y][j].m;
						int s = newFire[x][y][j].s;
						int d = newFire[x][y][j].d;
						sumM += m, sumS += s, d % 2 == 1 ? odd++ : even++;
					}
					newFire[x][y].clear();
					if ((sumM / 5) == 0) continue;
					if (!odd || !even)
						for (int j = 0; j < 4; j++)
							newFire[x][y].push_back({sumM / 5, sumS / cnt, 2 * j});
					else
						for (int j = 0; j < 4; j++)
							newFire[x][y].push_back({ sumM / 5, sumS / cnt, 2 * j + 1});
				}
		for (int x = 1; x <= N; x++)
			for (int y = 1; y <= N; y++)
				fire[x][y] = newFire[x][y];
	}
	int ans = 0;
	for (int x = 1; x <= N; x++)
		for (int y = 1; y <= N; y++)
			for(int j=0;j<fire[x][y].size();j++)
				ans += fire[x][y][j].m ;
	cout << ans;
	return 0;
}
