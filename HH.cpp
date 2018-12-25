#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn=200005;
int K;
struct SAM
{
    int ch[maxn][26];
    int pre[maxn],step[maxn];
    int last,id;
    ll ans;
    int num[maxn];
    void init()
    {
        ans=last=id=0;
        memset(ch[0],-1,sizeof(ch[0]));
        pre[0]=-1; step[0]=0;
    }
    void Insert(int c)
    {
        int p=last,np=++id;
        step[np]=step[p]+1;
        memset(ch[np],-1,sizeof(ch[np])); num[np]=0;

        while(p!=-1&&ch[p][c]==-1)  ch[p][c]=np,p=pre[p];
        if(p==-1) pre[np]=0;
        else
        {
            int q=ch[p][c];
            if(step[q]!=step[p]+1)
            {
                int nq=++id;
                memcpy(ch[nq],ch[q],sizeof(ch[q])); num[nq]=num[q];
                step[nq]=step[p]+1;
                pre[nq]=pre[q];
                pre[np]=pre[q]=nq;
                while(p!=-1&&ch[p][c]==q) ch[p][c]=nq,p=pre[p];
            }
            else pre[np]=q;
        }
        last=np;

        while(np!=-1&&num[np]<K)
        {
            num[np]++;
            if(num[np]>=K) ans+=step[np]-step[pre[np]];
            np=pre[np];
        }
    }
}sam;
char S[200001];
int main()
{
    while(scanf("%s",S)!=EOF)
    {
        int a,b;cin>>a>>b;
        K = a;
        sam.init();
        int N = strlen(S);
        for(int i=0;i<N;i++) sam.Insert(S[i]-'A');
        ll res = sam.ans;
        K = b+1;
        sam.init();
        for(int i=0;i<N;i++) sam.Insert(S[i]-'A');
        ll re1 = sam.ans;
        //cout<<re1<<endl;
        res-=re1;
        cout<<res<<endl;
    }
    return 0;
}