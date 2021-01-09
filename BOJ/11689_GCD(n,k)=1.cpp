#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<cmath>
#include<queue>
#include<functional>
#include<stack>
#include<map>
using namespace std;
typedef long long ll;
ll n, ans=1, num,com,cnt;
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	num = n;
	if (num%2 == 0) {
		cnt = 0;
		while (num % 2 == 0) num /= 2, cnt++;
		ans *= (pow(2, cnt) - pow(2, cnt - 1));
	}
	for (ll i = 3; i <= (ll)floor(sqrt(n)); i+=2) {
		if (num%i == 0) {
			cnt = 0;
			while (num%i == 0) num /= i, cnt++;
			ans *= (pow(i, cnt) - pow(i, cnt - 1));
		}
	}
	if (num != 1) ans *= (num-1);
	cout << ans << '\n';
	return 0;
}