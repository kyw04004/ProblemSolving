#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<cmath>
#include<queue>
#include<functional>
using namespace std;
typedef long long ll;
string str;
vector<int> cow;
int n, now, chk1, chk2, cnt, s;
priority_queue<int, vector<int>, less<int>> pq;
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n >> str;
	for (int i = 0; i < str.size(); i++) if (str[i] == '1') s++, cow.push_back(i);
	if (s == 0) {
		cout << n - 1;
		return 0;
	}
	for (int i = 0; i < cow.size() - 1; i++) pq.push(cow[i + 1] - cow[i]);
	int len1 = cow[0];
	int len2 = n - 1 - cow[cow.size() - 1];
	if (!pq.empty()) {
		now = pq.top();
		if (now/2 <= len1 && str[0] == '0') {
			cnt++;
			pq.push(len1);
			if (len1 / 2 > now) {
				cnt++;
				pq.push(len1 / 2);
			}
			else {
				cnt++;
				pq.push(now / 2);
			}
		}
		if (now/2 <= len2 && str[n - 1] == '0') {
			cnt++;
			pq.push(len2);
			if (len2 / 2 > now) {
				cnt++;
				pq.push(len2 / 2);
			}
			else {
				cnt++;
				pq.push(now / 2);
			}
		}
	}
	else {
		if (str[0] == '0') chk1 = 1;
		if (str[n - 1] == '0') chk2 = 1;
		if (chk1 && chk2) {
			if (len1 / 2 >= len2) {
				cnt += 2;
				pq.push(len1 / 2);
			}
			else if (len2 / 2 >= len1) {
				cnt += 2;
				pq.push(len2 / 2);
			}
			else {
				cnt += 2;
				pq.push(len1);
				pq.push(len2);
			}
		}
		else if (chk1) {
			cnt += 2;
			pq.push(len1/2);
		}
		else if (chk2) {
			cnt += 2;
			pq.push(len2/2);
		}
	}
	if (2-cnt && pq.size() == 1) {
		int val = pq.top();
		pq.push(val / 3);
	}
	else if (2-cnt) {
		int val1 = pq.top();
		pq.pop();
		int val2 = pq.top();
		pq.pop();
		if (val1 / 3 >= val2 / 2) pq.push(val1 / 3);
		else {
			pq.push(val1 / 2);
			pq.push(val2 / 2);
		}
	}
	while (!pq.empty()) {
		now = pq.top();
		pq.pop();
	}
	cout << now;
	return 0;
}