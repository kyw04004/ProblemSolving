#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
using namespace std;
typedef long long ll;
ll N, B, arr[41][6][6], ans[6][6];
void calculate(ll n) {
	for (ll i = 1; i <= N; i++)
		for (ll j = 1; j <= N; j++) {
			for (ll k = 1; k <= N; k++)
				arr[n+1][i][j] += arr[n][i][k] * arr[n][k][j];
			arr[n+1][i][j] %= 1000;
		}
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N >> B;
	for (ll i = 1; i <= N; i++)
		for (ll j = 1; j <= N; j++)
			cin >> arr[0][i][j];
	for (ll i = 0; i <= 39; i++) calculate(i);
	for (ll i = 1; i <= N; i++) ans[i][i] = 1;
	while (B) {
		ll e = 0;
		ll val = 1;
		while (val <= B) {
			val *= 2;
			e++;
		}
		val /= 2;
		e--;
		ll com[6][6];
		for (ll i = 1; i <= N; i++)
			for (ll j = 1; j <= N; j++)
				com[i][j] = ans[i][j], ans[i][j] = 0;
		for (ll i = 1; i <= N; i++)
			for (ll j = 1; j <= N; j++) {
				for (ll k = 1; k <= N; k++)
					ans[i][j] += com[i][k] * arr[e][k][j];
				ans[i][j] %= 1000;
			}
		B -= val;
	}
	for (ll i = 1; i <= N; i++) {
		for (ll j = 1; j <= N; j++)
			cout << ans[i][j] << ' ';
		cout << '\n';
	}
	return 0;
}