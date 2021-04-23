#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
int chk[105][105], dp[105][105], N, M;
int go(int x, int y) {
	if (x == N && y == M) return 1;
	int &ret = dp[x][y];
	if (ret != -1) return ret;
	ret = 0;
	if (x < N && !chk[x + 1][y]) ret += go(x + 1, y) % 1000000007;
	if (y < M && !chk[x][y + 1]) ret += go(x, y + 1) % 1000000007;
	return ret % 1000000007;
}
int solution(int m, int n, vector<vector<int>> puddles) {
	memset(dp, -1, sizeof(dp));
	N = n, M = m;
	for (int i = 0; i < puddles.size(); i++)
		chk[puddles[i][1]][puddles[i][0]] = 1;
	int answer = go(1, 1);
	return answer;
}