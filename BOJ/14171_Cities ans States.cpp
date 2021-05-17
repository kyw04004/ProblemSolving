#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <stack>
#include <map>
using namespace std;
typedef long long ll;
map <pair<string, string> , int> m;
vector <pair<string, string>> v;
int cnt;
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string city, state;
		cin >> city >> state;
		city = city.substr(0,2);
		v.push_back({ city, state });
		m[{city, state}]++;
	}
	for (int i = 0; i < v.size(); i++) {
		string city = v[i].first;
		string state = v[i].second;
		if (city == state) continue;
		cnt += m[{state, city}];
	}
	cout << cnt / 2;
	return 0;
}