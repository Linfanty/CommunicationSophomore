#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int N = 1e5+20;
const double eps = 1e-8;
 
int main()
{
    int n;
    cin >> n;
    while(n--) {
        double a, b;
        scanf("%lf%lf", &a, &b);
        if(a <= b)
            printf("0.000000\n");
        else printf("%.6lf\n", log(a/b) + 1);
    }
}
/*样例答案减去1后，1.386294是0.689147的两倍，
2.079442是它的三倍，然后猜出和2的对数有关，而且还是以e为底的*/