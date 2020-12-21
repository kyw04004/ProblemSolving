#include<iostream>
#include<stdio.h>
#include<cstring>
#include<string>
#include<algorithm>
#include<functional>
#include<queue>
#include<stack>
using namespace std;
typedef long long ll;
stack<pair<int, int>> s;
ll n, h, same, ans;
int main() {        
	scanf("%lld", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &h);
		same = 1;
		while (!s.empty() && s.top().first <= h) {
			ans += s.top().second;
			if (s.top().first == h)
				same += s.top().second;
			s.pop();
		}
		if (!s.empty())
			ans += 1;
		s.push({ h,same });
	}
	printf("%lld", ans);
	return 0;
}

