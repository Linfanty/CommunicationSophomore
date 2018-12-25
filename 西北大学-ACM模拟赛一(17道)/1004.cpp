#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
#define IO ios_base::sync_with_stdio(0),cin.tie(0)
ll a[100005], b[100005];

int main()
{IO;
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i], b[i] = a[i];

    sort(b+1, b+1+n);

    ll cnt = 0;
    for(int i = 1; i <= n; i++)
    {
        if( a[i] == b[i] )
            continue;
        if( a[i] != b[i] && a[n-i+1] == b[i] && a[i] == b[n-i+1])
        {
            swap(a[i], a[n-i+1]);
            cnt++;
        }
        else
        {
            for(int j = i+1; j <= n; j++)
            {
                if( a[j] == b[i] )
                {
                    swap(a[i], a[j]);
                    cnt++;
                    break;
                }
            }
        }
    }
    cout << cnt << endl;
}
