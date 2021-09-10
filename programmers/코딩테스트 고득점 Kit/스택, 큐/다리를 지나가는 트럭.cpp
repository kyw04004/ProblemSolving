#include <string>
#include <vector>
#include <queue>
using namespace std;
queue<int> bridge;
int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int sum = 0;
    int idx = 0;
    while (idx < truck_weights.size()) {
        answer++;
        if (bridge.size() == bridge_length) {
            sum -= bridge.front();
            bridge.pop();
        }
        if (sum + truck_weights[idx] <= weight) {
            sum += truck_weights[idx];
            bridge.push(truck_weights[idx++]);
        }
        else bridge.push(0);
    }
    answer += bridge_length;
    return answer;
}