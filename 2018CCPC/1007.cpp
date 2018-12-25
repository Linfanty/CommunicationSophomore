#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;
int arr[10010];

int main () {
    int T;
    scanf("%d", &T);
    for (int i = 1; i <= T; i++) {
        int n, s, m, k;
        scanf("%d%d%d%d", &n, &s, &m, &k);
        for (int i = 0; i < n; i++)
            scanf("%d", &arr[i]);
        int gg = __gcd(n, k);
        int lun = n / gg;
        int sheng = m % lun;
        int ci = m / lun;
        long long ans = 0;
        for (int i = 0; i < gg; i++) {
            long long s = 0;
            for (int j = i, dd = 0; dd < lun; j += k, j %= n, dd++)
                s += arr[j];
            long long sum = 0;
            int j = i;
            for (int dd = 0; dd < sheng; j += k, j %= n, dd++)
                sum += arr[j];
            int jj = i;
            for (int dd = 0; dd < lun - sheng; dd++) {
                ans = max(ans, s * ci + sum);
                sum += arr[j], sum -= arr[jj];
                j += k, j %= n, jj += k, jj %= n;
            }
            ans = max(ans, s * ci + sum);
        }
        cout << "Case #" << T << ": " << s - ans << endl;
    }
}
