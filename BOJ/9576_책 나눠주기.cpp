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
int T, N, M, ans, chk[1005];
vector<p> input;
bool compare(p a, p b) {
	if (a.second != b.second) return a.second < b.second;
	else return a.first < b.first;
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> T;
	while (T--) {
		memset(chk, 0, sizeof(chk));
		input.clear();
		ans = 0;
		cin >> N >> M;
		for (int i = 0; i < M; i++) {
			int s, e; cin >> s >> e;
			input.push_back({ s,e });
		}
		sort(input.begin(), input.end(), compare);
		for (int i = 0; i < input.size(); i++) {
			int s = input[i].first, e = input[i].second;
			for(int i=s;i<=e;i++)
				if (!chk[i]) {
					chk[i] = 1;
					ans++;
					break;
				}
		}
		cout << ans << '\n';
	}
	return 0;
}

