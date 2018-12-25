/*给你一个二分图，N左边的点，M右边的点的，K总共的边数，L，R
要求能否删除一些边使得图中所有点的度都在区间[L,R]

思路

构造一个网络流，这是关于网路流的上下界问题。增加四个点，分别是点超级源点s，超级汇点t,还有两个属于上下界问题的xx,yy节点。
题目这样就转化为了一个有汇源上下界限的可行流了。
*/
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
const int maxn = 4050;
const int INF = 0x3f3f3f3f;
const ll mod = 1000000007;
 
int n, m, k, s, t, S, T;
int l, r, no,
 a, b;
int head[maxn], level[maxn];
struct node
{
    int to, nxt;
    int f;
}e[maxn * 7];
void add(int a, int b, int w)
{
    e[no].to = b, e[no].nxt = head[a], e[no].f = w;
    head[a] = no++;
    e[no].to = a, e[no].nxt = head[b], e[no].f = 0;
    head[b] = no++;
}
 
bool bfs(int s, int t)
{
    memset(level, -1, sizeof(level));
    level[s] = 0;
    queue<int>q;
    q.push(s);
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(int i = head[u];i != -1;i = e[i].nxt)
        {
            int v = e[i].to;
            if(level[v] == -1 && e[i].f > 0)
            {
                level[v] = level[u] + 1;
                q.push(v);
                if(v == t) return true;
            }
        }
    }
    return level[t] != -1;
}
 
int dfs(int s, int t, int f)
{
    if(s == t || f == 0) return f;
    int tmp, ret = 0;
    for(int i = head[s];i != -1;i = e[i].nxt)
    {
        int v = e[i].to;
        if(level[v] == level[s] + 1 && e[i].f > 0 && (tmp = dfs(v, t, min(f, e[i].f))))
        {
            e[i].f -= tmp;
            e[i^1].f += tmp;
            ret += tmp;
            f -= tmp;
            if(f == 0) break;
        }
    }
    if(f > 0) level[s] = -1;
    return ret;
}
 
int dinic(int s, int t)
{
    int res = 0;
    while(bfs(s, t))
    {
        int tmp = dfs(s, t, INF);
        res += tmp;
    }
    return res;
}
 
int main()
{
    int kase = 0;
    while(scanf("%d%d%d", &n, &m, &k) != EOF)
    {
        no = 0;
        memset(head, -1, sizeof(head));
        s = n+m + 1, t = n+m + 2;
        S = 0, T = n+m + 3;
        scanf("%d%d", &l ,&r);
        for(int i = 0;i < k;i++)
        {
            scanf("%d%d", &a, &b);
            add(a, b + n, 1);
        }
        add(t, s, INF);
        for(int i = 1;i <= n;i++)
        {
            add(s, i, r - l);
            add(S, i, l), add(s, T, l);
        }
        for(int i = 1;i <= m;i++)
        {
            add(i + n, t, r - l);
            add(i + n, T, l), add(S, t, l);
        }
        printf("Case %d: ", ++kase);
        int ans = dinic(S, T);
        if(ans == (n + m)*l) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}