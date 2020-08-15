#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<functional>
#include<queue>
typedef long long ll;
using namespace std;
ll t, n, m, sum,chk[31];
int main() {
	cin >> t;
	while (t--) {
		memset(chk, 0, sizeof(chk));
		sum = 1;
		cin >> n >> m;
		for (int i = m; i >= m - n + 1; i--) {
			sum *= i;
			for (int j = 1; j <= n; j++)
				if (!chk[j] && sum%j == 0)
					chk[j]=1, sum /= j;
		}
		printf("%lld\n", sum);
	}
	return 0;
}