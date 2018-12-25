#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
#include<queue>
using namespace std;
int N,M,P;
char ma[55][55];
struct no
{
	int ax,ay,lu,yao;
};
int minlu[55][55][(1<<11)];
int fx[4][2]={1,0,-1,0,0,-1,0,1};
queue<no> dui;
int qix,qiy,zix,ziy;
int main()
{
	//freopen("maze2.in","r",stdin);
	//freopen("maze2.out","w",stdout);
	scanf("%d%d",&N,&M);
	cin>>P;
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=M;j++)
		{
			cin>>ma[i][j];
			if(ma[i][j]=='$')
				qix=i,qiy=j;
			if(ma[i][j]=='&')
				zix=i,ziy=j;
		}
	}
	no qi;
	qi.ax=qix,qi.ay=qiy;
	qi.lu=0,qi.yao=0;
	dui.push(qi);
	no nowe;
	memset(minlu,-1,sizeof(minlu));
	minlu[qix][qiy][0]=0;
	while(!dui.empty())
	{
		nowe=dui.front();
		dui.pop();
		for(int i=0;i<4;i++)
		{
			no now=(no){nowe.ax+fx[i][0],nowe.ay+fx[i][1],nowe.lu+1,nowe.yao};
			if(ma[now.ax][now.ay]=='#'||now.ax>N||now.ay>M||now.ax<=0||now.ay<=0)
				continue;
			if(ma[now.ax][now.ay]>='A'&&ma[now.ax][now.ay]<='Z')
				if((now.yao&(1<<(ma[now.ax][now.ay]-'A')))==0)
					continue;
			if(ma[now.ax][now.ay]>='a'&&ma[now.ax][now.ay]<='z'&&((now.yao&(1<<(ma[now.ax][now.ay]-'A')))==0))
				now.yao=1<<(ma[now.ax][now.ay]-'A')|now.yao;
			if(minlu[now.ax][now.ay][now.yao]==-1

                ||minlu[now.ax][now.ay][now.yao]>now.lu)
			{
				//cout<<"IIII"<<" "<<now.lu<<" "<<minlu[now.ax][now.ay][now.yao]<<" "<<now.yao<<" "<<now.ax<<" "<<now.ay<<endl;
				minlu[now.ax][now.ay][now.yao]=now.lu;
				dui.push(now);
			}
		}
	}
	int ans=~0u>>1;
	for(int i=0;i<(1<<P);i++)
	{
	//	cout<<minlu[zix][ziy][i]<<endl;
		if(minlu[zix][ziy][i]<ans&&minlu[zix][ziy][i]!=-1)
		{
			ans=minlu[zix][ziy][i];
		}
	}
	if(ans==~0u>>1)
		ans=-1;
	cout<<ans;
}
