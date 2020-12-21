#include<stdio.h>
using namespace std;
int arr[1001];
int main()
{
	int n, k;
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i++)
		arr[i] = 1;
	int i = 2;
	int cnt = 0;
	for (int j = 2; j <= n; j++)
	{
		i = j;
		while (i <= n)
		{
			if (arr[i] == 1)
			{
				arr[i] = 0;
				cnt++;
			}
			if (cnt == k)
			{
				printf("%d\n", i);
				return 0;
			}
			i += j;
		}
	}
	return 0;
}
