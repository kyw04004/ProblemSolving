#include<stdio.h>
#include<cmath>
#include<cstring>
#include<string>
#include<iostream>
#include<vector>
#include<queue>
#include<functional>
using namespace std;
typedef pair<int, int> P;
queue <P> q;
void honoi(int h, int a, int b, int c)
{
	if (h == 1)
		printf("%d %d\n", a, c);
	else
	{
		honoi(h - 1, a, c, b);
		printf("%d %d\n", a, c);
		honoi(h - 1, b, a, c);
	}
}
int main() {
	int n,ans=1;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		ans *= 2;
	printf("%d\n", ans - 1);
	honoi(n, 1, 2, 3);
	return 0;
}