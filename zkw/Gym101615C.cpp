#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf = 0x3f3f3f3f3f3f3f3f;
#define show(a) cout<<#a<<" = "<<a<<endl
#define show2(b,c) cout<<#b<<" = "<<b<<" "<<#c<<" = "<<c<<endl
#define show3(a,b,c) cout<<#a<<" = "<<a<<" "<<#b<<" = "<<b<<" "<<#c<<" = "<<c<<endl
#define show4(a,b,c,d) cout<<#a<<" = "<<a<<" "<<#b<<" = "<<b<<" "<<#c<<" = "<<c<<" "<<#d<<" = "<<d<<endl
const int maxn = 100005;
#define LOCAL

int main() {
    #ifdef LOCAL
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    // cin.tie(0);ios::sync_with_stdio(false);
    // priority_queue<ll,vector<ll>,greater<ll> > pq;//!empty() before pop()
    // vector<ll> vc; deque<ll> dq;
    // vector<ll>::iterator it = vc.begin();
    // map<ll, ll> mp; set<ll> st;// 去重
    // map<ll, ll>::reverse_iterator it; // rbegin rend it->first it-second
    //（n&(1<<i)) n=(n|(1<<i) n=(n&(~(1<<i)) (n&(-n))//判置10最后1 20(10100)得4(100)
    // ll Bs=0;ll t102(ll x){ll mid=x%2;if(x>=2)t102(x>>1);Bs=Bs*10 + mid;}ll Binary(ll x){t102(x);return Bs;}
    // string BinaryS(ll n) {string s="";for(ll a=n;a;a=a/2) s=s+(a%2?'1':'0');reverse(s.begin(),s.end());return s;}
    #endif
  

    ll a, b;
    cin >> a >> b;
    ll n = b - a + 1, ans = 0;

    for(ll i = 1; i * i <= b; i++) { // 1 - sqrt(b)
        ll k = a % i;  

        if( k != 0) k = i - k;

        while( a + k <= b) {
            ll z = ( a + k ) / i; // 另一位数
            
            show3(i, k, z);
            if( i < z) 
                ans += i + z;
            else if( i == z) ans += z;

            k += i; // 累加
        }
    }
    cout << ans << endl;
    
}
