#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
typedef long long ll;
int n;
ll sum;
pair<ll, ll> a[10001];
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		scanf("%lld %lld", &a[i].first, &a[i].second);
		if (i <= 1) continue;
		ll x = (a[i-1].first - a[0].first) * (a[i].second - a[0].second);
		x -= (a[i].first - a[0].first) * (a[i-1].second - a[0].second);
		sum += x;
	}
	sum = abs(sum);
	printf("%0.1lf", (double)sum / 2);
	return 0;
}