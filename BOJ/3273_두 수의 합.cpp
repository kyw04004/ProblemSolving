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
int n, arr[100005], x, ans;
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	sort(arr, arr + n);
	cin >> x;
	int sindex = 0, eindex = n - 1;
	while (sindex < eindex) {
		if (arr[sindex] + arr[eindex] > x) {
			eindex--;
		}
		else if (arr[sindex] + arr[eindex] == x) {
			ans++;
			sindex++;
			eindex--;
		}
		else {
			sindex++;
		}
	}
	cout << ans;
	return 0;
}