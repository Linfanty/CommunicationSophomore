#include <bits/stdc++.h>
using namespace std;
list<char> de;
char s[100005];
void output()
{
    list<char> ::iterator it;
    for(it = de.begin(); it != de.end(); it++)
        cout << *it;
    cout<<endl;
}

int main()
{
    while( scanf("%s", &s) != EOF) {
        de.clear();
        int len = strlen(s);
        int flag = 1;
        int q = 0;

        for(int i = 0; i < len; i++)
        {
            if(s[i] == '[')
            {
                flag = 1;
                q = 0;
                continue;
            }
            else if(s[i] == ']')
            {
                flag = 2;
                continue;
            }

            else
            {
                if( flag == 1)
                {
                    list<char> ::iterator it2;
                    it2 = de.begin();
                    for(int j = 1; j <= q; j++)
                        it2++;
                    de.insert(it2,s[i]);
                    q++;
                }
                else
                {
                    list<char> ::iterator it2 = de.end();
                    de.insert(it2,s[i]);
                }
            }
            //output();
        }
        output();
    }
}
