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
vector<pair<string, ll>> command;
vector<ll> nums;
string com;
int main() {
    while (true) {
        command.clear();
        nums.clear();
        ll num = 0, N;

        do {
            cin >> com;
            if (com == "QUIT") return 0;
            if (com == "NUM") cin >> num;
            command.push_back({ com, num });
        } while (com != "END");

        cin >> N;
        for (int i = 0; i < N; i++) {
            ll val; cin >> val;
            nums.push_back(val);
        }
        
        for (int idx = 0; idx < nums.size(); idx++) {
            stack<ll> s;
            s.push(nums[idx]);
            bool success = true;
            for (int i = 0; i < command.size(); i++) {
                string com = command[i].first;
                ll num = command[i].second;
                if (com == "NUM") s.push(num);
                if (com == "POP") {
                    if (s.empty()) {
                        success = false;
                        break;
                    }
                    s.pop();
                }
                if (com == "INV") {
                    if (s.empty()) {
                        success = false;
                        break;
                    }
                    ll val = s.top();
                    s.pop();
                    s.push(-val);
                }
                if (com == "DUP") {
                    if (s.empty()) {
                        success = false;
                        break;
                    }
                    ll val = s.top();
                    s.push(val);
                }
                if (com == "SWP") {
                    if (s.size() < 2) {
                        success = false;
                        break;
                    }
                    ll first = s.top();
                    s.pop();
                    ll second = s.top();
                    s.pop();
                    s.push(first);
                    s.push(second);
                }
                if (com == "ADD") {
                    if (s.size() < 2) {
                        success = false;
                        break;
                    }
                    ll first = s.top();
                    s.pop();
                    ll second = s.top();
                    s.pop();
                    ll sum = first + second;
                    if (abs(sum) > 1e9) {
                        success = false;
                        break;
                    }
                    else s.push(sum);
                }
                if (com == "SUB") {
                    if (s.size() < 2) {
                        success = false;
                        break;
                    }
                    ll first = s.top();
                    s.pop();
                    ll second = s.top();
                    s.pop();
                    ll sum = second - first;
                    if (abs(sum) > 1e9) {
                        success = false;
                        break;
                    }
                    else s.push(sum);
                }
                if (com == "MUL") {
                    if (s.size() < 2) {
                        success = false;
                        break;
                    }
                    ll first = s.top();
                    s.pop();
                    ll second = s.top();
                    s.pop();
                    ll sum = second * first;
                    if (abs(sum) > 1e9) {
                        success = false;
                        break;
                    }
                    else s.push(sum);
                }
                if (com == "DIV") {
                    if (s.size() < 2) {
                        success = false;
                        break;
                    }
                    ll first = s.top();
                    s.pop();
                    ll second = s.top();
                    s.pop();
                    int cnt = 0;
                    if (first < 0) cnt++, first = abs(first);
                    if (second < 0) cnt++, second = abs(second);
                    if (first == 0) {
                        success = false;
                        break;
                    }
                    ll sum = second / first;
                    if (cnt == 1) {
                        if (sum > 0) s.push(-sum);
                        else s.push(sum);
                    }
                    else {
                        if (sum < 0) s.push(-sum);
                        else s.push(sum);
                    }
                }
                if (com == "MOD") {
                    if (s.size() < 2) {
                        success = false;
                        break;
                    }
                    ll first = s.top();
                    s.pop();
                    ll second = s.top();
                    s.pop();
                    int cnt = 0;
                    if (second < 0) cnt++, second = abs(second);
                    if (first == 0) {
                        success = false;
                        break;
                    }
                    ll sum = second % first;
                    if (cnt == 1) {
                        if (sum > 0) s.push(-sum);
                        else s.push(sum);
                    }
                    else {
                        if (sum < 0) s.push(-sum);
                        else s.push(sum);
                    }
                }
            }
            if (s.size() != 1) success = false;
            if (success) cout << s.top() << '\n';
            else cout << "ERROR\n";
        }
        cout << '\n';
    }
    return 0;
}