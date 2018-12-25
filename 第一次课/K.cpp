#define _CRT_SBCURE_NO_DEPRECATE
#include <set>
#include <cmath>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;

const int maxn = 233;
const int INF = 0x3f3f3f3f;
typedef long long ll;

int par[7777];
int rankk[7777];
int u[maxn], v[maxn], w[maxn], r[maxn];
int N, M, a, b, c;

void init(int n); //初始化
int find(int x); //查找根节点(所属集合)
void unite(int x, int y); //合并集合
bool same(int x, int y); //是否属于同一集合

int cmp(const int i, const int j) {return w[i]<w[j];}

int Kruskal()
{
    int ans = 0;
    memset(par, 0, sizeof(par));
    init(maxn);
    for(int i = 0; i < M; i++) r[i] = i;
    sort(r, r+M, cmp);
    for(int i = 0; i < M - 1; i++)
    {
        int e = r[i]; int x = find(u[e]); int y = find(v[e]);
        if(x != y) {ans += w[e]; par[x] = y;}
    }
    return ans;
}

int main(void)
{
    while(cin >> N >> M)
    {
        if(!N) break;
        memset(u, 0, sizeof(u));
        memset(v, 0, sizeof(v));
        memset(r, 0, sizeof(r));
        memset(w, 0, sizeof(w));
        for(int i = 0; i < N; i++)
        {
            cin >> u[i] >> v[i] >> w[i];
        }
        int ans = Kruskal();

        int flag = 1;
        for(int i = 2; i <= M ; ++i)
        {
            if( find(1) != find(i) )
            {
                flag = 0;
                break;
            }
        }

        if(!flag) cout << "?" << endl;
        else cout << ans << endl;
    }
    return 0;
}

void init(int n)
{
    for(int i = 0; i < n; i++)
    {
        par[i] = i;
        rankk[i] = 0;
    }
}

int find(int x)
{
    if(par[x] == x)
        return x;
    else
        return par[x] = find(par[x]);
}

void unite(int x, int y)
{
    x = find(x);
    y = find(y);
    if(x == y)
        return;
    if(rankk[x] < rankk[y])
        par[x] = y;
    else
    {
        par[y] = x;
        if(rankk[x] == rankk[y])
            rankk[x]++;
    }
}

bool same(int x, int y)
{
    return find(x) == find(y);
}
