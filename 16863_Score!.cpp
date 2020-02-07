#include<cstring>
#include<string>
#include<algorithm>
#include<iostream>
#include<stdio.h>
#include<vector>
#include<cmath>
using namespace std;
int totala, totalh,alead,hlead, ns, nb, ls, lb, hscore, ascore;
char c,leadteam;
int main()
{
	int n;
	scanf("%d",&n);
	for (int i = 0; i < n; i++)
	{
		scanf(" %c",&c);
		if (totala > totalh)
			leadteam = 'a';
		if (totala < totalh)
			leadteam = 'h';
		if (totala == totalh)
			leadteam = ' ';
		if (c == 'H')
		{
			scanf("%d", &hscore);
			totalh += hscore;
		}
		if (c == 'A')
		{
			scanf("%d", &ascore);
			totala += ascore;
		}
		scanf("%d:%d", &ns, &nb);
		if (leadteam == 'a')
			alead += (60 * ns + nb) - (60 * ls + lb);
		if (leadteam == 'h')
			hlead += (60 * ns + nb) - (60 * ls + lb);
		ls = ns, lb = nb;
	}
	if (totalh > totala)
	{
		printf("H");
		hlead += (60 * 32) - (60*ls+lb);
	}
	else
	{
		printf("A");
		alead += (60 * 32) - (60 * ls + lb);
	}
	if(hlead%60<10)
		printf(" %d:0%d", hlead / 60, hlead % 60);
	else
		printf(" %d:%d", hlead / 60, hlead % 60);
	if (alead % 60 < 10)
		printf(" %d:0%d", alead / 60, alead % 60);
	else
		printf(" %d:%d", alead / 60, alead % 60);
	return 0;
}