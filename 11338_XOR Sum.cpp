#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
#include<functional>
using namespace std;
typedef long long ll;
int t;
int main() {
	scanf("%d", &t);
	while (t--) {
		priority_queue<int, vector<int>, greater<int>> pq;
		int n, k, cnt = 0, sum=0;
		scanf("%d %d", &n, &k);
		for (int i = 1; i <= n; i++) {
			char Command[7];
			scanf("%s", Command);
			if (Command[0] == 'i') {
				cnt++;
				int val;
				scanf("%d", &val);
				sum ^= val;
				pq.push(val);
				if (cnt > k) {
					int element = pq.top();
					pq.pop();
					sum ^= element;
				}
			}
			else printf("%d\n", sum);
		}
	}
	return 0;
}