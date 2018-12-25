/*
假设一个试题库中有n道试题。每道试题都标明了所属类别。同一道题可能有多个类别属性。现要从题库中抽取m 道题组成试卷。并要求试卷包含指定类型的试题。试设计一个满足要求的组卷算法。
«编程任务：

对于给定的组卷要求，计算满足要求的组卷方案。
输入输出格式

输入格式：
第1行有2个正整数k和n (2 <=k<= 20, k<=n<= 1000)
k 表示题库中试题类型总数，n 表示题库中试题总数。第2 行有k 个正整数，第i 个正整数表示要选出的类型i的题数。这k个数相加就是要选出的总题数m。接下来的n行给出了题库中每个试题的类型信息。每行的第1 个正整数p表明该题可以属于p类，接着的p个数是该题所属的类型号。

输出格式：
第i 行输出 “i：”后接类型i的题号。如果有多个满足要求的方案，只要输出1个方案。如果问题无解，则输出“No Solution!”。
3 15
3 3 4
2 1 2
1 3
1 3
1 3
1 3
3 1 2 3
2 2 3
2 1 3
1 2
1 2
2 1 2
2 1 3
2 1 2
1 1
3 1 2 3
输出样例#1： 
1: 1 6 8
2: 7 9 10
3: 2 3 4 5
解析

网络流24题之一orz。
二分图多重匹配。
每道题跟T连容量为1的边。
每类题跟S连容量为需要该类题数量的边。
每道题跟它所在的题的类别连容量为1的边。
跑最大流，如果结果小于题目总数，则无解。
否则，对每条连接题的类别和题目的边检查，
若满流，输出题目的编号即可。
*/#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cstdio>
#include<queue>
#define INF 2147483647
const int MAXN=1e7;
using namespace std;
struct Edge
{
	int from,next,to,c,f;
}edge[MAXN];
int head[MAXN],cnt,level[MAXN],Num_k[MAXN],n,m,p,s,t,k;
inline int read()
{
	int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return x;
}
inline void Add_Edge(int u,int v,int cc,int ff)
{
	edge[cnt]=(Edge){u,head[u],v,cc,ff};
	head[u]=cnt++;
} 
bool Bfs(int s,int t)
{
	memset(level,0,sizeof(level));
	level[s]=1;
	queue<int> que;
	que.push(s);
	while(!que.empty())
	{
		int c=que.front();
		que.pop();
		for(int i=head[c];i!=-1;i=edge[i].next)
		{
			int v=edge[i].to;
			if(level[v]==0&&edge[i].c>edge[i].f)
			{
				level[v]=level[c]+1;
				que.push(v);
			}
		}	
	}
	if(level[t]==0) return 0;
	else return 1;
}
int Dfs(int u,int f)
{
	if(u==t) return f;
	int adf=0;
	for(int i=head[u];i!=-1&&adf<f;i=edge[i].next)
	{
		int v=edge[i].to;
		if(level[v]==level[u]+1&&edge[i].c>edge[i].f)
		{
			int temp=Dfs(v,min(f-adf,edge[i].c-edge[i].f));
			edge[i].f+=temp;
			edge[i^1].f-=temp;
			adf+=temp;
		} 
	}
	return adf;
}
int Dinic(int s,int t)
{
	int sumflow=0;
	while(Bfs(s,t))
	{
		sumflow+=Dfs(s,INF);
	}
	return sumflow;
}
int main()
{
	memset(head,-1,sizeof(head));
	k=read(),n=read();
	for(int i=1;i<=k;i++)
	{
		Num_k[i]=read(); 
		m+=Num_k[i];
	}
	s=0,t=n+m+1;
	for(int i=1;i<=k;i++)
	{
		Add_Edge(i+n,t,Num_k[i],0);
		Add_Edge(t,i+n,0,0);
	}
	for(int i=1;i<=n;i++)
	{
		Add_Edge(s,i,1,0);
		Add_Edge(i,s,0,0);
		p=read();
		for(int j=1;j<=p;j++)
		{
			int x;
			scanf("%d",&x);
			Add_Edge(i,x+n,1,0);
			Add_Edge(x+n,i,0,0);
		}
	}
	int now=Dinic(s,t);
	if(!now)
	{
		printf("No Solution!");
		return 0;
	}
	else
	{
		for(int i=1;i<=k;i++)
		{
			printf("%d: ",i);
			for(int j=0;j<=cnt;j++)
			{
				// cout << "edge[i].from： " <<edge[i].from << endl;
				if(edge[j].to==i+n // 16 17 18 == j.to
					&&edge[j].f>0 // j.f 存在流
					&&edge[i].from>s) // i.from > 0 大概没必要吧？
				{
					printf("%d ",edge[j].from); // from
				}
			}
			printf("\n");
		}
	}
	return 0;
} 
