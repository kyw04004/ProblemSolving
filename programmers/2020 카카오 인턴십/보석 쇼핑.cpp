#include <string>
#include <vector>
#include <map>
using namespace std;
map <string, int> m;
int cnt, chk[100005], Min = 1e9;
vector<int> solution(vector<string> gems) {
	vector<int> answer;
	answer.resize(2);
	for (int i = 0; i < gems.size(); i++)
		if (m[gems[i]] == 0) m[gems[i]] = ++cnt;

	int s = 0, e = -1;
	for (int i = 0; i < gems.size(); i++) {
		if (chk[m[gems[i]]] == 0) cnt--;
		e++, chk[m[gems[i]]]++;
		while (chk[m[gems[s]]] >= 2) chk[m[gems[s]]]--, s++;
		if (cnt == 0 && Min > e - s) {
			Min = e - s;
			answer[0] = s + 1;
			answer[1] = e + 1;
		}
	}
	return answer;
}