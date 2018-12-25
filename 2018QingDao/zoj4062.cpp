#include<iostream>
#include<cstring>
#include<cmath>
#include<map>
#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
ll n,m;
ll a[100005];

// 每次模拟计算方案的最小花费是否超出机器人最大的行走距离，若不超出扩大否则缩小
bool check(ll x){
    ll sum=0;
    ll res=0;
    for(int i=0;i<n;i++){
        ll xx=(x/a[i]+(x%a[i]!=0)-res);
        if((x/a[i])+(x%a[i]!=0)<=res){if(i!=n-1)xx=1;else xx=0;}
        res=xx-1;
        if(res<0)res=0;
        sum+=xx+res;
        if(sum>m)return false;
    }
    return true;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        scanf("%lld%lld",&n,&m);
        ll maxx=0;
        for(int i=0;i<n;i++){
            scanf("%lld",&a[i]);
            maxx=max(maxx,a[i]);
        }
        ll r=1e18;
        ll l=0;
        ll ans=0;
        while(l<=r)
        {
            ll mid=(l+r)>>1;
            if(check(mid))
            {
                ans=mid;
                l=mid+1;
            }else{
                r=mid-1;
            }
        }
        if(l==0)l=1;
       printf("%lld\n",l-1);
    }
    return 0;
}
