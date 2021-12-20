#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<functional>
#include<queue>
using namespace std;
int N, M, state[101];
int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> state[i];
    cin >> M;
    for (int i = 0; i < M; i++) {
        int s, num; cin >> s >> num;
        if (s == 1) 
            for (int j = 1; num * j <= N; j++)
                state[num * j] = (state[num * j] + 1) % 2;
        else {
            int range = 0;
            while (num + range + 1 <= N && 1 <= num - range - 1) {
                if (state[num - range - 1] == state[num + range + 1]) range++;
                else break;
            }
            for (int j = num-range; j <= num +range; j++)
                state[j] = (state[j] + 1) % 2;
        }
    }
    for (int i = 1; i <= N; i++) {
        cout << state[i] << ' ';
        if (i % 20 == 0) cout << '\n';
    }
    return 0;
}