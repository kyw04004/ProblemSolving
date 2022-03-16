#include<iostream>
#include<map>
#include<queue>
#include<cstring>
#include<string>
#include<algorithm>
#include<functional>
#include<vector>
#include<stack>
#include<cmath>
#include<unordered_map>
using namespace std;
typedef long long ll;
vector<int> lis;
int N, swit[10005], bulb[10005], arr[10005], match[10005], parent[10005];
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> swit[i];
	for (int i = 1; i <= N; i++) {
		int num; cin >> num;
		bulb[num] = i;
		match[i] = num;
	}
	for (int i = 1; i <= N; i++)
		arr[i] = bulb[swit[i]];
	lis.push_back(arr[1]);
	parent[1] = 1;
	for (int i = 2; i <= N; i++) {
		if (lis.back() < arr[i]) {
			lis.push_back(arr[i]);
			parent[i] = lis.size();
		}
		else {
			int target = 0;
			int left = 0, right = lis.size() - 1;
			while (left <= right) {
				int mid = (left + right) / 2;
				if (arr[i] <= lis[mid]) {
					target = mid;
					right = mid - 1;
				}
				else left = mid + 1;
			}
			lis[target] = arr[i];
			parent[i] = target + 1;
		}
	}
	vector<int> output;
	int idx = lis.size();
	cout << idx << '\n';
	for (int i = N; i >= 1; i--) {
		if (idx == 0) break;
		if (parent[i] == idx) {
			output.push_back(match[arr[i]]);
			idx--;
		}
	}
	sort(output.begin(), output.end());
	for (int i = 0; i < output.size(); i++)
		cout << output[i] << ' ';
	return 0;
}