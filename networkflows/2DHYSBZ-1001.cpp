// 对偶图最小割 = 左下到右上边的最短路
//https://blog.csdn.net/fouzhe/article/details/54666994
#include <iostream>  
#include <cstdio>  
#include <cstdlib>  
#include <cstring>  
#include <string>  
#include <cmath>  
#include <set>  
#include <map>  
#include <stack>  
#include <queue>  
#include <ctype.h>  
#include <vector>  
#include <algorithm>  
#include <sstream>  
#define PI acos(-1.0)  
#define in freopen("in.txt", "r", stdin)  
#define out freopen("out.txt", "w", stdout)  
using namespace std;  
typedef long long ll;  
const int maxn = 2000000 + 7, INF = 0x3f3f3f3f, mod = 1e9 + 7;  
const int M = maxn * 3 + 700;  
int n, m;  
int u, v;  
   
struct edge {  
    int v, cost;  
    int next;  
} edge[M];  
int head[maxn], ednum;  
   
struct node {  
    int v, w;  
    bool operator < (const node b)const {  
        return w > b.w;  
    }  
} cur, tail;  
   
void add(int u, int v, int cost) {  
    edge[ednum].v = v; edge[ednum].cost = cost;  
    edge[ednum].next = head[u]; head[u] = ednum++;  
   
    edge[ednum].v = u; edge[ednum].cost = cost;  
    edge[ednum].next = head[v]; head[v] = ednum++;  
}  
   
int d[maxn], vis[maxn];  
void dijkstra(int u, int v) {  
    for(int i = 0; i <= v; ++i) d[i] = INF;  
    memset(vis, 0, sizeof vis);  
    d[u] = 0;  
    priority_queue<node > qu;  
    cur.v = u; cur.w = 0;  
    qu.push(cur);  
    while(!qu.empty()) {  
        cur = qu.top(); qu.pop();  
        int x = cur.v;  
        if(vis[x]) continue;  
        vis[x] = 1;  
        for(int i = head[x]; i != -1; i = edge[i].next) {  
            if(d[edge[i].v] > edge[i].cost + d[x]) {  
                d[edge[i].v] = edge[i].cost + d[x];  
                tail.v = edge[i].v;  
                tail.w = d[edge[i].v];  
                qu.push(tail);  
            }  
        }  
    }  
    printf("%d\n", d[v]);  
}  
   
   
void init() {  
    int x, y, cost;  
    for(int i = 1; i <= n; ++i) {  
        for(int j = 1; j < m; ++j) {  
            scanf("%d", &cost);  
            x = (i == 1 ? u : (2*(i-1)-1)*(m-1)+j);  
            y = (i == n ? v : 2*(i-1)*(m-1) + j);  
            add(x, y, cost);  
        }  
    }  
   
    for(int i = 1; i < n; ++i) {  
        for(int j = 1; j <= m; ++j) {  
            scanf("%d", &cost);  
            x = (j == 1 ? v : 2*(i-1)*(m-1)+j-1);  
            y = (j == m ? u : 2*(i-1)*(m-1)+j-1+m);  
            add(x, y, cost);  
        }  
    }  
   
    for(int i = 1; i < n; ++i) {  
        for(int j = 1; j < m; ++j) {  
            scanf("%d", &cost);  
            x = (2*(i-1)*(m-1)+j);  
            y = ((2*(i-1)+1)*(m-1)+j);  
            add(x, y, cost);  
        }  
    }  
}  
   
int main() {  
    while(scanf("%d %d", &n, &m) != EOF) {  
        memset(head, -1, sizeof head);  
        ednum = 0;                  // 结点个数  
        u = 0;                      // 起点  
        v = 2*(n-1)*(m-1)+1;        // 终点  
   
        init();  
        dijkstra(u, v);  
    }  
    return 0;  
} 