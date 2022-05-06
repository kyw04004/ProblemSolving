#include <string>
#include <vector>
#include <stack>
using namespace std;
struct Node {
    int n;
    Node* prev;
    Node* next;
    Node(int n, Node* prev, Node* next) : n(n), prev(prev), next(next) {}
};
stack<Node*> s;
int chk[1000005];
string solution(int n, int k, vector<string> cmd) {
    string answer = "";
    Node* cursor = new Node(0, NULL, NULL);
    for (int i = 1; i < n; i++) {
        cursor->next = new Node(i, cursor, NULL);
        cursor = cursor->next;
    }
    while (cursor->prev != NULL) cursor = cursor->prev;
    for (int i = 0; i < k; i++) cursor = cursor->next;
    for (string command : cmd) {
        if (command[0] == 'U') {
            int num = stoi(command.substr(2));
            for (int i = 0; i < num; i++) cursor = cursor->prev;
        }
        if (command[0] == 'D') {
            int num = stoi(command.substr(2));
            for (int i = 0; i < num; i++) cursor = cursor->next;
        }
        if (command[0] == 'C') {
            s.push(cursor);
            if (cursor->prev != NULL) cursor->prev->next = cursor->next;
            if (cursor->next != NULL) cursor->next->prev = cursor->prev;
            if (cursor->next == NULL) cursor = cursor->prev;
            else cursor = cursor->next;
        }
        if (command[0] == 'Z') {
            Node* r = s.top();
            s.pop();
            if (r->prev != NULL) r->prev->next = r;
            if (r->next != NULL) r->next->prev = r;
        }
    }
    while (cursor->prev != NULL) cursor = cursor->prev;
    while (cursor->next != NULL) chk[cursor->n] = 1, cursor = cursor->next;
    chk[cursor->n] = 1;
    for (int i = 0; i < n; i++) {
        if (chk[i] == 1) answer += 'O';
        else answer += 'X';
    }
    return answer;
}