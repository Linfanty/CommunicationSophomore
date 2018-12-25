#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod;

struct Matrix {
    ll m[10][10];
};

Matrix Mul(Matrix a, Matrix b) {
    Matrix c;
    memset(c.m, 0, sizeof c.m);

    for(int i = 0; i < 10; i++)
        for(int j = 0; j < 10 ; j++)
            for(int k = 0; k < 10; k++)
                c.m[i][j] = ((a.m[i][k] * b.m[k][j]) % mod + c.m[i][j] ) % mod;
    return c;
}

Matrix fastm(Matrix a, int k) {
    Matrix ans;
    Matrix res = a;
    memset(ans.m, 0, sizeof ans.m);

    for(int i = 0; i < 10; i++)
        ans.m[i][i] = 1;
    while(k) {
        if(k&1) ans = Mul(ans, res);
        k >>= 1;
        res = Mul(res, res);
    }
    return ans;
}



int main() {
    ll k, m;
    Matrix init; // 不变
    for(int i = 0; i < 10; i++) {
        init.m[i][0] = 9 - i;
        for(int j = 1; j < 10;j++)
            init.m[i][j] = 0;
    }

    while( cin >> k >> mod ) {
        Matrix a;
        memset(a.m, 0, sizeof a.m);

        for(int i = 0; i < 10; i++) {
            cin >> a.m[0][i]; // a1 a2 a3 a4 a5 a6 a7 a8 a9
            if( i ) a.m[i][i] = 0; // 11 22 33 44 55 66 77 88 99
            if( i < 9) a.m[i+1][i] = 1; /// 10 21 32 43 54 65 76 87 98 9行
        }

        if( k < 10) {cout << k % mod << endl; continue; }

        Matrix ans = fastm(a, k - 9);


        ans = Mul(ans, init);
        cout << ans.m[0][0] % mod  << endl;

    }
}