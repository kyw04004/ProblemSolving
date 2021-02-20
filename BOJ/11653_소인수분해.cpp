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
#include<bitset>
using namespace std;
typedef long long ll;
bool Prime(int num) {
	if (num == 1) return false;
	for (int i = 2; i < num; i++)
		if (num%i == 0) return false;
	return true;
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n; cin >> n;
	while (n % 2 == 0) {
		cout << "2\n";
		n /= 2;
	}
	for (int i = 3; i <= sqrt(n) ; i+=2) {
		if (!Prime(i)) continue;
		while (n % i == 0) {
			cout << i <<"\n";
			n /= i;
		}
	}
	if (Prime(n)) cout << n;
	return 0;
}