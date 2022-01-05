#include<iostream>
#include<map>
#include<queue>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
typedef long long ll;
int n;
vector<int> v[26];
void preorder(int now) {
	char alpha = now + 'A';
	cout << alpha;
	if (v[now][0] + 'A' != '.') preorder(v[now][0]);
	if (v[now][1] + 'A' != '.') preorder(v[now][1]);
}
void inorder(int now) {
	char alpha = now + 'A';
	if (v[now][0] + 'A' != '.') inorder(v[now][0]);
	cout << alpha;
	if (v[now][1] + 'A' != '.') inorder(v[now][1]);
}
void postorder(int now) {
	char alpha = now + 'A';
	if (v[now][0] + 'A' != '.') postorder(v[now][0]);
	if (v[now][1] + 'A' != '.') postorder(v[now][1]);
	cout << alpha;
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		char a, b, c; cin >> a >> b >> c;
		v[a - 'A'].push_back(b - 'A');
		v[a - 'A'].push_back(c - 'A');
	}
	preorder(0);
	cout << '\n';
	inorder(0);
	cout << '\n';
	postorder(0);
	return 0;
}