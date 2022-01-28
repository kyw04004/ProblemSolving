#include<iostream>
#include<map>
#include<queue>
#include<cstring>
#include<string>
#include<algorithm>
#include<functional>
using namespace std;
typedef long long ll;
int vote[10][2], cnt, ans = -1, chk[10];
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	for (int i = 1; i <= 9; i++) {
		int tf, who;
		cin >> tf >> who;
		if (tf == 1 && !vote[who][tf]) cnt++;
		vote[who][tf]++;
	}
	if (cnt == 2) {
		//1만 두표 이상, 나머지는 1을 한표
		bool two = false, one = false;
		for (int i = 1; i <= 9; i++) {
			if (chk[i]) continue;
			if (vote[i][1] >= 2 && !vote[i][0]) chk[i] = 1, two = true;
		}
		for (int i = 1; i <= 9; i++) {
			if (chk[i]) continue;
			if (vote[i][1] == 1) chk[i] = 1, one = true;
		}
		if (two && one) {
			for (int i = 1; i <= 9; i++) {
				if (vote[i][1] >= 2 && !vote[i][0])
					ans = i;
			}
		}
		memset(chk, 0, sizeof(chk));
		//1만 한표, 나머지는 1 1표와 0 한 표이상
		bool one1 = false, one2 = false;
		for (int i = 1; i <= 9; i++) {
			if (chk[i]) continue;
			if (vote[i][1] == 1 && !vote[i][0]) chk[i] = 1, one1 = true;
		}
		for (int i = 1; i <= 9; i++) {
			if (chk[i]) continue;
			if (vote[i][1] == 1 && vote[i][0] > 0) chk[i] = 1, one2 = true;
		}
		if (one1 && one2) {
			for (int i = 1; i <= 9; i++) {
				if (vote[i][1] == 1 && !vote[i][0])
					ans = i;
			}
		}

	}
	if (cnt == 1) {
		//1이 두 표이상이고 0이 한 표일때
		for (int i = 1; i <= 9; i++)
			if (vote[i][1] > 1 && vote[i][0] == 1)
				ans = i;

		//1이 한 표이고 아무표도 안받은 선수가 1명일 때
		bool one = false;
		int cnt = 0;
		for (int i = 1; i <= 9; i++) {
			if ((vote[i][1] + vote[i][0]) == 0) cnt++;
			if (vote[i][1] == 1) one = true;
		}
		if(one && cnt == 1)
			for (int i = 1; i <= 9; i++)
				if ((vote[i][1] + vote[i][0]) == 0) ans = i;
	}
	cout << ans;
	return 0;
}