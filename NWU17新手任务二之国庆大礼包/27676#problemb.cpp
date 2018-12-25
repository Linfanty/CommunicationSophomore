//#include <bits/stdc++.h>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <math.h>
#include <iostream>
#define lid (id<<1)
#define rid ((id<<1)|1)
#define lson rt<<1, l, (l+r)>>1
#define rson rt<<1|1, ((l+r)>>1)+1, r

const int maxn = 100005;
using namespace std;

int high[maxn*3], mx[maxn*3], mn[maxn*3], a, b;
int v[maxn], sum[maxn];
int n, q, cnt;

void pushup(int rt)
{
    mx[rt] = max(mx[rt<<1] ,mx[rt<<1|1]);
    mn[rt] = min(mn[rt<<1], mn[rt<<1|1]);
}

void build(int rt, int l, int r)
{
    if( l == r)
    {
        mx[rt] = mn[rt] = high[l];
        // high[l]
        return;
    }
    build(lson);
    build(rson);
    pushup(rt);
}

//void update(int rt, int l, int r)

int findmax(int rt, int l, int r)
{
    if( a <= l && b >= r)
        return mx[rt];
    if( a > r || b < l )
        return 0;
    int ans = 0;
    ans = max( findmax(lson), findmax(rson));
    return ans;
}

void init()
{
    cnt = 1;
    for(int i = 0; i < maxn; i++)
        v[i] = 0, sum[i] = 0;
}

void readcase()
{
    int num, pre;
    cin >> q >> pre;
    v[1] = 1;
    for(int i = 1; i < n; i++)
    {
        scanf("%d", &num);
        if( num == pre )
            v[cnt]++;
        else
        {
            cnt++;
            v[cnt]++;
            pre = num;
        }
        cout << i << " " << cnt << ' ' << v[cnt]
        << endl;
    }
    for(int i = 1; i <= cnt; i++)
        sum[i] = sum[i-1] + v[i];

}

int main()
{
    while( cin >> n && n)
    {
        init();
        readcase();
//        computing();
    }
    return 0;
}
