#include<stdio.h>
int n, col[15],x[2][30], ans;
void dfs(int i)
{
	if (i > n)
		ans++;
	for(int j=1; j<=n;j++)
		if (!col[j] && !x[0][i - j + 13] && !x[1][i + j])
		{
			col[j] = x[0][i - j + 13] = x[1][i + j] = 1;
			dfs(i + 1);
			col[j] = x[0][i - j + 13] = x[1][i + j] = 0;
		}
	return;
}
int main() {
	scanf("%d", &n);
	dfs(1);
	printf("%d\n", ans);
	return 0;
}