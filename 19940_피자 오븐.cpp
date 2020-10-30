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
int Min,n,aa,ab,ac,ad,ae;
void go(int a, int b, int c, int d, int e, int sum, int cnt) {
	if (sum == 0) {
		if (Min > cnt) {
			Min = cnt;
			aa = a, ab = b, ac = c, ad = d, ae = e;
		}
		return;
	}
	if (sum > 35) go(a + 1, b, c, d, e, sum - 60, cnt + 1);
	else if (sum > 5) go(a, b + 1, c, d, e, sum - 10, cnt + 1);
	else if (sum < -5)go(a, b, c + 1, d, e, sum + 10, cnt + 1);
	else if (sum > 0)go(a, b, c, d + 1, e, sum - 1, cnt + 1);
	else if (sum < 0)go(a, b, c, d, e + 1, sum + 1, cnt + 1);
	return;
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		Min = 1e7;
		cin >> n;
		go(0, 0, 0, 0, 0, n, 0);
		printf("%d %d %d %d %d\n",aa,ab,ac,ad,ae);
	}
	return 0;
}