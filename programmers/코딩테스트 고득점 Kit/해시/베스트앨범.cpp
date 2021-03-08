#include <string>
#include <vector>
#include <map>
#include<algorithm>
#include<iostream>
using namespace std;
map<string, pair<int, int>> m;
int cnt, chk[105];
vector<pair<int, string>> sv;
vector<pair<int, pair<string, int>>> splays;
vector<int> solution(vector<string> genres, vector<int> plays) {
	vector<int> answer;
	for (int i = 0; i < plays.size(); i++) {
		if (m[genres[i]].first == 0) m[genres[i]].first = ++cnt;
		m[genres[i]].second += plays[i];
		splays.push_back({ plays[i],{genres[i],100000 - i} });
	}
	for (int i = 0; i < plays.size(); i++) {
		if (chk[m[genres[i]].first] == 0) {
			chk[m[genres[i]].first] = 1;
			sv.push_back({ m[genres[i]].second, genres[i] });
		}
	}
	sort(sv.begin(), sv.end());
	sort(splays.begin(), splays.end());
	for (int i = sv.size() - 1; i >= 0; i--) {
		int count = 0;
		for (int j = splays.size() - 1; j >= 0; j--) {
			if (count == 2) break;
			if (sv[i].second == splays[j].second.first) {
				count++;
				answer.push_back(100000 - splays[j].second.second);
			}
		}
	}
	return answer;
}