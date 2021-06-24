#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<cmath>
#include<map>
using namespace std;
typedef long long ll;
char input[105][105],output[105][105];
int main() {
	int N, M;
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++) {
			cin >> input[i][j];
			if (input[i][j] == '.') output[i][j] = '.';
			if (input[i][j] == 'O') output[i][j] = 'O';
			if (input[i][j] == '-') output[i][j] = '|';
			if (input[i][j] == '|') output[i][j] = '-';
			if (input[i][j] == '/') output[i][j] = '\\';
			if (input[i][j] == '\\') output[i][j] = '/';
			if (input[i][j] == '^') output[i][j] = '<';
			if (input[i][j] == '<') output[i][j] = 'v';
			if (input[i][j] == 'v') output[i][j] = '>';
			if (input[i][j] == '>') output[i][j] = '^';
		}
	for (int j = M; j >= 1; j--) {
		for (int i = 1; i <= N; i++)
			cout << output[i][j];
		cout << '\n';
	}
	return 0;
}