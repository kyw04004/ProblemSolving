#include <string>
#include <vector>
#include <iostream>
#include <map>
using namespace std;
vector<string> uid, bid;
int answer,chk[9], chk2[1<<9];
void go(int depth, int sum) {
	if (depth == bid.size()) {
		if(!chk2[sum]) answer += 1;
		chk2[sum] = 1;
		return;
	}
	string ban = bid[depth];
	for (int i = 0; i < uid.size(); i++) {
		if (chk[i]) continue;
		string user = uid[i];
		int ok = 1;
		if (ban.size() != user.size()) continue;
		for (int j = 0; j < ban.size(); j++) {
			if (ban[j] == '*' || ban[j] == user[j]) continue;
			else {
				ok = 0;
				break;
			}
		}
		if (ok) {
			chk[i] = 1;
			go(depth + 1, sum + (1 << i));
			chk[i] = 0;
		}
	}
	return;
}
int solution(vector<string> user_id, vector<string> banned_id) {
	uid = user_id, bid = banned_id;
	go(0, 0);
	return answer;
}