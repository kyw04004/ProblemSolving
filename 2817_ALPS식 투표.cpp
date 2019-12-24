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
#include<stack>
using namespace std;
pair<int, char> arr[141];
struct sor {
	char c;
	int v;
	int s=0;
};
bool compare(sor a, sor b)
{
	if (a.c != b.c) return a.c < b.c;
}
int main()
{
	int X, N;
	struct sor p[11];
	cin >> X >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> p[i].c >> p[i].v;
		double chk = p[i].v;
		chk *= 100;
		chk /= X;
		if (chk < 5)
		{
			i--;
			N -= 1;
		}
	}
	for(int j=0;j<N;j++)
	for (int i = 1; i <=14; i++)
	{ 
		arr[14*j+i-1].first = p[j].v / i;
		arr[14 *j + i-1].second = p[j].c;
	}
	sort(arr, arr + N * 14);
	for(int j=0;j<N;j++)
		for (int i = N * 14 - 1; i >= N * 14 - 14; i--)
		{
			if (arr[i].second == p[j].c)
				p[j].s++;
		}
	sort(p, p + N, compare);
	for (int i = 0; i < N; i++)
		printf("%c %d\n", p[i].c,p[i].s);
	return 0;
}