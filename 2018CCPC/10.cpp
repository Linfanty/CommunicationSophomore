#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;
const int MAXN = 1e5 + 10;
int n, N;
struct Node {
    int x, y, c;
}ww[MAXN];
int best[MAXN << 2];

void Build () {
    memset(best, 0, sizeof best);
    N = 1;
    while (N < n + 2) N <<= 1;
}
void Update (int id, int data) {
    best[N + id] = data;
    for (int i = N + id; i ^ 1; i >>= 1) {
        best[i >> 1] = max(best[i], best[i ^ 1]);
    }
}

int Query (int L, int R) {
    int ret = 0;
    for (L += N - 1, R += N + 1; L ^ R ^ 1; L >>= 1, R >>= 1) {
        if (L % 2 == 0) ret = max(ret, best[L ^ 1]);
        if (R % 2 == 1) ret = max(ret, best[R ^ 1]);
    }
    return ret;
}

int main () {
    int T;
    scanf("%d", &T);
    while (T--) {
        memset(ww, 0, sizeof ww);
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d%d%d", &ww[i].x, &ww[i].y, &ww[i].c);
        }
        sort(ww, ww + n, [](Node a, Node b) -> bool {
                if (a.y < b.y) return 1;
                else if (a.y == b.y and a.x < b.x) return 1;
                else return 0;
            });
        int now = -1, id = 0;
        for (int i = 0; i < n; i++) {
            if (now != ww[i].y) now = ww[i].y, ww[i].y = ++id;
            else ww[i].y = id;
        }
        Build();
        sort(ww, ww + n, [](Node a, Node b) -> bool {
                if (a.x < b.x) return 1;
                else if (a.x == b.x and a.y > b.y) return 1;
                else return 0;
            });
        int ans = 0;
        for (int i = 0; i < n; i++) {
            /*for (int j = 0; j < 30; j++) cout << best[j] << " ";
        cout << endl;*/
            int y = ww[i].y, c = ww[i].c;
            int qaq = Query(1, y) + c;
            if (qaq > Query(y + 1, y + 1)) Update(y + 1, qaq), ans = max(ans, qaq);
        }
        printf("%d\n", ans);
    }
}
