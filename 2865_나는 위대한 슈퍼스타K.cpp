#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<functional>
#include<queue>
using namespace std;
typedef long long ll;
priority_queue<double, vector<double>, less<double>> pq;
int main()
{
	double n, m, k,sum=0;
	double arr[101][101] = { 0, };
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			double num, ability;
			cin >> num >> ability;
			arr[i][(int)num] = ability;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		double Max = 0;
		for (int j = 1; j <= m; j++)
			Max=max(Max,arr[j][i]);
		pq.push(Max);
	}
	while (!pq.empty()&&k)
	{
		sum += pq.top();
		pq.pop();
		k--;
	}
	printf("%0.1lf\n", sum);
	return 0;
}