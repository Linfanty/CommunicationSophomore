#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <cmath>
#include <stack>
#include <queue>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <stdlib.h>
#include <iomanip>
#include <fstream>

using namespace std;
#pragma comment(linker, "/STACK:102400000,102400000")
#define maxn 105
#define MOD 1000000007
#define mod 2147493647
#define mem(a , b) memset(a , b , sizeof(a))
#define LL long long
#define ULL unsigned long long
#define FOR(i , n) for(int i = 1 ;  i<= n ; i ++)
typedef pair<int , int> pii;
int n , m , t;
int a[maxn] , b[maxn] , M[maxn] , path[2*maxn];
int e[2*maxn][2*maxn] , vis[2*maxn];
int flow[2*maxn];
bool bfs(int ed)
{
    mem(path , -1);
    mem(vis , 0);
    mem(flow , 0);
    flow[0] = MOD;
    queue<int>q;
    while(!q.empty()) q.pop();
    q.push(0) ;
    vis[0] = 1;
    while(!q.empty())
    {
        int cur = q.front();
        q.pop();
        if(cur == ed) return 1;
        for(int i = 0 ; i <= ed; i ++)
        {
            if(!vis[i] && e[cur][i] > 0)
            {
                path[i] = cur;
                vis[i] = 1;
                flow[i] = min(flow[cur] , e[cur][i]);
                q.push(i);
            }
        }
    }
    return 0;
}

int main()
{
    scanf("%d" , &t);
    while(t--)
    {
        mem(e , 0);
        scanf("%d %d" , &n , &m);
        int st = 0 , ed = n+m+1;
        for(int i = 1 ; i <= m ; i ++)
        {
            scanf("%d" , &M[i]);
            e[n+i][ed] += M[i];
        }
        for(int i = 1 ; i <= n ; i ++)
        {
            scanf("%d %d" , &a[i] , &b[i]);
            e[0][i] += a[i];
            int v;
            for(int j = 0 ; j < b[i] ; j ++)
            {
                scanf("%d" , &v);
                e[i][n+v] += 1;
            }
        }
        while(bfs(ed))
        {
            int f = flow[ed];
            int u  = ed , v = path[u];
            while(v != -1)
            {
                e[u][v] += f;
                e[v][u] -= f;
                u = v;
                v = path[u];
            }
        }
        int flag = 0;
        for(int i = n + 1 ; i <= n + m ; i ++)
        {
            if(e[i][ed] != 0) /// -***
            {
                flag = 1;
                break;
            }
        }
        if(!flag) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}