#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<functional>
#include<queue>
using namespace std;
typedef long long ll;
int main()
{
	int i,K, L, N,cnt=0,ok=0,cp=0,chk=0;
	char Time[10001];
	cin >> K >> L >> N;
	for (i = 1; i <= N; i++)
		scanf(" %1c", &Time[i]);
	for (i = 1; i <= N; i++)
	{
		if (Time[i] == '1')
		{
			cp = 0;
			cnt++;
			if (cnt >= K)
				ok = 1;
		}
		else
		{
			if (ok == 1)
			{
				cp++;
				if (cp == L)
				{
					chk = 1;
					printf("%d\n", i);
					cnt = cp = ok = 0;
				}
			}
			else
				cnt = 0;
		}
	}
	if (ok == 1)
	{
		chk = 1;
		printf("%d\n", i-1+ L - cp);
	}
	if (chk == 0)
		printf("NIKAD");
	return 0;
}