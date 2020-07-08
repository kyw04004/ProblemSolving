#include<iostream>
#include<stdlib.h>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
using namespace std;
int n, m,ans;
queue <pair<int,int>> q;
int gcd(int a, int b)
{
	if (b == 0) return a;
	else return gcd(b, a%b);
}
int main()
{
	cin >> n >> m;
	if (n == 0 && m == 0) ans = 0;
	else if (gcd(abs(n),abs(m))==1) ans = 1;
	else ans = 2;
	printf("%d", ans);
	return 0;
}