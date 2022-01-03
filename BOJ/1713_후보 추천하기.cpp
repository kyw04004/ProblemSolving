#include<iostream>
#include<map>
#include<queue>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
int n, total;
struct element{
	int vote;
	int time;
	int num;
};
bool compare1(element a, element b) {
	if (a.vote != b.vote) return a.vote > b.vote;
	else return a.time > b.time;
}
bool compare2(element a, element b) {
	return a.num < b.num;
}
vector<element> candi;
int main() {
	cin >> n >> total;
	for (int i = 0; i < total; i++) {
		int num; cin >> num;
		bool exist = false;
		for (int j = 0; j < candi.size(); j++)
			if (candi[j].num == num) exist = true, candi[j].vote++;
		if (exist == false) {
			if (candi.size() < n) candi.push_back({ 1, i, num });
			else {
				candi.pop_back();
				candi.push_back({ 1, i, num });
			}
		}
		sort(candi.begin(), candi.end(), compare1);
	}
	sort(candi.begin(), candi.end(), compare2);
	for (int i = 0; i < candi.size(); i++)
		cout << candi[i].num << ' ';
	return 0;
}