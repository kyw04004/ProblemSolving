#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
#include<map>
#include<vector>
#include<functional>
#include<queue>
using namespace std;
int N, M, result[1000005], before[1000005], after[1000005], chk[1000005];
vector<int> moim[1000005];
int main() {
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int k; cin >> k;
        for (int j = 0; j < k; j++) {
            int num; cin >> num;
            moim[i].push_back(num);
            chk[num] = 1;
        }
    }

    for (int i = 1; i <= N; i++) {
        cin >> result[i];
        before[i] = 1;
    }

    for (int i = 0; i < M; i++) { // 초기값 탐색

        bool clean = false;
        for (int j = 0; j < moim[i].size(); j++)
            if (result[moim[i][j]] == 0 || before[moim[i][j]]==0) clean = true;

        if(clean)
            for (int j = 0; j < moim[i].size(); j++)
                before[moim[i][j]] = 0;
    }

    for (int i = 1; i <= N; i++) if (chk[i] == 0) before[i] = result[i];


    for (int i = 0; i < M; i++) { // 초기값의 결과값 도출

        bool clean = true;
        for (int j = 0; j < moim[i].size(); j++)
            if (before[moim[i][j]] || after[moim[i][j]]) clean = false;

        if (clean == false)
            for (int j = 0; j < moim[i].size(); j++)
                after[moim[i][j]] = 1;
    }
    for (int i = 1; i <= N; i++) if (chk[i] == 0) after[i] = before[i];

    bool YN = true;

    for (int i = 1; i <= N; i++)
        if (after[i] != result[i]) YN = false;

    if (YN) {
        cout << "YES\n";
        for (int i = 1; i <= N; i++)
            cout << before[i] << ' ';
    }
    else cout << "NO";

    return 0;
}