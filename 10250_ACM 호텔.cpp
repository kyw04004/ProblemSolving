#include<stdio.h>
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
#include<functional>
#include<vector>
#include<stack>
using namespace std;
int main()
{
	int n, H, W, N, cnt = 1;
	int arr[100][100];
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> H >> W >> N;
		cnt = 1;
		memset(arr, 0, sizeof(arr));
		for (int i = 1; i <= W; i++)
			for (int j = 1; j <= H; j++)
				arr[j][i] = cnt++;
		for (int i = 1; i <= W; i++)
			for (int j = 1; j <= H; j++)
				if (arr[j][i] == N)
				{
					if (i >= 10)
						printf("%d%d\n", j, i);
					else
						printf("%d0%d\n", j, i);
					i = W + 1;
				}
	}
	return 0;
}