#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <deque>
#include <stack>
#include <queue>
#include <functional>
using namespace std;
typedef pair<int, int> P;
int V, E, in[1005], output[1005];
vector<int> v[1005];
queue<int> q;
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> V >> E;
	for (int i = 1; i <= E; i++) {
		int s, e;
		cin >> s >> e;
		v[s].push_back(e);
		in[e]++;
	}
	for (int i = 1; i <= V; i++)
		if (in[i] == 0) {
			q.push(i);
			output[i] = 1;
		}
	while (!q.empty()) {
		int node = q.front();
		q.pop();
		for (int i = 0; i < v[node].size(); i++) {
			int nextNode = v[node][i];
			in[nextNode]--;
			if (in[nextNode] == 0) {
				output[nextNode] = max(output[nextNode], output[node] + 1);
				q.push(nextNode);
			}
		 }
	}
	for (int i = 1; i <= V; i++)
		cout << output[i] << ' ';
	return 0;
}