#include<bits/stdc++.h>
using namespace std;

/**
 �����������ʽ��formula
����PΪ�����εİ��ܳ��������׹�ʽ��
�����֮��������һЩ����4,14,52,194,724,2702
....Ȼ��ó�����ʽ�ӣ�F[n]=4*F[n-1]-F[n-2];
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
                    // ���������
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
