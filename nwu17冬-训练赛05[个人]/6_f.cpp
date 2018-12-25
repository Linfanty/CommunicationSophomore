#include <bits/stdc++.h>
using namespace std;  
#define ll long long 
ll dp[5005][5005];  
ll a[5005];  
ll sum[5005];  
int n,m,k;  
int main()  {  
	while(~scanf("%d%d%d",&n,&m,&k)) {  
	for(int i=1;i<=n;i++)   {  
		scanf("%I64d",&a[i]);  
		if(i<=m)   sum[i]=sum[i-1]+a[i];  
		else  sum[i]=sum[i-1]+a[i]-a[i-m];  
	}  
	memset(dp,0,sizeof(dp));  
	for(int i=1;i<=n;i++) 
		for(int kk=1;kk<=k;kk++)  
			if(i>=m) 
				dp[kk][i]=max(dp[kk][i-1],dp[kk][i]),
			dp[kk][i]=max(dp[kk-1][i-m]+sum[i],dp[kk][i]);  
			printf("%I64d\n",dp[k][n]);  
	}  
}  