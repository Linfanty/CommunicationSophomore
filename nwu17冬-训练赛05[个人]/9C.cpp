/*题目大意：给出数n（1<=n<=10^9)，求不超过n，只由0、1构成的数的个数。
分析：
1位数：1
2位数：10、11
3位数：100、101、110、111
……
即有：
k位数：a、b
k+1位数：a*10,a*10+1,b*10,b*10+1。*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, ans = 0;

void dfs(int x) {
	if( x > n) return;
	ans++;
	dfs(10*x);
	dfs(10*x+1);
}


int main() {
    cin >> n;
    dfs(1);
    cout << ans << endl;
}
