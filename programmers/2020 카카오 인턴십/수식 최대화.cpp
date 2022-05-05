#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
typedef long long ll;
vector<char> v[6] = { {'+', '-', '*'}, {'+', '*', '-'}, {'-', '+', '*'},
                   {'-', '*', '+'}, {'*', '-', '+'}, {'*', '+', '-'} };
long long solution(string expression) {
    ll answer = 0;
    //총 6가지의 경우의 수 탐색
    for (int i = 0; i < 6; i++) {
        string newCom = expression;
        ll first = 0, second = 0;
        char mark1 = 'x';
        //주어진 우선 순위대로 연산 실시
        for (int p = 0; p < 3; p++) {
            string com = newCom;
            newCom = "";
            char prority = v[i][p];
            int j;
            cout << prority << ' ' << "before = " << ' ' << com << '\n';
            for (j = 0; j < com.size(); j++) {
                if ('0' <= com[j] && com[j] <= '9') {
                    if (mark1 == 'x') {
                        first *= 10;
                        if (first >= 0)  first += com[j] - '0';
                        else first -= com[j] - '0';
                    }
                    else {
                        second *= 10;
                        if (second >= 0)  second += com[j] - '0';
                        else second -= com[j] - '0';
                    }
                }
                else {
                    if (mark1 == 'x') {
                        if (first == 0 && com[j] == '-') {
                            first -= com[j + 1] - '0';
                            j++;
                        }
                        else {
                            mark1 = com[j];
                            if (com[j + 1] == '-') {
                                second -= com[j + 2] - '0';
                                j += 2;
                            }
                        }
                    }
                    else {
                        if (mark1 == prority) {
                            if (mark1 == '+') first = first + second, second = 0, mark1 = com[j];
                            else if (mark1 == '-') first = first - second, second = 0, mark1 = com[j];
                            else if (mark1 == '*') first = first * second, second = 0, mark1 = com[j];
                        }
                        else {
                            newCom += to_string(first);
                            newCom += mark1;
                            first = second;
                            second = 0;
                            mark1 = com[j];
                        }
                        if (com[j + 1] == '-') {
                            second -= com[j + 2] - '0';
                            j += 2;
                        }
                    }
                }
            }
            if (mark1 == prority) {
                if (mark1 == '+') first = first + second;
                else if (mark1 == '-') first = first - second;
                else if (mark1 == '*') first = first * second;
                newCom += to_string(first);
            }
            else {
                newCom += to_string(first);
                if (mark1 != 'x') {
                    newCom += mark1;
                    newCom += to_string(second);
                }
                else answer = max(answer, (ll)abs(first));
            }
            first = 0;
            second = 0;
            mark1 = 'x';
            cout << "after = " << ' ' << newCom << '\n';
        }
        answer = max(answer, abs(stoll(newCom)));
    }
    return answer;
}