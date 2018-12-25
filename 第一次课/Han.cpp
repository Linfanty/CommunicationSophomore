#define _CRT_SBCURE_NO_DEPRECATE
#include <set>
#include <cmath>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;

const int maxn = 30307;
const int INF = 0x3f3f3f3f;
typedef long long ll;

struct Edge
{
    int from, to, dist;
    Edge(int u, int v, int d):from(u), to(v), dist(d) {}
};

struct HeapNode
{
    int d, u;
    bool operator < (const HeapNode& rhs) const {return d > rhs.d;}
};

struct Dijkstra
{
    int n, m;
    vector<Edge> edges;
    vector<int> G[maxn];
    bool done[maxn]; //是否永久标记
    int d[maxn]; //s到各个点距离
    int p[maxn]; //最短路上的一条弧

    void init(int n)
    {
        this->n = n;
        for(int i = 0; i < n; i++) G[i].clear();
        edges.clear();
    }

    void AddEdge(int from, int to, int dist)
    {
        edges.push_back(Edge(from, to, dist));
        m = edges.size();
        G[from].push_back(m-1);
    }

    void dijkstra(int s)
    {
        priority_queue<HeapNode> Q;
        for(int i = 0; i < n; i++) d[i] = INF;
        d[s] = 0;
        memset(done, false, sizeof(done));
        Q.push((HeapNode){0, s});
        while(!Q.empty())
        {
            HeapNode x = Q.top(); Q.pop();
            int u = x.u;
            if(done[u]) continue;
            done[u] = true;
            for(int i = 0; i < G[u].size(); i++)
            {
                Edge& e = edges[G[u][i]];
                if(d[e.to] > d[u] + e.dist)
                {
                    d[e.to] = d[u] + e.dist;
                    p[e.to] = G[u][i];
                    Q.push((HeapNode){d[e.to], e.to});
                }
            }
        }
    }
}QAQ;

int main(void)
{
    int n, m, a, b, c, t;
    while(cin >> n >> m)
    {
        if(!n && !m) break;
        QAQ.init(maxn);
        for(int i = 0; i < m; i++)
        {
            cin >> a >> b >> c;
            QAQ.AddEdge(a, b, c);
            QAQ.AddEdge(b, a, c);
        }
        /*
        QAQ.dijkstra(1);
        t = QAQ.d[n];
        //cout << t << endl;
        QAQ.dijkstra(n);
        cout << min(t, QAQ.d[1]) << endl;
        */
        QAQ.dijkstra(1);
        cout << QAQ.d[n] << endl;
    }
    return 0;
}
