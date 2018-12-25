#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <queue>
using namespace std;
const int MAXN=1010;
int n,m;
char g[MAXN][MAXN];
queue<pair<int,int> >q;
int a[MAXN][MAXN];
int move[][2]={{0,1},{0,-1},{1,0},{-1,0}};

/*

2
4
4
FFFF
FFJF
FFFF
FFFF
*/
void bfs1()
{
    memset(a,-1,sizeof(a));
    while(!q.empty())q.pop();
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(g[i][j]=='F')
            {
                a[i][j]=0;
                q.push(make_pair(i,j));
            }
    while(!q.empty())
    {
        pair<int,int> tmp=q.front();
        q.pop();
        int x=tmp.first;
        int y=tmp.second;
        for(int i=0;i<4;i++)
        {
            int tx=x+move[i][0];
            int ty=y+move[i][1];
            if(tx<0||ty<0||tx>=n||ty>=m)continue;
            if(a[tx][ty]!=-1)continue;
            if(g[tx][ty]=='#')continue;
            a[tx][ty]=a[x][y]+1;
            q.push(make_pair(tx,ty));
        }
    }
}
int b[MAXN][MAXN];
int bfs2()
{
    memset(b,-1,sizeof(b));
    while(!q.empty())q.pop();
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(g[i][j]=='J')
            {
                q.push(make_pair(i,j));
                b[i][j]=0;
            }
    while( !q.empty() )
    {
        pair<int,int> tmp=q.front();
        q.pop();
        int x=tmp.first;
        int y=tmp.second;
        if(x==0 || y==0 || x==n-1 || y==m-1)
            return b[x][y]+1;
        for(int i=0;i<4;i++)
        {
            int tx=x+move[i][0];
            int ty=y+move[i][1];
            if(tx<0||ty<0||tx>=n||ty>=m)continue;
            if(b[tx][ty]!=-1)continue;
            if(g[tx][ty]=='#')continue;
            if(a[tx][ty]!=-1 && b[x][y]+1>=a[tx][ty])continue;
            b[tx][ty]=b[x][y]+1;
            q.push(make_pair(tx,ty));
        }
    }
    return -1;
}
int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++)
            scanf("%s",g[i]);
        bfs1();
        int ans=bfs2();
        if(ans==-1)printf("IMPOSSIBLE\n");
        else printf("%d\n",ans);
    }
    return 0;
}
