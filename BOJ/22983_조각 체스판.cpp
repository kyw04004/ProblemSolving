#include<iostream>
#include<map>
#include<queue>
#include<cstring>
#include<string>
#include<algorithm>
#include<functional>
#include<vector>
#include<stack>
using namespace std;
typedef long long ll;
ll N, M, dp[3001][3001], ans;
char board[3001][3001];
int dx[3] = {-1,-1,0}; // À§ ´ë°¢ ¿Þ
int dy[3] = {0,-1,-1};
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++) {
			cin >> board[i][j];
			dp[i][j] = 1;
		}
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++) {
			ll Min = 1e18;
			char now = board[i][j];
			bool success = true;
			for (int k = 0; k < 3; k++) {
				if (success == false) break;
				int nx = i + dx[k];
				int ny = j + dy[k];
				if (nx < 1 || ny < 1) {
					success = false;
					continue;
				}
				char next = board[nx][ny];
				Min = min(Min, dp[nx][ny]);
				if (k % 2 == 0 && now == next) success = false;
				if (k == 1 && now != next) success = false;
			}
			if (success) dp[i][j] = Min + 1;
		}
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			ans += dp[i][j];
	cout << ans;
	return 0;
}