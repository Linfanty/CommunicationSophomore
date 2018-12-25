#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 4e5 + 10;
const int INF = 0x3f3f3f3f;

//终点 容量 反向边
struct Edge
{
    int to;
    ll cap;
    int rev;
};

vector<Edge> G[N];
int level[N];
int iter[N];
void add_edge(int from, int to, ll cap)
{
    G[from].push_back((Edge){to, cap, (int)G[to].size()});
    G[to].push_back((Edge){from, 0, (int)G[from].size() - 1});
}
void bfs(int s)
{
    memset(level, -1, sizeof(level));
    queue<int> que;
    level[s] = 0;
    que.push(s);
    while(!que.empty())
    {
        int v = que.front(); que.pop();
        for(int i = 0; i < G[v].size(); i++)
        {
            Edge &e = G[v][i];
            if(e.cap > 0 && level[e.to] < 0)
            {
                level[e.to] = level[v] + 1;
                que.push(e.to);
            }
        }
    }
}

ll dfs(int v, int t, ll f)
{
    if(v == t) return f;
    for(int &i = iter[v]; i < G[v].size(); i++)
    {
        Edge &e = G[v][i];
        if(e.cap > 0 && level[v] < level[e.to])
        {
            ll d = dfs(e.to, t, min(f, e.cap));
            if(d > 0)
            {
                e.cap -= d;
                G[e.to][e.rev].cap += d;
                return d;
            }
        }
    }
    return 0;
}

ll max_flow(int s, int t)
{
    ll flow = 0;
    while(1)
    {
        bfs(s);
        if(level[t] < 0) return flow;
        memset(iter, 0, sizeof(iter));
        ll f;
        while((f = dfs(s, t, INF)) > 0) {
            flow += f;
        }
    }
}

int n, m, d, s, t, f;
int main() {
    //freopen("in.txt", "r", stdin);
    
    while ( ~scanf("%d %d %d", &n, &f, &d) ) {
        s = 0, t = d + f + 2 * n + 1;

        for(int i = 0; i <= N; i++)
            G[i].clear();

        ll sum = 0;
        ll tmp;
        for(int i = 1; i <= f; i++) {
            scanf("%lld", &tmp);
            add_edge(0, i, tmp);
        }
        for(int i = 1; i <= d; i++) {
            scanf("%lld", &tmp);
            add_edge(i + f + n*2, t, tmp);
        }

        char str[505];
        // http://dl2.iteye.com/upload/attachment/0073/8833/c84db2a4-9f00-37b7-ae37-075c5f843d25.jpg
        for(int i = 1; i <= n; i++) {
            scanf("%s", str);
            add_edge(i + f, i + f + n, 1);
            for(int j = 1; j <= f; j++) 
                if( str[j-1] == 'Y')
                    add_edge(j, i + f, 1);
        }
        for(int i = 1; i <= n; i++) {
            scanf("%s", str);
            for(int j = 0; j <= d; j++) 
                if( str[j-1] == 'Y')
                    add_edge(i + f + n, j + f + n*2, 1);
        }


        printf("%lld\n", max_flow(s, t));
    }
    return 0;
}
