#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	string s;
	cin >> s;
	int len = s.size();
	int ans = 0;
	char mid = 'a';

	for(int i = 0; i < len; i++) {
		int minn = min(mid, s[i]); //找出字母的大小序号   
		int maxx = max(mid, s[i]);  
		ans += min(minn - maxx + 26, maxx - minn);
		mid = s[i];
	}
	cout << ans << endl;
}