#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
int dist[20005], Max;
vector<int> v[20005];
void dfs(int now) {
	for (int i = 0; i < v[now].size(); i++) {
		int next = v[now][i];
		if (dist[next] > dist[now] + 1) {
			dist[next] = dist[now] + 1;
			dfs(next);
		}
	}
}
int solution(int n, vector<vector<int>> edge) {
	int answer = 0;
	for (int i = 0; i < edge.size(); i++) {
		v[edge[i][1]].push_back(edge[i][0]);
		v[edge[i][0]].push_back(edge[i][1]);
	}
	for (int i = 1; i <= n; i++) dist[i] = 1e9;
	dist[1] = 0;
	dfs(1);
	for (int i = 1; i <= n; i++) Max = max(Max, dist[i]);
	for (int i = 1; i <= n; i++)
		if (Max == dist[i]) answer++;
	return answer;
}