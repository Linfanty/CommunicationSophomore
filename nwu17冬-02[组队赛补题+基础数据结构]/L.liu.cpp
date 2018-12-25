#include <bits/stdc++.h>
using namespace std;
const int N = 1e2 + 10;

char oil[N][N];
bool vis[N][N];
int m, n, dir[8][2] = {1, 0, -1, 0, 0, 1, 0, -1, 1, 1, 1, -1, -1, 1, -1, -1};
bool check(int x, int y)
{
	return x >= 0 && x < m && y >= 0 && y < n && !vis[x][y] && oil[x][y] == '@';
}
void dfs(int x, int y)
{
	if(vis[x][y]) return;
	vis[x][y] = 1;
	for(int i = 0; i < 8; i++)
	{
		int fx = x + dir[i][0], fy = y + dir[i][1];
		if(!check(fx, fy)) continue;
		dfs(fx, fy);
	}
}
int main()
{
	while(scanf("%d %d", &m, &n) && m && n)
	{
		memset(vis, 0, sizeof(vis));
		for(int i = 0; i < m; i++)
			scanf("%s", oil[i]);
		int ans = 0;
		for(int i = 0; i < m; i++)
		for(int j = 0; j < n; j++)
			if(!vis[i][j] && oil[i][j] == '@')
				dfs(i, j), ans++;
		printf("%d\n", ans);
	}

	return 0;
}
