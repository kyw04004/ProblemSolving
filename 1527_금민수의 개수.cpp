#include<cstring>
#include<string>
#include<algorithm>
#include<iostream>
#include<stdio.h>
#include<vector>
#include<cmath>
using namespace std;
int ans, st, en, cnt;
void go(int en, int sum,int s)
{
	if (sum > en || s >= 10)
	{
		cnt--;
		return;
	}
	cnt += 2;
	go(en, sum * 10 + 4,s+1);
	go(en, sum * 10 + 7,s+1);
}
int main()
{
	scanf("%d %d", &st, &en);
	go(en,0,0);
	ans += cnt;
	cnt = 0;
	go(st - 1, 0, 0);
	ans -= cnt;
	printf("%d", ans);
	return 0;
}