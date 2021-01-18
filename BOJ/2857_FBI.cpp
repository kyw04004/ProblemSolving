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
	vector<int> v;
	for (int i = 1; i <= 5; i++) {
		string str; cin >> str;
		if (str.size() < 3) continue;
		for (int j = 0; j < str.size() - 2; j++)
			if (str[j] == 'F' && str[j + 1] == 'B' && str[j + 2] == 'I') {
				v.push_back(i);
				break;
			}
	}
	if (v.size() == 0) cout << "HE GOT AWAY!";
	else {
		for (int i = 0; i < v.size(); i++)
			cout << v[i] << ' ';
	}
	return 0;
}