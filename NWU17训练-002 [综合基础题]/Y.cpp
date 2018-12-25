#include<iostream>
#include<stdio.h>
#include<queue>
#include<cstring>
using namespace std;
const int maxn = 1005;

char g[maxn][maxn];
bool vit[maxn][maxn];
int a[maxn][maxn];
int b[maxn][maxn];
int n, m;

int dir[4][2] = {1,0,-1,0,0,1,0,-1};
queue< pair<int, int> > q;
#define mkp make_pair

void bfs1()
{
    memset(a, -1, sizeof a);/// -1 未走过
    while( !q.empty() ) q.pop();
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(g[i][j] == 'F')
                a[i][j] = 0, q.push( mkp(i,j) );
    while( !q.empty() )
    {
        pair<int, int> tmp = q.front();
        q.pop();
        int x = tmp.first;
        int y = tmp.second;

        for(int i = 0; i < 4; i++ )
        {
            int dx = x + dir[i][0];
            int dy = y + dir[i][1];
            if( dx<0|| dy<0 || dx >= n || dy >= m)
                continue; // 越界
            if( a[dx][dy] != -1) continue; // 已经走过
            if( g[dx][dy] == '#' )  continue; // 墙壁
            a[dx][dy] = a[x][y] + 1;
            q.push( mkp(dx,dy) );
        }
    }
}

int bfs2()
{
    memset(b, -1, sizeof b);/// -1 未走过
    while( !q.empty() ) q.pop();
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(g[i][j] == 'J')
                b[i][j] = 0, q.push( mkp(i,j) );

    while( !q.empty() )
    {
        pair<int, int > tmp = q.front();
        q.pop();
        int x = tmp.first;
        int y = tmp.second;

        if( x==0 || y==0 || x==n-1 || y==m-1 )
            return b[x][y] + 1;
        for(int i = 0; i < 4; i++)
        {
            int dx = x + dir[i][0];
            int dy = y + dir[i][1];
            if( dx<0|| dy<0 || dx >= n || dy >= m)
                continue; // 越界
            if( b[dx][dy] != -1) continue; // 已经走过
            if( g[dx][dy] == '#' )  continue; // 墙壁

            if( a[dx][dy] != -1 && b[x][y] + 1 >= a[dx][dy] )
                continue; /// Burned
            b[dx][dy] = b[x][y] + 1;
            q.push(mkp(dx,dy));
        }
    }
    return -1;
}



int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        for(int i = 0; i < n; i++)
            cin >> g[i];

        bfs1();
        int ans = bfs2();
        if( ans == -1 ) cout << "IMPOSSIBLE" << endl;
        else cout << ans << endl;
    }
}
