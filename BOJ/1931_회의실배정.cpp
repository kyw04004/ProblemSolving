#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
#include<functional>
using namespace std;
pair<int, int> arr[100001];
int main()
{
	int n,com1,com2,cnt=0;
	cin >> n;
	for (int i = 0; i < n; i++)
		scanf("%d %d", &arr[i].second, &arr[i].first);
	sort(arr, arr + n);
	com1 = arr[0].first;
	cnt++;
	for (int i = 1; i < n; i++)
		if (com1 <= arr[i].second)
			cnt++, com1 = arr[i].first;
	printf("%d", cnt);
	return 0;
}