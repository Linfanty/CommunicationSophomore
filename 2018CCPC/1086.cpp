#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod = 1e9 + 7;

struct Node {
    int v, w;
    Node() {}
    Node(int v, int w) : v(v), w(w) {}
};

int nn;
ll ret, sum[100005];
vector<Node> G[100005];

void dfs(int rt, int pre) {
    sum[rt] = 1;
    for (int i = 0; i < G[rt].size(); i++) {
        Node& e = G[rt][i];
        int son = e.v;
        if (son == pre) continue;

        dfs(son, rt);
        sum[rt] = (sum[son] + sum[rt] ) % mod;
        ll tmp = (sum[son] * (nn - sum[son])) % mod;
        ll tmp2 = e.w % mod;
        ll tmp3 = (tmp *  tmp2) % mod;
        ret += tmp3;
    }
}

int main() {
    while( scanf("%d", &nn) != EOF) {
        memset(sum, 0, sizeof(sum));
        for (int i = 0; i < nn; i++) G[i].clear();
        ret = 0;
        int u, v, w;

        for (int i = 0; i < nn - 1; i++) {
            scanf("%d %d %d", &u, &v, &w);
            G[u-1].push_back(Node(v-1, w));
            G[v-1].push_back(Node(u-1, w));
        }
        dfs(0, -1);
        ret *= 2;

        for (int i = 2; i < nn; i++) {
            ret = i * ret;
            ret = ret % mod;
        }
        printf("%lld\n", ret);
    }
}
