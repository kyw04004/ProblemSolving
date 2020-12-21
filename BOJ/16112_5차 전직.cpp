#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
#include<deque>
#include<stack>
#include<functional>
#include<vector>
#include<cmath>
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
using namespace std;
typedef long long ll;
ll n, k, arr[300005],sum;
int main() {
	cin >> n >> k;
	for (ll i = 0; i < n; i++) cin >> arr[i];
	sort(arr, arr + n);
	for (ll i = 0; i < n; i++) {
		if (i < k) sum += i * arr[i];
		else sum += k*arr[i];
	}
	cout << sum;
	return 0;
}