#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <stack>
#include <map>
#include <set>
#include <stack>
#include <queue>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
priority_queue<int, vector<int>, greater<int>> pq;
int n, sum;
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int val; cin >> val;
		pq.push(val);
	}
	while (pq.size() > 1) {
		int com1 = pq.top();
		pq.pop();
		int com2 = pq.top();
		pq.pop();
		sum += com1 + com2;
		pq.push(com1 + com2);
	}
	cout << sum;
	return 0;
}