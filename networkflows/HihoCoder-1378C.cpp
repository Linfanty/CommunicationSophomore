#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <climits>
#include <vector>
#include <queue>
#include <cstdlib>
#include <string>
#include <set>
#include <stack>

using namespace std;

const int max_n  = 505;
const int inf = 0xfffffff;
int gra[max_n][max_n];
vector<int>v[max_n];
int level[max_n];
int n,m;
vector<int>mp;
int flag;

bool bfs() {
    queue<int>q;
    memset(level,0,sizeof(level));
    q.push(1);
    level[1] = 1;
    if(flag) {
        mp.push_back(1);
    }
    while(!q.empty()) {
        int p = q.front();
        q.pop();
        if(p == n) {
            return true;
        }
        for(int i = 0; i < v[p].size(); i++) {
            int st = v[p][i];
            if(!level[st]&&gra[p][st]) {
                level[st] = level[p]+1;
                q.push(st);
                // cout << flag << ' ' << st << endl;
                if(flag) { //** 最好找不到的都加到mp中
                    mp.push_back(st);
                }
            }
        }
    }
    return false;
}
int dfs(int x,int sup) {
    if(x == n) {
        return sup;
    }
    int ret = 0;
    for(int i = 0; i < v[x].size(); i++) {
        int st = v[x][i];
        if(level[st] == level[x]+1 && gra[x][st]) {
            int mi = min(sup-ret,gra[x][st]);
            int mx = dfs(st,mi);
            gra[x][st] -= mx;
            gra[st][x] += mx;
            ret += mx;
            if(ret == sup) {//这里的返回是说当前的点所能流过的最大流，和后面所有能流过的总和相等是，便不可能再允许后面的流量流过
                return ret;
            }

        }
    }
    return ret;
}
int max_flow() {
    int ans = 0;
    while(bfs()) {
        ans += dfs(1,inf);
    }
    return ans;
}

int main() {
    scanf("%d%d",&n,&m);
    memset(gra,0,sizeof(gra));
    int a,b,c;
    for(int i = 0; i < m; i++) {
        scanf("%d%d%d",&a,&b,&c);
        v[a].push_back(b);
        gra[a][b] += c;
    }
    int ans = max_flow();
    printf("%d ",ans);

    mp.clear();
    flag = 1;
    bfs(); // 再跑一遍bfs 找增光路

    printf("%d\n",mp.size());
    printf("%d",mp[0]);
    for(int i = 1;i < mp.size();++i){
        printf(" %d",mp[i]);
    }
    printf("\n");
    return 0;
}