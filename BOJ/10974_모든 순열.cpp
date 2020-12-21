#include<cstring>
#include<string>
#include<algorithm>
#include<iostream>
#include<stdio.h>
#include<vector>
#include<cmath>
using namespace std;
int output[9],chk[9], n;
void go(int cnt)
{
	if (cnt == n)
	{
		for (int i = 0; i < n; i++)
			printf("%d ", output[i]);
		printf("\n");
		return;
	}
	for (int i = 1; i <= n; i++)
	{
		if (chk[i] == 0)
		{
			chk[i] = 1;
			output[cnt] = i;
			go(cnt + 1);
			chk[i] = 0;
		}
	}
}
int main()
{
	cin >> n;
	go(0);
	return 0;
}