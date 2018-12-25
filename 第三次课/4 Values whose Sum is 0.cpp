#include<iostream>
#include<cstring>
#include<cstdio>
#include<malloc.h>
#include<algorithm>
#define MAXN 4005
#define inf 0x3f3f3f3f
using namespace std;
int n;
int a[MAXN],b[MAXN],c[MAXN],d[MAXN];
int cd[MAXN*MAXN];//c,d�����ֵ���Ϸ���

void solve()
{
    for(int i=0; i<n; ++i)
        for(int j=0; j<n; ++j)
            cd[i*n+j]=c[i]+d[j];
            //ö��c,d����֮�͵��������

    sort(cd,cd+n*n);

    long long res=0;
    for(int i=0; i<n; ++i)
        for(int j=0; j<n; ++j)
        {
            int addcd = -(a[i]+b[j]);//��Ҫ���ϵ���
            ���������飬����+���ȣ�Ŀ��ֵ
            upper_bound���ص�һ�����ֵ�λ��
            lower_bound�������һ���ĺ���һ�����ֵ�λ��
            //��û�оͷ���Ӧ�ó��ֵ�λ��ʹ��sort��Ȼ����
            res+=upper_bound(cd,cd+n*n,addcd) - cd
                - ( lower_bound(cd,cd+n*n,addcd) - cd );
                ����cd������
            //cout << upper_bound(cd,cd+n*n,addcd)-lower_bound(cd,cd+n*n,addcd) << endl;
        }
    cout<<res<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>n;
    for(int i=0; i<n; ++i)
        cin>>a[i]>>b[i]>>c[i]>>d[i];
    solve();
    return 0;
}
/*
6
-45 22 42 -16
-41 -27 56 30
-36 53 -37 77
-36 30 -75 -46
26 -38 -10 62
-32 -54 -6 45
*/
