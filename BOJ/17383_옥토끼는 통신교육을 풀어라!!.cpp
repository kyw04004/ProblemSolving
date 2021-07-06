#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<vector>
#include<map>
using namespace std;
int N;
vector<int> T;
bool possible(int len) {
	map<int, int> M;
	for (int i = 0; i < T.size(); i++)
		M[((T[i] - 1) / len) + 1]++;
	if (M[1]) {
		M[1]--;
		int one = 0;
		for (auto iter=M.begin(); iter != M.end(); iter++) {
			if (iter->first == 1) one = iter->second;
			else if (iter->first == 2) continue;
			else {
				if (one >= (iter->first - 2) * iter->second)
					one -= (iter->first - 2) * iter->second;
				else return false;
			}
		}
		return true;
	}
	else return false;
}
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int time; cin >> time;
		T.push_back(time);
	}
	int ans;
	int left = 1, right = 1e9;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (possible(mid)) ans = mid, right = mid - 1;
		else left = mid + 1;
	}
	cout << ans;
	return 0;
}