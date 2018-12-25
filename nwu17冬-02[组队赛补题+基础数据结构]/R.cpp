#include <set>
#include <cstdio>
#include <iostream>
using namespace std;

set<int> st;
set<int> :: iterator it;
int main()
{
    int n, m, a;
    while( cin >> n >> m)
    {
        st.clear();
        while(n--)
        {
            cin >> a;
            st.insert(a);
        }
        while(m--)
        {
            cin >> a;
            st.insert(a);
        }
        it = st.begin();
        cout << *it;
        for(it++; it != st.end(); it++)
            cout << ' ' << *it;
            cout << endl;
    }
}
