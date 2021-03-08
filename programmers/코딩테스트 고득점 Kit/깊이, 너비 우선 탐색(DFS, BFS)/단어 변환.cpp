#include <string>
#include <vector>
#include <queue>
using namespace std;
string arr[55], com;
int cnt = 1, chk[55];
vector<int> v[55];
int bfs(int now) {
	chk[now] = 1;
	queue<pair<int, int>> q;
	q.push({ now, 0 });
	while (!q.empty()) {
		int here = q.front().first;
		int cnt = q.front().second;
		q.pop();
		if (arr[here] == com) return cnt;
		for (int i = 0; i < v[here].size(); i++) {
			int next = v[here][i];
			if (chk[next] == 0) {
				chk[next] = 1;
				q.push({ next, cnt + 1 });
			}
		}
	}
	return 0;
}
int solution(string begin, string target, vector<string> words) {
	int answer = 0;
	arr[1] = begin;
	com = target;
	for (int i = 0; i < words.size(); i++)
		arr[++cnt] = words[i];
	for (int i = 1; i < cnt; i++) {
		for (int j = i + 1; j <= cnt; j++) {
			int cnt = 0;
			int len = arr[i].size();
			for (int a = 0; a < len; a++)
				if (arr[i][a] != arr[j][a]) cnt++;
			if (cnt == 1) {
				v[i].push_back(j);
				v[j].push_back(i);
			}
		}
	}
	answer = bfs(1);
	return answer;
}