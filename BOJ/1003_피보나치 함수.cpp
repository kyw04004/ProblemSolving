#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
int n, s;
long long dp0[41];
long long dp1[41];
int main()
{
	dp0[0] = 1;
	dp0[1] = 0;
	for (int i = 2; i <= 40; i++)
		dp0[i] = dp0[i - 1] + dp0[i - 2];
	dp1[0] = 0;
	dp1[1] = 1;
	for (int i = 2; i <= 40; i++)
		dp1[i] = dp1[i - 1] + dp1[i - 2];
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &s);
		printf("%lld% lld\n", dp0[s], dp1[s]);
	}
	return 0;
}