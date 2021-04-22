#include <string>
#include <vector>
#include <functional>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;
vector<int> solution(vector<string> operations) {
	int pq[1000005] = { 0, };
	int s = 0, e = 0;
	for (int i = 0; i < operations.size(); i++) {
		if (operations[i][0] == 'I') {
			int num = stoi(operations[i].substr(2));
			pq[e++] = num;
			cout << "insert " << num << '\n';
		}
		if (operations[i][0] == 'D') {
			if (operations[i][2] == '1')
				if (e - s > 0)
					cout << "delete back " << pq[e--] << '\n';
			if (operations[i][2] == '-')
				if (e - s > 0)
					cout << "delete front " << pq[s++] << '\n';
		}
		sort(pq + s, pq + e);
		for (int i = s; i < e; i++)
			cout << pq[i] << ' ';
		cout << '\n';
	}
	vector<int> answer;
	if (e - s > 0) {
		answer.push_back(pq[e - 1]);
		answer.push_back(pq[s]);
	}
	else {
		answer.push_back(0);
		answer.push_back(0);
	}
	return answer;
}