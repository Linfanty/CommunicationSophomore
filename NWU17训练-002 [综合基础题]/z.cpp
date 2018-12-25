#include<iostream>
#include<stdio.h>
#include<queue>
#include<cstring>
using namespace std;
const int maxn = 1005;

char mp[maxn][maxn];
bool vit[maxn][maxn];
int tm[maxn][maxn];
int n, m;

int dir[4][2] = {1,0,-1,0,0,1,0,-1};

struct Node{
    int x, y, step;
}node;

bool check(int x, int y)
{
    if( vit[x][y] == 1 || x < 0 || x >= n || y < 0 || y >= m
        ||  mp[x][y] == '#' )
        return false;
    return true;
}

void bfs_fire_time(int x, int y)
{
    queue<Node> q;
    q.push(Node{x, y, 0});

    vit[x][y] = 1;
    while( !q.empty() )
    {
        Node now = q.front();
        int xx = now.x;
        int yy = now.y;
        int stepp = now.step;
        q.pop();
        //if( check(x,y) )
        //   return;

        for(int i = 0; i <= 3; ++i)
        {
            int dx = xx + dir[i][0];
            int dy = yy + dir[i][1];

            if( check(dx, dy) )
            {
                vit[dx][dy]  = 1;
                tm[dx][dy] = stepp + 1;
                //cout << dx << ' ' << dy << ' ' << stepp+1 << endl;
                q.push(Node{dx, dy, stepp+1});
            }
        }
    }
}
bool check_out(int x, int y, int st, int time_fire)
{
   // cout <<" x : y : st : " <<  x << y << st << ' ' << time_fire<< endl;
    if( (st < time_fire )  && (x < 0 || y < 0 || x >=n || y >= m ) )
        return true;
    return false;
}


int inf = 0x3f3f3f;
int bfs_joe(int x, int y)
{
    int min_time = inf;
    queue<Node> q;
    q.push(Node{x, y, 0});

    vit[x][y] = 1;
    while( !q.empty() )
    {
        Node now = q.front();
        int xx = now.x;
        int yy = now.y;
        int stepp = now.step;
        q.pop();

        for(int i = 0; i <= 3; ++i)
        {
            int dx = xx + dir[i][0];
            int dy = yy + dir[i][1];

            if( check_out(dx, dy, stepp, tm[xx][yy] ) )
            {
                min_time = min(min_time, stepp+1);
                //cout << "min_time: " << min_time << endl;
                return min_time;
            }

            if( check(dx, dy) )
            {
                vit[dx][dy]  = 1;
                q.push(Node{dx, dy, stepp+1});
            }
        }
    }
    return -1;
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        memset(mp, 0, sizeof mp);
        memset(vit, false, sizeof vit);
        memset(tm, 0, sizeof tm);


        int fx, fy, jx, jy;
        scanf("%d %d", &n, &m);
        for(int i = 0; i < n; ++i)
        {
            getchar();
            for(int j = 0; j < m; ++j)
            {
                scanf("%c", &mp[i][j]);
                if( mp[i][j] == 'J' )
                {
                    jx = i;
                    jy = j;
                }
                if( mp[i][j] == 'F' )
                {
                    fx = i;
                    fy = j;
                }
            }
        }
        bfs_fire_time(fx, fy);
        memset(vit, false, sizeof vit);
        int min_tm = bfs_joe(jx, jy);

        if(min_tm == -1 )
            printf("IMPOSSIBLE\n");
        else printf("%d\n", min_tm);
    }
}

