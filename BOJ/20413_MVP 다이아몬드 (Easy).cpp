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
int n, grade[5], sum, now;
string str;
vector<int> v;
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= 4; i++) cin >> grade[i];
	cin >> str;
	for (int i = 0; i < str.size(); i++) {
		if (v.size() >= 1) now = v.back();
		if (str[i] == 'B') {
			v.push_back((grade[1] - now) - 1);
			sum += v.back();
		}
		if (str[i] == 'S') {
			v.push_back((grade[2] - now) - 1);
			sum += v.back();
		}
		if (str[i] == 'G') {
			v.push_back((grade[3] - now) - 1);
			sum += v.back();
		}
		if (str[i] == 'P') {
			v.push_back((grade[4] - now) - 1);
			sum += v.back();
		}
		if (str[i] == 'D') {
			v.push_back((grade[4]));
			sum += v.back();
		}
	}
	cout << sum;
	return 0;
}