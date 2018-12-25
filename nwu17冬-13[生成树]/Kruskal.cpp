#include<iostream>
#include<algorithm>
#define MAXN 55
using namespace std;
int f[MAXN];
int n,m,cnt;

struct Edge{
    int from,to,cost;
}edge[MAXN * MAXN];

int Find(int x){
    return x == f[x]?x:f[x] = Find(f[x]);
}

void Union(int x,int y){
    int fx = Find(x);
    int fy = Find(y);
    if(fx != fy)
        f[fy] = fx;
}

void addEdge(int from,int to,int cost){
    edge[cnt].from = from;
    edge[cnt].to = to;
    edge[cnt++].cost = cost;
}

bool cmp(Edge a,Edge b){
    return a.cost < b.cost;
}

int Kruskal(){
    int tot = 0;//已选用的边的数目
    int sum = 0;//生成树的权值
    for(int i = 1;i <= n;i++) // 并查集的初始化
        f[i] = i; 

    sort(edge,edge + cnt,cmp);// 1.把图中的所有边按边权从小到大排序 
    /*****/
    for(int i = 0;i < cnt;i++){
        if(Find(edge[i].from) == Find(edge[i].to))// 2.属于两棵相同的树
            continue; // 再选择这条边必成环，所以跳过这条边选择下一条。 
        Union(edge[i].from, edge[i].to); // 3.将这两棵树合并为一棵树
        tot++; // 4.计数 已用边++
        sum += edge[i].cost; // 计数 权值

        if(tot == n - 1)//5.已选用的边的数目 够了
            break;
    }
    if(tot < n - 1)
        return -1;// 边不够 没有最小生成树
    return sum;
}
int main(){
    while(cin>>n && n){
        cin>>m;
        int a,b,w;
        cnt = 0;
        for(int i = 1;i <= m;i++){
            cin>>a>>b>>w;
            addEdge(a,b,w);
        }
        cout<<Kruskal()<<endl;
    }
}
