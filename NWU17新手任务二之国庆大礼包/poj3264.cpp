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

const int maxn = 50005;
using namespace std;

int high[maxn*3], mx[maxn*3], mn[maxn*3], a, b;

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

int findmin(int rt, int l, int r)
{
    if( a <= l && b >= r)
        return mn[rt];
    if( a > r || b < l )
        return 0x3f3f3f3f;
    int ans = 0x3f3f3f3f;
    ans = min( findmin(lson), findmin(rson));
    return ans;
}

int main()
{
    int n, q;
    scanf("%d %d",&n, &q);

    for(int i = 1; i <= n; i++)
        scanf("%d", &high[i]);

    build(1, 1, n);
    while(q--)
    {
        int max1 = 0, min1 = 999999999;
        scanf("%d %d", &a, &b);
        //printf("%d %d    ", findmax(1,1,n), findmin(1,1,n));
        printf("%d\n", findmax(1,1,n) - findmin(1,1,n) );
    }
    return 0;
}
