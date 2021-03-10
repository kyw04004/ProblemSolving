#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<functional>
#include<stack>
#include<map>
using namespace std;
typedef long long ll;
int n, ans, arr[2005];
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> arr[i];
	for (int i = 1; i <= n; i++) {
		vector<int> v1, v2;
		int Max = 0;
		v1.push_back(arr[i]);
		for (int j = i + 1; j <= n; j++) {
			if (v1.back() < arr[j]) v1.push_back(arr[j]);
			else if(arr[i] < arr[j]){
				auto it = lower_bound(v1.begin(), v1.end(), arr[j]);
				*it = arr[j];
			}
		}
		Max = v1.size();
		v2.push_back(arr[i]);
		for (int j = i+1; j <= n; j++) {
			if (v2.back() > arr[j]) v2.push_back(arr[j]);
			else if (arr[i] > arr[j]) {
				int index;
				int left = 0, right = v2.size() - 1;
				while (left <= right) {
					int mid = (left + right) / 2;
					if (v2[mid] > arr[j]) {
						left = mid + 1;
					}
					else {
						index = mid;
						right = mid - 1;
					}
				}
				v2[index] = arr[j];
			}
		}
		Max += v2.size();
		ans = max(Max - 1, ans);
	}
	cout << ans;
	return 0;
}