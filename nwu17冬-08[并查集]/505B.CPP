#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define show(a) cout<<#a<<" = "<<a<<endl
#define show2(b,c) cout<<#b<<" = "<<b<<" "<<#c<<" = "<<c<<endl
#define show3(a,b,c) cout<<#a<<" = "<<a<<" "<<#b<<" = "<<b<<" "<<#c<<" = "<<c<<endl
const int maxn = 105;
#define LOCAL
	int u, v, w;
	int n, m, t;

int pre[maxn][maxn];

int fd(int x, int w) {
	return  x == pre[x][w] ? x : pre[x][w] = fd(pre[x][w], w); 
}

void join(int u, int v, int w)	{
	int fu = fd(u, w);
	int fv = fd(v, w);
	if(fu!=fv)
		pre[fu][w] = fv;
}

int solve(int u, int v)	{
	int cnt = 0;
	for(int i = 1; i <= m; i++) { // 遍历每种颜色
		int uu = fd(u, i);
		int vv = fd(v, i);
		if( uu == vv)	cnt++;
	}
	return cnt;
}

int main() {
    #ifdef LOCAL
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    //cin.tie(0);cin.sync_with_stdio(false);
    #endif

	cin >> n >> m;
		
	for(int i = 1; i <= max(n, m); i++) // 颜色
		for(int j = 1; j <= max(n, m); j++) // 点
			pre[j][i] = j; // 点为j的颜色为i的自己为j

	for(int i = 1; i <= m; i++) {
		cin >> u >> v >> w;
		join(u, v, w);
	}

	cin >> t;
	while(t--) {	
		cin >> u >> v;
		cout << solve(u,v) << endl;
	}
	
}