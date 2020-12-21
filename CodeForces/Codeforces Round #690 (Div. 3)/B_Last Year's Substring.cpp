#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
#include<functional>
using namespace std;
int t, n;
string str;
int main()
{
	cin >> t;
	while (t--) {
		vector<pair<int, int>> v;
		cin >> n;
		cin >> str;
		if (str == "2020") {
			printf("YES\n");
			continue;
		}

		for (int i = 0; i < n; i++)
			for (int j = i; j < n; j++)
				v.push_back({ i,j });
		for (int i = 0; i < v.size(); i++) {
			string ans = str;
			if (v[i].first == v[i].second) ans.erase(ans.begin() + v[i].first);
			else ans.erase(v[i].first, v[i].second - v[i].first + 1);
			if (ans == "2020") {
				printf("YES\n");
				break;
			}
			else if (i == v.size() - 1) printf("NO\n");
		}

	}
	return 0;
}