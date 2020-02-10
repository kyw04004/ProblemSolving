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
int main()
{
	int n, m, k, t;
	scanf("%d %d %d", &n, &m, &k);
	for(int i=n;i>0;i--)
	{
		t = m % i;
		if (t == 0)
			t = i;
		k -= t;
		if (k == 0)
		{
			printf("%d", n - i + 1);
			break;
		}
		if (k < 0)
			k += i;
	}
	return 0;
}