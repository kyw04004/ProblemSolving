#include<cstring>
#include<string>
#include<algorithm>
#include<iostream>
#include<stdio.h>
#include<vector>
#include<cmath>
using namespace std;
int n,s,cnt,Min=5e5,t;
int seq[10];
void go(int sum,int depth)
{
	if (depth==cnt+1)
	{
		if(Min > abs(n-sum)+depth)
			Min = abs(n-sum)+depth;
		return;
	}
	if (depth > 0)
		if (Min > abs(n - sum)+depth)
			Min = abs(n - sum)+depth;
	for (int k = 0; k <= 9; k++)
		if (seq[k] != -1)
			go(sum * 10 + k, depth + 1);
}
int main()
{
	scanf(" %d %d", &n,&s);
	t = n;
	if (n == 0)
		cnt = 1;
	while (t > 0)
	{
		t /= 10;
		cnt++;
	}
	for (int i = 1; i <= s; i++)
	{
		int a;
		scanf(" %d", &a);
		seq[a] = -1;
	}
	go(0, 0);
	Min = min(Min,abs(n - 100));
	printf("%d", Min);
	return 0;
}