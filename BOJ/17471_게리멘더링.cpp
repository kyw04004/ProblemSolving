#include<iostream>
#include<queue>
#include<string>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<functional>
#include<stack>
#include<vector>
#include<map>
using namespace std;
typedef long long ll;
typedef pair<int, int> p;
int N, population[11], ans = 1e9, area[11], sum;
vector<int> grape[11];
int bfs(int st, int areaN) {
	queue<int> q;
	int sum = 0;
	int chk[11] = {};
	q.push(st);
	chk[st] = 1;
	while (!q.empty()) {
		int now = q.front();
		sum += population[now];
		q.pop();
		for (int i = 0; i < grape[now].size(); i++) {
			int next = grape[now][i];
			if (!chk[next] && area[next] == areaN) {
				chk[next] = 1;
				q.push(next);
			}
		}
	}
	return sum;
}
void makeSeq(int num) {
	if (num > N) return;
	if (num > 1) {
		int oneN = 0, twoN = 0;
		for (int i = 1; i <= N; i++)
			if (area[i] == 1) {
				oneN = bfs(i, 1);
				break;
			}
		for (int i = 1; i <= N; i++)
			if (area[i] == 2) {
				twoN = bfs(i, 2);
				break;
			}
		if (oneN + twoN == sum)
			ans = min((int)abs(oneN - twoN), ans);
	}
	for (int i = num; i <= N; i++) {
		area[i] = 1;
		makeSeq(i + 1);
		area[i] = 2;
	}
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> population[i];
		area[i] = 2;
		sum += population[i];
	}
	for (int i = 1; i <= N; i++) {
		int cnt; cin >> cnt;
		for (int j = 0; j < cnt; j++) {
			int num; cin >> num;
			grape[i].push_back(num);
		}
	}
	makeSeq(1);
	if (ans == 1e9) ans = -1;
	cout << ans;
	return 0;
}