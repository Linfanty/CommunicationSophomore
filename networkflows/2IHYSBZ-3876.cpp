/*上下界费用流。。。

这道题再次让我体会到建图的技巧性，，，我建的图跑出来6000ms+。。。。排行榜前几名的建图跑出来只有几百ms、、

一开始我的建图是这样建的、、、

对于每条边u->v，，都从超级源点拉一条容量为1，话费为cost的边到v，，

然后从u拉一条容量为1，话费为0的边到超级汇点，，，，这样加的边很多。


然后看了排行榜前几名的大牛之后，，，顿时觉得orz，，，大致思路是这样的。。

既然，，每条边都有下界1，，那么我一开始就把，，这些花费加起来好了，，，，记做sum

然后就变成

对于每条边u->v，，都从超级源点拉一条容量为1，话费为0的边到v，，

然后从u拉一条容量为1，话费为0的边到超级汇点，，，，这样加的边很多。

这样，，一个点引发的边就可以进行合并！

记录每个点的入度出度情况就好了，，

然后就合成一条容量IN[I]-OUT[i]的边！

瞬间，，边的数量就比第一种建图少了一半*/
#include<algorithm>
#include<iostream>
#include<cstring>
#include<queue>
#include<cmath>
#include<cstdio>
using namespace std;
#define mem(x,y) memset(x,y,sizeof(x))
#define FIN freopen("input.txt","r",stdin)
#define fuck(x) cout<<x<<endl
const int MX=333;
#define INF 0x3f3f3f3f
#define lson l,m,rt<<1
typedef long long LL;
#define rson m+1,r,rt<<1|1
int n,m;
int head[MX],cnt;
struct Edge
{
    int nxt,to,cap,cost;
} E[2*MX*MX];
void edge_init()
{
    mem(head,-1);
    cnt=0;
}
void edge_add(int u,int v,int cap,int cost)
{
    E[cnt].nxt=head[u];
    E[cnt].to=v;
    E[cnt].cap=cap;
    E[cnt].cost=cost;
    head[u]=cnt++;
}
int dis[MX],pre[MX]; //储存前驱顶点
bool vis[MX];
bool spfa(int s, int t)
{
    mem(dis,0x3f);
    mem(vis,0);
    mem(pre,-1);
    deque<int>q;
    q.push_back(s);
    dis[s]=0,vis[s]=1;
    while (!q.empty())
    {
        int u = q.front();
        q.pop_front();
        vis[u] = 0;
        for (int i= head[u]; ~i; i=E[i].nxt)
        {
            int v=E[i].to;
            if (E[i].cap&& dis[v]>dis[u]+E[i].cost)
            {
                dis[v]=dis[u]+E[i].cost;
                pre[v] = i;
                if (!vis[v])
                {
                    vis[v]=1;
                    if(!q.empty()&&dis[v]<=dis[q.front()])q.push_front(v);//SLF优化
                    else q.push_back(v);
                }
            }
        }
    }
    if (pre[t]==-1) return 0;
    else return 1;
}
//返回的是最大流， cost存的是最小费用
int MCMF(int s,int t,int &cost)
{
    int flow = 0;
    cost = 0;
    while (spfa(s, t))
    {
        int Min = INF;
        for (int i = pre[t]; i != -1; i = pre[E[i ^ 1].to])
            if (Min > E[i].cap) Min = E[i].cap;
        for (int i = pre[t]; i != -1; i = pre[E[i ^ 1].to])
            E[i].cap -= Min,E[i ^ 1].cap += Min;
        cost += dis[t]* Min;
        flow+=Min;
    }
    return flow;
}
int IN[333];
int main()
{
    while(cin>>n)
    {
        int S=n+1,T=S+1;
        edge_init();
        mem(IN,0);
        int sum=0;
        for(int i=1; i<=n; i++)
        {
            int cnt,v,cost;
            scanf("%d",&cnt);
            for(int j=1; j<=cnt; j++)
            {
                scanf("%d%d",&v,&cost);
                IN[i]--;//计算每个点的入度出度
                IN[v]++;
                sum+=cost;//直接把必要的费用加起来
                edge_add(i,v,INF,cost),edge_add(v,i,0,-cost);
            }
        }
        for(int i=1; i<=n; i++)
        {
            if(IN[i]>0)
                edge_add(S,i,IN[i],0),edge_add(i,S,0,0);
            else if(IN[i]<0)edge_add(i,T,-IN[i],0),edge_add(T,i,0,0);
            edge_add(i,1,INF,0);
            edge_add(1,i,0,0);
        }
        int cost=0;
        MCMF(S,T,cost);
        printf("%d\n",sum+cost);
    }
    return 0;
}