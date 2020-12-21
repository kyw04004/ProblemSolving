#include<iostream>
#include<algorithm>
using namespace std;
double n, h[51],ans[51];
int main() {
	scanf("%lf", &n);
	for (int i = 0; i < n; i++)
		scanf("%lf", &h[i]);
	for (int i = 0; i < n-1; i++)
	{
		double Max = -1e9;
		for (int j = i + 1; j < n; j++)
		{
			double compare = (h[j] - h[i]) / (j - i);
			if (compare > Max)
				Max = compare,ans[i]++,ans[j]++;
		}
	}
	sort(ans, ans + (int)n);
	printf("%d", (int)ans[(int)n - 1]);
	return 0;
}