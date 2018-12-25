#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 2*1e5+10;
#define LL long long
int c[maxn],v[maxn],g[maxn];
int n,s,k,t,flag;

bool judge(LL mid)
{
    LL time=0;
    for(int i=1;i<k;++i)
    {
        LL dix=g[i]-g[i-1];
        if(dix>mid)//油量mid不足以支撑以慢速到达下一个加油站
            return false;
        LL fv=(mid-dix)*2;//fv+sv=mid  fv/2+sv=dix 解这个方程组
        LL sv=mid-fv;
        if(sv<0)//sv为负数表示，可以全程用快速从上一个加油站跑到当前加油站
            time+=dix;
        else time+=fv/2+sv*2;
    }
    if(time<=t){
        flag=1;//全程快速能在t时间内到达
        return true;
    }
    else
        return false;
}

int main()
{
    while(scanf("%d%d%d%d",&n,&k,&s,&t)!=EOF)
    {
        for(int i=0;i<n;++i)
            scanf("%d%d",&c[i],&v[i]);
        for(int i=1;i<=k;++i)
            scanf("%d",&g[i]);
        g[0]=0;//加入起点
        g[k+1]=s;//加入终点
        k+=2;
        sort(g,g+k);//将油站按位置排序，给出的是乱序

        LL left=0,right=s*2,mid;
        flag=0;
        while(left<right)
        {
            mid=(left+right)/2;
            if(judge(mid))
                right=mid;
            else left=mid+1;
        }
        if(!flag){//全程快速也不能在t时间内到达
            printf("-1\n");
            continue;
        }
        int ans=1e9+10;
        for(int i=0;i<n;++i)
        {
            if(v[i]>=left)
                ans=min(ans,c[i]);
        }
        if(ans==1e9+10)//表示没有足够大油量的汽车
            printf("-1\n");
        else    printf("%d\n",ans);
    }
    return 0;
}
