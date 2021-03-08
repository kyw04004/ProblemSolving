#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> citations) {
	int answer = 0;
	sort(citations.begin(), citations.end());
	for (int i = 0; i <= 1000; i++) {
		int cnt = 0;
		for (int j = 0; j < citations.size(); j++) {
			if (citations[j] >= i) cnt++;
			if (cnt == i) {
				answer = max(answer, cnt);
				break;
			}
		}
	}

	return answer;
}