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
		int n, k, arr[101];
		cin >> n >> k;
		for (int i = 1; i <= n; i++) cin >> arr[i];
		for (int i = 1; i <= n-1;) {
			if (arr[i] >= arr[i + 1]) i++;
			else {
				k -= 1;
				arr[i] += 1;
				if (k <= 0) {
					cout << i << '\n';
					break;
				}
				else i = 1;
			}
		}
		if (k > 0) cout << "-1\n";
	}
	return 0;
}