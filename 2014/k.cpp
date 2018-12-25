#define IO std::ios::sync_with_stdio(false);
#define show(a) cout << #a << " = " << a << endl;
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const int MOD = 1000000007;

ll pow_mod(ll a, ll n) {
	ll res = 1;
	while(n) {
		if(n & 1) res = (res * a) % MOD;
		a = (a * a) % MOD, n >>= 1;
	}
	return res;
}
ll inv(ll a) {
	return pow_mod(a, MOD - 2); 
}
 
ll jie (ll n) {
	ll ret = 1;
	for (int i = 2; i <= n; i++)
		ret *= i, ret %= MOD;
	return ret;
}
const int N = 1e6 + 10;
ll aa[N];
ll c (ll a, ll b) {
	return (aa[a]) * inv(aa[b] * (aa[a - b]) % MOD) % MOD;
}
ll cc (ll a, ll b) {
	ll ret = 1;
	for (int i = a; i > (a - b); i--)
		ret *= i, ret %= MOD;
//	cout << ret << endl;
	ret *= inv(aa[b]);
	ret %= MOD;
//	cout << ret << endl;
	return ret;
	
}

int main(void) {
	IO;
	aa[0] = 1;
	for(int i = 1; i < N; i++) {
		aa[i] = aa[i - 1] * i % MOD;
		aa[i] %= MOD;
	}
	ll T; cin >> T;
	for (int t = 1; t <= T; t++) {
		ll n, m, k; cin >> n >> m >> k;
		
		if (k > n or (k == 1 and n != 1)) {
			cout << "Case #" << t << ": " << 0 << endl;
			continue;
		}
		else if (k == 1 and n == 1) {
			cout << "Case #" << t << ": " << m << endl;
			continue;
		}
		
		ll power = 1;
		if (n == k or k == 2) power = 1;
		else power = (n - 1) * (n - 2) / 2;
		if (power == 0) power = 1;
		
		//power * k! * c(m, k);
		//cout << power << " " << jie(k) % MOD << endl;
		
		ll ans = 0;
		for(int i = 1; i <= k; i++) {
			ll res = pow_mod(-1, k - i);
			res = (res + MOD) % MOD;
			res *= c(k, i) * i % MOD * pow_mod(i - 1, n - 1) % MOD;
			res %= MOD;
			ans += res;
			ans %= MOD;
		}
		cout << "Case #" << t << ": " << ans * cc(m, k) % MOD << endl;
	}
	
}
