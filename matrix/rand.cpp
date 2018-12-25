#include<bits/stdc++.h>
using namespace std;
#define random(a,b) ((a)+rand()%((b)-(a)+1))

stringstream ss;

int main( int argc, char *argv[] )
{ 
    int seed=time(NULL);
    if(argc > 1)//如果有参数
    {
        ss.clear();
        ss<<argv[1];
        ss>>seed;//把参数转换成整数赋值给seed
    }
    srand(seed);
    //以上为随机数初始化，请勿修改
    //random(a,b)生成[a,b]的随机整数

    //以下写你自己的数据生成代码 
    
    // 2 10 
    int m = 10;

    printf("2 ");

    printf("%d %d\n",random(0,100000000), random(0,1000));
    printf("%d %d\n",random(0,m), random(0,m));
    printf("%d %d\n",random(0,m), random(0,m));
}