#include<iostream>
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
string str;
bool can() {
    if (str.size() % 2 == 1) return false;
    stack<char> s;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '(' || str[i] == '[') s.push(str[i]);
        else {
            if (s.empty()) return false;
            if (s.top() == '(') {
                if (str[i] == ')') s.pop();
                else return false;
            }
            else {
                if (str[i] == ']') s.pop();
                else return false;
            }
        }
    }
    if (s.empty()) return true;
    return false;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> str;
    if (!can()) cout << 0;
    else {
        int sum = 0;
        int now = 1;
        stack<int> s;
        for (int i = 0; i < str.size();) {
            if (str[i] == '(') {
                s.push(str[i++]);
                now *= 2;
            }
            else if (str[i] == '[') {
                s.push(str[i++]);
                now *= 3;
            }
            else {
                sum += now;
                while (str[i] == ')' || str[i] == ']') {
                    s.pop();
                    if (str[i] == ')') now /= 2;
                    if (str[i] == ']') now /= 3;
                    i++;
                }
            }
        }
        cout << sum;
    }
    return 0;
}
