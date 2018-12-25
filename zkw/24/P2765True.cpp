/*有n个柱子，编号为1，2…….的小环，要将它们依次套在环上，要求直接接触的两小球的和为完全平方数，那么最多可以套几个小球。
做法
没错，就是这样，是不是马上想到了暴力dfs！！！n只有55，但是你无法确定球的个数，所以dfs暴枚肯定会很慢（wjh：不然怎么出在网络流24题里）所以，我们要往网络流方面去想，而我们又要运用到网络流的反悔性质，所以很明显就会想到拆点.

      我们每一次把一个球拆成两个点，前面的点连（源点），后面的点连（汇点），权值都为1，然后中间的怎么连呢？

      很明显我们回记起来还有一个条件没有用上，那就是同一个柱子中，两个相邻的球的编号之和为完全平方数，所以如果a+b为完全平方数，那么我们就把a的前面那个店和b后面那个点连接起来，权值为一（注意：这里可能会理解错误，因为有些人可能想问x后面可以跟y，y后面可以跟z，那么是不是要把y的后面那个点与y前面那个点连起来，这样跑出来的结果才会对。。错！！！因为这个网络流中的流量只有两种状态，无解和有解，无解时跑出来的结果为0，有解时跑出来的结果>0，这样才能实现一次装一个柱子，要不你一次装多个柱子，那你怎么加点。。对吧!？）

      我们每次加一个点，然后跑一次网络流，如果有解，那么就继续加点，否则，就将它压在第二个柱子的最底下，也就是里面的head[]数组。
input = 4

11
1 3 6 10
2 7 9
4 5 11
8
*/

/*
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#include <cmath>
#include <map>
using namespace std;
const int maxn = 2e5 + 10;
const int INF = 1e9 + 7;
typedef long long LL;
int st = 0, ed = 4000;
#include <iostream>
#define show(a) cout<<#a<<" = "<<a<<endl
#define show2(b,c) cout<<#b<<" = "<<b<<" "<<#c<<" = "<<c<<endl
#define show3(a,b,c) cout<<#a<<" = "<<a<<" "<<#b<<" = "<<b<<" "<<#c<<" = "<<c<<endl
#define show4(a,b,c,d) cout<<#a<<" = "<<a<<" "<<#b<<" = "<<b<<" "<<#c<<" = "<<c<<" "<<#d<<" = "<<d<<endl

struct node {
    int from, to, cap, flow;
};
struct Dinic {
    int n, m, s, t;
    vector<node>nodes;
    vector<int>g[maxn];
    int vis[maxn], d[maxn], cur[maxn];
    void clearall(int n) {
        for (int i = 0 ; i < n ; i++) g[i].clear();
        nodes.clear();
    }
    void clearflow() {
        int len = nodes.size();
        for (int i = 0 ; i < len ; i++) nodes[i].flow = 0;
    }
    void add(int from, int to, int cap) {
        nodes.push_back((node) {
            from, to, cap, 0
        });
        nodes.push_back((node) {
            to, from, 0, 0
        });
        m = nodes.size();
        g[from].push_back(m - 2);
        g[to].push_back(m - 1);
    }
    bool bfs() {
        memset(vis, 0, sizeof(vis));
        queue<int>q;
        q.push(s) ;
        d[s] = 0;
        vis[s] = 1;
        while(!q.empty()) {
            int x = q.front();
            q.pop();
            int len = g[x].size();
            for (int i = 0 ; i < len ; i++) {
                node & e = nodes[g[x][i]];
                if (!vis[e.to] && e.cap > e.flow ) {
                    vis[e.to] = 1;
                    d[e.to] = d[x] + 1;
                    q.push(e.to);
                }
            }
        }
        return vis[t];
    }
    int dfs(int x, int a) {
        if (x == t || a == 0  ) return a;
        int flow = 0, f, len = g[x].size();
        for (int & i = cur[x] ; i < len ; i++) {
            node & e = nodes[g[x][i]];
            if (d[x] + 1 == d[e.to] && (f = dfs(e.to, min(a, e.cap - e.flow))) > 0 ) {
                e.flow += f;
                nodes[g[x][i] ^ 1].flow -= f;
                flow += f;
                a -= f;
                if (a == 0) break;
            }
        }
        return flow;
    }
    int maxflow(int a, int b) {
        s = a;
        t = b;
        int flow = 0;
        while(bfs()) {
            memset(cur, 0, sizeof(cur));
            flow += dfs(s, INF) ;
        }
        return flow;
    }
    void print(int  u) {
        vis[u] = 1;
        for (int i = 0 ; i < (int)g[u].size() ; i++ ) {
            node & e = nodes[g[u][i]];
            if (!vis[e.to] && e.flow == 1 && e.from != st && e.to != ed) {
                printf(" %d", e.to - ed / 2);
                print(e.to - ed / 2);
            }
        }
    }
} f;



求最大匹配数，
点数=两点最大匹配数+最小路径覆盖数，
它给的n就是最小路径覆盖数，网络流跑最大匹配数

int main() {
    int n;
    scanf("%d", &n);
    int flow = 0, num = 0;
    while(num - flow <= n ) {
        num += 1;
        f.add(st, num, 1);
        f.add(num + ed / 2, ed, 1);
        for (int i = 1 ; i < num ; i++) { 
            if ((int)sqrt(i + num) == sqrt(i + num)) // i + num 为完全平数 ！
                // show4(i, num, num + ed/2, sqrt(i + num));
                f.add(i, num + ed / 2, 1);
            
        }
        int ttt = f.maxflow(st, ed);
        //cout << ttt << endl;
        flow += ttt;
    }

    num -= 1;
    f.clearall(ed);
    f.clearflow();
    memset(f.vis, 0, sizeof(f.vis));
    for (int i = 1 ; i <= num ; i++) {
        f.add(0, i, 1);
        f.add(i + ed / 2, ed, 1);
        for (int j = 1 ; j < i ; j++) {
            if ((int)sqrt(i + j) == sqrt(i + j)) f.add(j, i + ed / 2, 1);
        }
    }
    f.maxflow(st, ed);
    printf("%d\n", num);



    memset(f.vis, 0, sizeof(f.vis)) ;
    for (int i = 1 ; i <= num ; i++) {
        if (!f.vis[i]) {
            printf("%d", i);
            f.print(i);
            printf("\n");
        }
    }
    return 0;
}
*/
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>

int n;//共有柱子 
int spend=0;//开始用第几根柱子 
int tot_ball=0;
int begin,end;
int head[60];//第i根柱子在柱底的是第几号球 
struct edge{int y,next,c;};
edge s[400010];
int first[200010];
int match[50010];
int len=1;
int h[50010];
int f[100010];

void ins(int x,int y,int c)
{
    len++;
    s[len].y=y;s[len].c=c;
    s[len].next=first[x];first[x]=len;
}

int min(int x,int y){
    return x<y?x:y;
}

bool bfs()
{
    int st=1,ed=2;
    f[st]=begin;
    memset(h,0,sizeof(h));
    h[begin]=1;
    while(st!=ed)
    {
        int x=f[st];
        for(int i=first[x];i!=0;i=s[i].next)
        {
            int y=s[i].y;
            if(h[y]==0 && s[i].c>0)
            {
                h[y]=h[x]+1;
                f[ed]=y;
                ed++;
                if(ed==100000) ed=1;
            }
        }
        st++;
        if(st==100000) st=1;
    }
    return h[end];
}

int dfs(int x,int t)
{
    if(x==end) return t;
    int tot=0,flow=0;
    for(int i=first[x];i!=0;i=s[i].next)
    {
        if(tot==t) return t;
        int y=s[i].y;
        if(s[i].c>0 && h[y]==h[x]+1)
        {
            flow=dfs(y,min(s[i].c,t-tot));
            tot+=flow;s[i].c-=flow;s[i^1].c+=flow;
            if(flow!=0 && y!=begin && y!=end && x%2==0)
                match[x>>1]=y>>1;
        }
    }
    if(tot==0) h[x]=0;
    return tot;
}

int dinic()
{
    int tot=0;
    int dx;
    while(bfs())
    {
        dx=dfs(begin,1e9);
        while(dx!=0)
        {
            tot+=dx;
            dx=dfs(begin,1e9);
        }
    }
    return tot;
}

int main()
{
    scanf("%d",&n);
    begin=1;end=50000;
    while(spend<=n)
    {
        tot_ball++;
        ins(begin,tot_ball<<1,1);ins(tot_ball<<1,begin,0);
        ins((tot_ball<<1)|1,end,1);ins(end,(tot_ball<<1)|1,0);
        for(int i=sqrt(tot_ball)+1;i*i<2*tot_ball;i++)
        {
            ins((i*i-tot_ball)<<1,(tot_ball<<1)|1,1),ins((tot_ball<<1)|1,(i*i-tot_ball)<<1,0);
        }
        int k=dinic();
        if(k==0) {
        //因为没有流量流到汇点（也就是说，这个球只能放到下一个柱子了）； 
        //所以我们把它设为下一个柱子的开头 
            spend++;
            cout << spend << ' ' << tot_ball << endl;
            head[spend]=tot_ball;
        }
    }
    printf("%d\n",tot_ball-1);
    bool visit[50010];//第i号球是否用过 
    memset(visit,false,sizeof(visit));
    for(int i=1;i<=n;i++)
    {
        if(visit[head[i]]) continue;
        int now=head[i];
        while(now!=0 && visit[now]==false)
        {
            printf("%d ",now);
            visit[now]=true;
            now=match[now];
        }
        printf("\n");
    }
}