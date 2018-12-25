
#include <bits/stdc++.h>
#include <set>
using namespace std;

set<int> st;


int main()
{
    int n;
    cin >> n;

    int flag = 0, a, b = 0, b1, b2, cnt1=0, cnt2=0;
    bool f = true;
    for(int i = 1; i <= n; i++)
    {
        cin >> a;
        st.insert(a);
        if( st.size() > 2)
        {
            flag = 1;
            continue;
        }
        if( f )
            b1 = a, f = false;
        if( a != b1)
            b2 = a;

        if( a == b1)
            cnt1++;
        else if( a == b2)
            cnt2++;

    }
    if( flag == 1 || st.size() < 2 || cnt1 != cnt2)
        cout << "NO" << endl;
    else cout << "YES" << endl << b1 << ' '
        << b2 << endl;
}
