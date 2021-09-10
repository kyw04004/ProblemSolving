#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <functional>
#include <iostream>
using namespace std;
typedef pair<int, int> P;
priority_queue <P, vector<P>, greater<P>> pq; 
int solution(vector<vector<int>> jobs) {
    sort(jobs.begin(), jobs.end());
    int answer = 0;
    int now = 0;
    int idx = 0;
    while (idx < jobs.size()) {
        if (now >= jobs[idx][0]) pq.push({ jobs[idx][1], jobs[idx++][0] });
        else {
            if (!pq.empty()) { 
                answer += pq.top().first; 
                answer += (now - pq.top().second); 
                now += pq.top().first; 
                pq.pop();
            }
            else now = jobs[idx][0]; 
        }
    }
    while (!pq.empty()) {
        answer += pq.top().first; 
        answer += (now - pq.top().second); 
        now += pq.top().first; 
        pq.pop();
    }
    return answer / jobs.size();
}