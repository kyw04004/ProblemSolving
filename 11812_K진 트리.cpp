#include<stdio.h>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
ll n, k, q,a,b,cnt;
int main() {
	scanf("%lld %lld %lld",&n,&k,&q);
	while (q--)
	{
		cnt = 0;
		scanf("%lld %lld", &a, &b);
		a -= 1, b -= 1;
		if (k == 1)
		{
			printf("%lld\n", abs(a - b));
			continue;
		}
		while (a != b)
		{
			if (a > b)
				a = (a - 1) / k;
			else
				b = (b - 1) / k;

			cnt++;
		}
		printf("%lld\n",cnt);
	}
	return 0;
}


