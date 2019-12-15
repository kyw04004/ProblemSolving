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
	int t1, t2, ch;
	cin >> t1 >> t2 >> ch;
	if (t1 + t2 >= 2 * ch)
		printf("%d", (t1 + t2) - 2 * ch);
	else
		printf("%d", t1 + t2);
	return 0;
}