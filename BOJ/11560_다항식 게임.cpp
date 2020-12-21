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
ll t,k,n,dp[22][220],len=2,a=2;
int main() {
	cin >> t;
	dp[1][0] = 1, dp[1][1] = 1;
	for (int i = 2;i<=20;i++) { // k
		len += a;
		for (int j = 0; j<=i; j++)  // k+1번 반복더하기
			for (int k = 0; k < len; k++) 
				dp[i][j+k] += dp[i - 1][k];
		a++;
	}
	while (t--) {
		cin >> k >> n;
		printf("%lld\n",dp[k][n]);
	}
	return 0;
}