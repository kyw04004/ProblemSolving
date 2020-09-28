#include<iostream>
#include<vector>
#include<string>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<queue>
using namespace std;
typedef long long ll;
int n, arr[1001],com[1001],ans;
int gcd(int a, int b) {
	if (b == 0) return a;
	else return gcd(b, a%b);
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	sort(arr, arr + n);
	for (int i = 1; i < n; i++) com[i] = arr[i] - arr[i - 1];
	ans = com[1];
	for (int i = 2; i < n; i++) ans = gcd(ans, com[i]);
	if (n == 1) ans = arr[0];
	cout << ans;
	return 0;
}