#include<iostream>
#include<queue>
#include<string>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<functional>
#include<stack>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int, int> p;
struct element {
	int t;
	int p;
	int runT;
	int proN;
};
struct compare1 {
	bool operator() (element A, element B) {
		if (A.p != B.p) return A.p < B.p; // 큰 값 우선
		else if (A.runT != B.runT) return A.runT > B.runT; // 작은 값 우선
		else if (A.proN != B.proN) return A.proN > B.proN; // 작은 값 우선
	}
};
struct compare2 {
	bool operator() (element A, element B) {
		return A.t > B.t; //작은값 우선
	}
};
priority_queue<element, vector<element>, compare1> pq;
priority_queue<element, vector<element>, compare2> wpq;
int N, now;
vector<int> ans;
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N;
	for (int i = 0; i < N; i++) {
		int t, p, b;
		cin >> t >> p >> b;
		wpq.push({t,p,b,i+1});
	}
	while (!wpq.empty()) {
		int t = wpq.top().t;
		int p = wpq.top().p;
		int runT = wpq.top().runT;
		int proN = wpq.top().proN;
		if (now >= t) {
			pq.push({ t,p - t , runT , proN });
			wpq.pop();
		}
		else {
			if (!pq.empty()) {
				ans.push_back(pq.top().proN);
				now += pq.top().runT;
				pq.pop();
			}
			else now = t;
		}
	}
	while (!pq.empty()) {
		ans.push_back(pq.top().proN);
		pq.pop();
	}
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << ' ';
	return 0;
}