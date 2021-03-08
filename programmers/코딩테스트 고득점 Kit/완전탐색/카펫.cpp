#include <string>
#include <vector>
using namespace std;
vector<pair<int, int>> candicate;
vector<int> solution(int brown, int yellow) {
	vector<int> ans;
	for (int i = 1; i <= yellow; i++) {
		if (yellow % i == 0) {
			if (i < (yellow / i)) continue;
			candicate.push_back({ i, yellow / i });
		}
	}
	for (int i = 0; i < candicate.size(); i++) {
		if ((candicate[i].first + 2) * (candicate[i].second + 2) == (yellow + brown)) {
			ans.push_back(candicate[i].first + 2);
			ans.push_back(candicate[i].second + 2);
			return ans;
		}
	}
}