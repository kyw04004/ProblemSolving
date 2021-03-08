#include <string>
#include <vector>
using namespace std;
vector<int> v[205];
int chk[205];
void dfs(int now) {
	chk[now] = 1;
	for (int i = 0; i < v[now].size(); i++) {
		int next = v[now][i];
		if (chk[next] == 0) dfs(next);
	}
}
int solution(int n, vector<vector<int>> computers) {
	int answer = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) continue;
			if (computers[i][j] == 1) {
				v[i].push_back(j);
				v[j].push_back(i);
			}
		}
	}
	for (int i = 0; i < n; i++)
		if (chk[i] == 0) {
			answer++;
			dfs(i);
		}
	return answer;
}