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
int n, sum;
p dot[1000005];
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> dot[i].first >> dot[i].second;
	sort(dot + 1, dot + n + 1);
	int left = dot[1].first, right = dot[1].second;
	for (int i = 2; i <= n; i++) {
		if (right < dot[i].first) {
			sum += (right - left);
			left = dot[i].first;
			right = dot[i].second;
		}
		else if(right < dot[i].second)
			right = dot[i].second;
	}
	sum += (right - left);
	cout << sum;
	return 0;
}