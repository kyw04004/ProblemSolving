#include<stdio.h>
#include<iostream>
#include<queue>
#include<cstring>
#include<string>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int a, b, c, d, p, m, n, cnt = 0;
	cin >> a >> b >> c >> d >> p >> m >> n;
	int sum1 = a + b;
	int sum2 = c + d;
	if (p%sum1 <= a && p%sum1 > 0)
		cnt++;
	if (p%sum2 <= c && p%sum2 > 0)
		cnt++;
	printf("%d\n", cnt);
	cnt = 0;
	if (m%sum1 <= a && m%sum1 > 0)
		cnt++;
	if (m%sum2 <= c && m%sum2 > 0)
		cnt++;
	printf("%d\n", cnt);
	cnt = 0;
	if (n%sum1 <= a && n%sum1 > 0)
		cnt++;
	if (n%sum2 <= c && n%sum2 > 0)
		cnt++;
	printf("%d\n", cnt);
	return 0;
}