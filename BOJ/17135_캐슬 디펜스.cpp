#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
#include<map>
#include<vector>
#include<functional>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
int N, M, D, Max;
char board[16][16];
void make_max(vector<int> seq) {
	int kill = 0;
	char com[16][16];

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			com[i][j] = board[i][j];

	for(int k=1; k <= N; k++) {

		int Min[3]; for (int i = 0; i < 3; i++) Min[i] = 1e9;
		int minx[3]; for (int i = 0; i < 3; i++) minx[i] = -1;
		int miny[3]; for (int i = 0; i < 3; i++) miny[i] = -1;

		for (int i = 0; i < 3; i++) {
			int aX = N+1, aY = seq[i];
			for (int y = 1; y <= M; y++)
				for (int x = N; x >= 1 ; x--) {
					if (com[x][y] == '0') continue;
					int dist = abs(aX - x) + abs(aY - y);
					if (Min[i] > dist && dist <= D) Min[i] = dist, minx[i] = x, miny[i] = y;
				}
		}

		for (int i = 0; i < 3; i++) {
			if (Min[i] == 1e9) continue;
			if (com[minx[i]][miny[i]] == '1')
				com[minx[i]][miny[i]] = '0', kill++;
		}

		for (int x = N; x >=1; x--)
			for (int y = 1; y <= M; y++) {
				if (x == N) com[x][y] = '0';
				else if (com[x][y] == '1') com[x + 1][y] = '1', com[x][y] = '0';
			}
	}
	Max = max(Max, kill);
}
void make_seq(int depth, vector<int> seq, int idx) {
	if (depth == 3) {
		make_max(seq);
		return;
	}
	for (int i = idx + 1; i <= M; i++) {
		seq.push_back(i);
		make_seq(depth + 1, seq, i);
		seq.pop_back();
	}
}
int main() {
	cin >> N >> M >> D;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			cin >> board[i][j];
	vector<int> v;
	make_seq(0, v, 0);
	cout << Max;
	return 0;
}