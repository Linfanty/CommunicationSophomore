#include <bits/stdc++.h>
#include <set>
using namespace std;
typedef long long ll;

ll pow1(ll a, ll b)
{
    ll ans = 1, base = a;
    while(b!= 0)
    {
        if(b&1!=0) ans *= base;
        base *= base;
        b >>= 1;
    }
    return ans;
}
// STL pow »áÕ¨
//ÖØµþ ¼õÈ¥ n * m
int main()
{
    int n, m;
    cin >> n >> m;
    int mp[55][55];

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            cin >> mp[i][j];

    int cnt0 = 0, cnt1 = 0;
    ll ans = (ll)-1*n*m;
    //cout << ans << endl;

    for(int i = 1; i <= n; i++)
    {
        cnt0 = 0, cnt1 = 0;
        for(int j = 1; j <= m; j++)
        {
            if(mp[i][j] == 0)
                cnt0++;
            else cnt1++;
        }
        ans += pow1(2,cnt0) - 1;
        ans += pow1(2,cnt1) - 1;
    }
    //cout << ans << endl;

    for(int i = 1; i <= m; i++)
    {
        cnt0 = 0, cnt1 = 0;
        for(int j = 1; j <= n; j++)
        {
            if(mp[j][i] == 0)
                cnt0++;
            else cnt1++;
        }
        ans += pow1(2,cnt0) - 1;
        ans += pow1(2,cnt1) - 1;
    }
    cout << ans << endl;

}
