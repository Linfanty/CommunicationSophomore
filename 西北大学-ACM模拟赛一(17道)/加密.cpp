#include <iostream>
#include <string>
#include <vector>
using namespace std;
/// maxn 1000005
/// abcdeedfggfhhcbz
vector <char> ve;
vector<char>:: iterator it;

int main()
{
    string s;
    cin >> s;
    int len = s.size();

    for(int i = 0; i < len ; i++)
        ve.push_back(s[i]);
    for(int i = 0; i < len-1 ; i++)
    {
        //or(it = ve.begin(); it!= ve.end(); it++)
        //    cout << (*it) ;
        //cout <<endl;
        if( ve[i] == ve[i+1] )
        {
            ve.erase(ve.begin()+i);
            ve.erase(ve.begin()+i);
            i = i-2;
            len = len - 2;
        }
    }
    for(it = ve.begin(); it!= ve.end(); it++)
        cout << (*it) ;
}
