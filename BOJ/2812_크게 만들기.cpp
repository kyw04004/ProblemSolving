#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <stack>
#include <map>
#include <set>
#include <queue>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
stack <int> s, ans;
int N, K;
string num;
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N >> K >> num;
	for (int i = 0; i < N; i++) {
		while (K > 0 && !s.empty() && s.top() < num[i] - '0') K--, s.pop();
		s.push(num[i] - '0');
	}
	while (K--) s.pop();
	while (!s.empty()) {
		ans.push(s.top());
		s.pop();
	}
	while (!ans.empty()) {
		cout << ans.top();
		ans.pop();
	}
	return 0;
}