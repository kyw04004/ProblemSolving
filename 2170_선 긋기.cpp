#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
pair<int, int> arr[1000001];
int main()
{
	int n,sum=0;
	cin >> n;
	for (int i = 0; i < n; i++)
		scanf("%d %d", &arr[i].first, &arr[i].second);
	sort(arr, arr + n);
	int right = -1e9-1;
	for (int i = 0; i < n; i++)
	{
		if (right < arr[i].first)
			sum += (arr[i].second-arr[i].first);
		else if (right < arr[i].second)
			sum += (arr[i].second - right);
		right = max(right, arr[i].second);
	}
	printf("%d", sum);
	return 0;
}