/*
样例输入
2 1 1
1
8 3 5
1 3 4
4 5 1
5 4 3 2 1
样例输出
1 0
0 1
0 3
题意：
给你m条鱼，有n只猫，每只猫吃鱼的速度不同，问x秒后有多少鱼是没被吃的，有多少是没吃完的，吃的快的优先吃鱼
思路：
因为是吃的快的优先吃鱼，那么先将吃鱼的时间从大到小排个序，优先判断吃的快的，猫的速度为ai
那么只有当时间是ai的倍数的时候他才能完整的吃掉一条鱼，这时候我们可以用一个数组b来记录他的状态，
这样最后可以通过直接便利b数组来求出有多少鱼没有被完整吃完，当时间i%ai=0的时候代表已经吃完一条鱼，
此时将状态标记一下bi=0，此时代表他已经吃完了一条鱼（记录下一共吃完了多少鱼num++），现在就要再给他一条鱼，
所以鱼的剩余数量cnt--，当没有鱼的时候就可以退出了。
此时求出了一共吃完了多少鱼num,有多少鱼还没吃完（遍历b数组可得），用鱼的总数减去完全吃掉的减去没吃完的，
就得到了还没吃的鱼的数量。
*/
#include<bits/stdc++.h>
using namespace std;
const int M = 100050;
#define ll long long

int main()
{
    int n,m,x,i,j,a[1009],b[1009];
    while(cin>>n>>m>>x)
    {
        memset(b,0,sizeof(b));
        for(i=1;i<=m;i++)   cin>>a[i];
        sort(a+1,a+1+m);

        int cnt = n;
        int num = 0;

        for(i=1;i<=x;i++)
        {
            for(j=1;j<=m;j++)
            {
                if(b[j]==0) cnt--;
                if(i%a[j]==0){
                    b[j]=0;num++;
                }
                else b[j]=1;
                if(cnt==0) break;
            }
            if(cnt==0) break;
        }

        int ans=0;
        for(i=1;i<=m;i++)
            if(b[i]==1)
                ans++;
        cout    <<n-num-ans<<" "<<ans<<endl;
    }

}
