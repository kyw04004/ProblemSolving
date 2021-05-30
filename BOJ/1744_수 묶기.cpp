#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <stack>
#include <map>
#include <set>
#include <stack>
#include <queue>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
vector<ll> posV, negV;
ll n, sum;
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++) {
		ll val; cin >> val;
		if(val > 0) posV.push_back(val);
		else negV.push_back(val);
	}
	sort(posV.begin(), posV.end());
	sort(negV.begin(), negV.end());
	for (int i = posV.size() - 1; i >= 0; i-=2) {
		if (i == 0) {
			sum += posV[i];
			continue;
		}
		(posV[i] * posV[i-1]) > (posV[i] + posV[i-1])? sum+= (posV[i] * posV[i - 1]) : sum += (posV[i] + posV[i - 1]);
	}
	for (int i = 0; i < negV.size(); i += 2) {
		if (i == negV.size() - 1) {
			sum += negV[i];
			continue;
		}
		sum += negV[i] * negV[i + 1];
	}
	cout << sum;
	return 0;
}