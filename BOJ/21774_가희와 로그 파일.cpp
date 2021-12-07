#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
#include<map>
#include<vector>
#include<queue>
#include<stack>
#include<functional>
using namespace std;
typedef long long ll;
vector<ll> lv[7];
int N, Q;
ll format(string str) {
	ll time = 0;
	for (int j = 0; j < str.size(); j++) {
		if (str[j] == '#') break;
		int num = str[j] - '0';
		if (num < 0 || num > 9) continue;
		time *= 10;
		time += num;
	}
	return time;
}
int binarySearch1(int level, ll time) {
	int left = 0, right = lv[level].size() - 1;
	if (right == -1) return -1;
	int ans = -1;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (lv[level][mid] >= time) {
			ans = mid;
			right = mid - 1;
		}
		else left = mid + 1;
	}
	return ans;
}
int binarySearch2(int level, ll time) {
	int left = 0, right = lv[level].size() - 1;
	if (right == -1) return -1;
	int ans = -1;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (lv[level][mid] <= time) {
			ans = mid;
			left = mid + 1;
		}
		else right = mid - 1;
	}
	return ans;
}
int main(void) {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N >> Q;
	for (int i = 1; i <= N; i++) {
		string str1, str2;
		cin >> str1 >> str2;
		ll time = format(str1 + str2);
		int level = str2[str2.size()-1] - '0';
		lv[level].push_back(time);
	}
	for (int i = 1; i <= Q; i++) {
		string str1, str2, str3;
		cin >> str1 >> str2 >> str3;
		string str = str1 + str2 + str3;
		ll time1 = format(str.substr(0, 19));
		ll time2 = format(str.substr(19));
		int level = str[str.size() - 1] - '0';
		int sum = 0;
		for (int j = level; j <= 6; j++) {
			int idx1 = binarySearch1(j, time1);
			int idx2 = binarySearch2(j, time2);
			if (idx1 == -1) continue;
			if (idx2 == -1) continue;
			sum += (idx2 - idx1 + 1);
		}
		cout << sum << '\n';
	}
	return 0;
}