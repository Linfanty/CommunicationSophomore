#include <bits/stdc++.h>
using namespace std;
/*
 ZOJ - 4067
题意：买书，必须按照书的顺序去遍历，当前钱数大于书的价格就必须买。
思路 ：三种情况：1，带无限多的钱也就只能买m本，输出Richman。
2,无论带多少都不行输出impossible，3合法情况贪心求一个最大值，
4
4 2
1 2 4 8
4 0
100 99 98 97
2 2
10000 10000
5 3
0 0 0 0 1

6
96
Richman
Impossible
*/
int n, m;
int a[100005];

int main() {
    int t, tmp;
    cin >> t;
    while( t-- ) {
        cin >> n >> m;

        int cnt = 0, num = 0;
        for(int i = 1; i <= n; ++i) {
            cin >> tmp;
            if(tmp == 0) num++;
            else a[++cnt] = tmp;
        }

        if(n == m) { ///
            cout << "Richman\n";
            continue;
        }
        if(m < num) { /// 3 < 4
            cout << "Impossible\n";
            continue;
        }

        m -= num;
        long long sum = 0;
        int maxn = 0x3f3f3f3f;

        for(int i = 1; i <= cnt; ++i) {
            if(i <= m) sum += a[i];
            else maxn = min(maxn, a[i]);
        }

        sum += maxn - 1;
        cout << sum << endl;
    }
}
