#define IO std::ios::sync_with_stdio(false);std::cin.tie(0);
#define show(a) cout << #a << " = " << a << endl;
#include<bits/stdc++.h>

using namespace std;

int main () {
    int T; cin >> T;

    for (int i = 1; i <= T; i++) {
        int n; cin >> n;
        bool flag = 1;
        while (n--) {
            int ww; cin >> ww;
            if (ww % 3 != 0) flag = 0;
        }

        cout << "Case #" << i << ": " << (flag ? "Yes" : "No") << endl;
    }
}