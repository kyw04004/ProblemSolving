#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
#include<map>
#include<vector>
#include<functional>
#include<queue>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
int N, c[53][53];
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N;
	for (int i = 0; i <= 52; i++) c[i][0] = 1;
	for (int i = 1; i <= 52; i++)
		for (int j = 1; j <= i; j++)
			c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % 10007;
	int ans = 0;
	for (int i = 1; 4 * i <= N; i++) {
		if (i % 2 == 1) ans = (ans + c[13][i] * c[52 - 4 * i][N - 4 * i]) % 10007;
		else ans = (ans - c[13][i] * c[52 - 4 * i][N - 4 * i] % 10007 + 10007) % 10007;
	}
	cout << ans;
	return 0;
}