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
struct score {
	int p;
	int w;
};
int n,m,j;
long long sum;
int pocket[300001];
priority_queue<int,vector<int>,less<int>> pq;
bool compare(score a, score b)
{
	if (a.w != b.w) return a.w < b.w;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n>>m;
	score* s=new score[300001];
	for (int i = 0; i < n; i++)
		cin>> s[i].w >> s[i].p;
	for (int i = 0; i < m; i++)
		cin >> pocket[i];
	sort(s, s + n, compare);
	sort(pocket, pocket + m);
	for (int i = 0; i < m; i++)
	{
		while (j < n&&s[j].w <= pocket[i])
			pq.push(s[j++].p);
		if (!pq.empty())
		{
			sum += pq.top();
			pq.pop();
		}
	}
	printf("%lld\n", sum);
	delete[] s;
	return 0;
}