#include<stdio.h>
#include<cstring>
#include<algorithm>
#include<string>
#include<iostream>
#include<stack>
#include<vector>
#include<queue>
#include<functional>
#include<cmath>
#include<map>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll t, n,sum;
int main() {
	scanf("%lld", &t);
	while (t--)
	{
		scanf("%lld", &n);
		sum = 0;
		while (sum % 2 == 0)
		{
			sum = 0;
			ll com = n;
			while (com > 0)
				sum += (com % 10), com /= 10;
			n *=2;
		}
		n -= (n/2);
		printf("%lld\n", n);
	}
	return 0;
}