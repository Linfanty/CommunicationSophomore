#include <stdio.h>
#define ll long long
#define maxn 20000001
ll v[maxn];
ll ans[maxn];

int main()
{
    int i, j, n;
    for(i = 2; i < maxn; i++)
    {
        for(j = i; j < maxn; j+=i)
            v[j] += i;
        ans[i] = ans[i-1] + v[i] + 1;
    }
    while(scanf("%d", &n) && n)
        printf("%lld\n", ans[n]);
}
