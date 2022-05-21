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
int N;
unordered_map<char, pair<int, int>> m;
pair<int, int> king, stone;
void kingMove(string command) {
    for (char c : command) {
        king.first += m[c].first;
        king.second += m[c].second;
    }
}
void kingReturn(string command) {
    for (char c : command) {
        king.first -= m[c].first;
        king.second -= m[c].second;
    }
}
void stoneMove(string command) {
    for (char c : command) {
        stone.first += m[c].first;
        stone.second += m[c].second;
    }
}
void stoneReturn(string command) {
    for (char c : command) {
        stone.first -= m[c].first;
        stone.second -= m[c].second;
    }
}
int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    m['R'] = { 0,1 }, m['L'] = { 0,-1 }, m['B'] = { 1,0 }, m['T'] = { -1,0 };
    string location;
    cin >> location;
    king = {9 - (location[1] - '0'), location[0] - 'A' + 1};
    cin >> location;
    cin >> N;
    stone = { 9 - (location[1] - '0'), location[0] - 'A' + 1 };
    for (int i = 0; i < N; i++) {
        string command; cin >> command;
        bool isStoneMoved = false;
        kingMove(command);
        if (king == stone) {
            isStoneMoved = true;
            stoneMove(command);
        }
        if (king.first < 1 || king.first > 8 || king.second < 1 || king.second > 8) {
            if (isStoneMoved) stoneReturn(command);
            kingReturn(command);
        }
        else  if (stone.first < 1 || stone.first > 8 || stone.second < 1 || stone.second > 8) {
            stoneReturn(command);
            kingReturn(command);
        }
    }
    cout << char('A' + (king.second - 1)) << (9 - king.first) << '\n';
    cout << char('A' + (stone.second - 1)) << (9 - stone.first);
}
