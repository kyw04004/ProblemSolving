#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
typedef long long ll;
ll pow(ll a, ll b, ll c)
{
	if (b == 0) return 1;
	ll temp = pow(a, b / 2, c);
	ll sum = temp * temp %c;
	if (b % 2 == 1) sum = a * sum %c;
	return sum;
}
int main()
{
	ll a, b, c;
	cin >> a >> b >> c;
	printf("%lld\n", pow(a, b, c));
	return 0;
}