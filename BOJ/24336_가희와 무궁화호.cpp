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
unordered_map<string, double> dist;
unordered_map<string, pair<double, double>> seTime;
int N, Q;
double convert(string time) {
    double hour = stod(time.substr(0, 2));
    hour += stod(time.substr(3, 2)) / 60.0;
    return hour;
}
void setDistance() {
    dist["Seoul"] = 0.0;
    dist["Yeongdeungpo"] = 9.1;
    dist["Anyang"] = 23.9;
    dist["Suwon"] = 41.5;
    dist["Osan"] = 56.5;
    dist["Seojeongri"] = 66.5;
    dist["Pyeongtaek"] = 75.0;
    dist["Seonghwan"] = 84.4;
    dist["Cheonan"] = 96.6;
    dist["Sojeongni"] = 107.4;

    dist["Jeonui"] = 114.9;
    dist["Jochiwon"] = 129.3;
    dist["Bugang"] = 139.8;
    dist["Sintanjin"] = 151.9;
    dist["Daejeon"] = 166.3;
    dist["Okcheon"] = 182.5;
    dist["Iwon"] = 190.8;
    dist["Jitan"] = 196.4;
    dist["Simcheon"] = 200.8;
    dist["Gakgye"] = 204.6;

    dist["Yeongdong"] = 211.6;
    dist["Hwanggan"] = 226.2;
    dist["Chupungnyeong"] = 234.7;
    dist["Gimcheon"] = 253.8;
    dist["Gumi"] = 276.7;
    dist["Sagok"] = 281.3;
    dist["Yangmok"] = 289.5;
    dist["Waegwan"] = 296.0;
    dist["Sindong"] = 305.9;
    dist["Daegu"] = 323.1;

    dist["Dongdaegu"] = 326.3;
    dist["Gyeongsan"] = 338.6;
    dist["Namseonghyeon"] = 353.1;
    dist["Cheongdo"] = 361.8;
    dist["Sangdong"] = 372.2;
    dist["Miryang"] = 381.6;
    dist["Samnangjin"] = 394.1;
    dist["Wondong"] = 403.2;
    dist["Mulgeum"] = 412.4;
    dist["Hwamyeong"] = 421.8;

    dist["Gupo"] = 425.2;
    dist["Sasang"] = 430.3;
    dist["Busan"] = 441.7;
}
int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    setDistance();
    cin >> N >> Q;
    double day = 0, last = -1;
    for (int i = 0; i < N; i++) {
        string station, start, end;
        cin >> station >> start >> end;
        double s = day * 24.0;
        double e = day * 24.0;
        if (i == 0) s = -1;
        else s += convert(start);
        if (i + 1 < N) e += convert(end);
        else e = -1;
        if (last > s) day+=1, s += 24.0, e += 24.0;
        if (s > e) day+=1, e += 24.0;
        seTime[station] = { s,e };
        last = e;
    }
    cout << fixed;
    cout.precision(6);
    for (int i = 0; i < Q; i++) {
        string station1, station2;
        cin >> station1 >> station2;
        cout << abs(dist[station2] - dist[station1]) / (seTime[station2].first - seTime[station1].second) << '\n';
    }
    return 0;
}