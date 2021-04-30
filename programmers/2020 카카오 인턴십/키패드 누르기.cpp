#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
int keypad[4][3];
string solution(vector<int> numbers, string hand) {
	string answer = "";
	pair<int, int> left = { 3, 0 }, right = { 3, 2 };
	for (int i = 0; i < numbers.size(); i++) {
		if (numbers[i] == 1) {
			answer += "L";
			left = { 0,0 };
		}
		if (numbers[i] == 4) {
			answer += "L";
			left = { 1,0 };
		}
		if (numbers[i] == 7) {
			answer += "L";
			left = { 2,0 };
		}
		if (numbers[i] == 3) {
			answer += "R";
			right = { 0,2 };
		}
		if (numbers[i] == 6) {
			answer += "R";
			right = { 1,2 };
		}
		if (numbers[i] == 9) {
			answer += "R";
			right = { 2,2 };
		}

		if (numbers[i] == 2) {
			int Lcnt = abs(left.first - 0) + abs(left.second - 1);
			int Rcnt = abs(right.first - 0) + abs(right.second - 1);
			if (Lcnt == Rcnt) {
				if (hand == "left") {
					answer += "L";
					left = { 0, 1 };
				}
				else {
					answer += "R";
					right = { 0, 1 };
				}
			}
			else if (Lcnt > Rcnt) {
				answer += "R";
				right = { 0, 1 };
			}
			else {
				answer += "L";
				left = { 0, 1 };
			}
		}
		if (numbers[i] == 5) {
			int Lcnt = abs(left.first - 1) + abs(left.second - 1);
			int Rcnt = abs(right.first - 1) + abs(right.second - 1);
			if (Lcnt == Rcnt) {
				if (hand == "left") {
					answer += "L";
					left = { 1, 1 };
				}
				else {
					answer += "R";
					right = { 1, 1 };
				}
			}
			else if (Lcnt > Rcnt) {
				answer += "R";
				right = { 1, 1 };
			}
			else {
				answer += "L";
				left = { 1, 1 };
			}
		}
		if (numbers[i] == 8) {
			int Lcnt = abs(left.first - 2) + abs(left.second - 1);
			int Rcnt = abs(right.first - 2) + abs(right.second - 1);
			if (Lcnt == Rcnt) {
				if (hand == "left") {
					answer += "L";
					left = { 2, 1 };
				}
				else {
					answer += "R";
					right = { 2, 1 };
				}
			}
			else if (Lcnt > Rcnt) {
				answer += "R";
				right = { 2, 1 };
			}
			else {
				answer += "L";
				left = { 2, 1 };
			}
		}
		if (numbers[i] == 0) {
			int Lcnt = abs(left.first - 3) + abs(left.second - 1);
			int Rcnt = abs(right.first - 3) + abs(right.second - 1);
			if (Lcnt == Rcnt) {
				if (hand == "left") {
					answer += "L";
					left = { 3, 1 };
				}
				else {
					answer += "R";
					right = { 3, 1 };
				}
			}
			else if (Lcnt > Rcnt) {
				answer += "R";
				right = { 3, 1 };
			}
			else {
				answer += "L";
				left = { 3, 1 };
			}
		}
	}
	return answer;
}