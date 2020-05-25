#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
using namespace std;
int n, k, arr[1000001];
int main()
{
	int cnt = 0;
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	for (int i = n - 1; i >= 0; i--)
		cnt += k / arr[i], k %= arr[i];
	printf("%d", cnt);
	return 0;
}