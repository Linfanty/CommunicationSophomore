#include <bits/stdc++.h>
using namespace std;
 ///  ([])
stack<int> st;
int main()
{
    int n;
    cin >> n;
    getchar();
    string s;

    while( n-- )
    {
        int flag = 0;
        while(!st.empty())
            st.pop();
        getline(cin,s);
        if( s.size() == 0)
        {
            cout << "Yes" << endl;
            continue;
        }
        if( s.size()&1 )
        {
            cout << "No" << endl;
            continue;
        }

        for(int i = 0; i < s.size(); i++)
        {
            if( s[i] == '(' )
                st.push(1);
            else if( s[i] == '[')
                st.push(2);
            else if( s[i] == ')')
            {
                if(st.empty())
                {
                    flag = 1;
                    break;
                }
                if(st.top() == 1)
                    st.pop();
                else
                {
                   flag = 1;// cout << "No" << endl;
                   break;
                }
            }
            else if( s[i] == ']')
            {
                if(st.empty())
                {
                    flag = 1;
                    break;
                }
                if( st.top() == 2)
                    st.pop();
                else
                {
                   flag = 1;// cout << "No" << endl;
                   break;
                }
            }
        }
        if( st.size() != 0)
            flag = 1;// cout << "No" << endl;

        if(flag)
            cout << "No" << endl;
        else cout << "Yes" << endl;

    }
}
/// [([)]]
