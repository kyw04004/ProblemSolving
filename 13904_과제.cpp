#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
#include<functional>
using namespace std;
pair<int, int> arr[1001];
priority_queue<int, vector<int>, greater<int>> pq;
int n, cnt, sum;
bool compare(pair<int,int> a, pair<int,int> b)
{
	if (a.first != b.first) return a.first < b.first;
	else if (a.second != b.second) return a.second > b.second;
}
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		scanf("%d %d", &arr[i].first, &arr[i].second);
	sort(arr, arr + n, compare);
	sum = arr[0].second;
	pq.push(arr[0].second);
	cnt++;
	for (int i = 1; i < n; i++)
	{
		if (arr[i].first > cnt)
		{
			sum += arr[i].second;
			pq.push(arr[i].second);
			cnt++;
		}
		else if (arr[i].second > pq.top())
		{
			sum -= pq.top();
			pq.pop();
			sum += arr[i].second;
			pq.push(arr[i].second);
		}
	}
	printf("%d", sum);
	return 0;
}