#include<iostream>
#include<vector>
#include<queue>
#include<string>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<functional>
#include<stack>
#include<stdio.h>
using namespace std;
typedef long long ll;
int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    int N; cin >> N;
    for (int i = 1; i <= N; i++) {
        if (i == N) {
            if (N % 2 == 0) cout << "2";
            else cout << "3";
        }
        else {
            if (i % 2 == 1) cout << "1 ";
            else cout << "2 ";
        }
    }
    return 0;
}