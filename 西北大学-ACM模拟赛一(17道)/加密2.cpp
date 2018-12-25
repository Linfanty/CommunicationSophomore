#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;
/// maxn 1000005
/// abcdeedfggfhhcbz

stack<char> st;
vector <char> ans;
vector<char>:: iterator it;

int main()
{
    string s;
    cin >> s;
    int len = s.size();

    for(int i = 0; i < len; i++)
    {
        if( !st.empty() && st.top() != s[i] )
            st.push(s[i]);
        else if( !st.empty() && st.top() == s[i] )
            st.pop();
        else st.push(s[i]);
    }

    while( !st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }

    for(it = ans.end()-1; it!= ans.begin()-1; it--)
        cout << (*it) ;
}
