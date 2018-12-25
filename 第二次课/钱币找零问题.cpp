#include<iostream>
#include<algorithm>
using namespace std;
int Count[7]={3,0,2,1,0,3,5};
int Value[7]={100,50,20,10,5,2,1};
    123 :1张100 1张20 1张2元 1张1元
int main()
{
    int money;
    cin >> money;

    int num = 0;
    for(int i = 0; i <= 6; i++)
    {
        int c = min(money/Value[i],Count[i]);
        money = money - c*Value[i];
        num += c;
    }

    if(money > 0) cout<<"NO"<<endl;
    else cout<<num<<endl;
}
