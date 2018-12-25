/* http://www.itdaan.com/blog/2018/02/04/5a3d711eaf666eb5fdae5098802ee58a.html
给定正整数序列x1,...,xn 。

（1）计算其最长不下降子序列的长度s。

（2）计算从给定的序列中最多可取出多少个长度为s的不下降子序列。

（3）如果允许在取出的序列中多次使用x1和xn，则从给定序列中最多可取出多少个长度为s的不下降子序列。

«编程任务：

设计有效算法完成（1）（2）（3）提出的计算任务。

思路与想法

      看到这道题，我想到的只是推DP方程，只要保持n的平方就可以完成了（但是不行，最少n的三次方）。

      网络流中的最大流可以解决这个东西，只要保证从原点流到汇点的流量满足s长度的最长非下降就可以了。怎么保证呢？

解法

      我们把第一问的答案用n的平方（或者大佬可以用单调队列来维护这个max）。f[i]表示以i结尾的最长非下降序列长度是多少。(拆点，把 i 拆成 i 和 i’)

      1.当f[i]==1时，那么表示i不能作为一个序列的结尾，只能作为开头，所以从begin（源点）到i连一条流量为1的边。

      2.当f[i]==mmax时,表示i能作为一个最长非下降序列的结尾，所以从i’到end（汇点）连一条流量为1的边。

      3.当a[i]<a[j]  and(&&)   f[j]=f[i]+1  的时候，那么从i到j‘连一条流量为1的边。

      4.为了能使流量能连续流通，我们从i’到i连一条流量为1的边。

（注意，当mmax==1 时，要一定要特判，从i到i’连一条流量为1的边；因为不这样子的话，i到end就没有边可以通，一开始我就卡了两个点。。。）

第三个问，就干脆将begin到1点连一条INF的边，n’点到end连一条INF的边。
想看具体图片吗？。。

像下面这组样例

4
3 6 2 5
*/

#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<queue>
using namespace std;

int n;
int a[510];
int f[510];
struct edge{int y,next,c;};
edge s[600010];
int bg,endd;
int first[10010];
int len=1;
int q[10010];
int h[10010];
bool tf[10010];
int mmax=0;
int st,ed;

int mmin(int x,int y)
{
	return x<y?x:y;
}

void ins(int x,int y,int c)
{
	len++;
	s[len].y=y;s[len].c=c;
	s[len].next=first[x];first[x]=len;
	len++;
	s[len].y=x;s[len].c=0;
	s[len].next=first[y];first[y]=len;
}

void build_edge(int x)
{
	memset(first,0,sizeof(first));
	len=1;
	for(int i=1;i<=n;i++)
		if(f[i]==1) 
			if(i==1)
				ins(bg,i,x);
			else
				ins(bg,i,1);
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++)
			if(a[i]<=a[j] && (f[j]==f[i]+1 || mmax==1)) 
				ins(i,n+j,1);
	for(int i=1;i<=n;i++) ins(i+n,i,1);
	for(int i=1;i<=n;i++) 
		if(f[i]==mmax) 
			if(i==n)
				ins(i+n,endd,x);
			else
				ins(i+n,endd,1);
}

bool bfs()
{
	st=1,ed=2;
	memset(h,0,sizeof(h));
	h[bg]=1;
	q[st]=bg;
	while(st!=ed)
	{
		int x=q[st];
		for(int i=first[x];i!=0;i=s[i].next)
		{
			int y=s[i].y;
			if(h[y]==0 && s[i].c>0)
			{
				h[y]=h[x]+1;
				q[ed]=y;
				ed++;
				if(ed==n+n+n) ed=1;
			}
		}
		st++;
		if(st==n+n+n) st=1;
	}
	if(h[endd]!=0) return true;
	return false;
}

int dfs(int x,int t)
{
	if(x==endd) return t;
	int tot=0;
	for(int i=first[x];i!=0;i=s[i].next)
	{
		if(t==tot) return t;
		int y=s[i].y;
		if(h[y]==h[x]+1)
		{
			int get=dfs(y,mmin(t-tot,s[i].c));
			tot+=get;s[i].c-=get;s[i^1].c+=get;
		}
	}
	if(tot==0) h[x]=0;
	return tot;
}

int max_flow()
{
	int flow=0,now=0;
	while(bfs())
	{
		now=dfs(bg,1e9);
		while(now!=0)
		{
			flow+=now;
			now=dfs(bg,1e9);
		}
	}
	return flow;
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
	{
		f[i]=1;
		for(int j=1;j<i;j++)
			if(a[j]<=a[i] && f[j]+1>f[i]) f[i]=f[j]+1; 
		if(f[i]>mmax) mmax=f[i];
	}
	printf("%d\n",mmax);

	bg=0;
	endd=2*n+1;
	
	build_edge(1);
	printf("%d\n",max_flow());
	build_edge(1e9);
	printf("%d\n",max_flow());
}