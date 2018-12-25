#include <iostream>
using namespace std;

int main()
{
    int s[11] ={1,3,0,5,3,5,6,8,8,2,12};
    int f[11] ={4,5,6,7,8,9,10,11,12,13,14};

    bool flag[11] = {0};

    flag[0] = true;
    int j = 0;
    //for(int i=1;i<11;i++) 代码规范问题
    for(int i = 1; i < 11; ++i)
        if(s[i] >= f[j])
        {
            flag[i] = true;
            j = i;
        }

    for(int i = 0 ; i < 11; i++)
        if(flag[i])
            cout << i << " ";

    return 0;
}
