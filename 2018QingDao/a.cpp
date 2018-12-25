#include <bits/stdc++.h>
using namespace std;
/*
 ZOJ - 4067
���⣺���飬���밴�����˳��ȥ��������ǰǮ��������ļ۸�ͱ�����
˼· �����������1�������޶��ǮҲ��ֻ����m�������Richman��
2,���۴����ٶ��������impossible��3�Ϸ����̰����һ�����ֵ��
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
