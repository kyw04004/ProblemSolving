#include<cstring>
#include<string>
#include<algorithm>
#include<iostream>
#include<vector>
#include<cmath>
#include<queue>
using namespace std;
typedef long long ll;
ll n, arr[250001];
int main() {
	while (1) {
		ll Max, index = 1, sum;
		scanf("%lld", &n);
		if (n == 0) break;
		for (int i = 1; i <= n; i++) cin >> arr[i];
		sum = arr[1];
		Max = sum;
		for (ll i = 2; i <= n; i++) {
			sum += arr[i];
			if (sum < 0) {
				sum = arr[i];
				index = i;
				Max = max(Max, sum);
				continue;
			}
			while (sum <= (sum - arr[index]) && index < n) {
				sum -= arr[index];
				index++;
			}
			Max = max(Max, sum);
		}
		printf("%lld\n", Max);
	}
	return 0;
}