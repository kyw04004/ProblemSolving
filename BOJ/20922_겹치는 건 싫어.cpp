#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<cmath>
#include<map>
#include<set>
#include<queue>
using namespace std;
typedef long long ll;
queue<int> q;
map<int, int> m;
int N, K, Max;
int main() 	{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		int num; cin >> num;
		m[num]++;
		q.push(num);
		while (m[num] > K) {
			m[q.front()]--;
			q.pop();
		}
		Max = max(Max, (int)q.size());
	}
	cout << Max;
	return 0;
}