#include<iostream>
#include<map>
#include<queue>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
string str;
int K, ans = -1;
map<pair<string, int>, int> m;
queue<pair<string, int>> q;
void bfs() {
	q.push({ str, 0 });
	m[{str, 0}] = 1;
	while (!q.empty()) {
		string now = q.front().first;
		int step = q.front().second;
		q.pop();
		if (step == K) {
			ans = max(ans, stoi(now));
			continue;
		}
		for (int i = 0; i < str.size() - 1; i++) {
			for (int j = i + 1; j < str.size(); j++) {
				string com = now;
				swap(com[i], com[j]);
				if (m[{com, step + 1}] || com[0] == '0') continue;
				m[{com, step + 1}] = 1;
				q.push({ com, step + 1 });
			}
		}
	}
}
int main() {
	cin >> str >> K;
	bfs();
	cout << ans;
	return 0;
}