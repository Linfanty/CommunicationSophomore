#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 2*1e5+10;
#define LL long long
int c[maxn],v[maxn],g[maxn];
int n,s,k,t,flag;

bool judge(LL mid)
{
    LL time=0;
    for(int i=1;i<k;++i)
    {
        LL dix=g[i]-g[i-1];
        if(dix>mid)//����mid������֧�������ٵ�����һ������վ
            return false;
        LL fv=(mid-dix)*2;//fv+sv=mid  fv/2+sv=dix �����������
        LL sv=mid-fv;
        if(sv<0)//svΪ������ʾ������ȫ���ÿ��ٴ���һ������վ�ܵ���ǰ����վ
            time+=dix;
        else time+=fv/2+sv*2;
    }
    if(time<=t){
        flag=1;//ȫ�̿�������tʱ���ڵ���
        return true;
    }
    else
        return false;
}

int main()
{
    while(scanf("%d%d%d%d",&n,&k,&s,&t)!=EOF)
    {
        for(int i=0;i<n;++i)
            scanf("%d%d",&c[i],&v[i]);
        for(int i=1;i<=k;++i)
            scanf("%d",&g[i]);
        g[0]=0;//�������
        g[k+1]=s;//�����յ�
        k+=2;
        sort(g,g+k);//����վ��λ�����򣬸�����������

        LL left=0,right=s*2,mid;
        flag=0;
        while(left<right)
        {
            mid=(left+right)/2;
            if(judge(mid))
                right=mid;
            else left=mid+1;
        }
        if(!flag){//ȫ�̿���Ҳ������tʱ���ڵ���
            printf("-1\n");
            continue;
        }
        int ans=1e9+10;
        for(int i=0;i<n;++i)
        {
            if(v[i]>=left)
                ans=min(ans,c[i]);
        }
        if(ans==1e9+10)//��ʾû���㹻������������
            printf("-1\n");
        else    printf("%d\n",ans);
    }
    return 0;
}
