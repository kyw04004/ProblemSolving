#include<stdio.h>
int main()
{
	long long L = 1, P = 1, V = 1, ans, i = 0;
	while (1)
	{
		i++;
		scanf("%lld %lld %lld", &L, &P, &V);
		if (L == 0 && P == 0 && V == 0)
			break;
		ans = (V / P)*L;
		if (V%P <= L)
			ans += V % P;
		else
			ans += L;
		printf("Case %lld: %lld\n", i, ans);
	}
	return 0;
}