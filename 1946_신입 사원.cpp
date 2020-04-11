#include<iostream>
#include<algorithm>
using namespace std;
int t,n,ans,chk;
pair<int, int> input[100001];
int main()
{
	cin >> t;
	while (t--)
	{
		cin >> n;
		int ans = 0;
		int Min = 1e9;
		for (int i = 0; i < n; i++)
			cin >> input[i].first >> input[i].second;
		sort(input, input + n);
		for (int i = 0; i < n; i++)
			if (Min > input[i].second)
				ans++, Min = input[i].second;
		printf("%d\n", ans);
	}
	return 0;
}