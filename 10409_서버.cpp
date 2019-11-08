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
	int n, M,cnt=0,sum=0;
	int s[51];
	cin >> n >> M;
	for (int i = 1; i <= n; i++)
	{
		cin >> s[i];
		sum += s[i];
		if (sum <= M)
			cnt++;
	}
	printf("%d", cnt);
	return 0;
}