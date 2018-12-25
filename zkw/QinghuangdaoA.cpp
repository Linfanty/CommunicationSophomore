#include<iostream>
#include<cstdio>
#include<cstring>
#define N 6001
#define M 1000010
#define INF 0x7fffffff 
using namespace std;
int n,m,cnt=1;
long long ans;
struct data{int from,to,v,c,next;}e[M];
int dis[N],head[N],q[M],from[N];
bool inq[N];
int nnn;

void insert(int u,int v,int w,int c)
{
    cnt++;
    e[cnt].from=u;e[cnt].to=v;
    e[cnt].v=w;e[cnt].c=c;
    e[cnt].next=head[u];head[u]=cnt;
}
void ins(int u,int v,int w,int c)
{insert(u,v,w,c);insert(v,u,0,-c);}

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
    if(dis[nnn]==-1)return 0;
    return 1;
}
void mincf()
{
    int i,sum=INF;
    i=from[nnn];
    while(i)
    {
        sum=min(sum,e[i].v);
        i=from[e[i].from];
    } 
    i=from[nnn];
    while(i)
    {  
        cout <<  << endl; // sum = 5; e[i].c = 1
        // cout << "i = " << i << " e[i].v = " << e[i].v << endl;
        e[i].v-=sum;
        e[i^1].v+=sum;
        ans+=sum*e[i].c;
        //printf("%d %d %d\n",sum, e[i].c, ans);  
        i=from[e[i].from];
    }
} 

long long F;
int main()
{
    freopen("in.txt", "r", stdin);
    scanf("%d %d %lld",&n, &m, &F);
    memset(head,0,sizeof(head));
    int a, b, mx, cst;
    for(int i=1;i<=m;i++) {
        scanf("%d %d %d %d",&a, &b, &mx, &cst);
        ins(a-1, b-1, mx, cst);
    }
    nnn = n-1;
  /*  for(int i=1;i<=m;i++) ins(0,i,1,0);
    for(int i=1;i<=m;i++) ins(i,nnn,1,0);
*/
/*
    ins(0, 1, 100, 0);
    ins(n, n+1, 100, 0);
    nnn = n + 1;
*/
    while(spfa()) {
        mincf();
        cout << " ans =  " << ans << endl;
    }
    printf("%lld\n",ans);
    return 0;
}