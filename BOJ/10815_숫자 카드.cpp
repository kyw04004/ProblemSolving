#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<stdio.h>
#include<math.h>
#include<map>
using namespace std;
map <int, int> m;
int com[500001];
int main()
{
	int n,t;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int a;
		scanf("%d", &a);
		m[a] = 1;
	}
	scanf("%d", &t);
	for (int i = 0; i < t; i++)
		scanf("%d", &com[i]);
	for (int i = 0; i < t; i++)
	{
		if (m[com[i]] == 1)
			printf("1 ");
		else
			printf("0 ");
	}
	return 0;
}