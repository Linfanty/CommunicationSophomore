#include <iostream>
#include <algorithm>
#include <queue>
#include <cstdio>
#include <cstring>
#include <limits.h>
using namespace std;
const int maxn = 55;

char mp[maxn][maxn];
int min_step[maxn][maxn][1<<10]; // ���������С����
int dir[4][2] = {0,1,0,-1,1,0,-1,0};
int n, m, key_num;
int sx, sy, ex, ey;
/// queue< pair<int, int> > q;

struct Node{
    int x, y, key_door, step;
    /// ���� Կ��_�� ��ǰ����
};

bool bianjie(int x,int y)
{
    if(x<=0 || y<=0 || x>n || y>m || mp[x][y]=='#')
        return false;
    return true;
}

int bfs()
{
    queue <Node> q;
    q.push({sx, sy, 0, 0});
    memset(min_step, 0, sizeof(min_step));

    while(!q.empty())
    {
        Node tmp = q.front();// ��ǰλ��
        q.pop();
        int xx = tmp.x;
        int yy = tmp.y;

        for(int i = 0; i < 4; i++)
        {
            Node Next = tmp;// ��һ��λ��
            int dx = xx + dir[i][0];
            int dy = yy + dir[i][1];
            int key_door = Next.key_door;
            int step = Next.step+1;

            if( !bianjie(dx, dy))   continue;
            if( mp[dx][dy] != '.' && mp[dx][dy] != '&' && mp[dx][dy] != '$')
            {
                if(isupper(mp[dx][dy]))
                {
                    int num = mp[dx][dy] - 'A';
                    if( !(key_door&(1<<num)) ) continue;
                    /// ״ѹΪ0 û���õ�Կ��
                    else ;/// �ſ��Կ� �����
                }
                else if(islower(mp[dx][dy]))
                {
                    int num = mp[dx][dy] - 'a';
                    key_door = key_door|(1<<num);
                    /// set���� �õ�Կ��
                }
            }
            // ֮ǰ����С���� ���� ��ǰ�����Ĳ���
            if(  min_step[dx][dy][key_door] > step
               || min_step[dx][dy][key_door] == 0 )
            {
                min_step[dx][dy][key_door] =  step;// ������С����
                q.push(Node{dx, dy, key_door, step});
            }
        }
    }
}

int main()
{
    scanf("%d %d", &n, &m);
    scanf("%d", &key_num);
    for(int i = 1; i <= n; i++)
    {
        getchar();
        for(int j = 1; j <= m; j++)
        {
            scanf("%c", &mp[i][j]);
            if( mp[i][j] == '$')
                sx = i, sy = j;
            if( mp[i][j] == '&')
                ex = i, ey = j;
        }
    }
        bfs();
        int ans = INT_MAX;
        for(int i = 0; i < (1<<key_num) ; i++)
            if( min_step[ex][ey][i] != 0 &&
                min_step[ex][ey][i] < ans )
               ans = min_step[ex][ey][i];
        printf("%d\n", ans==INT_MAX?-1:ans);
}

/**
5 5
1
&A..$
####.
...#.
.#.#.
a#...
*/
