#include<iostream>
#include<vector>
#include<queue>
#include<string>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<functional>
using namespace std;
typedef long long ll;
priority_queue<int, vector<int>, greater<int>> m1,m2,f1,f2;
int n, cnt;
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int mh; cin >> mh;
		if (mh > 0) m1.push(mh);
		else m2.push(-1 * mh);
	}
	for (int i = 0; i < n; i++) {
		int fh; cin >> fh;
		if (fh > 0) f1.push(fh);
		else f2.push(-1 * fh);
	}

	while (!m2.empty()) {
		int mt = m2.top();
		m2.pop();
		if (!f1.empty() && mt > f1.top()) {
			f1.pop();
			cnt++;
		}
	}

	while (!f2.empty()) {
		int ft = f2.top();
		f2.pop();
		if (!m1.empty() && ft > m1.top()) {
			m1.pop();
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}

