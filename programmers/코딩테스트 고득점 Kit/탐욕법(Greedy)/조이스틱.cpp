#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
int cnt;
int solution(string name) {
	int answer = 1e9;
	for (int i = 0; i < name.size(); i++)
		if (name[i] != 'A') cnt++;

	string com = name;
	for (int i = 0; i < name.size(); i++) {
		if (com[i] != 'A') {
			cnt--;
			com[i] = 'A';
		}

		if (cnt == 0) {
			answer = min(answer, i);
			break;
		}

		int count = cnt;
		int index = i;

		for (int j = 0; j < name.size() - 1; j++) {
			index--;
			if (index == -1) index = name.size() - 1;
			if (com[index] != 'A') count--;
			if (count == 0) {
				answer = min(answer, i + j + 1);
				break;
			}
		}
	}

	for (int i = 0; i < name.size(); i++)
		answer += min(name[i] - 'A', 91 - name[i]);
	cout << answer;
	return answer;
}