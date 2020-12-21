#include<stdio.h>
#include<cstring>
#include<algorithm>
#include<string>
#include<iostream>
#include<stack>
#include<vector>
#include<queue>
#include<functional>
#include<cmath>
#include<map>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
stack <P> s;
int n,sum;
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		int a, score, time;
		scanf("%d", &a);
		if (a == 1)
		{
			scanf("%d %d", &score, &time);
			time--;
			if (time == 0)
				sum += score;
			else
				s.push({ score,time });
		}
		if (a == 0)
		{
			if (!s.empty())
			{
				s.top().second--;
				if (s.top().second == 0)
				{
					sum += s.top().first;
					s.pop();
				}
			}
		}
	}
	printf("%d", sum);
	return 0;
}