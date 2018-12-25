#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int mod = 1e9 + 7;

struct Matrix {
    ll mp[5][5];
    int n, m;

    Matrix(int _n, int _m) {
        n = _n, m = _m;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                mp[i][j] = 0;
    }

    Matrix operator+ (const Matrix &b) const {
        Matrix tmp(n, m);
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                tmp.mp[i][j] = mp[i][j] + b.mp[i][j],
                tmp.mp[i][j] %= mod;
        return tmp;
    }

    Matrix operator* (const Matrix &b) const {
        Matrix ret(n, b.m);
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                for(int k = 0; k < m; k++)
                    ret.mp[i][j] += mp[i][k] * b.mp[k][j],
                    ret.mp[i][j] %= mod;
        return ret;
    }

    Matrix operator^ (ll k) const {
        Matrix ret(n, m), b(n, m);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++)
                b.mp[i][j] = mp[i][j];
            ret.mp[i][i] = 1;
        }

        while(k) {
            if(k&1) ret = ret * b;
            b = b * b;
            k >>= 1;
        }
        return ret;
    }

};

int t, a, b, c, d, p, n;

int main() {
    cin >> t;
    while(t--) {
        cin >> a >> b >> c >> d >> p >> n;
        if( n == 1) cout << a << endl;
        else if( n == 2) cout << b << endl;
        else {
            Matrix yy(3, 1);
            yy.mp[0][0] = b;
            yy.mp[1][0] = a;
            yy.mp[2][0] = 1;

            int now = 3;
            Matrix zz(3, 3);
            zz.mp[0][0] = d;
            zz.mp[0][1] = c;
            zz.mp[1][0] = 1;
            zz.mp[2][2] = 1;


            while( now <= n ) {
                int tmp = p/now; //  p/now
                zz.mp[0][2] = tmp;

                if( tmp == 0) {
                    yy = ( zz ^ (n-now+1) ) * yy;
                    break;
                }

                                      // p/(p/mow) 取整
                int x = p/tmp;        // x 计算的是 下一次要到哪一块 p/tmp
                 cout << now << ' ' << tmp << ' ' << x << " 块: " << x-now+1 << endl;
                if( x > n) x = n;
                yy = ( zz ^ (x-now+1) ) * yy;
                now = x + 1;         // 下一次的 now = x + 1
            }
            cout << yy.mp[0][0] << endl;
        }

    }

}


