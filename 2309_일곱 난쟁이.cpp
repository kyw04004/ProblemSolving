#include<cstring>
#include<string>
#include<algorithm>
#include<iostream>
#include<stdio.h>
#include<vector>
#include<cmath>
using namespace std;
int tall[9],sum,j,ok;
int chk[9];
void go(int idx,int cnt,int sum)
{
	if (cnt == 7 && sum == 100)
	{
		ok = 1;
		for (int i = 0; i < 9; i++)
			if (chk[i] == 1)
				printf("%d\n", tall[i]);
		return;
	}
	for (int i = idx; i < 9; i++)
	{
		if (ok == 1)
			return;
		if (chk[i] == 1)
			continue;
		chk[i] = 1;
		go(i,cnt + 1, sum + tall[i]);
		chk[i] = 0;
	}
}
int main()
{
	for (int i = 0; i < 9; i++)
		scanf("%d", &tall[i]);
	sort(tall, tall + 9);
	go(0,0,0);
	return 0;
}