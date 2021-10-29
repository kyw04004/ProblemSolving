#include<iostream>
using namespace std;
int n,a,b,ans=1;
int main() {
    cin >> n >> a >> b;
    while( ((a+1)/2) != ((b+1)/2) ) {
        ans++;
        a = (a+1)/2;
        b = (b+1)/2;
    }
    cout << ans;
}
