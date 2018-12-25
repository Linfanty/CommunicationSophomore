#include<iostream>
#include<algorithm>
#include<fstream>
#include<math.h>
#include<algorithm>
#include<stack>
#include<queue>
using namespace std;
fstream fin("1.txt");
//streambuf *buf = cin.rdbuf(fin.rdbuf());//用于重定项输入改成，把cin当成fin

const int inf = 1 << 29;
const int MAXN = 310;

int n, np, nc, m;
int map[MAXN][MAXN];
bool vis[MAXN];
int pre[MAXN];

void init()//初始化
{
    int len = n + 2;
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < len; j++)
        {
            map[i][j] = 0;
        }
    }
}
int getmin(int a, int b)
{
    return a < b ? a : b;
}
int getroute(int s, int e)//bfs求源点到汇点的路径
{
    int len = n + 2;
    int temp;
    for (int i = 0; i < len; i++)
    {
        vis[i] = false;
        pre[i] = -1;
    }
    bool haveroute = false;
    queue<int> que;
    que.push(s);
    vis[s] = true;
    while (!haveroute && !que.empty())
    {
        temp = que.front();
        que.pop();
        for (int i = 0; i < len; i++)
        {
            if (map[temp][i] && !vis[i])
            {
                vis[i] = true;
                pre[i] = temp;
                if (i == e)
                {
                    haveroute = true;
                    break;
                }
                que.push(i);
            }
        }
    }
    if (!haveroute)
        return false;
    return true;
}
int getMaxflow(int s, int e)//求最大流
{
    int t;
    int result = 0;
    while (getroute(s, e))
    {
        int minflow = inf;
        t = e;
        while (pre[t] != -1)//寻找路线中最小的线路
        {
            minflow = getmin(minflow, map[pre[t]][t]);
            t = pre[t];
        }
        t = e;
        while (pre[t] != -1)//增广路
        {
            map[pre[t]][t] -= minflow;
            map[t][pre[t]] += minflow;
            t = pre[t];
        }
        result += minflow;
    }
    return result;
}
int main()
{
    char rubbish;
    int first, next;
    int value;
    while (cin >> n >> np >> nc >> m)
    {
        init();
        int start = n;
        int end = n + 1;
        for (int i = 0; i < m; i++)
        {
            cin >> rubbish;
            cin >> first;
            cin >> rubbish;
            cin >> next;
            cin >> rubbish;
            cin >> value;
            if (first == next)
                continue;
            map[first][next] = value;
        }
        for (int i = 0; i < np; i++)
        {
            cin >> rubbish;
            cin >> first;
            cin >> rubbish;
            cin >> value;
            map[start][first] = value;//超级源点与供电点相连
        }
        for (int i = 0; i < nc; i++)
        {
            cin >> rubbish;
            cin >> first;
            cin >> rubbish;
            cin >> value;
            map[first][end] = value;//超级汇点与消费点相连
        }
        cout << getMaxflow(start, end) << endl;
    }
    return 0;
}