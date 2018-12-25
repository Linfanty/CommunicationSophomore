#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>

using namespace std;
const double PI = acos(-1.0);
struct complex
{
    double r,i;
    complex(double _r = 0.0,double _i = 0.0){r = _r; i = _i;}
    complex operator +(const complex &b){return complex(r+b.r,i+b.i);}
    complex operator -(const complex &b){return complex(r-b.r,i-b.i);}
    complex operator *(const complex &b){return complex(r*b.r-i*b.i,r*b.i+i*b.r);}
}x1[2000000],x2[2000000],w1[2000000],w2[2000000];
int N;
void change(complex y[],int len)
{
    int i,j,k;
    for(i=1,j=len/2;i<len-1;i++)
    {
        if(i<j)swap(y[i],y[j]);
        k=len/2;
        while(j>=k)
        {
            j-=k;
            k/=2;
        }
        if(j<k) j+=k;
    }
}
void fft_init()
{
  for (int h=2;h<=(1<<20);h<<=1)
    for (int d=0;d<h/2;d++)
      w1[h+d]=complex(cos(2*d*PI/h),sin(2*d*PI/h)),w2[h+d]=complex(cos(-2*d*PI/h),sin(-2*d*PI/h));
}
void fft(complex y[],int len,int on)
{
    change(y,len);
    for(int h=2;h<=len;h<<=1)
        for(int j=0;j<len;j+=h)
            for(int k=j,d=0;k<j+h/2;k++,d++)
            {
        complex w;
        if (on==1) w=w1[h+d];
        else w=w2[h+d];
                complex u=y[k], t=w*y[k+h/2];
                y[k]=u+t;
                y[k+h/2]=u-t;               
            }
    if(on==-1)
        for(int i=0;i<len;i++)
            y[i].r/=len;
}
char s[1100000];
char t[1100000];
int a[1100000];
int b[1100000];
int n,m;
int cal(char x)
{
  if (x=='R') return 0;
  if (x=='S') return 1;
  if (x=='P') return 2;
  if (x=='K') return 3;
  return 4;
}
int pp[5][5];
void init()
{
  fft_init();
  pp[1][2]=1;
  pp[2][0]=1;
  pp[0][4]=1;
  pp[4][3]=1;
  pp[3][1]=1;
  pp[1][4]=1;
  pp[4][2]=1;
  pp[2][3]=1;
  pp[3][0]=1;
  pp[0][1]=1;
}
int sum[1100000];
int main()
{
  scanf("%s",s);
  scanf("%s",t);
  n=strlen(s);
  m=strlen(t);
  init();
  for (int i=0;i<n;i++)
    a[i]=cal(s[i]);
  for (int i=0;i<m;i++)
    b[i]=cal(t[i]);
  reverse(a,a+n);
  N=1;
  while (N<n) N*=2;
  for (int l=0;l<5;l++)
  {
    for (int i=0;i<m;i++)
      if (b[i]==l) x1[i]=complex(1.0,0);
      else x1[i]=complex(0.0,0.0);
    for (int i=m;i<N;i++)
      x1[i]=complex(0.0,0.0);
    for (int i=0;i<n;i++)
      if (pp[l][a[i]]) x2[i]=complex(1.0,0.0);
      else x2[i]=complex(0.0,0.0);
    for (int i=n;i<N;i++)
      x2[i]=complex(0.0,0.0);
    fft(x1,N,1);
    fft(x2,N,1);
    for (int i=0;i<N;i++)
      x1[i]=x1[i]*x2[i];
    fft(x1,N,-1);
    for (int i=0;i<n-1;i++)
      sum[n-1-i]+=int(x1[i].r+0.0001);
  }
  int ans=0;
  for (int i=0;i<n;i++) {
    ans=max(ans,sum[i]);
    printf("%d\n", sum[i]);
  }
  printf("%d\n",ans);
  return 0;
}