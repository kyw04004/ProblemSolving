#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int chk[101];
vector<int> solution(vector<int> progresses, vector<int> speeds) {
	vector<int> answer;
	int Max = 0;
	for (int i = 0; i < progresses.size(); i++) {
		int com = progresses[i];
		int spd = speeds[i];
		for (int j = 1; j < 100; j++) {
			if (com + j * spd >= 100) {
				Max = max(Max, j);
				chk[Max]++;
				break;
			}
		}
	}
	for (int i = 1; i < 100; i++)
		if (chk[i]) answer.push_back(chk[i]);
	return answer;
}