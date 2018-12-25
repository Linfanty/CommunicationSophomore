#include <bits/stdc++.h>
using namespace std;

const int MAXN = 20;
char ww[MAXN][MAXN];
struct City {
    int x1, y1, x2, y2;
};
int n, m;
City c[MAXN];
bool vis[MAXN][MAXN];
int dis[MAXN][MAXN];
const int xx[] = {1, -1, 0, 0};
const int yy[] = {0, 0, 1, -1};

struct Node {
    int s, e, cost;
    bool operator < (const Node a) const {
        return cost < a.cost;
    }
};
vector<Node> vecDis;
bool Check (int x, int y) {
    return x > 0 and x <= n and y > 0 and y <= n;
}

void bfs (int s) {
    memset(vis, 0, sizeof vis);
    queue <pair<int, int> > qu;
    qu.push(make_pair(c[s].x2, c[s].y2));
    vis[c[s].x2][c[s].y2] = 1;

    int disss = 0, dao = 1;
    while (!qu.empty()) {
        //cout << endl;
        auto nowVis = qu.front(); qu.pop();
           for (int j = 0; j < m; j++) {
              if (dis[s][j] == 0x3f3f3f3f and c[j].x1 == nowVis.first and c[j].y1 == nowVis.second)
                 dis[s][j] = disss;
          }
        for (int i = 0; i < 4; i++) {
            int x = nowVis.first + xx[i], y = nowVis.second + yy[i];
            if (Check(x, y)) {
                if (!vis[x][y] and ww[x][y] == '.') {
                    qu.push(make_pair(x, y)); vis[x][y] = 1;
                    //cout << x << y << endl;
                }
            }
        }
        //cout << dao << " " << disss << endl;
        if (dao) dao--;
        if (!dao) disss++, dao = qu.size();
    }
/*
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            cout << vis[i][j] << " ";
        cout << endl;
    }
    cout << endl;*/
}
/*
int f[MAXN];

int Find (int n) {
    return (f[n] == n ? n : f[n] = Find(f[n]));
}

bool Union (int a, int b) {
    int fa = Find(a);
    int fb = Find(b);
    if (fa == fb) return 0;
    f[fa] = fb;
    return 1;
}
*/

int dp[1 << 15][MAXN];

int main () {
    while (cin >> n >> m) {
        memset(dis, 0x3f, sizeof dis);
        memset(c, 0, sizeof c);
        vecDis.clear();

        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                cin >> ww[i][j];


        for (int i = 0; i < m; i++) {
            cin >> c[i].x1 >> c[i].y1 >> c[i].x2 >> c[i].y2;
        }

        for (int i = 0; i < m; i++) {
            bfs(i);
        }
/*
        cout << endl;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++)
                cout << dis[i][j] << ' ';
            cout << endl;
        }
        cout << endl;*/
/*
        for (int i = 0; i < m; i++)
            for (int j = 0; j < m; j++)
                if (i != j) vecDis.push_back((Node) {i, j, dis[i][j]});

        sort(vecDis.begin(), vecDis.end());

        int cnt = 0;
        int sum = 0;
        for (auto qwe : vecDis) {
            if (Union(qwe.s, qwe.e)) cnt++, sum += qwe.cost, cout << qwe.s << " " << qwe.e << " " << qwe.cost << endl;
            if (cnt == n - 1) break;
        }

        cout << sum << endl;
    }
*/

        memset(dp, 0x3f, sizeof dp);

        for (int i = 0; i < m; i++) {
            dp[1 << i][i] = 0;
        }

        for (int i = 0; i < (1 << m); i++) {
            for (int u = 0; u < m; u++) {
                for (int v = 0; v < m; v++) {
                    if (u != v and ((1 << u) & i) and (~i) & (1 << v))
                        dp[i | (1 << v)][v] = min (dp[i | 1 << v][v], dp[i][u] + dis[u][v]);
                }
            }
        }
/*
        for (int i = 0; i < (1 << m); i++) {
            for (int j = 0; j < m; j++) {
                if (i & (1 << j)) cout << 1;
                else cout << 0;
            }
            for (int j = 0; j < m; j++) {
                cout << " " << dp[i][j];
            }
            cout << endl;
        }
*/
        int ans = 0x3f3f3f3f;
        for (int i = 0; i < m; i++)
            ans = min (ans, dp[(1 << m) - 1][i]);
        if (ans != 0x3f3f3f3f) cout << ans << endl;
        else cout << -1 << endl;
    }

}
