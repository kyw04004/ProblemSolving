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
ll ans = 0, n, arr[4000005];
vector<ll> v;
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n;

	//에라토스테네스의 체 알고리즘으로 소수 판별
	for (int i = 2; i <= n; i ++) arr[i] = 1;
	for (int i = 2; i * i <= n; i++)
		for (int j = i * i; j <= n; j += i)
			arr[j] = 0;

	//누적합 벡터 만들기
	v.push_back(0);
	for (int i = 2; i <= n; i++)
		if (arr[i]) v.push_back(i);
	for (int i = 0; i < v.size() - 1; i++)
		v[i + 1] += v[i];

	//정답 연산
	for (int i = v.size() - 1; i >= 1; i--) {
		int left = 0, right = i;
		while (left <= right) {
			int mid = (left + right) / 2;
			ll com = v[i] - v[mid];
			if (com == n) {
				ans++;
				break;
			}
			if (com > n) left = mid + 1;
			else right = mid - 1;
		}
	}

	cout << ans;
	return 0;
}