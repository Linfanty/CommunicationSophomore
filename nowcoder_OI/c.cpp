#include<algorithm>
#include<iostream>
#include<string>
#include<map>//int dx[4]={0,0,-1,1};int dy[4]={-1,1,0,0};
#include<set>//int gcd(int a,int b){return b?gcd(b,a%b):a;}
#include<vector>
#include<cmath>
#include<stack>
#include<string.h>
#include<stdlib.h>
#include<cstdio>
#define maxn 500003
#define ll long long
#define INF 10000000
using namespace std;
ll ans[maxn] ;
struct node
{
    ll l,sta;
    node() {}
};
/*
题目大意：给定n个线段，如给定1，3线段则，1到3每个数计数加一次。
最后统计计数1到n中点的个数。
本题本人踩的最多的坑点，是数据量大小没把握好，因为n范围是2e5，
而我存储的是边界点，所以数组范围应该是4e5这样，，没注意，wrong了一次。
本题的思维还是很巧妙的，有点像线段树中的技巧（树状数组），
当要将区间1到n每个数的计数加一时，可以设置标记（懒惰标记）
在1位置设1，在n+1位置（注意不是n位置）设置-1.
这样从头到尾扫一遍维护者标记和就可以描述区间的计数情况。
本来我也有这样的想法，但想的是开一个1e18数组显然不可行，也是晕头了，
没想到可以遍历标记的位置区间（预处理按边界排序）。
节点由边界和边界性质（sta）构成。
和上面说的一样，从头到尾维护标记和就可以描述计数，
至于具体点，那就是扫描到的当前边界减去上一次的边界，得到标记和对应的点数。
这题还是很好的，值得研究。
至于排序后产生的序列的做法的正确性，可以简单证明，不难。在此略。
*/
node seq[maxn];
 
bool cmp(node x,node y)
{
    if(x.l==y.l) return x.sta>y.sta;
    return x.l<y.l;
}
 
int main()
{
    ll n ; scanf("%lld",&n);
    for ( ll i=1 ; i<=2*n ; i++ )
    {
        scanf("%lld",&seq[i-1].l);
        if(i&1)  seq[i-1].sta=1;
        else { seq[i-1].sta=-1;seq[i-1].l++; }
        //scanf("%d",&seq[i].r);
        //seq[i].sta=-1;
    }
    sort(seq,seq+2*n,cmp);
 
    memset(ans,0,sizeof(ans));
    ll cnt=0,ts=1,lb=seq[0].l;
    for(ll i=1;i<2*n;i++)
    {
        ans[ts]+=(seq[i].l-seq[i-1].l);
        if ( seq[i].sta == 1 )  ts++;
        else  ts-- ;
    }
    printf("%lld",ans[1]);
    for(int i=2;i<=n;i++) printf(" %lld",ans[i]);puts("");
 
    return 0;
}