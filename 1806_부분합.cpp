#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
#include<functional>
using namespace std;
typedef long long ll;
int n, sum, arr[100001],Min=1e9;
int main() {
	cin >> n >> sum;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		arr[i] += arr[i - 1];
	}
	for (int i = 1; i <= n; i++) {
		if (arr[i] < sum) continue;
		else {
			int left = 0, right = i - 1;
			while (left <= right) {
				int mid = (left + right) / 2;
				if (arr[i] - arr[mid] >= sum) {
					Min = min(Min, i - mid);
					left = mid + 1;
				}
				else right = mid -1;
			}
		}
	}
	if(Min==1e9) cout << 0 << "\n";
	else cout << Min << "\n";
	return 0;
}