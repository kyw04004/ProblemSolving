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
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		int ans = 0;
		int arr[105] = { 0, };
		for (int i = 1; i <= n; i++) {
			int a;
			cin >> a;
			arr[a]++;
		}
		int Max = 0;
		for (int i = 1; i <= n; i++)
			Max = max(Max, arr[i]);
		cout << Max << '\n';
	}
	return 0;
}
