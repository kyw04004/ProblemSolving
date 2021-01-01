#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<cmath>
#include<queue>
#include<functional>
using namespace std;
typedef long long ll;
int t, n;
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> t;
	while (t--) {
		int ans = 12;
		pair<string, int> MBTI[16] = { { "ESTJ",0 },{"ESTP",0}, {"ESFJ",0}, {"ESFP",0},
{"ENTJ",0},{"ENTP",0}, {"ENFJ",0}, {"ENFP",0},
{ "ISTJ",0 },{"ISTP",0}, {"ISFJ",0}, {"ISFP",0},
{"INTJ",0}, {"INTP",0},{"INFJ",0}, {"INFP",0} };
		cin >> n;
		for (int i = 0; i < n; i++) {
			string str;
			cin >> str;
			for (int i = 0; i < 16; i++) if (str == MBTI[i].first) MBTI[i].second++;
		}
		for (int i = 0; i < 16; i++) {
			if (MBTI[i].second == 0) continue;
			MBTI[i].second--;
			for (int j = 0; j < 16; j++) {
				if (MBTI[j].second == 0) continue;
				MBTI[j].second--;
				for (int k = 0; k < 16; k++) {
					if (MBTI[k].second == 0) continue;
					int com = 0;
					string str1 = MBTI[i].first;
					string str2 = MBTI[j].first;
					string str3 = MBTI[k].first;
					if (str1[0] != str2[0]) com++;
					if (str1[1] != str2[1]) com++;
					if (str1[2] != str2[2]) com++;
					if (str1[3] != str2[3]) com++;
					if (str2[0] != str3[0]) com++;
					if (str2[1] != str3[1]) com++;
					if (str2[2] != str3[2]) com++;
					if (str2[3] != str3[3]) com++;
					if (str1[0] != str3[0]) com++;
					if (str1[1] != str3[1]) com++;
					if (str1[2] != str3[2]) com++;
					if (str1[3] != str3[3]) com++;
					ans = min(ans, com);
				}
				MBTI[j].second++;
			}
			MBTI[i].second++;
		}
		cout << ans << '\n';
	}
	return 0;
}