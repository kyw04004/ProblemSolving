#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
	vector<int> answer;
	for (int i = 0; i < commands.size(); i++) {
		vector<int> sortv;
		int s = commands[i][0];
		int e = commands[i][1];
		int k = commands[i][2];
		for (int j = s - 1; j < e; j++) sortv.push_back(array[j]);
		sort(sortv.begin(), sortv.end());
		answer.push_back(sortv[k - 1]);
	}
	return answer;
}