#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
#include<functional>
using namespace std;
typedef long long ll;
typedef pair<int, pair<int, int>> P;
vector<int> tree[11][11];
int n, m, k, A[11][11], Map[11][11], ans, del,sum;
int dx[8] = { -1,-1,-1,0,0,1,1,1 };
int dy[8] = { -1,0,1,-1,1,-1,0,1 };
int main() {
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) Map[i][j] = 5;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) cin >> A[i][j];
	for (int i = 0; i < m; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		tree[x][y].push_back(z);
	}
	for (int i = 1; i <= k; i++) {
		vector<P> die;
		for (int a = 1; a <= n; a++)
			for (int b = 1; b <= n; b++) {
				sort(tree[a][b].begin(), tree[a][b].end());
				for (int j = 0; j < tree[a][b].size(); j++) {
					int z = tree[a][b][j];
					if (z <= Map[a][b]) Map[a][b] -= z, tree[a][b][j]++;
					else {
						die.push_back({ z,{a,b} });
						tree[a][b].erase(tree[a][b].begin() + j), j--;
					}
				}
			}
		for (int j = 0; j < die.size(); j++) {
			int z = die[j].first;
			int x = die[j].second.first;
			int y = die[j].second.second;
			Map[x][y] += (z / 2);
		}
		for (int a = 1; a <= n; a++)
			for (int b = 1; b <= n; b++) {
				for (int j = 0; j < tree[a][b].size(); j++) {
					if (tree[a][b][j] % 5 == 0) {
						for (int k = 0; k < 8; k++) {
							int nx = a + dx[k];
							int ny = b + dy[k];
							if (nx >= 1 && nx <= n && ny >= 1 && ny <= n) {
								tree[nx][ny].push_back(1);
							}
						}
					}
				}
			}
		for (int a = 1; a <= n; a++)
			for (int b = 1; b <= n; b++) Map[a][b] += A[a][b];
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			sum += tree[i][j].size();
	cout << sum << "\n";
	return 0;
}