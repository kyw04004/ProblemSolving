#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
int main() {
	pair<int, int> a,b,c;
	scanf("%d %d", &a.first, &a.second);
	scanf("%d %d", &b.first, &b.second);
	scanf("%d %d", &c.first, &c.second);
	int x = (b.first - a.first)*(c.second - a.second);
	x -= (c.first - a.first) * (b.second - a.second);
	if (x > 0) printf("1");
	else if(x == 0) printf("0");
	else printf("-1");
	return 0;
}