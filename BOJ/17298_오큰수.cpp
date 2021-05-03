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
int n, output[1000005];
stack<P> s;
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int val;
		cin >> val;
		while (!s.empty() && s.top().first < val ) {
			output[s.top().second] = val;
			s.pop();
		}
		s.push({val, i});
	}
	while (!s.empty()) {
		output[s.top().second] = -1;
		s.pop();
	}
	for (int i = 0; i < n; i++)
		cout << output[i] << ' ';
	return 0;
}