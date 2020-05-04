#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<functional>
#include<queue>
using namespace std;
typedef long long ll;
int main()
{
	ll sum, sum2, com, com2;
	ll ag, po, cr, crd, sp;
	ll ag2, po2, cr2, crd2, sp2;
	ll a, b, c, d, e;
	ll pa, pb, pc, pd, pe;
	cin >> ag >> po >> cr >> crd >> sp;
	cin >> ag2 >> po2 >> cr2 >> crd2 >> sp2;
	cin >> a >> b >> c >> d >> e;
	cin >> pa >> pb >> pc >> pd >> pe;
	sum = ag * (100 + po) * ((10000 - min(100*cr, (ll)10000)) + min(cr, (ll)100) * (crd)) * (100 + sp);
	sum2 = ag2 * (100 + po2)*((10000 - min(100*cr2, (ll)10000)) + min(cr2, (ll)100)*(crd2))*(100 + sp2);
	ag += (pa - a), po += (pb - b), cr += (pc - c), crd += (pd - d), sp += (pe - e);
	ag2 += (a - pa), po2 += (b - pb), cr2 += (c - pc), crd2 += (d - pd), sp2 += (e - pe);
	com = ag * (100 + po) * ((10000 - min(100 * cr, (ll)10000)) + min(cr, (ll)100) * (crd)) * (100 + sp);
	com2 = ag2 * (100 + po2)*((10000 - min(100 * cr2, (ll)10000)) + min(cr2, (ll)100)*(crd2))*(100 + sp2);
	if (com > sum) printf("+\n");
	if (com < sum) printf("-\n");
	if (com == sum) printf("0\n");
	if (com2 > sum2) printf("+\n");
	if (com2 < sum2) printf("-\n");
	if (com2 == sum2) printf("0\n");
	return 0;
}