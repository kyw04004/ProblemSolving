#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<cmath>
#include<map>
#include<set>
#include<queue>
using namespace std;
typedef long long ll;
ll N, a[21], b[21];
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N;
	for (int i = 0; i < N; i++) cin >> a[i];
	for (int i = 0; i < N; i++) cin >> b[i];
	sort(a, a + N);
	sort(b, b + N);
	ll sum = 1;
	for (int i = 0; i < N; i++) {
		ll cnt = 0;
		for (int j = 0; j < N; j++) {
			if (a[j] <= b[i]) cnt++;
			else break;
		}
		sum *= (cnt - i);
	}
	cout << sum;
	return 0;
}