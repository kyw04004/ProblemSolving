#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<cmath>
#include<queue>
#include<functional>
#include<stack>
#include<map>
#include<bitset>
using namespace std;
typedef long long ll;
int n, arr[205], dp[205];
int Lis(int index) {
	if (index == n) return 0;
	int &ret = dp[index];
	if (ret != -1) return ret;
	ret = 0;
	for (int i = index + 1; i <= n; i++)
		if (arr[index] < arr[i])
			ret = max(ret, Lis(i) + 1);
	return ret;
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	memset(dp, -1, sizeof(dp));
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> arr[i];
	cout << n - Lis(0);
	return 0;
}