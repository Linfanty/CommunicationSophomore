#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
// ÓÐBUG°¢
//Ò»¿ªÊ¼Ô¤´¦ÀíÇ°×ººÍ£¬È»ºó¶þ·ÖÕý·½ÐÎ±ß³¤£¬Ã¶¾ÙÕý·½ÐÎµÄÎ»ÖÃ¼´¿É
int n,m,a[1005][1005],ans1;
long long sum[1005][1005],sum0[1005][1005],ans2=1LL<<60;

bool checkzero(int x,int y,int len)
{
    int newx = x+len-1;
    int newy = y+len-1;
//cout << x << ' ' << y << ' ' << newx << ' ' << newy << ' ' << len << endl;
    // ÓÒÏÂ½ÇÃæ»ý == 4 - 3 - 2 + 1
    return (sum0[newx][newy]-sum0[x-1][newy]
                -sum0[newx][y-1]+sum0[x-1][y-1] )==0; // ÇÉÃî
}

bool check(int len)
{
    int i,j;
    for(i=1;i+len-1<=n;i++)
      for(j=1;j+len-1<=m;j++)// Ã¶¾ÙÃ¿¸ö¾ØÐÎ
        if(checkzero(i,j,len)) return true;

    return false;
}

int main()
{
    int i,j,nowsum0,l,r,mid,nowi,nowj;
    long long nowsum;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)
      for(j=1;j<=m;j++)
        scanf("%d",&a[i][j]);/// ¶ÁÈë

    for(i=1;i<=n;i++)
    {
        nowsum=0LL;
        nowsum0=0;
        for(j=1;j<=m;j++)
        {
            nowsum += a[i][j];
            nowsum0 += (a[i][j]==0);
            sum[i][j]=sum[i-1][j]+nowsum;
            sum0[i][j]=sum0[i-1][j]+nowsum0; // ÇÉÃî
        //cout << i << ' ' << j << ' ' << sum0[i][j] << endl;
        }
    }
    // nowsum:µ±Ç°ÁÐµÄÇ°×ººÍ
    // sum[i][j]:¾ØÕói jµÄÇ°×ººÍ
    // nowsum: µ±Ç°ÁÐµÄÇ°×ººÍÓÐÎª0µÄ´æÔÚ
    // sum0[i][j] ¾ØÕói jµÄ 0µÄÇ°×ººÍ
    /*
    0 0 0 1 1 1 1
    0 0 0 2 2 2 2
    0 0 0 3 3 3 3*/

    l=1;// ans¾ØÕóµÄ±ß³¤µÄ×îÐ¡Öµ
    r=n<m?n:m; // ans¾ØÕóµÄ±ß³¤µÄ×î´óÖµ
    while(l<=r) // ¶þ·ÖÇóµÃ±ß³¤
    {
        mid=(l+r)>>1;
        if(check(mid))
        {
           ans1=mid;
           l=mid+1;
        }
        else r=mid-1;
    }

    printf("%d ",ans1*ans1);// ±ß³¤³ËÒÔ±ß³¤: ÇóµÃÂú×ãÌõ¼þµÄÃæ»ý

    for(i=1;i+ans1-1<=n;i++)
      for(j=1;j+ans1-1<=m;j++)
        if(checkzero(i,j,ans1)) // ÔÙ´ÎÃ¶¾ÙÊÇ·ñ¾ØÕó°üº¬0
        {
            nowi=i+ans1-1;
            nowj=j+ans1-1;
            ans2=min(ans2,sum[nowi][nowj]-sum[i-1][nowj]
                     -sum[nowi][j-1]+sum[i-1][j-1]);
        }
    printf("%lld",ans2);
    return 0;
}
