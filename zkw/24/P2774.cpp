/*在一个有 m*n 个方格的棋盘中，每个方格中有一个正整数。现要从方格中取数，使任意 2 个数所在方格没有公共边，且取出的数的总和最大。试设计一个满足要求的取数算法。对于给定的方格棋盘，按照取数要求编程找出总和最大的数。
输入输出格式

输入格式：
第 1 行有 2 个正整数 m 和 n，分别表示棋盘的行数和列数。接下来的 m 行，每行有 n 个正整数，表示棋盘方格中的数。

输出格式：
程序运行结束时，将取数的最大总和输出
输入输出样例

输入样例：
3 3
1 2 3
3 2 3
2 3 1

输出样例：
11
说明

m,n<=100

这是一道最小割题目，答案=全局和-最小割，由于最小割等于最大流，所以我们只要求出全局和-最大流即可。
我们先对棋盘进行染色，把行加列为偶数的格子染成黑色，其余为白色，有些人也许会想，ans=max(Σ
白,Σ

黑)，但为了让一个点与它不相邻且颜色不相同的点连边，我们要用到最小割。

构图
1. 建立超级源点与超级汇点
2. 从源点向每一个白色格子建一条边，流量为这个格子的值，从每一个黑色格子向汇点建一条边，流量也为这个格子的值
3. 从每一个白色的点向与它相临的黑色的点建边，流量为INF，这些边是要割掉的

然后跑最大流，由于最大流等于最小割，用所有格子的值的和减去最大流即为答案。
*/
#include<cstdio>
#include<cstdlib>
#include<cstring>

const int INF=1e9;

struct node{int x,y,c,next,other;}a[200010];
int first[2510],last[2510],h[2510],q[2510];
int n,m,st,ed,len=0,ans=0;
int fx[4]={0,1,0,-1};
int fy[4]={1,0,-1,0};

void ins(int x,int y,int c)
{
    int k1,k2;
    len++;k1=len;
    a[len].x=x;a[len].y=y;a[len].c=c;
    a[len].next=first[x];first[x]=len; 
    len++;k2=len;
    a[len].x=y;a[len].y=x;a[len].c=0;
    a[len].next=first[y];first[y]=len;
    a[k1].other=k2;a[k2].other=k1;
}

bool bfs()
{
    int head=1,tail=2;q[1]=st;
    memset(h,0,sizeof(h));h[st]=1;
    while(head!=tail)
    {
        int x=q[head];
        for(int i=first[x];i;i=a[i].next)
        {
            int y=a[i].y;
            if(h[y]==0 && a[i].c>0)
            {
                q[tail++]=y;
                h[y]=h[x]+1;
            }
        }
        head++;
    }
    if(h[ed]==0) return false;
    return true;
}

inline int mymin(int x,int y)
{
    return x<y?x:y;
} 

inline int dfs(int x,int flow)
{
    if(x==ed) return flow;
    int tt=0,minf=0;
    for(int i=first[x];i;i=a[i].next)
    {
        int y=a[i].y;
        if(a[i].c>0 && h[y]==(h[x]+1) && tt<=flow)
        {
            minf=dfs(y,mymin(flow-tt,a[i].c));
            tt+=minf;
            a[i].c-=minf;a[a[i].other].c+=minf;
        }
    }
    if(tt==0) h[x]=0;
    return tt;
}

inline int dinic()
{
    int s=0;
    while(bfs()) s+=dfs(st,INF);
    return s;
}

inline int num(int i,int j){return i*m+j+1;}

int main()
{
    memset(first,0,sizeof(first));
    scanf("%d %d",&n,&m);
    st=n*m+1;ed=st+1;
    int x;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            scanf("%d",&x);
            ans+=x;
            if((i+j)&1) ins(st,num(i,j),x);
            else ins(num(i,j),ed,x);
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if((i+j)&1)
            for(int k=0;k<4;k++)
            {
                int xx=i+fx[k],yy=j+fy[k];
                if(xx<0 || xx>=n || yy<0 || yy>=m) continue;
                ins(num(i,j),num(xx,yy),INF);
            }
        }
    }
    int tt=dinic();
    printf("%d",ans-tt);
}