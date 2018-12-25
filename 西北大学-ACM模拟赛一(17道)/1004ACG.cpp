#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdlib>
using namespace std;
#define maxn 110

int n,m;
int a[maxn][maxn];
int color[maxn];
struct Edge{int to,next;}edge[maxn*maxn];
int h[maxn],cnt;
// void add(int u,int v){cnt++;edge[cnt].to=v;edge[cnt].next=h[u];h[u]=cnt;}
void add(int u,int v){cnt++;edge[cnt].to=v;edge[cnt].next=h[u];h[u]=cnt;}


void read(){
	int x,y;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(i!=j)a[i][j]=1;
	for(int i=1;i<=m;i++){
		scanf("%d%d",&x,&y);
		a[x][y]=a[y][x]=0;
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(a[i][j])	add(i,j);

}
//-----------------------------------------//
bool dfs(int x){
	for(int i=h[x];i;i=edge[i].next){
		int v=edge[i].to;
		if(!color[v]){
			color[v]=3^color[x];
			if(!dfs(v))return false;
			continue;
		}
		if(color[x]==color[v])return false;
	}
	return true;
}
void judge(){
	for(int i=1;i<=n;i++)
		if(!color[i]) {
			color[i]=1;
			if(!dfs(i)){
				printf("0");
				exit(0);
			}
		}
}
//-----------------------------------------//
int q[maxn];
bool vis[maxn];
int size[maxn][2],p0;
void bfs(int st){
	int head=0,tail=1;
	q[head]=st;vis[st]=1;
	++p0; size[p0][color[st]-1]=1;
	while(head!=tail){
		int u=q[head];
		for(int i=h[u];i;i=edge[i].next){
			int v=edge[i].to;
			if(vis[v])continue;
			vis[v]=1;q[tail++]=v;
			++size[p0][color[v]-1];
		}
		head++;
	}
}
const int MOD=1000000007;
int g[maxn][maxn];
void work(){
	for(int i=1;i<=n;i++)
		if(!vis[i])bfs(i);
	//装包求解方案数，包容量为n，物品大小为size[i][0],size[i][1],求装满n/2的方案
	int size_bag=n;
	g[0][0]=1;
	for(int i=1;i<=p0;i++)
		for(int j=0;j*2<=size_bag;j++){
			if(j>=size[i][0])g[i][j]=(g[i][j]+g[i-1][j-size[i][0]]) % MOD;
			if(j>=size[i][1])g[i][j]=(g[i][j]+g[i-1][j-size[i][1]]) % MOD;
		}
	printf("%d\n",g[p0][size_bag/2]%MOD);
	return;
}
int main(){
	scanf("%d%d",&n,&m);
	if(n&1){printf("0");return 0;}
	read();
	judge();
	work();
	return 0;
}
