#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include<cstring>
#include<cmath>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
int R, C, M;
//1:U
//2:D
//3:R
//4:L
struct shInfo {
	int s, d, z; // speed, direction, size
};
shInfo sharks[105][105];
int sumSize;
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> R >> C >> M;
	for (int i = 0; i < M; i++) {
		int r, c, s, d, z;
		cin >> r >> c >> s >> d >> z;
		sharks[r - 1][c - 1] = { s,d,z };
	}
	for (int i = 0; i < C; i++) { // fishing king moves
		shInfo com[105][105]; // initialize
		for (int x = 0; x < R; x++)
			for (int y = 0; y < C; y++)
				com[x][y] = { 0,0,0 };

		for (int j = 0; j < R; j++) // fishing
			if (sharks[j][i].z) {
				sumSize += sharks[j][i].z;
				sharks[j][i] = { 0,0,0 };
				break;
			}

		for (int x = 0; x < R; x++) { // sharks moving
			for (int y = 0; y < C; y++) {
				if (sharks[x][y].z) { // shark exists
					int z = sharks[x][y].z;
					int d = sharks[x][y].d;
					int s = sharks[x][y].s;
					int ss = s;
					int nx = x, ny = y;
					while (s) {
						if (d == 1) {
							if (s > nx) {
								s -= nx;
								nx = 0;
								d = 2;
							}
							else {
								nx -= s;
								break;
							}
						}
						if (d == 2) {
							if (s + nx >= R) {
								s -= R - 1 - nx;
								nx = R - 1;
								d = 1;
							}
							else {
								nx += s;
								break;
							}
						}
						if (d == 3) {
							if (ny + s >= C) {
								s -= C - 1 - ny;
								ny = C - 1;
								d = 4;
							}
							else {
								ny += s;
								break;
							}
						}
						if (d == 4) {
							if (s > ny) {
								s -= ny;
								ny = 0;
								d = 3;
							}
							else {
								ny -= s;
								break;
							}
						}
					}
					if (z > com[nx][ny].z) com[nx][ny] = { ss,d,z };
				}
			}
		}
		for (int x = 0; x < R; x++) // sharks's location save
			for (int y = 0; y < C; y++)
				sharks[x][y] = com[x][y];
	}
	cout << sumSize;
	return 0;
}