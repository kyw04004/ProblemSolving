#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstring>
using namespace std;
vector<vector<int>> v;
int dp[505][505], N;
int go(int depth, int index) {
	if (depth == N - 1) return 0;
	int &ret = dp[depth][index];
	if (ret != -1) return ret;
	ret = 0;
	ret = max(ret, go(depth + 1, index) + v[depth + 1][index]);
	ret = max(ret, go(depth + 1, index + 1) + v[depth + 1][index + 1]);
	return ret;
}
int solution(vector<vector<int>> triangle) {
	v = triangle;
	memset(dp, -1, sizeof(dp));
	N = triangle.size();
	int answer = v[0][0] + go(0, 0);
	return answer;
}