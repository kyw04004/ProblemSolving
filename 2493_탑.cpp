#include<stdio.h>
#include<cstring>
#include<algorithm>
#include<string>
#include<iostream>
#include<stack>
using namespace std;
typedef long long ll;
int arr[500001];
int ans[500001];
stack <pair<int, int>> s;
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		scanf("%d", &arr[i]);
	s.push({ arr[n],n });
	for (int i = n - 1; i >= 1; i--)
	{
		int here = arr[i];
		if (s.top().first < here)
		{
			while (!s.empty() && s.top().first < here)
			{
				ans[s.top().second] = i;
				s.pop();
			}
			s.push({ here,i });
		}
		else
			s.push({ here,i });
	}
	for (int i = 1; i <= n; i++)
		printf("%d ", ans[i]);
	return 0;
}