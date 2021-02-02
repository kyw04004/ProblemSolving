//LIS - nlogn(only size)
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
int n, arr[1000005];
vector<int> ans;
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	ans.push_back(-1000000001);
	for (int i = 0; i < n; i++) {
		if (ans.back() < arr[i])
			ans.push_back(arr[i]);
		else {
			auto it = lower_bound(ans.begin(), ans.end(), arr[i]);
			*it = arr[i];
		}
	}
	cout << ans.size() - 1 << '\n';
	return 0;
}