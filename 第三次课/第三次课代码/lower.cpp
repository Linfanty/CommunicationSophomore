#include <iostream>
#include <cstdio>
#include <algorithm>//必须包含的头文件
using namespace std;

int main(){
    int point[10] = {1,3,7,7,9};
    int tmp;
    tmp = lower_bound(point, point + 5, 6) - point;
    ////按从小到大，7最少能插入数组point的哪个位置
    printf("%d\n",tmp);

    tmp = upper_bound(point, point + 5, 6) - point;
    //按从小到大，7最多能插入数组point的哪个位置
    printf("%d\n",tmp);

    cout << binary_search(point, point + 5, 9) << endl;


    return 0;
}


/*
output
4
2
*/
