#include <string>
#include <vector>
#include <queue>
#include<functional>
using namespace std;
queue<pair<int, int>> q;
priority_queue<int, vector<int>, less<int>> pq;
int solution(vector<int> priorities, int location) {
	int answer = 0;
	for (int i = 0; i < priorities.size(); i++) {
		pq.push(priorities[i]);
		int val = 0;
		if (i == location) val = 1;
		q.push({ priorities[i], val });
	}
	while (!pq.empty()) {
		if (pq.top() == q.front().first) {
			answer++;
			pq.pop();
			if (q.front().second == 1) break;
		}
		else q.push(q.front());
		q.pop();
	}
	return answer;
}