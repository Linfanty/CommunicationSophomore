#include <iostream>
using namespace std;
int A[1001]={0};
int main( )
{
    int a,b,c,d,e,f,i,sum,num;
    int arr[7];
    int w[7]={0,1,2,3,5,10,20};
    cin>>a>>b>>c>>d>>e>>f;
    for(arr[1]=0; arr[1]<=a; arr[1]++)
        for(arr[2]=0; arr[2]<=b; arr[2]++)
            for(arr[3]=0; arr[3]<=c; arr[3]++)
                for(arr[4]=0; arr[4]<=d; arr[4]++)
                    for(arr[5]=0; arr[5]<=e; arr[5]++)
                        for(arr[6]=0; arr[6]<=f; arr[6]++) {
                            sum=0;
                            for(i=1; i<=6; i++) {
                                sum+=arr[i]*w[i];
                                A[sum]=1;
                            }
                        }
    num=0;
    for(i=1; i<=1000; i++) {
        if(A[i]==1)
            num++;
    }
    cout<<num<<endl;return 0;
}
