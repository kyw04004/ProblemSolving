#include<cstring>
#include<string>
#include<algorithm>
#include<iostream>
#include<stdio.h>
#include<vector>
#include<cmath>
using namespace std;
int output[21],chk[21],input[21],n,m,sum,s;
void go(int now, int cnt,int sum)
{
	if (now == n + 1)
	{
		if (cnt > 0 && sum == m)
			s++;
		return;
	}
	go(now + 1, cnt, sum);
	go(now + 1, cnt + 1, sum + input[now]);
}
int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		scanf(" %d", &input[i]);
	go(1, 0,0);
	printf("%d", s);
	return 0;
}