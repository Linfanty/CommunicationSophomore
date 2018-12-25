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

char a[3][1000005];
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

    string s;
    cin >> s;
    int len = s.size();
    int j = 0;
    

    for(int i = 0; i < len; i++) {
        if( s[i] == '0' )
            a[0][j] = '.', a[0][j+1] = '_', a[0][j+2] = '.',
            a[1][j] = '|', a[1][j+1] = '.', a[1][j+2] = '|',
            a[2][j] = '|', a[2][j+1] = '_', a[2][j+2] = '|';
        else if (s[i] == '1')
            a[0][j] = '.', a[0][j+1] = '.', a[0][j+2] = '.',
            a[1][j] = '.', a[1][j+1] = '.', a[1][j+2] = '|',
            a[2][j] = '.', a[2][j+1] = '.', a[2][j+2] = '|';        
        else if (s[i] == '2')
            a[0][j] = '.', a[0][j+1] = '_', a[0][j+2] = '.',
            a[1][j] = '.', a[1][j+1] = '_', a[1][j+2] = '|',
            a[2][j] = '|', a[2][j+1] = '_', a[2][j+2] = '.';   
        else if (s[i] == '3')
            a[0][j] = '.', a[0][j+1] = '_', a[0][j+2] = '.',
            a[1][j] = '.', a[1][j+1] = '_', a[1][j+2] = '|',
            a[2][j] = '.', a[2][j+1] = '_', a[2][j+2] = '|'; 
        else if (s[i] == '4')
            a[0][j] = '.', a[0][j+1] = '.', a[0][j+2] = '.',
            a[1][j] = '|', a[1][j+1] = '_', a[1][j+2] = '|',
            a[2][j] = '.', a[2][j+1] = '.', a[2][j+2] = '|'; 
        else if (s[i] == '5')
            a[0][j] = '.', a[0][j+1] = '_', a[0][j+2] = '.',
            a[1][j] = '|', a[1][j+1] = '_', a[1][j+2] = '.',
            a[2][j] = '.', a[2][j+1] = '_', a[2][j+2] = '|'; 
        else if (s[i] == '6')
            a[0][j] = '.', a[0][j+1] = '_', a[0][j+2] = '.',
            a[1][j] = '|', a[1][j+1] = '_', a[1][j+2] = '.',
            a[2][j] = '|', a[2][j+1] = '_', a[2][j+2] = '|'; 
        else if (s[i] == '7')
            a[0][j] = '.', a[0][j+1] = '_', a[0][j+2] = '.',
            a[1][j] = '.', a[1][j+1] = '.', a[1][j+2] = '|',
            a[2][j] = '.', a[2][j+1] = '.', a[2][j+2] = '|'; 
        else if (s[i] == '8')
            a[0][j] = '.', a[0][j+1] = '_', a[0][j+2] = '.',
            a[1][j] = '|', a[1][j+1] = '_', a[1][j+2] = '|',
            a[2][j] = '|', a[2][j+1] = '_', a[2][j+2] = '|'; 
        else if (s[i] == '9')
            a[0][j] = '.', a[0][j+1] = '_', a[0][j+2] = '.',
            a[1][j] = '|', a[1][j+1] = '_', a[1][j+2] = '|',
            a[2][j] = '.', a[2][j+1] = '.', a[2][j+2] = '|'; 
        if( i != len - 1)
            a[0][j+3] = ' ', a[1][j+3] = ' ', a[2][j+3] = ' ';
        // cout << i << ' ' << j << ' ' << s[i] << ' ' <<  a[0][1] << endl;
        j = j + 4;
    }


    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 4 * len - 1; j++) 
        cout << a[i][j];
    cout << endl;
    }
    
}
