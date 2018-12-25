#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod = 1e9 + 7;

int main() {
    int t;
    scanf("%d", &t);
    while( t-- ) {
        int n;
        scanf("%d", &n);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(i == 0)
                    printf("%d", j);
                else {
                    if( j == 0) printf("%d", i);
                    else printf("0");
                }
                if( j != n - 1)  printf(" ");
            }
            printf("\n");
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if( i == 0)
                    printf("0");
                else {
                    if( j == 0) printf("0");
                    else  printf("%d",(j + 1 <= n? (j + i - 1): (j + i - n) ));
                }
                if( j != n - 1) printf(" ");
            }
            printf("\n");
        }
    }
}
