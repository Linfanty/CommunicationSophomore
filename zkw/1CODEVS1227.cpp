/*    给出一个n*n的矩阵,每一格有一个非负整数Aij,(Aij <= 1000)现在从(1,1)出发,可以往右或者往下走,最后到达(n,n),每达到一格,把该格子的数取出来,该格子的数就变成0,这样一共走K次,现在要求K次所达到的方格的数的和最大
输入描述 Input Description
    第一行两个数n,k（1<=n<=50, 0<=k<=10）
    接下来n行,每行n个数,分别表示矩阵的每个格子的数

输出描述 Output Description
    一个数,为最大和
样例输入 Sample Input

    3 1

    1 2 3
    0 2 1
    1 4 2

样例输出 Sample Output

    11
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#define N 6001
#define M 1000010
#define INF 0x7fffffff 
using namespace std;
int n,k,cnt=1;
long long ans;
struct data{int from,to,v,c,next;}e[M];
int dis[N],head[N],q[M],from[N];
bool inq[N];
void insert(int u,int v,int w,int c)
{
    cnt++;
    e[cnt].from=u;e[cnt].to=v;
    e[cnt].v=w;e[cnt].c=c;
    e[cnt].next=head[u];head[u]=cnt;
}
void ins(int u,int v,int w,int c)
{insert(u,v,w,c);insert(v,u,0,-c);}
////////////////////////////////////////
bool spfa()
{
    int t=0,w=1,i,now;
    memset(dis,-1,sizeof(dis));
    q[0]=0;dis[0]=0;inq[0]=1;
    while(t<w)
    {
        now=q[t];t++;i=head[now];
        while(i)
        {
            if(e[i].v>0&&dis[now]+e[i].c>dis[e[i].to])
            {
                dis[e[i].to]=dis[now]+e[i].c;
                from[e[i].to]=i;
                if(!inq[e[i].to])
                {q[w]=e[i].to;w++;inq[e[i].to]=1;}
            }
            i=e[i].next;
        }
        inq[now]=0; 
    }
    if(dis[6000]==-1)return 0;
    return 1;
}
void mincf()
{
    int i,sum=INF;
    i=from[6000];
    while(i)
    {
        sum=min(sum,e[i].v);
        i=from[e[i].from];
    } 
    i=from[6000];
    while(i)
    {
        e[i].v-=sum;
        e[i^1].v+=sum;
        ans+=sum*e[i].c;
        i=from[e[i].from];
    }
} 
// 走1次价值x
// 走k次价值0
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            int x;
            scanf("%d",&x);
            ins((i-1)*n+j,(i-1)*n+j+n*n,1,x); // to : (i-1)*n+j+n*n 后面大
            ins((i-1)*n+j,(i-1)*n+j+n*n,k,0); // to : (i-1)*n+j+n*n 后面大
            if(j<n) // 细节 
                ins((i-1)*n+j+n*n,(i-1)*n+j+1,k,0); // from : (i-1)*n+j+n*n 前面大
            if(i<n) // 细节
                ins((i-1)*n+j+n*n,i*n+j,k,0);   // from : (i-1)*n+j+n*n 前面大
        }

    ins(0,1,k,0);
    ins(n*n*2,6000,k,0);
    while(spfa())mincf();
    printf("%lld",ans);
    return 0;
}
