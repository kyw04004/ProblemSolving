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
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int sum = 0;
	int num = 0;
	int minus = 0;
	string str; cin >> str;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '-' || str[i] == '+') {
			if(minus == 0) sum += num;
			else sum -= num;
			num = 0;
			if (str[i] == '-') minus = 1;
		}
		else {
			num *= 10;
			num += (str[i] - '0');
		}
	}
	if (minus == 0) sum += num;
	else sum -= num;
	cout << sum;
	return 0;
}