#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>

using namespace std;

const int MAXN = 1510;
const int MAXM = 200010;
const int INF = 0x3f3f3f3f;

struct Edge {
	int to, next;
	int cap;
};

Edge edge[MAXM];

int N, F, D;
int cnt, src, des;//cnt表示一共有几条边
int head[MAXN];//head[i]表示节点i的第一条边的编号
int level[MAXN];

void addedge(int from, int to, int cap) {
	edge[cnt].to = to;
	edge[cnt].cap = cap;
	edge[cnt].next = head[from];
	head[from] = cnt++;

	edge[cnt].to = from; 
	edge[cnt].cap = 0;  
	edge[cnt].next = head[to];
	head[to] = cnt++;
}

int bfs() {
	queue<int> q;
	while (!q.empty())
		q.pop();
	memset(level, -1, sizeof(level));
	level[src] = 0; //源点的深度为0
	q.push(src);

	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (int i = head[u]; i != -1; i = edge[i].next) {
			int v = edge[i].to;
			if (edge[i].cap > 0 && level[v] == -1) {
				level[v] = level[u] + 1;
				q.push(v);//该边未访问过且该边有流量
			}
		}
	}
	return level[des] != -1; //返回是否还存在连通路
}

int dfs(int u, int f) {
	if (u == des)
		return f;
	int tem;
	for (int i = head[u]; i != -1; i = edge[i].next){
		int v = edge[i].to;
		if (edge[i].cap > 0 && level[v] == level[u] + 1) {
			tem = dfs(v, min(f, edge[i].cap));
			if (tem > 0) {
				edge[i].cap -= tem;
				edge[i ^ 1].cap += tem; //更新边与反向边的流量
				return tem;
			}
		}
	}
	level[u] = -1; //表示已经走过该点
	return 0;
}

int Dinic(){
	int ans = 0, tem;
	while (bfs()){
		while (tem = dfs(src, INF))
			ans += tem;
	}
	return ans;
}

int main()
{

	//freopen("input.txt","r",stdin);

	char str[220];
	while (~scanf("%d%d%d", &N, &F, &D))
	{
		cnt = 0;
		memset(head, -1, sizeof(head));
		int f, d;
		src = 0, des = F + 2 * N + D + 1;
		for (int i = 1; i <= F; i++)
		{
			scanf("%d", &f);
			addedge(src, i, f);
		}
		for (int i = F + 2 * N + 1; i <= F + 2 * N + D; i++)
		{
			scanf("%d", &d);
			addedge(i, des, d);
		}
		for (int i = 1; i <= N; i++)
		{
			scanf("%s", str);
			for (int j = 0; j < F; j++)
			if (str[j] == 'Y')
				addedge(j + 1, F + i, 1);
		}
		for (int i = 1; i <= N; i++)
		{
			scanf("%s", str);
			for (int j = 0; j < D; j++)
			if (str[j] == 'Y')
				addedge(F + N + i, F + 2 * N + j + 1, 1);
		}
		for (int i = F + 1; i <= F + N; i++)
			addedge(i, i + N, 1);
		printf("%d\n", Dinic());
	}
	return 0;
}