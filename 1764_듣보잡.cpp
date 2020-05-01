#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
	int n, m, cnt = 0;
	string str[1000001],ans[500001];
	cin >> n >> m;
	for (int i = 0; i < n+m; i++)
		cin >> str[i];
	sort(str, str + n + m);
	for (int i = 0; i < n + m - 1; i++)
		if (str[i] == str[i + 1])
			ans[cnt] = str[i], cnt++;
	printf("%d\n", cnt);
	for (int i = 0; i < cnt; i++)
		cout << ans[i] << '\n';
	return 0;
}