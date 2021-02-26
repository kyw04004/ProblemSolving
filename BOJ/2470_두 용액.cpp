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
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n, arr[100005];
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	sort(arr, arr + n);
	int sindex = 0, eindex = n - 1;
	int com = 2e9+1;
	pair<int, int> ans;
	while (sindex < eindex) {
		int sum = arr[sindex] + arr[eindex];
		if (com > abs(sum)) {
			com = abs(arr[sindex] + arr[eindex]);
			ans = {arr[sindex], arr[eindex]};
		}
		if (sum < 0) sindex++;
		else eindex--;
	}
	cout << ans.first << ' ' << ans.second;
	return 0;
}