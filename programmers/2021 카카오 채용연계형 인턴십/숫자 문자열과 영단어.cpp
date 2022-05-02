#include <string>
#include <vector>
#include <unordered_map>
using namespace std;
unordered_map<string, int> m;
void stringToNum() {
    m["zero"] = 1;
    m["one"] = 2;
    m["two"] = 3;
    m["three"] = 4;
    m["four"] = 5;
    m["five"] = 6;
    m["six"] = 7;
    m["seven"] = 8;
    m["eight"] = 9;
    m["nine"] = 10;
}
int solution(string s) {
    stringToNum();
    int answer = 0;
    for (int i = 0; i < s.size();) {
        answer *= 10;
        int num = s[i] - '0';
        if (0 <= num && num <= 9) {
            answer += num;
            i++;
        }
        else {
            string alphabets = "";
            while (!m[alphabets]) {
                alphabets += s[i++];
            }
            answer += (m[alphabets] - 1);
        }
    }
    return answer;
}