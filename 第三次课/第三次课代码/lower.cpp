#include <iostream>
#include <cstdio>
#include <algorithm>//���������ͷ�ļ�
using namespace std;

int main(){
    int point[10] = {1,3,7,7,9};
    int tmp;
    tmp = lower_bound(point, point + 5, 6) - point;
    ////����С����7�����ܲ�������point���ĸ�λ��
    printf("%d\n",tmp);

    tmp = upper_bound(point, point + 5, 6) - point;
    //����С����7����ܲ�������point���ĸ�λ��
    printf("%d\n",tmp);

    cout << binary_search(point, point + 5, 9) << endl;


    return 0;
}


/*
output
4
2
*/
