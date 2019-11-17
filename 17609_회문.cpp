#include<iostream>
#include<stdio.h>
#include<string>
#include<cstring>
#include<algorithm>
#include<queue>
#include<stdlib.h>
using namespace std;
int main()
{
	int n;
	string str;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int cnt = 2;
		cin >> str;
		int a = 0;
		int b = str.size() - 1;
		for (int j = 1; j <= str.size() / 2; j++)
		{
			if (str[a] == str[b])
				cnt = 0;
			else
			{
				cnt = 2;
				break;
			}
			a++;
			b--;
		}
		if (cnt == 2)
		{

			string str2 = str;
			str2.erase(str2.begin() + a);
			int c = 0;
			int d = str2.size() - 1;
			for (int k = 1; k <= str2.size() / 2; k++)
			{
				if (str2[c] == str2[d])
					cnt = 1;
				else
				{
					cnt = 2;
					k = str2.size() + 1;
				}
				c++;
				d--;
			}
			if (cnt != 1)
			{
				str2 = str;
				str2.erase(str2.begin() + b);
				c = 0;
				d = str2.size() - 1;
				for (int k = 1; k <= str2.size() / 2; k++)
				{
					if (str2[c] == str2[d])
						cnt = 1;
					else
					{
						cnt = 2;
						k = str2.size() + 1;
					}
					c++;
					d--;
				}
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
}