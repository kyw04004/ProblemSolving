#include<iostream>
#include<stdio.h>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
typedef long long ll;
int n, lef, rig, blef, brig,sum;
int main()
{
	scanf("%d", &n);
	scanf("%d %d", &lef, &rig);
	sum += (rig - lef);
	brig = rig, blef = lef;
	for (int i = 2; i <= n; i++)
	{
		scanf("%d %d", &lef, &rig);
		sum += (rig - lef);
		if (brig > lef)
		{
			if (brig > rig)
				sum -= (rig - lef);
			else
				sum -= (brig - lef);
		}
		brig = max(brig,rig), blef = max(brig,lef);
	}
	printf("%d", sum);
	return 0;
}
