#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<functional>
#include<queue>
#include<vector>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n,sum=0;
		cin >> n;
		for (int i = 1; i < n; i++)
			if (n%i == 0)
				sum += i;
		if (sum == n)
			printf("Perfect\n");
		else if (sum > n)
			printf("Abundant\n");
		else
			printf("Deficient\n");
	}
	return 0;
}