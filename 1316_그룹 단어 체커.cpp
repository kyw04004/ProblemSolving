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
int alpha[30];
int main()
{
	int t;
	string str;
	scanf("%d", &t);
	int ans = t;
	while (t--)
	{
		memset(alpha, 0, sizeof(alpha));
		cin >> str;
		for (int i = 0; i < str.size(); i++)
		{
			if (alpha[str[i]-'a'] == 0)
				alpha[str[i] - 'a'] = 1;
			else if (str[i - 1] == str[i])
				continue;
			else
			{
				ans--;
				i = str.size() + 1;
			}

		}
	}
	printf("%d\n", ans);
	return 0;
}
