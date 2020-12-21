#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
#include<functional>
using namespace std;
pair<int, int> arr[200001];
priority_queue<int, vector<int>, greater<int>> pq;
int main()
{
	int n,com1,com2,cnt=0;
	cin >> n;
	for (int i = 0; i < n; i++)
		scanf("%d %d", &arr[i].first, &arr[i].second);
	sort(arr, arr + n);
	com1 = arr[0].first, com2 = arr[0].second;
	pq.push(arr[0].second);
	int i = 1;
	while(i<n)
	{
		if (pq.top() > arr[i].first)
		{
			pq.push(arr[i].second);
			cnt = max(cnt, (int)pq.size());
			i++;
		}
		else
			pq.pop();
	}
		
	printf("%d", cnt);
	return 0;
}