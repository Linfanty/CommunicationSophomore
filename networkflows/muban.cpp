#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1e3 + 10;
const int INF = 0x3f3f3f3f;

//终点 容量 反向边
struct Edge
{
	int to;
	ll cap;
	int rev;
};

vector<Edge> G[N];
int level[N];
int iter[N];
void add_edge(int from, int to, ll cap)
{
	G[from].push_back((Edge){to, cap, (int)G[to].size()});
	G[to].push_back((Edge){from, 0, (int)G[from].size() - 1});
}
void bfs(int s)
{
	memset(level, -1, sizeof(level));
	queue<int> que;
	level[s] = 0;
	que.push(s);
	while(!que.empty())
	{
		int v = que.front(); que.pop();
		for(int i = 0; i < G[v].size(); i++)
		{
			Edge &e = G[v][i];
			if(e.cap > 0 && level[e.to] < 0)
			{
				level[e.to] = level[v] + 1;
				que.push(e.to);
			}
		}
	}
}

ll dfs(int v, int t, ll f)
{
	if(v == t) return f;
	for(int &i = iter[v]; i < G[v].size(); i++)
	{
		Edge &e = G[v][i];
		if(e.cap > 0 && level[v] < level[e.to])
		{
			ll d = dfs(e.to, t, min(f, e.cap));
			if(d > 0)
			{
				e.cap -= d;
				G[e.to][e.rev].cap += d;
				return d;
			}
		}
	}
	return 0;
}

ll max_flow(int s, int t)
{
	ll flow = 0;
	while(1)
	{
		bfs(s);
		if(level[t] < 0) return flow;
		memset(iter, 0, sizeof(iter));
		ll f;
		while((f = dfs(s, t, INF)) > 0) {
			flow += f;
		}
	}
}

ll val[N], cost[N];
int main() {
	//freopen("in.txt", "r", stdin);
	int T;
	scanf("%d", &T);
	while (T--) {
		int n, m;
		scanf("%d %d", &n, &m);
		for(int i = 0; i <= m + n + 1; i++) {
			G[i].clear();
		}
		ll sum = 0;
		for(int i = 1; i <= n; i++) {
			scanf("%lld", val + i);
			sum += val[i];
			add_edge(0, i, val[i]);
		}
		for(int i = 1; i <= m; i++) {
			scanf("%lld", cost + i);
			add_edge(i + n, m + n + 1, cost[i]);
		}
		for(int i = 1; i <= n; i++) {
			int n1, n2, v;
			scanf("%d %d", &n1, &n2);
			while(n1--) {
				scanf("%d", &v);
				add_edge(i, v + n, INF);
			}
			while(n2--) {
				scanf("%d", &v);
				add_edge(i, v, INF);
			}
		}
		printf("%lld\n", sum - max_flow(0, m + n + 1));
	}
	return 0;
}
