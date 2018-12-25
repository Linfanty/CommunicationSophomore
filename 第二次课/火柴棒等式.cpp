#include <iostream>
using namespace std;
int a[2223]={6,2,5,5,4,5,6,3,7,6};
const int b[10]={6,2,5,5,4,5,6,3,7,6};
//计算自然数n所需要的火柴数
int need(int n)
{
    int tmp, num;
    num=0;
    if(n==0) return 6;
    while(n>0) {
        tmp=n%10;
        num+=b[tmp];
        n/=10;
    }
    return num;
}

int main( )
{
    int n,A,B,C,D,sum;
    cin>>n;
    sum=0;
    for(int i=10; i<2223; i++) //预处理
        a[i]=need(i);

    for(int i=0; i<=1000; i++) {
        for(int j=0; j<=1000; j++) {
            A=a[i];   B=a[j];  C=n-4-A-B;
            D=a[i+j];
            if(D==C) sum++;
        }
    }
    cout << sum <<endl;
    return 0;
}
