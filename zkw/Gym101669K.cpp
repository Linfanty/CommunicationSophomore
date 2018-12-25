#include <bits/stdc++.h>
// 考虑 Ai=1 的，显然我们会顺着放 N,N−1,N−2,⋯ 然后开始放 Ai=2 的。排序即可
/* 思路：可想而知，从左往右扫，a[i]=1的可以考虑到是从这一位至末尾最大的数，
所以n一定是在第一个a[i]=1的位置，所以从左往右扫a[i]=1,a[i]=2
依次铺放n，n-1，…，1。考虑到复杂度的原因，可以用一个set来维护一下即可。
*/

using namespace std;

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  int n;
  scanf("%d", &n);
  vector<pair<int, int> > a(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i].first);
    a[i].second = i;
  }

  sort(a.begin(), a.end(), greater<pair<int, int> > ());
  vector<int> answer(n);

  for (int i = 0; i < n; ++i) {
    answer[a[i].second] = i;
  }
  for (int i = 0; i < n; ++i) {
    printf("%d%c", answer[i] + 1, i == n - 1 ? '\n' : ' ');
  }
  return 0;
}