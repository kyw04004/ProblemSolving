#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
#include<functional>
using namespace std;
typedef long long ll;
int N, K, Max, arr[1005], Mod;
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		Mod = max(Mod, arr[i]);
	}
	for (int i = 1; i <= Mod; i++) {
		int sum = 0;
		for (int j = 1; j <= N; j++) sum += arr[j] / i;
		if (sum >= K)
			Max = max(Max, i * (K / 2));
		else {
			vector<int> v;
			for (int j = 1; j <= sum; j++)
				v.push_back(i);
			for (int j = 1; j <= N; j++)
				v.push_back(arr[j]%i);
			sort(v.begin(), v.end());
			int val = 0, index = 0;
			for (int j = v.size() - 1; j >= 0; j--) {
				index++;
				if (index > K / 2 && index <= K) val += v[j];
			}
			Max = max(Max, val);
		}
	}
	cout << Max;
	return 0;
}