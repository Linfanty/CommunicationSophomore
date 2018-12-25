#include <iostream>
#include <cstring>
using namespace std;

int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
bool visit[50][50];
int l = 0;
int num = 1;
int n;

void dfs(int x, int y)
{
    visit[x][y] = true;//�������Ǳ�ʾ�����λ��������
    if(num < n)
    {
        int nx = x+dir[l][0];
        int ny = y+dir[l][1];//���������������ߵ���һ��λ��
        num++;
        if(num == n)
        {
            num = 1;
            l = (l+1)%4;
        }
        int flag = 0;   int i;

        for(i = 0; i < 4; i++)//�������λ�����ܳ��˸ղŹ�����λ����������λ����û�к���Ȧ������ճ��һ��
        {
            int nnx = nx + dir[i][0];
            int nny = ny + dir[i][1];
            if(nnx == x && nny == y)    continue;
            if(nnx>=0&&nny>=0&&visit[nnx][nny]) flag = 1;
        }
        if(!flag)
            dfs(nx, ny);//���λ������

        else//ճ��һ��Ļ��ͻ���һ�����������
        {
            num = 1;
            l = (l+1)%4;
            nx = x+dir[l][0];
            ny = y+dir[l][1];
            flag = 0;
            if(!visit[nx][ny])
            {
                for(i = 0; i < 4; i++)
                {
                    int nnx = nx + dir[i][0];
                    int nny = ny + dir[i][1];
                    if(nnx == x && nny == y)    continue;
                    if(nnx>=0&&nny>=0&&visit[nnx][nny]) flag = 1;
                }
                if(!flag)
                    dfs(nx, ny);
                else return;
            }
        }
    }
}

int main()
{
    int t;  cin >> t;
    while(t--)
    {
        l = 0;
        num = 1;
        memset(visit, false, sizeof(visit));
        cin >> n;
        dfs(0, 0);//����dfs�ߵĽ�������ߵ�λ�ñ��Ϊtrue

        for(int i = 0; i < n; i++)//����visit�������
        {
            for(int j = 0; j < n; j++)
                if(visit[i][j]) cout << "#";
                else    cout << " ";
            cout << endl;
        }
    }
}
