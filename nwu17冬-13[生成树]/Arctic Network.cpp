#include<cstdio>
#include<algorithm>
#include<cmath> 
#include<iostream>
#include<cstring>
#define maxn 505
using namespace std;
int f[maxn];

double MSTedge[maxn]; 

int Find(int x){
	return f[x]==x?x:f[x]=Find(f[x]);
}

void Union(int x,int y){ 
	int fx = Find(x);
	int fy = Find(y);
	if(fx != fy)
		f[fy] = fx;
}

struct Point{
	int x,y,id;
}point[maxn];

double dis(Point a,Point b){
	return sqrt(1.0*(a.x-b.x)*(a.x-b.x)+1.0*(a.y-b.y)*(a.y-b.y));
}

struct Edge{
	int from;
	int to;
	double w;
}edge[250050];

bool cmp1(Edge a,Edge b){
	return a.w<b.w;
}

bool cmp2(int x,int y){
	return x>y;
}

int N,S,P,cnt;

double Kruskal(){
	sort(edge,edge+cnt,cmp1);
	memset(f,0,sizeof(f));
	for(int i=1;i<=P;i++){
		f[point[i].id]=point[i].id;
	}


	int num=0; 
	int tot=0;
	for(int i=0;i<cnt;i++){
		if(Find(edge[i].from)==Find(edge[i].to))
			continue;
		num++;
		MSTedge[tot++]=edge[i].w;
		Union(edge[i].from,edge[i].to);
		if(num==P-1) break;
	}

	sort(MSTedge,MSTedge+tot,cmp2);
	if(num<P-1)	return -1;
	else return MSTedge[S-1];
}

int main(){
	scanf("%d",&N);
	while(N--){
		cnt=0;
		scanf("%d%d",&S,&P);
		for(int i=1;i<=P;i++){
			scanf("%d%d",&point[i].x,&point[i].y);
			point[i].id=i;
		}
		for(int i=1;i<=P;i++){
			for(int j=1;j<=P;j++){
				edge[cnt].from=point[i].id;
				edge[cnt].to=point[j].id;
				edge[cnt++].w=dis(point[i],point[j]);
			}
		}
	    printf("%.2f\n",Kruskal());
	}
}
