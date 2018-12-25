#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<queue>
using namespace std;
#define N 20010

struct rng{
    int st,ed;
}a[N];
int Max=1;
int cmp(rng x,rng y){
    return x.ed<y.ed?1:0;
}

priority_queue<int>s;
int main()
{
    int i,j,n,m;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d %d",&a[i].st,&a[i].ed);
    }
    sort(a+1,a+1+n,cmp);
    int res=1;
    for(i=2;i<=n;i++){
        if(a[1].ed<=a[i].st){
            res++;
            a[1].ed=a[i].ed;
        }
    }
    printf("%d\n",res);
    return 0;
}
