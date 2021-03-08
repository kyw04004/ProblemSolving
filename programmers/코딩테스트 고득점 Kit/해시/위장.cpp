#include <string>
#include <vector>
#include <map>
using namespace std;
map<string, int> m;
map<string, int> chk;
int solution(vector<vector<string>> clothes) {
	int answer = 1;
	int cnt = 0;
	for (int i = 0; i < clothes.size(); i++)
		m[clothes[i][1]]++;
	for (int i = 0; i < clothes.size(); i++) {
		if (chk[clothes[i][1]] == 0) {
			chk[clothes[i][1]] = 1;
			answer *= (m[clothes[i][1]] + 1);
		}
	}
	return answer - 1;
}