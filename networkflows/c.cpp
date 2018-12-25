#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MODX = 5837501, MODY = 9860381, MODZ = 8475871;
const ll N = 1e3 + 10;
ll n, m;
ll x[N * N], y[N * N], z[N * N], c[N][N];
void cal(int n) {
    for(int i = 2; i <= n * n; i++) {
        x[i] = (12345 + x[i - 1] * 23456 % MODX + x[i - 2] * 34567 % MODX + ((x[i - 1] * x[i - 2]) % MODX) * 45678 % MODX) % MODX;
        y[i] = (56789 + y[i - 1] * 67890 % MODY + y[i - 2] * 78901 % MODY + ((y[i - 1] * y[i - 2]) % MODY) * 89012 % MODY) % MODY;
    }
    for (int i = 0; i <= n * n; i++) z[i] = (x[i] * 90123 % MODZ+ y[i]) % MODZ + 1;
}
typedef pair<ll, int> P;
struct Edge {
    int to; ll cost;
};
vector<Edge> graph[N];
ll dis[N];
void dijkstra(int s) {
    priority_queue<P, vector<P>, greater<P> > pq;
    memset(dis, 0x3f, sizeof(dis));
    dis[s] = 0;
    pq.push(P(0, s));
    while(!pq.empty()) {
        P p = pq.top(); pq.pop();
        int v = p.second;
        if(dis[v] < p.first) continue;
        for(Edge e : graph[v]) {
            if(dis[e.to] > dis[v] + e.cost) {
                dis[e.to] = dis[v] + e.cost;
                pq.push(P(dis[e.to], e.to));
            }
        }
    }
}
ll mm[1000010];
int main() {
    while(cin >> n >> m) {
        for(int i = 0; i < n; i++)
            graph[i].clear();
        cin >> x[0] >> x[1]>> y[0] >> y[1];
        cal(n);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(i != j)
                graph[i].push_back((Edge){j, z[i * n + j]});
            }
        }
        dijkstra(0);
        memset(mm, 0, sizeof(mm));
        ll min1 = 0x3f3f3f3f3f3f3f3f;
        for(int i = 1; i < n; i++)
            min1 = min(min1, dis[i] % m);
        cout << min1 << endl;
    }
}
