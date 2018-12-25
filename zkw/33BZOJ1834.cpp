/*
Description
给定一张有向图，每条边都有一个容量C和一个扩容费用W。这里扩容费用是指将容量扩大1所需的费用。求： 1、 在不扩容的情况下，1到N的最大流； 2、 将1到N的最大流增加K所需的最小扩容费用。
Input
输入文件的第一行包含三个整数N,M,K，表示有向图的点数、边数以及所需要增加的流量。 接下来的M行每行包含四个整数u,v,C,W，表示一条从u到v，容量为C，扩容费用为W的边。
Output
输出文件一行包含两个整数，分别表示问题1和问题2的答案。
Sample Input
5 8 2
1 2 5 8
2 5 9 9
5 1 6 2
5 1 1 8
1 2 8 7
2 5 4 9
1 2 1 1
1 4 2 1
Sample Output
13 19
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#define inf 0x7fffffff
using namespace std;
int n,m,k,cnt=1,ans,head[1001],from[1001],q[1001],h[1001],dis[1001];
bool inq[1001];
struct data{int from,to,v,c,next,t;}e[50001];
void ins(int u,int v,int w,int c)//原图中的所有边费用都是0，但是要把扩容费用记下来
{
     cnt++;
     e[cnt].to=v;e[cnt].from=u;
     e[cnt].v=w;e[cnt].t=c;//暂存扩容费用
     e[cnt].next=head[u];head[u]=cnt;
 }
void insert(int u,int v,int w,int c)
{ins(u,v,w,c);ins(v,u,0,-c);}
void ins2(int u,int v,int w,int c)
{
     cnt++;
     e[cnt].to=v;e[cnt].from=u;
     e[cnt].v=w;e[cnt].c=c;
     e[cnt].next=head[u];head[u]=cnt;
 }

void insert2(int u,int v,int w,int c)
{ 
    ins2(u,v,w,c);ins2(v,u,0,-c);}

void build()
{
     int t=cnt;
     for(int i=2;i<=t;i+=2)
         if(i%2==0)
            insert2(e[i].from,e[i].to,inf,e[i].t);
/*  第一问很简单，按数据建图，然后一遍最大流算法即可。
    第二问则需要用最小费用最大流算法，主要是建图，那么可以从第一问的残留网络上继续建图，
    对残留网络上的每一条边建一条容量是inf∞费用是w的边（反向弧容量为0，费用为-w），
    然后建一个超级源点，从超级源向1建一条容量为k，费用为0的边，对这个图进行最小费用最大流算法。
    最小费用最大流操作：
    1.首先要对于这道题的图来说，有的边需要花费费用，而有的又不用，而不用扩容的边费用为0，需要扩容的边费用为w，容量无限，这就是本题这样建图的原因。
    2.对于残留网络进行费用最短路SPFA算法，不用扩容的边一定会选费用为0的边，然后记录路径，找最小容量对可行路进行增流，更新ans
*/
 }
bool bfs()
{
     int t=0,w=1,i,now;
     memset(h,-1,sizeof(h));
     q[0]=1;h[1]=0;
     while(t!=w)
     {
               now=q[t];t++;if(t==1000)t=0;i=head[now];
               while(i)
               {
                       if(e[i].v&&h[e[i].to]==-1)
                       {
                            h[e[i].to]=h[now]+1;
                            q[w++]=e[i].to;if(w==1000)w=0;
                       }
                       i=e[i].next; 
                       } 
               }
     if(h[n]==-1)return 0;
     return 1;
 }
int dfs(int x,int f)
{
    if(x==n)return f;
    int i=head[x],w,used=0;
    while(i)
    {
            if(e[i].v>0&&h[e[i].to]==h[x]+1)
            {
                w=f-used;
                w=dfs(e[i].to,min(w,e[i].v));
                e[i].v-=w;
                e[i^1].v+=w;
                used+=w;
                if(used==f)return f;
                }
            i=e[i].next;
            }
    if(!used)h[x]=-1;
    return used;
}
void dinic(){while(bfs())ans+=dfs(1,inf);}
bool spfa()
{
    int t=0,w=1,i,now;
    for(int i=0;i<=n;i++)dis[i]=inf;
    q[0]=dis[0]=0;inq[0]=1;
    while(t!=w)
    {
        now=q[t];t++;i=head[now];
        if(t==n)t=0;
        while(i)
        {
            if(e[i].v>0&&dis[now]+e[i].c<dis[e[i].to])
            {
                dis[e[i].to]=dis[now]+e[i].c;
                from[e[i].to]=i;
                if(!inq[e[i].to])
                {q[w++]=e[i].to;if(w==n)w=0;inq[e[i].to]=1;}
            }
            i=e[i].next;
        }
        inq[now]=0;
    }
    if(dis[n]==inf)return 0;
    return 1;
}
void mcf()
{
    int i,x=inf;
    i=from[n];
    while(i)
    {
        x=min(x,e[i].v);
        i=from[e[i].from];
    }
    i=from[n];
    while(i)
    {
        e[i].v-=x;
        e[i^1].v+=x;
        ans+=x*e[i].c;
        i=from[e[i].from];
    }
}
int main()
{
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=m;i++)
    {
            int u,v,w,c;
            scanf("%d%d%d%d",&u,&v,&w,&c);
            insert(u,v,w,c);
            }
    dinic();
    printf("%d ",ans);
    ans=0;build();
	ins(0,1,k,0);
    while(spfa())mcf();
    printf("%d",ans);
    return 0;
}