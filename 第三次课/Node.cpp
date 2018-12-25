#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long int ll;
const int maxn = 105;

struct Node
{
    string s;
    int num;
    bool operator < (const Node &x)
    {
        return s < x.s;
    }
}student[105];


bool cmp(Node x, Node y)
{
    if( x. num != y.num )
    return x.num < y.num;
    else return x.num < y.num;
}

int main()
{
    for(int i = 1; i <= 3; i++)
    {
        cin >> student[i].s >> student[i].num;
    }
    sort(student + 1, student + 4,cmp);

    for(int i = 1; i <= 3; i++)
    {
        cout << student[i].s << ' ' <<  student[i].num << endl;
    }
}


