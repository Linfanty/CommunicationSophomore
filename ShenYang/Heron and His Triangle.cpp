#include<bits/stdc++.h>
using namespace std;

/**
 三角形面积公式：formula
其中P为三角形的半周长。（海伦公式）
打个表之后发现这样一些数字4,14,52,194,724,2702
....然后得出递推式子，F[n]=4*F[n-1]-F[n-2];
*/

int main()
{
    int n = 1;
    while(n++&&n<=1000)
    {
        for(int i = 4; i <= 10000; i++)
        {
            int p = (3 * i) / 2;
            int area = p * (p - i - 1) * (p - i + 1) * (p - i);
            bool flag = false;
            for(int j = 1; j <= sqrt(area) + 1; j++)
            {
                if(j * j == area && i >= n)
                {
                    // 面积是整数
                    cout << j << ' ' << area << endl;
                    flag = true;
                    printf("%d\n", i);
                    break;
                }
            }
            if(flag) break;
        }
    }
    return 0;
}
