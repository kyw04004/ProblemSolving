#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<functional>
#include<queue>
#include<stack>
using namespace std;
typedef long long ll;
int N, K, ans;
vector<string> words;
void make_ans(int idx, int key, int cnt) {
    if (idx == N) {
        ans = max(ans, cnt);
        return;
    }
    bool success = true;
    for (int j = 4; j < (words[idx].size() - 4); j++) {
        if (key & (1 << (words[idx][j] - 'a'))) continue;
        else {
            success = false;
            break;
        }
    }
    if (success) make_ans(idx + 1, key, cnt + 1);
    else make_ans(idx + 1, key, cnt);
}
void make_key(int idx, int key, int can) {
    if (idx == 26 || can == 0) {
        make_ans(0, key, 0);
        return;
    }
    if (key & (1 << idx)) make_key(idx + 1, key, can);
    else {
        if (can > 0) make_key(idx + 1, (key | (1 << idx)), can - 1);
        make_key(idx + 1, key, can);
    }
}
int main() {
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        string word; cin >> word;
        words.push_back(word);
    }
    if (K < 5) {
        cout << "0";
        return 0;
    }
    int key = 0;
    key |= (1 << ('a' - 'a'));
    key |= (1 << ('n' - 'a'));
    key |= (1 << ('t' - 'a'));
    key |= (1 << ('i' - 'a'));
    key |= (1 << ('c' - 'a'));
    make_key(0, key, K - 5);
    cout << ans;
    return 0;
}