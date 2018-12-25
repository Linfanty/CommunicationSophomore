#include<bits/stdc++.h>
using namespace std;

const int MAXN = 100000 + 10;
int vis[MAXN];
vector<int> from[MAXN];
int to[MAXN];
vector<int> wId;

int main() {
    int T; scanf("%d", &T);
    while (T--) {
        int n; scanf("%d", &n);
        memset(vis, 0, sizeof vis);
        memset(from, 0, sizeof from);
        memset(to, 0, sizeof to);
        for (int i = 0; i < MAXN; i++) from[i].clear();
        wId.clear();
        for (int i = 1; i <= n; i++) {
            int x; scanf("%d", &x);
            char str[15]; scanf("%s", str);
            if (str[0] == 'v') to[i] = x, from[x].push_back(i);
            else to[i] = -x, from[x].push_back(-i);
        }
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            if (vis[i]) continue;
            int j = i, bufCnt = 0, bufId = 0;
            for (; vis[j] == 0; j = abs(to[j])) vis[j] = i;
            for (; vis[j] == i; j = abs(to[j]))
                vis[j] = -i, bufCnt += (to[j] < 0 ? bufId = abs(to[j]), 1 : 0);
            if (bufCnt == 1) cnt++, wId.push_back(bufId);
            //cout << bufCnt << " " << bufId << endl;
        }
        for (int w : wId) {
            queue<int> que; que.push(w);
            while (!que.empty()) {
                int ww = que.front(); que.pop();
                for (int ee : from[ww])
                    if (ee > 0) cnt++, que.push(ee);
            }
        }
        printf("0 %d\n", cnt);
    }
}
