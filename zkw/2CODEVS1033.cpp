/*
题目描述 Description
    在一块梯形田地上，一群蚯蚓在做收集食物游戏。蚯蚓们把梯形田地上的食物堆积整理如下：
    a(1,1)  a(1,2)…a(1,m)
    a(2,1)  a(2,2)  a(2,3)…a(2,m)  a(2,m+1)
    a(3,1)  a (3,2)  a(3,3)…a(3,m+1)  a(3,m+2)
   ……
    a(n,1)   a(n,2)   a(n,3)…           a(n,m+n-1)

    它们把食物分成n行，第1行有m堆的食物，每堆的食物量分别是a(1,1),a(1,2),…,a(1,m)；
    第2行有m+1堆食物，每堆的食物量分别是a(2,1),a(2,2),…,  a(2,m+1)；以下依次有m+2堆、m+3堆、…m+n-1堆食物。
    现在蚯蚓们选择了k条蚯蚓来测试它们的合作能力（1≤ k ≤m）。测试法如下：第1条蚯蚓从第1行选择一堆食物，然后往左下或右下爬，并收集1堆食物，例如从a（1,2）只能爬向a(2,2) 或a(2,3)，而不能爬向其它地方。接下来再爬向下一行收集一堆食物，直到第n行收集一堆食物。第1条蚯蚓所收集到的食物量是它在每一行所收集的食物量之和；第2条蚯蚓也从第1行爬到第n行，每行收集一堆食物，爬的方法与第1条蚯蚓相类似，但不能碰到第1条蚯蚓所爬的轨迹；一般地，第i 条蚯蚓从第1行爬到第 n行，每行收集一堆食物，爬的方法与第1条蚯蚓类似，但不能碰到前 I-1 条蚯蚓所爬的轨迹。这k条蚯蚓应该如何合作，才能使它们所收集到的食物总量最多？收集到的食物总量可代表这k条蚯蚓的合作水平。
        Ø编程任务：
    给定上述梯形m、n和k的值（1≤k≤m≤30;1≤n≤30）以及梯形中每堆食物的量（小于10的非整数），编程计算这k条蚯蚓所能收集到的食物的最多总量。

输入描述 Input Description
           输入数据由文件名为INPUT1.*的文本文件提供，共有n+1行。每行的两个数据之间用一个空格隔开。

    ●第1行是n、m和k的值。

        接下来的n行依次是梯形的每一行的食物量a(i,1)，a(i,2)，…，a(i,m+i-1)，i=1,2,…,n。

输出描述 Output Description
    程序运行结束时，在屏幕上输出k蚯蚓条所能收集到的食物的最多总量。

样例输入 Sample Input
    3    2   2
    1   2
    5   0   2
    1   10  0  6

样例输出 Sample Output
    26
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#define inf 0x7fffffff
#define X 1501
#define N 3001
#define M 50001 
using namespace std;
int n,m,k,ans,cnt=1,tot;
struct data{int from,to,v,c,next;}e[M];
int head[N],inq[N],from[N],dis[N],q[N];
void ins(int u,int v,int w,int c)
{
	cnt++;
	e[cnt].to=v;e[cnt].from=u;
	e[cnt].v=w;e[cnt].c=c;
	e[cnt].next=head[u];head[u]=cnt;
}

void insert(int u,int v,int w,int c)
{ins(u,v,w,c);ins(v,u,0,-c);}
////////////////////////////////////////
bool spfa()
{
	int t=0,w=1,i,now;
	memset(dis,-1,sizeof(dis));
	q[0]=dis[0]=0;inq[0]=1;
	while(t!=w)
    {
    	now=q[t];t++;i=head[now];
    	if(t==N)t=0;
    	while(i)
    	{
    		if(e[i].v>0&&dis[now]+e[i].c>dis[e[i].to])
    		{
    			dis[e[i].to]=dis[now]+e[i].c;
    			from[e[i].to]=i;
    			if(!inq[e[i].to])
				{q[w++]=e[i].to;if(w==N)w=0;inq[e[i].to]=1;}
    		}
    		i=e[i].next;
    	}
    	inq[now]=0;
    }
    if(dis[N-1]==-1)return 0;
    return 1;
}
void mcf()
{
	int i,x=inf;
	i=from[N-1];
	while(i)
	{
		x=min(x,e[i].v);
		i=from[e[i].from];
	}
	i=from[N-1];
	while(i)
	{
		e[i].v-=x;e[i^1].v+=x;
		ans+=x*e[i].c;
		i=from[e[i].from];
	}
}
// 走1次价值x
// 走1次价值0
// insert( 1 , k ) ---> insert( 1 , 0 )insert( 1 , 0 )insert( 1 , 0 )insert( 1 , 0 )
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	int x;
	for(int i=1;i<=n;i++)
       for(int j=1;j<=m+i-1;j++)
       {
          tot++;
          scanf("%d",&x); // #define X 1501
          insert(tot,tot+X,1,x); // to : tot+X 后面大
          if(i<n) // 细节
          {
              insert(tot+X,tot+i+m,1,0); // from : tot+X 前面大
              insert(tot+X,tot+i+m-1,1,0); // from : tot+X 前面大
          }
      }
    for(int i=1;i<=m;i++)insert(0,i,1,0);
    for(int i=1;i<=m+n-1;i++)insert(tot-i+X+1,N-1,1,0);
    for(int i=1;i<=k;i++)if(spfa())mcf();else break;
    printf("%d",ans);
	return 0;
}