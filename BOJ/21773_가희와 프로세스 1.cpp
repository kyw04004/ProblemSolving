#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
#include<map>
#include<vector>
#include<queue>
#include<stack>
#include<functional>
using namespace std;
int T, n;
struct element {
	int id;
	int time;
	int p;
};
struct compare {
	bool operator() (element A, element B) {
		if (A.p != B.p) return A.p < B.p;
		else return A.id > B.id;
	}
};
priority_queue<element, vector<element>, compare> pq;
int main(void) {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> T >> n;
	for (int i = 1; i <= n; i++) {
		int a, b, c; cin >> a >> b >> c;
		pq.push({ a,b,c });
	}
	for(int i=1;i<=T;i++) {
		if (!pq.empty()) {
			element e = pq.top();
			pq.pop();
			cout << e.id << '\n';
			e.p -= 1;
			e.time -= 1;
			if (e.time > 0) pq.push(e);
		}
	}
	return 0;
}