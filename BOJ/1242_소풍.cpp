#include<stdio.h>
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
#include<functional>
#include<stack>
using namespace std;
int main() {
	int n, m, k, point = 0, ans = 1;
	scanf("%d %d %d", &n, &m, &k);
	while (1)
	{
		point += m;
		while (point > n)
			point -= n;
		if (point == k)
			break;
		if (point < k)
			k--;
		n--;
		point--;
		ans++;
	}
	printf("%d", ans);
	return 0;
}