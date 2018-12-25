#include <cstdio>
#include <cstring>
using namespace std;

const int N = 61;
struct Matrix {
  int n, A[N][N];
  Matrix(int sz) {
    n = sz;
    memset(A, 0, sizeof(A));
  }
  void init() {
    memset(A, 0, sizeof(A));
    for(int i = 0; i < n; i++) {
      A[i][i] = 1;
    }
  }
};
Matrix mul(Matrix a, Matrix b, int m) {
  Matrix tmp(a.n);
  int n = tmp.n;
  for(int i = 0; i < n; i++)
    for(int k = 0; k < n; k++)
      for(int j = 0; j < n; j++)
        (tmp.A[i][j] += (a.A[i][k] * b.A[k][j]) % m) %= m;
  return tmp;
}
Matrix pow_mod(Matrix a, int n, int m) {
  Matrix res(a.n);
  res.init();
  while(n) {
    if(n & 1) res = mul(res, a, m);
    a = mul(a, a, m), n >>= 1;
  }
  return res;
}
int main() {
  int n, k, m;
  scanf("%d %d %d", &n, &k, &m);
  Matrix a(n << 1);
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      scanf("%d", &a.A[i][j]);
    }
  }
  for(int i = n; i < (n << 1); i++) {
  	for(int j = 0; j < (n << 1); j++) {
  		if(i - n == j || i == j) {
  			a.A[i][j] = 1;
  		}
  	}
  }
  Matrix ans = pow_mod(a, k + 1, m);
  for(int i = n; i < (n << 1); i++) {
    for(int j = 0; j < n; j++) {
      printf("%d%c", i - n == j ? (ans.A[i][j] + m - 1) % m : ans.A[i][j], " \n"[j == n - 1]);
    }
  }
  return 0;
}
