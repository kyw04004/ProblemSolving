#include<cstring>
#include<string>
#include<algorithm>
#include<iostream>
#include<stdio.h>
#include<vector>
#include<cmath>
using namespace std;
int output[14],chk[14], n,input[14];
void go(int cnt)
{
	if (cnt == 6)
	{
		for (int i = 0; i < 6; i++)
			printf("%d ", output[i]);
		printf("\n");
		return;
	}
	for (int i = 1; i <= n; i++)
	{
		if (chk[i] == 0)
		{
			if (output[cnt - 1] < input[i])
			{
				chk[i] = 1;
				output[cnt] = input[i];
				go(cnt + 1);
				chk[i] = 0;
			}
		}
	}
}
int main()
{
	while (1)
	{
		cin >> n;
		if (n == 0)
			break;
		for (int i = 1; i <= n; i++)
			scanf(" %d", &input[i]);
		go(0);
		printf("\n");
	}
	return 0;
}