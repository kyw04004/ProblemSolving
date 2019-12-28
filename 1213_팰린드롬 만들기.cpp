#include<stdio.h>
#include<cstring>
#include<string>
#include<algorithm>
#include<iostream>
#include<queue>
#include<vector>
using namespace std; 
int main()
{
	char name[51];
	int odd = 0;
	int alpha[26] = { 0 };
	int one;
	scanf("%s", name);
	for (int i = 0; i < strlen(name); i++)
		alpha[name[i] - 'A']++;
	for (int i = 0; i < 26; i++)
		if (alpha[i] % 2 == 1)
		{
			odd++;
			one = i;
		}
	if (odd > 1)
	{
		printf("I'm Sorry Hansoo");
		return 0;
	}
	else
	{
		if (odd == 1)
		{
			if (strlen(name) % 2 == 0)
			{
				printf("I'm Sorry Hansoo");
				return 0;
			}
			else
			{
				name[strlen(name) / 2] = one + 'A';
				alpha[one]--;
			}
		}
		for(int i=0;i<strlen(name)/2;i++)
			for (int j = 0; j < 26; j++)
			{
				while(alpha[j] != 0)
				{
					name[i] = j + 'A';
					name[strlen(name)-i-1] = j + 'A';
					alpha[j]--;
					alpha[j]--;
					i++;
				}	
			}
	}
	printf("%s", name);
	return 0;
}