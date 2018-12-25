#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
typedef long long ll;
ll mod = 10000;
ll n = 2, k, m;

struct Matrix {
    ll m[2][2];
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

    while( cin >> k ) {
    	if( k == -1 ) break;
    	if( k == 0 ) {cout << 0 << endl; continue;}
        Matrix a; // 不变
        a.m[0][0] = 1;
        a.m[0][1] = 1;
        a.m[1][0] = 1;
		a.m[1][1] = 0;        

        Matrix ans = fastm(a, k-1);
       
        cout << ans.m[0][0]  << endl;
    }
}