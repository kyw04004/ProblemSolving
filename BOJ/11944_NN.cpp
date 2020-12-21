#include<stdio.h>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<stdlib.h>
#include<iostream>
#include<stack>
#include<functional>
using namespace std;
int n, m, cnt, time;
int main()
{
	int m,b;
	string str2;
	char str1[5];
	cin >> str1 >> m;
	b = atoi(str1);
	int cnt = strlen(str1)*b;
	if (cnt > m)
		cnt = m;
	for (int i = 0; i < b; i++)
		str2 += str1;
	for (int i = 0; i < cnt; i++)
		cout << str2[i];
	return 0;
}
