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
ll N, K, v[200005], Min = 1e18;
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N >> K;
	for (ll i = 0; i < N; i++) cin >> v[i];
	sort(v, v + N);
	for (ll i = 1; i < N; i++)
		Min = min(Min, (K - 1) / (v[0] * i + v[i] * (N - i)) + 1);
	cout << Min;
	return 0;
}

