#include<stdio.h>
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
int main()
{
	int arr[7];
	int chk[10] = { 0 };
	int N,i=0;
	scanf("%d", &N);
	if (N == 0)
	{
		printf("1");
		return 0;
	}
	while (N > 0)
	{
		arr[i] = N % 10;
		chk[N % 10]++;
		N /= 10;
		i++;
	}
	int sum = chk[6] + chk[9];
	if (sum % 2 == 0)
	{
		sum /= 2;
		chk[6] = sum;
		chk[9] = sum;
	}
	else
	{
		sum /= 2;
		sum += 1;
		chk[6] = sum;
		chk[9] = sum;
	}
	sort(chk, chk + 10);
	printf("%d", chk[9]);
	return 0;
}