#include<cstring>
#include<string>
#include<algorithm>
#include<iostream>
#include<stdio.h>
#include<vector>
#include<cmath>
using namespace std;
int n,cnt;
string arr[101];
int alpha[27];
int chk[27];
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	for (int i = 1; i < n; i++)
	{
		for (int j = i + 1; j <= n; j++)
		{
			memset(alpha, 0,sizeof(alpha));
			memset(chk, 0, sizeof(chk));
			cnt++;
			for (int k = 0; k < arr[i].size(); k++)
			{
				if (arr[i].size() != arr[j].size())
				{
					cnt--;
					k += 100;
				}
				if (!alpha[arr[i][k] - 'a' + 1]&& !chk[arr[j][k] - 'a' + 1])
				{
					alpha[arr[i][k] - 'a' + 1] = arr[j][k] - 'a' + 1;
					chk[arr[j][k] - 'a' + 1] = 1;
				}
				else if(alpha[arr[i][k] - 'a' + 1] != arr[j][k] - 'a' + 1)
					{
						cnt--;
						k += 100;
					}
			}
		}
	}
	printf("%d", cnt);
	return 0;
}