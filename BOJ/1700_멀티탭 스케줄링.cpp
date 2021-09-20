#include<iostream>
#include<vector>
#include<queue>
#include<string>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<functional>
#include<stack>
using namespace std;
typedef long long ll;
typedef pair<int, int> p;
int N, K, input[105], cnt;
vector<int> tap;
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N >> K;

	for (int i = 1; i <= K; i++) cin >> input[i];

	for (int i = 1; i <= K; i++) {
		bool already = false;
		for (int j = 0; j < tap.size(); j++)
			if (input[i] == tap[j]) already = true;
		if (already) continue;

		if (tap.size() < N) {
			tap.push_back(input[i]);
			continue;
		}

		cnt += 1;
		int Max = 0, deleteIndex = 0;
		for (int j = 0; j < tap.size(); j++)
			for (int k = i + 1; k <= K; k++) {
				if (tap[j] == input[k]) {
					if (Max < k) {
						Max = k;
						deleteIndex = j;
					}
					break;
				}
				else if (k == K){
					deleteIndex = j;
					j = 1e9;
				}
			}
		tap[deleteIndex] = input[i];
	}
	cout << cnt;
	return 0;
}

