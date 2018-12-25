#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf = 0x3f3f3f3f3f3f3f3f;
#define show(a) cout<<#a<<" = "<<a<<endl
#define show2(b,c) cout<<#b<<" = "<<b<<" "<<#c<<" = "<<c<<endl
#define show3(a,b,c) cout<<#a<<" = "<<a<<" "<<#b<<" = "<<b<<" "<<#c<<" = "<<c<<endl
#define show4(a,b,c,d) cout<<#a<<" = "<<a<<" "<<#b<<" = "<<b<<" "<<#c<<" = "<<c<<" "<<#d<<" = "<<d<<endl
const int maxn = 100005;
#define LOCAL

struct edge {
	int to, cap, rev; // 终点 容量 反向边
};
vector<edge> G[max_v]; // 邻接表
bool used[max_v]; // 访问标记

// 向图中增加一条从S到T容量为 cap 的边
void add_edge(int from, int to, int cap) {
	G[from].push_back((edge) {to, cap, G[to].size() }); // 从from到to容量cap 反向边为G[to].size()
	G[to].push_back((edge) {from, 0, G[from].size()-1 }); // 从to到from容量0 反向边为G[from].size()-1
}

// DFS寻找增广路
int dfs(int v, int t, int f) {
	if( v == t ) return f;
	used[v] = true;

	for(int i = 0; i < G[v].size(); i++) {
		edge &e = G[v][i];

		if( !used[e.to] && e.cap > 0 ) { // 终点未访问过 且 容量 > 0
			int d = dfs(e.to, t, min(f, e.cap)); // f和e.cap的最小值

			if( d > 0 ) {
				e.cap -= d;
				G[e.to][e.rev].cap += d;
				return d;
			}
		}
	}
	return 0;
}

int max_flow(int s, int t) {
	int flow = 0;
	for(;;) {
		memset(used, 0, sizeof(used));
		int f = dfs(s, t, inf);
		if( f == 0 ) return flow;
		flow += f;
	}

} 


int main() {

    /* code */

}78
