#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 200010;
const int INF = 0x3f3f3f3f;
const long long int inf = 0x3f3f3f3f3f3f3f3f;

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

int main() {
	//freopen("in.txt", "r", stdin);
	int T;
	scanf("%d", &T);
	while (T--) {
		int n, m;
		scanf("%d %d", &n, &m);

		for(int i = 0; i <= N; i++) /// mark
			G[i].clear();
		ll sum = 0;
		
		ll minx = inf, maxx = -inf, cost;
		ll x, y;
		ll s, t;
		for(int i = 1; i <= n; i++) {
			scanf("%lld %lld", &x, &y);
			if( x < minx ) minx = x, s = i;
			if( x > maxx ) maxx = x, t = i;
		}

		for(int i = 1; i <= m; i++) {
			scanf("%lld %lld %lld", &x, &y, &cost);
			add_edge(x, y, cost);
			add_edge(y, x, cost);
		}

		printf("%lld\n", max_flow(s, t));
	}
	return 0;
}
