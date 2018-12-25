    #include <iostream>
    #include<deque>
    #include<algorithm>
    #include<cstdio>
    #include<stack>
    #include<string>
    using namespace std;
    char f(char c)
    {
        if(c==')')return '(';
        if(c==']')return '[';
        return 0;
    }
    bool judge(const string& s)
    {
        stack<char>st;
        st.push('0');
        for(int i=0;i<s.size();i++)
        {
            if(st.top()!=f(s[i]))
            st.push(s[i]);
            else st.pop();
        }
        return st.size()==1;
    }


    int main()
    {
        int n;
        cin>>n;
        string s;
        getchar();
        while(n--)
        {
            getline(cin,s);
            if(s.size()==0||judge(s))cout<<"Yes"<<endl;
            else cout<<"No"<<endl;
        }
        return 0;
    }
