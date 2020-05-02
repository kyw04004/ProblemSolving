#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
	int n, k;
	cin >> n >> k;
	int left = 1, right = k;
	while (left <= right)
	{
		int mid = (left + right) / 2;
		int sum = 0;
		for (int i = 1; i <= n; i++)
			sum += min(n, mid / i);
		if (sum < k)
			left = mid + 1;
		else
			right = mid - 1;
	}
	printf("%d", left);
	return 0;
}