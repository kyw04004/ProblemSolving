#include <string>
#include <vector>
#include <queue>
#include <functional>
using namespace std;
priority_queue<int, vector<int>, greater<int>> pq;
int solution(vector<int> scoville, int K) {
	int answer = 0;
	for (int i = 0; i < scoville.size(); i++)
		pq.push(scoville[i]);
	while (!pq.empty()) {
		int one = pq.top();
		pq.pop();

		if (one >= K) break;
		else answer++;

		if (!pq.empty()) {
			int two = pq.top();
			pq.pop();
			pq.push(one + 2 * two);
		}
		else {
			answer = -1;
			break;
		}
	}
	return answer;
}