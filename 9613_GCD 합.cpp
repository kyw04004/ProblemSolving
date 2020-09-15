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
ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a%b);
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		ll n, arr[101],sum=0;
		cin >> n;
		for (int i = 0; i < n; i++) cin >> arr[i];
		for (int i = 0; i < n - 1; i++)
			for (int j = i + 1; j < n; j++)
				sum += gcd(arr[i], arr[j]);
		cout << sum << "\n";
	}
	return 0;
}