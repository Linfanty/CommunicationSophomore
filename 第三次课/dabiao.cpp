#include<iostream>
 #include<string.h>
 #include<stdio.h>
 #include<stdlib.h>
 #define maxn 10000000
 bool visit[maxn+1000000];
 int prime[maxn],n; ///prime�Ĵ�С��Ź���һ���ٿ����顣����ǣ�x/lnx��
 void getprime()

 {
     memset(visit, false, sizeof(visit));
     int num = 0;
     for (int i = 2; i <= n; ++i)
     {
         if ( !visit[i] )  prime[++num] = i;
         for (int j = 1; j <= num && i * prime[j] <= n ;  j++)
         {
             visit[ i  *  prime[j] ]  =  true;
             if (i % prime[j] == 0) break; ///�˴����ص㣬�����˺ܶ���ظ��жϣ�����i=9,����������2,3,5,7,�������ѭ����visit[2*9]=1;visit[3*9]=1�����ʱ��9%3==0��Ҫ��������Ϊ5*9������3*15�����棬������ʱ������ˣ�i=15��ʱ���ֻᱻ�ظ�����һ�Σ�������������������ظ����㡣
         }
     }
 }
 int main()
 {
     //scanf("%d",&n);
     n = 10000;
     getprime();
     for(int i = 1; i <= 10000; i++)
        if(prime[i])
            printf("%d,",i);
     return 0;
 }
























