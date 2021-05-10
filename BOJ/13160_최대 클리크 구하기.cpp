#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <functional>
using namespace std;
typedef pair<pair<int, int>, int> PP;
typedef pair<int, int> P;
priority_queue <PP, vector<PP>, greater<PP>> input, input2;
priority_queue <P, vector<P>, greater<P>> com, answer;
int N, Max;
int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		int s, e; cin >> s >> e;
		input.push({ {s,e}, i });
		input2.push({ {s,e}, i });
	}
	int E = input.top().first.second;
	com.push({ input.top().first.second, input.top().second });
	input.pop();
	while (!input.empty()) {
		int s = input.top().first.first;
		int e = input.top().first.second;
		int idx = input.top().second;
		if (s <= E) {
			com.push({ e, idx });
			input.pop();
			Max = max(Max, (int)com.size());
		}
		else com.pop();
		E = com.top().first;
	}
	Max = max(Max, (int)com.size());
	cout << Max << '\n';

	E = input2.top().first.second;
	answer.push({ input2.top().first.second, input2.top().second });
	input2.pop();
	while (!input2.empty()) {
		int s = input2.top().first.first;
		int e = input2.top().first.second;
		int idx = input2.top().second;
		if (s <= E) {
			answer.push({ e, idx });
			input2.pop();
			if (Max == (int)answer.size()) {
				while (!answer.empty()) {
					cout << answer.top().second << ' ';
					answer.pop();
				}
				return 0;
			}
		}
		else answer.pop();
		E = answer.top().first;
	}
	return 0;
}