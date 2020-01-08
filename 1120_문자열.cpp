#include<cstring>
#include<string>
#include<algorithm>
#include<iostream>
#include<stdio.h>
#include<vector>
#include<cmath>
using namespace std;
int main()
{
	string s1, s2;
	int Min=51,cnt = 0;
	cin >> s1 >> s2;
	int china = s2.size() - s1.size();
	if (china>0)
	{
		for (int i = 0; i <= china; i++)
		{
			cnt = 0;
			for (int j = i; j < i + s1.size(); j++)
			{
				if (s1[j-i] != s2[j])
					cnt++;
			}
			if (cnt < Min)
				Min = cnt;
		}
	}
	else
	{
		for (int i = 0; i < s1.size(); i++)
			if (s1[i] != s2[i])
				cnt++;
		Min = cnt;
	}
	printf("%d", Min);
	return 0;
}