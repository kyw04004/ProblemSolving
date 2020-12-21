#include<stdio.h>
#include<cmath>
#include<cstring>
#include<string>
#include<iostream>
using namespace std;
int arr[10000000],chk[10000000],ans,t,ichk[8];
string str;
void go(int depth, string s)
{
	int now = stoi(s);
	if (depth > str.size())
		return;
	if (arr[now] == 1 && chk[now] == 0)
		ans++;
	chk[now] = 1;
	for (int k = 0; k < str.size(); k++)
	{
		if (ichk[k] == 0)
		{
			ichk[k] = 1;
			go(depth + 1, s + str[k]);
			ichk[k] = 0;
		}
	}
}
int main() {
	for (int i = 2; i <= 9999999; i++)
		arr[i] = 1;
	for (int i = 2; i*i <= 9999999; i++)
		for (int j = i * i; j <= 9999999; j += i)
			arr[j] = 0;
	scanf("%d", &t);
	while (t--)
	{
		cin >> str;
		ans = 0;
		memset(chk, 0, sizeof(chk));
		memset(ichk, 0, sizeof(ichk));
		string s = "";
		for (int i = 0; i < str.size(); i++)
		{
			ichk[i] = 1;
			go(1, s + str[i]);
			ichk[i] = 0;
		}
		printf("%d\n", ans);
	}
	return 0;
}