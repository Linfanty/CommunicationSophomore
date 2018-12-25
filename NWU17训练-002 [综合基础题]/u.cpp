#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// 统计t1到t2通过了几个指针
// 0 || 3 YES

int main()
{
    int clock[105] = {0}, cnt = 0;
    int n, m, s;
    int t1, t2;
    cin >> n >> m >> s >> t1 >> t2;
    n *= 5, t1 *= 5, t2 *= 5;
    n %= 60, t1 %= 60, t2 %= 60;

    clock[n]++, clock[m]++, clock[s]++;
    if(t1>t2) swap(t1,t2);

    for(int i = t1; i < t2; i++)
        cnt += clock[i];

    if(cnt%3)   puts("NO");
    else puts("YES");
}
