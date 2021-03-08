#include <string>
#include <vector>
#include <map>
using namespace std;
vector<int> num;
int chk[10], answer;
map<int, int> m;
bool Prime(int n) {
	if (n < 2) return false;
	if (n == 2) return true;
	for (int i = 2; i < n; i++)
		if (n%i == 0) return false;
	return true;
}
void go(int now) {
	if (Prime(now) && !m[now]) {
		answer++;
		m[now] = 1;
	}
	for (int i = 0; i < num.size(); i++) {
		if (now == 0 && num[i] == 0) continue;
		if (chk[i] == 0) {
			chk[i] = 1;
			go(now * 10 + num[i]);
			chk[i] = 0;
		}
	}
}
int solution(string numbers) {
	for (int i = 0; i < numbers.size(); i++)
		num.push_back(numbers[i] - '0');
	go(0);
	return answer;
}