#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
//#define IO ios_base::sync_with_stdio(0),cin.tie(0)
const int maxn = 10005;
vector<int> ans[maxn];
int q[maxn];string s;

int output(int p)
{
    if( ans[p].size() == 0)
        cout << s[p];
    else
    {
        cout << 'x';
        for(int i = 0; i < 4; i++)
        {
            int v = (i+2)%4;
            // cout << p << ' ' << v << ' ' << ans[p][v] << endl;
            /// ��� ��p��ĵ�v�� (0<=v<4)
            output( ans[p][v] );
            // ans[p][2] ans[p][3] ans[p][0] ans[p][1]
        }
    }
}

int main()
{
    int t;cin >> t;
    while( t-- )
    {
        cin >> s; int len = s.size();
        for(int i = 0; i < maxn; i++) ans[i].clear();
        int top = 0;/// top :���� �ݹ�ĵڼ��� ���� ���
        /// q����: q[top] = i ���ظ��Ĳ��� �ӵ�i����ʼ�зֲ�

        for(int i = 0; i < len; i++)
        {
            int _top = top-1;

            if( top && ans[ q[_top] ].size() == 4)
            // ���ջ����Ԫ��(�Ѿ��ڵݹ��� �����Ԫ��)&&�Ѿ������ĸ�(�Ѿ�����)
                top--, _top--;/// ��ջ �˳���ǰ�ĵݹ����

            if( s[i] == 'x') // ��ʱ��������Ķ��ĸ���
            {
                if(top)  // ���ջ����Ԫ��
                    ans[q[_top]].push_back(i);// ����q[_top]�����ĸ�

                q[top] = i;// ��� �ӵ�i����ʼ�зֲ� �ڵ�top�����i
                top++; // �ݹ�Ĳ�����1
            }
            else if(top) // ���ջ����Ԫ�� ���ڵݹ���
                ans[q[_top]].push_back(i); // ����i��Ԫ�ؼ���ans��q[_top]����

            //cout << _top << ' ' << q[_top] <<' ' <<  i << endl;
        }
        output(0);
        cout << endl;
    }
}
0 2 15
15 2 26
15 3 27
15 0 16
16 2 23
16 3 24
16 0 17
17 2 20
17 3 21
17 0 18
17 1 19
16 1 22
15 1 25
0 3 28
0 0 1
1 2 4
1 3 5
1 0 2
1 1 3
0 1 6
6 2 13
6 3 14
6 0 7
6 1 8
8 2 11
8 3 12
8 0 9
8 1 10
