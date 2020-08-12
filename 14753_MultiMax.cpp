#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<functional>
using namespace std;
typedef long long ll;
int n, msum, psum, sum, zero;
vector <int> p;
vector <int> m;
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int a;
		cin >> a;
		if (a == 0) zero = 1;
		if (a < 0) m.push_back(a);
		else if (a > 0) p.push_back(a);
	}
	sort(m.begin(), m.end());
	sort(p.begin(), p.end());
	if (m.size() >= 2) {
		msum = m[0] * m[1];
		if (p.size() > 0) msum *= p[p.size() - 1];
	}
	if (p.size() >= 2) {
		psum = p[p.size() - 2] * p[p.size() - 1];
		if (p.size() > 2) psum *= p[p.size() - 3];
	}
	if (psum > msum) sum = psum;
	else sum = msum;
	if (sum < 0 && zero == 1) sum = 0;
	cout << sum;
	return 0;
}