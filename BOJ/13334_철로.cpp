#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<map>
#include<queue>
#include<functional>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int, int> p;
priority_queue<p, vector<p>, greater<p>> pq;
priority_queue<int, vector<int>, greater<int>> com;
int N, D, Max;
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		int a, b; cin >> a >> b;
		pq.push({max(a,b), min(a,b)});
	}
	cin >> D;
	while (!pq.empty()) {
		int s = pq.top().second;
		int e = pq.top().first;
		pq.pop();
		if (e - s > D) continue;
		com.push(s);
		while (!com.empty()) {
			if (com.top() + D >= e) {
				int cnt = com.size();
				Max = max(Max, cnt);
				break;
			}
			else com.pop();
		}
	}
	cout << Max;
	return 0;
}