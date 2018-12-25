/*
4

3 1
1 2 2
2 3 4
3 4 8

3 1
1 3 2
2 3 4
3 4 8

3 1
1 100000 100000
1 2 3
100 200 300

3 2
1 100000 100000
1 150 301
100 200 300

Sample Output

14
12
100000
100301
费用流，构图方法很巧妙。

我一开始的想法是区间放左边，点放右边，跑费用流。后来发现显然是错的，因为在最大流时源点流入区间的边不一定满流，也就是一个区间内的点没有全部覆盖，这显然是错误的。

下面是正确地做法：要保证每个点最多覆盖k次，可以把所有点串联起来，每个点向后一个点连一条容量k、费用0的边。(是不是很机智啊！！)然后对于区间[a,b]，从a到b连一条容量1、费用w的边就可以了。最后从源点到1点、从n点到汇点，分别连一条容量k、费用0的点。

至于这个方法的正确性如何证明呢？？我可以说只可意会不可言传吗=_=……大家自己脑补吧……额

如此看来，构图真是一种艺术啊！
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;
#define N 1010
#define INF 0x3f3f3f3f
struct Edge
{
    int from,to,next,cap,cost;///起点，终点，同起点下一条边，残余流量，费用
} edge[N*N];
struct E
{
    int u,v,w;
} e[N];
int cnt,head[N],sum[N];
int vis[N],d[N],pp[N],f[N];
int sumflow;///最大流量总和
void init()
{
    cnt=0;
    memset(head,-1,sizeof(head));
}
void addedge(int from,int to,int cap,int cost)
{
    edge[cnt].from=from;
    edge[cnt].to=to;
    edge[cnt].cost=cost;
    edge[cnt].cap=cap;
    edge[cnt].next=head[from];
    head[from]=cnt++;
    edge[cnt].from=to;
    edge[cnt].to=from;
    edge[cnt].cost=-cost;
    edge[cnt].cap=0;
    edge[cnt].next=head[to];
    head[to]=cnt++;///存反向边
}
int spfa(int s,int t,int n)
{
    queue<int>q;
    memset(vis,0,sizeof(vis));
    memset(pp,-1,sizeof(pp));///pp[i]表示最短路径上以i为终点的边的编号
    for(int i=0; i<=n; i++)
        d[i]=-INF;
    d[s]=0;
    vis[s]=1;
    q.push(s);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        vis[u]=0;
        for(int i=head[u]; i!=-1; i=edge[i].next)
        {
            int v=edge[i].to;
            if(edge[i].cap>0&&d[v]<d[u]+edge[i].cost)
            {
                d[v]=d[u]+edge[i].cost;
                pp[v]=i;
                if(!vis[v])
                {
                    vis[v]=1;
                    q.push(v);
                }
            }
        }
    }
    if(d[t]==-INF) return 0;///找不到一条到终点的路
    return 1;
}
int MCMF(int s,int t,int n)
{
    int mincost=0,minflow,flow=0;///最小费用，路径中最小流量，总流量
    while(spfa(s,t,n))///找当前的最短路
    {
        minflow=INF+1;
        for(int i=pp[t]; i!=-1; i=pp[edge[i].from])
            minflow=min(minflow,edge[i].cap);///从路径中找最小的流量
        flow+=minflow;///总流量加上最小流量
        for(int i=pp[t]; i!=-1; i=pp[edge[i].from])
        {
            edge[i].cap-=minflow;///当前边减去最小流量
            edge[i^1].cap+=minflow;///反向边加上最小流量
        }
        mincost+=d[t]*minflow;///最小费用等于路径和*每条路径的流量（经过多少次）
    }
    sumflow=flow;
    return mincost;
}
int main()
{
    int T,n,m,k;
    scanf("%d",&T);
    while(T--)
    {
        init();
        scanf("%d %d",&n,&m);
        int num=0;
        for(int i=1; i<=n; i++)
        {
            scanf("%d %d %d",&e[i].u,&e[i].v,&e[i].w);
            f[++num]=e[i].u;
            f[++num]=e[i].v;
        }
        sort(f+1,f+1+num);
        int tot=1;
        for(int i=2; i<=num; i++)
            if(f[i]!=f[i-1])
                f[++tot]=f[i];
        int s=0,t=tot+1;
        addedge(s,1,m,0);
        for(int i=1;i<tot;i++)
            addedge(i,i+1,m,0);
        for(int i=1;i<=n;i++)
        {
            int u=lower_bound(f+1,f+1+tot,e[i].u)-f;
            int v=lower_bound(f+1,f+1+tot,e[i].v)-f;
            addedge(u,v,1,e[i].w);
        }
        addedge(tot,t,m,0);
        printf("%d\n",MCMF(s,t,t));
    }
    return 0;
}