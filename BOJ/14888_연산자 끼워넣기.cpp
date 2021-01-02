#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<cmath>
#include<queue>
#include<functional>
using namespace std;
typedef long long ll;
int n, Max= -1e9-1, Min = 1e9+1, arr[15];
int p, mi, mu, d;
void go(int depth, int val, int p, int mi, int mu, int d) {
	if (depth == n) {
		Max = max(Max, val);
		Min = min(Min, val);
		return;
	}
	if( p > 0) go(depth + 1, val + arr[depth + 1],  p-1, mi, mu, d);
	if (mi > 0) go(depth + 1, val - arr[depth + 1],  p, mi-1, mu, d);
	if (mu > 0) go(depth + 1, val * arr[depth + 1],  p, mi, mu-1, d);
	if (d > 0) go(depth + 1, val / arr[depth + 1],  p, mi, mu, d-1);
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> arr[i];
	cin >> p >> mi >> mu >> d;
	go(1,arr[1],p,mi,mu,d);
	cout << Max << '\n' << Min;
	return 0;
}