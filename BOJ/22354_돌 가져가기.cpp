#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
ll N,ans;
string str;
vector<ll> point;
stack<char> sq;
stack<ll> pq, input;
int main() {
	cin >> N;

	cin >> str;

	for (int i = 0; i < N; i++) {
		ll p; cin >> p;
		point.push_back(p);
	}

	for (int i = 0; i < N; i++) {
		char c = str[i];
		ll p = point[i];
		if (i == 0) {
			sq.push(c);
			pq.push(p);
			continue;
		}
		if (sq.top() == c) {
			if (pq.top() > p) {
				continue;
			}
			else {
				pq.pop();
				pq.push(p);
			}
		}
		else {
			sq.push(c);
			pq.push(p);
		}
	}

	point.clear();
	while (!pq.empty()) {
		input.push(pq.top());
		pq.pop();
	}

	while (!input.empty()) {
		point.push_back(input.top());
		input.pop();
	}

	if (point.size()< 3) {
		cout << 0;
		return 0;
	}

	sort(point.begin() + 1, point.end() - 1);

	int cnt = (point.size() - 3) / 2 + 1;

	for (int i = point.size() - 2, s = 0; s < cnt; i--,s++)
		ans += point[i];
	cout << ans;
}