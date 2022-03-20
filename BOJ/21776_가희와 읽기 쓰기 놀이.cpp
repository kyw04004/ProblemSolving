#include<iostream>
#include<map>
#include<queue>
#include<cstring>
#include<string>
#include<algorithm>
#include<functional>
#include<vector>
#include<stack>
#include<cmath>
#include<unordered_map>
using namespace std;
typedef long long ll;
int N, C, chk[10], dp[10];
vector<pair<char, char>> command[10];
vector<string> ans;
unordered_map<string, int> m;
void go(string str,int depth, int sum) {
    if (depth == C) {
        if (str == "") str = "EMPTY";
        if (!m[str]) {
            m[str] = 1;
            ans.push_back(str);
        }
        return;
    }
    for (int i = 1; i <= C; i++) {
        if ((sum & dp[i]) != dp[i]) continue;
        string com = str;
        if (chk[i] == 0) {
            chk[i] = 1;
            bool can = true;
            for (int j = 0; j < command[i].size(); j++) {
                if (command[i][j].first == 'A') com += command[i][j].second;
                else {
                    int idx = command[i][j].second - '0';
                    if (com.size() <= idx) {
                        can = false;
                        break;
                    }
                    else com.erase(idx, 1);
                }
            }
            if (can) go(com, depth + 1, sum + (1 << i));
            else go("ERROR", C, -1);
            chk[i] = 0;
        }
    }
}
int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> N >> C;
    for (int i = 0; i < N; i++) {
        int cnt; cin >> cnt;
        int sum = 0;
        for (int i = 0; i < cnt; i++) {
            int num; cin >> num;
            dp[num] = sum;
            sum += (1 << num);
        }
    }
    for (int i = 1; i <= C; i++) {
        string com; 
        getline(cin, com);
        cin.clear();
        if (com == "") {
            i--;
            continue;
        }
        int cnt = (com.size()) / 6;
        cnt += 1;
        int idx = 0;
        for (int j = 1; j <= cnt; j++) {
            if (com[idx] == 'A')
                command[i].push_back({ 'A', com[idx + 4] });
            else command[i].push_back({ 'D', com[idx + 4] });
            idx += 6;
        }
    }
    go("", 0, 0);
    sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << '\n';
    return 0;
}