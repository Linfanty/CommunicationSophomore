#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

struct node
{
    int start;
    int end;
} a[11111];

bool cmp(node x,node y)
{
    if(x.end<y.end) return true;
    else if(x.end==y.end && x.start>y.start) return true;
    return false;
}

int main()
{
    int n,i,j,ans,end;
    cin>>n;
    for(i=0;i<n;i++) cin>>a[i].start>>a[i].end;
    sort(a,a+n,cmp);
    ans=0;
    end=-1e9-100;
    for(i=0;i<n;i++) {
        if(a[i].start>=end) {
            ans++;
            end=a[i].end;
        }
    }
    cout<<ans<<endl;
    return 0;
}
