#include <string>
#include <vector>
#include <stack>
using namespace std;
stack <int> s;
int N;
int solution(vector<vector<int>> board, vector<int> moves) {
	N = board.size();
	int answer = 0;
	for (int i = 0; i < moves.size(); i++) {
		int num = moves[i] - 1;
		for (int j = 0; j < N ; j++) {
			if (board[j][num] != 0) {
				if (!s.empty() && s.top() == board[j][num]) {
					s.pop();
					answer += 2;
				}
				else s.push(board[j][num]);
				board[j][num] = 0;
				break;
			}
		}
	}
	return answer;
}