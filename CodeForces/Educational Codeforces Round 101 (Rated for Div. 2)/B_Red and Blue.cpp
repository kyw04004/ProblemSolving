#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
typedef long long ll;
int t;
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> t;
	while (t--) {
		int n, m,narr[101],marr[101],nsum=0,msum=0;
		int nMax = 0, mMax = 0;
		cin >> n;
		for (int i = 1; i <= n; i++) cin >> narr[i];
		cin >> m;
		for (int i = 1; i <= m; i++) cin >> marr[i];
		for (int i = 1; i <= n; i++) {
			nsum += narr[i];
			if (nMax < nsum) nMax = nsum;
		}
		for (int i = 1; i <= m; i++) {
			msum += marr[i];
			if (mMax < msum) mMax = msum;
		}
		cout << nMax + mMax << '\n';
	}
	return 0;
}