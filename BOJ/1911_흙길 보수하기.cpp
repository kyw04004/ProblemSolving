#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<map>
#include<vector>
#include<queue>
#include<functional>
using namespace std;
typedef long long ll;
typedef pair<int, int> p;
int N, L, cnt;
p line[10005];
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N >> L;
	for (int i = 1; i <= N; i++)
		cin >> line[i].first >> line[i].second;
	sort(line + 1, line + N + 1);
	int left = line[1].first, right = line[1].second;
	for (int i = 2; i <= N; i++) {
		int add = (right - left + L - 1) / L;
		int end = left + add * L;
		left = max(line[i].first, end);
		right = max(line[i].second, left);
		cnt += add;
	}
	cnt += (right - left + L - 1) / L;
	cout << cnt;
	return 0;
}