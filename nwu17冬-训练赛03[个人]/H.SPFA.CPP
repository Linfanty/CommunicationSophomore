/**********************
*@Name: hdu 2544 spfa
*
*@Author: Nervending
*@Describtion: spfa link easy
*@DateTime: 2017-10-04 14:00:39
***********************/
#include<bits/stdc++.h> 
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int maxn = 1e5+100;
const int maxm = 2e5+100; 
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int DINF = 0xc0c0c0c0;
int a, b, c;
int n, m, k, T;
ll t, ans;
int x, y, z;
struct node {
    long long to, cost, next;
} e[maxm];
int head[maxn];
bool vis[maxn];
long long dis[maxn], nume;
int pre[maxn]; 
int path[maxn];
void init() {
    memset(head, -1, sizeof head);
//  memset(vis, false, sizeof vis);
    memset(dis, 0x3f, sizeof dis);
    memset(pre, -1, sizeof pre);
//  nume = 0;
}
inline void add(int a, int b , int c) {
    node t = {b, c, head[a]};
    e[nume] = t;
    head[a] = nume++;
    node t2 = {a, c, head[b]};
    e[nume] = t2;
    head[b] = nume++;
}
void spfa(int st, int ed) {
    int q[maxn];
    int top=0,end=0;
    dis[st] = 0;
    q[end++]=st;
    while (end!=top) {
        int now = q[top++];
        top%=maxn;
        vis[now] = false;
        for (int i = head[now]; ~i; i = e[i].next) {
            int to = e[i].to;
            int cost = e[i].cost;
            if (dis[to] > dis[now] + cost) {
                dis[to] = dis[now] + cost;
                pre[to]=now; 
                if (!vis[to]) {
                    vis[to] = true;
                    q[end++]=to;
                    end%=maxn;
                }
            }
        }
    }
}

int main() {
//  freopen("in.txt","r",stdin);
//  freopen("out.txt","w",stdout);
    


    while (~scanf("%d %d",&n,&m)) {
        init();
        for (int i = 0; i < m; i++) {
        scanf("%d %d %d",&a,&b,&c);
            node t = {b, c, head[a]};
            e[nume] = t;
            head[a] = nume++;
            node t2 = {a, c, head[b]};
            e[nume] = t2;
            head[b] = nume++;
        }
        spfa(1, n);
        int now=n;
        int cnt=0;
        if(pre[now]==-1){
            cout<<-1<<endl;
            continue;
        } 
        while(now!=-1){
            path[cnt++]=now;
            now=pre[now];
        }
        for(int i=cnt-1;i>=0;i--){
            printf("%d ",path[i]); 
        } 
    }
    return 0;
}