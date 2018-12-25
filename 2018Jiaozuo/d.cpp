#include <bits/stdc++.h>
using namespace std;

const double PI = acos(-1.0);

int main() {
    int t; cin >> t;
    while(t--) {
        double a, b, r, d;
        cin >> a >> b >> r >> d;
        d = d / 180.0 * PI;
        double d2 = atan(b / (a + r));
        double R = sqrt((a + r) * (a + r) + b * b);

        if(d >= d2) {
            printf("%.12lf\n", R - r);
        }
        else {
            printf("%.12lf\n", R * cos(d2 - d) - r);
        }
    }
}
