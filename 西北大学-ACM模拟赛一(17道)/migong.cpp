#include <cstdio>
#include <queue>
#include <climits>
#include <ctype.h>
#define pname "maze2"
#define commonfio freopen(pname".in","r",stdin); freopen(pname".out","w",stdout);
char mp[105][105];
using namespace std;
#define pushnode(x,y,k) q.push(x); q.push(y); q.push(k)
#define popnode(x,y,k) x=q.front(); q.pop();y=q.front(); q.pop();k=q.front(); q.pop()
#define toc mp[nx][ny]
queue<int> q;
bool vis[105][105][1<<10];
int dis[105][105][1<<10];
int dx[]= {-1,0,0,1};
int dy[]= {0,1,-1,0};
#define has(n) (s&(1<<n))
#define clr(id) ns=ns&(~(1<<id))
#define set(id) ns=ns|(1<<id)
int n,m,p;
int main()
{
    int sx,sy,ex,ey;
    commonfio;
    scanf("%d%d%d", &n, &m, &p);
    for (int i=1; i<=n; i++)
        {
            scanf("%s",mp[i]+1);
        }
    for (int i=1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (mp[i][j] == '$')
                {
                    sx = i;
                    sy = j;
                }
    for (int i=1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (mp[i][j] == '&')
                {
                    ex = i;
                    ey = j;
                }
    pushnode(sx,sy,0);
    vis[sx][sy][0]=1;
    while(!q.empty())
        {
            int x,y,s;
            popnode(x,y,s);
            //    printf("%d %d %d\n",x,y,s);
            vis[x][y][s]=0;
            for(int i=0; i<4; i++)
                {
                    int nx=x+dx[i],ny=y+dy[i],ns=s;
                    if (nx < 1 || ny < 1 || nx > n || ny > m) continue;
                    char cc=toc;
                    if(cc=='#') continue;
                    if(cc!='.' && cc!='&' && cc!='$')
                        {
                            if(isupper(cc))
                                {
                                    int id=cc-'A';
                                    if(has(id)==0) continue;
                                    //clr(id);
                                }
                            else
                                {
                                    int id=cc-'a';
                                    set(id);
                                }
                        }
                    if(dis[x][y][s]+1<dis[nx][ny][ns] || dis[nx][ny][ns]==0)
                        {
                            dis[nx][ny][ns]=dis[x][y][s]+1;
                            if(!vis[nx][ny][ns])
                                {
                                    vis[nx][ny][ns]=1;
                                    pushnode(nx,ny,ns);
                                }
                        }
                }
        }
    int ans=INT_MAX;
    for (int i = 0; i < (1 << p); i++)
        {
            if(dis[ex][ey][i]!=0 && ans>dis[ex][ey][i] ) ans=dis[ex][ey][i];
        }
    printf("%d\n",ans==INT_MAX?-1:ans);
}
