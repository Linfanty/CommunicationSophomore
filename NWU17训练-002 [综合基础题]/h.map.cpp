#pragma GCC diagnostic error "-std=c++11"
#include <bits/stdc++.h>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
#define FIN freopen("in.txt","r",stdin)
#define IO ios_base::sync_with_stdio(0),cin.tie(0)
#define pb push_back
typedef long long LL;
typedef pair<int, int> PIR;
#include <vector>

const int maxn = 55;

int T, n, x;
string s1, s2;
map <string, set <string> > adr;
map <string, map <string, int> > cnt;

int main ()
{//IO;
	cin >> T;
	int fir = 0;
	while (T--) {
		cin >> n;
		adr.clear();
		cnt.clear();
		for (int i = 1; i <= n; ++i) {
			cin >> s1 >> s2 >> x;
			adr[s2].insert(s1);
			cnt[s2][s1] += x;
		}
		if (fir) cout << endl;
		fir++;
		for (auto it:adr) {
			cout << it.first << endl;
			for (auto v:it.second)
                cout << "   |----" << v << "("
                << cnt[it.first][v] << ")" << endl;
		}
	}
	return 0;
}
