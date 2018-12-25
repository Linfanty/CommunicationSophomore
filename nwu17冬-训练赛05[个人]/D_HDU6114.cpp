/* 假设矩阵的长边为n，短边为m，那么按题意摆放最多能放m个車，
题目就转化为我们从1~n里边随意选择m个数，
然后把它们按前后顺序挨个放在1~m即可
*/
#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1005;
#define LOCAL
ll mod = 1e9+7, c[maxn][maxn];

int main() {
    #ifdef LOCAL
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    #endif

	memset(c, 0, sizeof c);
	c[0][0] = c[1][0] = c[1][1] = 1;
	
	for(int i = 2; i <= 100; i++) {
		c[i][0] = c[i][i] = 1;
		for(int j = 1; j < i; j++)
			c[i][j] = (c[i-1][j] + c[i-1][j-1]) % mod; 
	}
    
    int t;
    cin >> t;
    while( t-- ) {
    	int n, m;
    	cin >> n >> m;
    	cout << c[max(m,n)][min(m,n)] << endl;
    }
}