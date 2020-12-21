#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
#include<functional>
using namespace std;
typedef long long ll;
ll t, n, arr[100001];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> t;
	while (t--) {
		ll total = 0;
		ll ans = 0;
		ll sum = 0;
		cin >> n;
		memset(arr, 0, sizeof(arr));
		for (ll i = 1; i <= n; i++) {
			cin >> arr[i];
			total += arr[i];
		}
		ll si=1;
		ll en;
		if (arr[1] > total) {
			cout << "No" << "\n";
			continue;
		}
		for (ll i = 1; i <= n; i++) {
			sum += arr[i];
			if (sum <= 0) sum=0, si = i+1;
			if (sum > ans) {
				ans = sum;
				en = i;
			}
		}
		if ((total == ans && si==1 && en == n) || (total > ans)) cout << "Yes" << "\n";
		else cout << "No" << "\n";
	}
	return 0;
}