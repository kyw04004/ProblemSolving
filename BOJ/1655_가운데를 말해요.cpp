#include<iostream>
#include<map>
#include<queue>
#include<cstring>
#include<string>
#include<algorithm>
#include<functional>
using namespace std;
typedef long long ll;
int n;
priority_queue<int, vector<int>, less<int>> maxH;
priority_queue<int, vector<int>, greater<int>> minH;
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int val; cin >> val;
		if (minH.size() == maxH.size()) maxH.push(val);
		else minH.push(val);
		if (!minH.empty() && !maxH.empty() && maxH.top() > minH.top()) {
			int minT = minH.top();
			int maxT = maxH.top();
			minH.pop();
			maxH.pop();
			minH.push(maxT);
			maxH.push(minT);
		}
		cout << maxH.top() << '\n';
	}
	return 0;
}