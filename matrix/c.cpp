#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod = 9973;
ll n, k, m;

struct Matrix {
    ll m[10][10];
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

Matrix fastm(Matrix a, int k) {
    Matrix ans;
    Matrix res = a;
    memset(ans.m, 0, sizeof ans.m);

    for(int i = 0; i < n; i++)
        ans.m[i][i] = 1;
    while(k) {
        if(k&1) ans = Mul(ans, res);
        k >>= 1;
        res = Mul(res, res);
    }
    return ans;
}



int main() {

    int t;
    cin >> t;

    while( t-- ) {
        cin >> n >> m;

        int tmp;
        Matrix a; // 不变
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n;j++) {
                cin >> tmp;
                a.m[i][j] = tmp;
            }
        }


        Matrix ans = fastm(a,  m);
        ll anss = 0;

        for(int i = 0; i < n; i++) {
            anss = ( ans.m[i][i] + anss )  % mod;
        }

        cout << anss  << endl;

    }
}