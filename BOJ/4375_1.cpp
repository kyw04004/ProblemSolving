#include<stdio.h>
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
#include<functional>
#include<stack>
using namespace std;
int sum,cnt;
int main() {
	int n;
	while (~scanf("%d", &n))
	{
		sum = 0, cnt = 0;
		while (1)
		{
			sum = (sum % n) * (10 % n) + (1 % n);
			cnt++;
			if (sum % n == 0)
				break;
		}
		printf("%d\n", cnt);
	}
	return 0;
}