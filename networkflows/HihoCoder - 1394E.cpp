#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<queue>
#define INF 0x3f3f3f3f
using namespace std;
const int maxn=1005;
const int maxx=42005;
int edge;
int to[maxx],flow[maxx],nex[maxx];
int head[maxn];

void addEdge(int v,int u,int cap)
{
    to[edge]=u,flow[edge]=cap,nex[edge]=head[v],head[v]=edge++;
    to[edge]=v,flow[edge]=0,nex[edge]=head[u],head[u]=edge++;
}
int vis[maxn];
int pre[maxn];
bool bfs(int s,int e)
{
    queue<int> que;
    pre[s]=-1;
    memset(vis,-1,sizeof(vis));
    que.push(s);
    vis[s]=0;
    while(!que.empty())
    {
        int u=que.front();
        que.pop();
        for(int i=head[u];~i;i=nex[i])
        {
            int v=to[i];
            if(vis[v]==-1&&flow[i])
            {
                vis[v]=vis[u]+1;
                if(v==e)
                    return true;
                que.push(v);
            }

        }
    }
    return false;
}
int dfs(int s,int t,int f)
{
    if(s==t||!f)
        return f;
    int r=0;
    for(int i=head[s];~i;i=nex[i])
    {
        int v=to[i];
        if(vis[v]==vis[s]+1&&flow[i])
        {
            int d=dfs(v,t,min(f,flow[i]));
            if(d>0)
            {
                flow[i]-=d;
                flow[i^1]+=d;
                r+=d;
                f-=d;
                if(!f)
                    break;
            }
        }
    }
    if(!r)
        vis[s]=INF;
    return r;
}

int maxFlow(int s ,int e)//然后直接调用这个即可
{
    int ans=0;
    while(bfs(s,e))
        ans+=dfs(s,e,INF);
    return ans;
}

void init()//记得每次使用前初始化
{
    memset(head,-1,sizeof(head));
    edge=0;
}

int main()
{
    int n,m;
    int v,u;
    scanf("%d%d",&n,&m);
    init();
    while(m--)
    {
        scanf("%d%d",&u,&v);
        addEdge(u,n+v,1);
    }
    for(int i=1;i<=n;i++)
        addEdge(0,i,1),addEdge(n+i,n+n+1,1);
    printf("%d\n",n-maxFlow(0,n+n+1)); // ***
    return 0;
}