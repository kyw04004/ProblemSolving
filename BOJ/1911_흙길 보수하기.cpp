#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
pair<int, int> arr[10001];
int main()
{
	int n, l, cnt, sum = 0;
	cin >> n >> l;
	for (int i = 0; i < n; i++)
		scanf("%d %d", &arr[i].first, &arr[i].second);
	sort(arr, arr + n);
	int left = -1, right = -1;
	for (int i = 0; i < n; i++)
	{
		left = max(left, arr[i].first);
		right = max(left, max(right, arr[i].second));
		cnt = (right - left +l - 1) / l;
		sum += cnt;
		left += cnt * l;
	}
	printf("%d", sum);
	return 0;
}