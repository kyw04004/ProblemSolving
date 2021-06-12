//Meet in the middle algorithm
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
typedef long long ll;
int N, C, cnt;
vector<int> A, B, aSub, bSub;
void makeAsubset(int index, int sum) {
	if (sum > C) return;
	if (index == A.size()) {
		aSub.push_back(sum);
		return;
	}
	makeAsubset(index + 1, sum + A[index]);
	makeAsubset(index + 1, sum);
}
void makeBsubset(int index, int sum) {
	if (sum > C) return;
	if (index == B.size()) {
		bSub.push_back(sum);
		return;
	}
	makeBsubset(index + 1, sum + B[index]);
	makeBsubset(index + 1, sum);
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N >> C;
	for (int i = 0; i < N; i++) {
		int W; cin >> W;
		if (i < N / 2) A.push_back(W);
		else B.push_back(W);
	}
	makeAsubset(0, 0);
	makeBsubset(0, 0);
	sort(aSub.begin(), aSub.end());
	sort(bSub.begin(), bSub.end());
	for (int i = 0; i < aSub.size(); i++) {
		int left = 0, right = bSub.size() - 1, ans;
		while (left <= right) {
			int mid = (left + right) / 2;
			if (aSub[i] + bSub[mid] <= C) ans = mid, left = mid + 1;
			else right = mid - 1;
		}
		cnt += (ans + 1);
	}
	cout << cnt;
	return 0;
}