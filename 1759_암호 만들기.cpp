#include<stdio.h>
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;
int n,m;
char arr[16];
char out[16];
int chk[16];
void go(int depth,int a, int b)
{
	if (depth == n&&a>=1&&b>=2)
	{
		for (int i = 1; i <= n; i++)
			printf("%c", out[i]);
		printf("\n");
		return;
	}
	for (int i = 0; i < m; i++)
	{
		if (chk[i] == 0&&out[depth]<arr[i])
		{
			chk[i] = 1;
			out[depth+1] = arr[i];
			if(arr[i]=='a'|| arr[i] == 'e'|| arr[i] == 'i'|| arr[i] == 'o'|| arr[i] == 'u')
				go(depth + 1,a+1,b);
			else
				go(depth + 1, a , b+1);
			chk[i] = 0;
		}
	}
}
int main()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++)
		scanf(" %c", &arr[i]);
	sort(arr, arr + m);
	go(0,0,0);
	return 0;
}
