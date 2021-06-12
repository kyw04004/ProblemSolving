//Meet in the middle algorithm
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<cmath>
#include<map>
using namespace std;
typedef long long ll;
ll N, S, cnt;
vector<ll> A, B, aSub, bSub;
map<ll, int> bm;
void makeAsubset(int index, ll sum) {
	if (index == A.size()) {
		aSub.push_back(sum);
		return;
	}
	makeAsubset(index + 1, sum + A[index]);
	makeAsubset(index + 1, sum);
}
void makeBsubset(int index, ll sum) {
	if (index == B.size()) {
		bSub.push_back(sum);
		bm[sum]++;
		return;
	}
	makeBsubset(index + 1, sum + B[index]);
	makeBsubset(index + 1, sum);
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N >> S;
	for (int i = 0; i < N; i++) {
		ll val; cin >> val;
		if (i < N / 2) A.push_back(val);
		else B.push_back(val);
	}
	makeAsubset(0,0);
	makeBsubset(0,0);
	sort(aSub.begin(), aSub.end());
	sort(bSub.begin(), bSub.end());
	for (int i = 0; i < aSub.size(); i++) {
		int left = 0, right = bSub.size() - 1;
		while (left <= right) {
			int mid = (left + right) / 2;
			if (aSub[i] + bSub[mid] == S) {
				cnt += bm[bSub[mid]];
				break;
			}
			else if (aSub[i] + bSub[mid] < S) left = mid + 1;
			else right = mid - 1;
		}
	}
	if (S == 0) cnt --;
	cout << cnt;
	return 0;
}