/*魔术球问题*/
#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define show(a) cout<<#a<<" = "<<a<<endl
#define show2(b,c) cout<<#b<<" = "<<b<<" "<<#c<<" = "<<c<<endl
#define show3(a,b,c) cout<<#a<<" = "<<a<<" "<<#b<<" = "<<b<<" "<<#c<<" = "<<c<<endl
#define show4(a,b,c,d) cout<<#a<<" = "<<a<<" "<<#b<<" = "<<b<<" "<<#c<<" = "<<c<<" "<<#d<<" = "<<d<<endl

const int inf = 1e9;
const int maxm = 800001;
const int maxn = 10001;
int node,src,dest,edge;
int ver[maxm],flow[maxm],nxt[maxm];
int head[maxn],work[maxn],dis[maxn],q[maxn];
void prepare(int _node,int _src,int _dest)
{
    node=_node,src=_src,dest=_dest;
    for(int i=0; i<node; ++i)head[i]=-1;
    edge=0;
}
void addedge(int u,int v,int c)
{
    ver[edge]=v,flow[edge]=c,nxt[edge]=head[u],head[u]=edge++;
    ver[edge]=u,flow[edge]=0,nxt[edge]=head[v],head[v]=edge++;
}
bool Dinic_bfs()
{
    int i,u,v,l,r=0;
    for(i=0; i<node; ++i)dis[i]=-1;
    dis[q[r++]=src]=0;
    for(l=0; l<r; ++l)
        for(i=head[u=q[l]]; i>=0; i=nxt[i])
            if(flow[i]&&dis[v=ver[i]]<0)
            {
                dis[q[r++]=v]=dis[u]+1;
                if(v==dest)return 1;
            }
    return 0;
}
int Dinic_dfs(int u,int exp)
{
    if(u==dest)return exp;
    for(int &i=work[u],v,tmp; i>=0; i=nxt[i])
        if(flow[i]&&dis[v=ver[i]]==dis[u]+1&&(tmp=Dinic_dfs(v,min(exp,flow[i])))>0)
        {
            flow[i]-=tmp;
            flow[i^1]+=tmp;
            return tmp;
        }
    return 0;
}
int Dinic_flow()
{
    int i,ret=0,delta;
    while(Dinic_bfs())
    {
        for(i=0; i<node; ++i)work[i]=head[i];
        while(delta=Dinic_dfs(src,inf))ret+=delta;
    }
    return ret;
}


// 网络流模板省去
int n,m = 2000;
int main(){
    scanf("%d",&n);
    prepare(2*m+3,0,2*m+2);
    addedge(2*m+1,2*m+2,n);
    for(int i = 1;;++i){ 
    // 增量式建图，每次加入一个球，然后在残余网络中跑最大流，判断能否跑满，如果跑不满，那么答案就是上次跑满时候的结果。


        addedge(0,2*i-1,1);
        addedge(2*i-1,2*m+1,1,1);
        addedge(2*i,2*m+2,1);
        show4(i, 2*i-1, 2*m+1, 2*m+2);
        /// T′用来表示柱子的上限，连接一条容量为n的边(T′,T)

        for(int j = 1;j < i;++j){
            int rt = sqrt(i+j+0.5);
            show3(rt, i, j);
            if(rt*rt == i+j) addedge(2*i-1,2*j,1,2);
        }

        int ans = Dinic_flow();
        if(ans < i){
            printf("%d\n",i-1);
            int vc = 0;
            //生成方案
            vector<int> G[n];
            vector<int> bl(i,-1);
            for(int e = 0;e < edge;e += 2){
                if(flow[e] != 0) continue;
                if(tps[e] == 1){
                    int u = (ver[e+1]+1)/2;
                    G[vc].push_back(u);
                    bl[u] = vc;
                    vc++;
                }
                else if(tps[e] == 2){
                    int u = (ver[e+1]+1)/2;
                    int v = (ver[e]+1)/2;
                    bl[u] = bl[v];
                    G[bl[u]].push_back(u);
                }
            }
            for(int i = 0;i < n;++i){
                for(auto v : G[i]) printf("%d ",v);
                puts("");
            }
            break;
        }
    }
    return 0;
}
