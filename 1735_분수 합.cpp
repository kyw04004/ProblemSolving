#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
#include<functional>
using namespace std;
typedef long long ll;
int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a%b);
}
int main() {
	int a, b, c, d, ansa,ansb;
	cin >> a >> b >> c >> d;
	a *= d, c *= b, b *= d;
	ansa = a + c, ansb = b;
	int div = gcd(ansa, ansb);
	printf("%d %d\n", ansa / div, ansb / div);
	return 0;
}