#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;
const int maxn = 1005;
/**
题目大意：给定区间l，r，找到一个数x，保证x在区间上，
并且要求x的bitcount尽量大的前提下数值尽量小。

解题思路：默认x为全1的二进制数，每次从最高为判断，

首先我们把L和R拆成二进制数，然后个位对齐，形如下面这样：

R:1100101000011111
L:0000101100000001
假设L和R的二进制里前缀[1,t]这部分是相同的，
那么答案数字x在[1,t]这部分必须和L和R相同。

若之后R全部是1，那么x就可以在之后全部取1，
否则x在第t+1位取0，t+2之后全部取1
这个贪心的正确性应该是非常显然的吧

*/
ll l, r;

ll t10to2(ll x) // transform 10 to 2
{
	ll mid = x%2;
	if(x >= 2)	t10to2(x>>1);
	cout << mid;
}

int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		cin >> l >> r;
		ll ans = (1ll<<62) - 1;
		// t10to2(ans), cout << endl;
		// t10to2(l), cout << endl;
		// t10to2(r), cout << endl;
		ll midr = r;

        for(int i = 61; i >= 0; i--)
        {
            midr =  ( midr & (~(1ll<<i) ));
            //t10to2(ans), cout << endl, t10to2( ans & (~(1ll<<i) )), cout << endl << endl;
            if( (l&(1ll<<i))  && (r&(1ll<<i)) )
                continue;
            else if( !(l&(1ll<<i))  && (r&(1ll<<i)) )  {
                if( midr == ((1ll<<i)-1) )
                    break;
                ans = ( ans & (~(1ll<<i) ));
                break;
            }
            else ans = ( ans & (~(1ll<<i) ));

        }
		cout << ans << endl;
	}
}
/*
1 10
11111111111111111111111111111111111111111111111111111111111111
0001
1010

0111

01
11
*/
