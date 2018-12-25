#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod = 1e9 + 7;
const int MAXN = 100000 + 5;
struct TNode {
    int v, w;
    TNode() {}
    TNode(int v, int w) : v(v), w(w) {}
};
int N;
vector<TNode> G[MAXN];
ll sum[MAXN];
ll ans;

void init() {
    memset(sum, 0, sizeof(sum));
    for (int i = 0; i < N; i++) G[i].clear();
}

void dfs(int root, int father) {
    sum[root] = 1;
    for (int i = 0; i < G[root].size(); i++) {
        TNode& e = G[root][i];
        int son = e.v;
        if (son == father) continue;
        dfs(son, root); /// dfs ºó´¦Àí sum¡¾root¡¿

        sum[root] = (sum[son] + sum[root] ) % mod;
        ans += (((sum[son] * (N - sum[son])) % mod  * e.w % mod ) % mod );
    }
}

int main() {
    while (~scanf("%d", &N)) {
        init();
        int u, v, w;
        for (int i = 0; i < N - 1; i++) {
            scanf("%d %d %d", &u, &v, &w);
            G[u-1].push_back(TNode(v-1, w));
            G[v-1].push_back(TNode(u-1, w));
        }
        ans = 0;
        dfs(0, -1);
        ans *= 2;
        for (int i = 2; i < N; i++) ans *= i, ans %= mod;
        cout << ans << endl;
    }
}
