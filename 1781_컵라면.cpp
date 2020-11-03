#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
#include<deque>
#include<stack>
#include<functional>
#include<vector>
#include<cmath>
using namespace std;
typedef long long ll;
int n, sum;
pair<int,int> arr[200005];
priority_queue<int, vector<int>, greater<int>> pq;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		arr[i] = { a,b };
	}
	sort(arr, arr + n);
	for (int i = 0; i < n; i++) {
		int day = arr[i].first;
		pq.push(arr[i].second);
		if (!pq.empty() && day < pq.size()) pq.pop();
	}
	while (!pq.empty()) {
		sum += pq.top();
		pq.pop();
	}
	printf("%d", sum);
	return 0;
}