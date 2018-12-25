#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

set<ll> st;
int cnt = 0;
int main()
{
    long long int i = 2;
    st.insert(1);
    st.insert(2);
    set<ll> :: iterator it;
    for(it = st.begin(); it != st.end(); it++)
    {
        cnt++;
        st.insert( (*it)*2 );
        st.insert( (*it)*3 );
        st.insert( (*it)*5 );
        if( cnt == 1500 ) break;
    }
    cout << "The 1500'th ugly number is " << *it<<"." << endl;
}
