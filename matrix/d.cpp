#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
typedef long long ll;
ll n, k, mod;

struct Matrix {
    ll m[61][61];
};

Matrix Mul(Matrix a, Matrix b) {
    Matrix c;
    memset(c.m, 0, sizeof c.m);

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n ; j++)
            for(int k = 0; k < n; k++)
                c.m[i][j] = ((a.m[i][k] * b.m[k][j]) % mod + c.m[i][j] ) % mod;
    return c;
}

void debug(Matrix a) {
    for(int i = 0; i < n; i++ ) {
        for(int j = 0; j < n; j++) {
            cout << a.m[i][j] << ' ';
        }
        cout << endl;
    }cout << endl;
}

Matrix fastm(Matrix a, ll k) {
    Matrix ans;
    Matrix res = a;
    memset(ans.m, 0, sizeof ans.m);

    for(int i = 0; i < n; i++)
        ans.m[i][i] = 1;

    // debug(a); debug(ans);
    while(k) {
        if(k&1) ans = Mul(ans, res);
        k >>= 1;
        res = Mul(res, res);
        
    }
    
    return ans;
}



int main() {

        cin >> n >> k >> mod;

        ll tmp;
        Matrix a; // 不变
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n;j++) {
                cin >> tmp;
                a.m[i][j] = tmp;
            }
            a.m[i][i+n] = a.m[i+n][i+n] = 1;
        }

        ll m = n;
        n = n << 1;

        Matrix ans = fastm(a,  k + 1);
        // debug(ans);
        ll anss = 0;

        int j;
        for(int i = 0; i < m; i++) {
            for(j = m; j < n - 1; j++) 
                if( i + m == j)
                    printf("%lld ", (ans.m[i][j] + mod - 1) % mod);
                else printf("%lld ", (ans.m[i][j] + mod) % mod);
            if( i + m == j)
                 printf("%lld\n", (ans.m[i][n-1] + mod - 1) % mod);
            else printf("%lld\n", (ans.m[i][n-1] + mod) % mod);
        }

}
/*
3 7848554 1000
52 65 87
40 56 541
5468 45 784
636 625 223 353 320 224
656 116 417 756 670 225
652 705 524 316 365 2
0 0 0 1 0 0
0 0 0 0 1 0
0 0 0 0 0 1

352 320 224
756 669 225
316 365 1

2 998 889
1 2
3 4
4 35
497 501
*/