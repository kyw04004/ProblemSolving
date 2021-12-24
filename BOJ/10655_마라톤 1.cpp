#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<functional>
#include<queue>
using namespace std;
typedef long long ll;
ll N, x[100005], y[100005], sum, Max;
int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> x[i] >> y[i];
    
    for (int i = 1; i < N; i++) {
        int d = abs(x[i] - x[i + 1]) + abs(y[i] - y[i + 1]);
        sum += d;
    }

    for (int i = 1; i < N - 1; i++) {
        ll d1 = abs(x[i] - x[i + 1]) + abs(y[i] - y[i + 1]);
        ll d2 = abs(x[i + 2] - x[i + 1]) + abs(y[i + 2] - y[i + 1]);
        ll d3 = abs(x[i + 2] - x[i]) + abs(y[i + 2] - y[i]);
        Max = max(Max, d1+d2-d3);
    }
    
    cout << sum - Max;
    return 0;
}