#include<cstdio>  
#include<cstring>  
#include<iostream>  
#include<algorithm>  
using namespace std;  
int dp[2][10005];  
string str1,str2;  
int len1,len2;  
//最长公共子序列  

int LCS(int x,int y)  {  
    for(int i=0;i<=x;i++)  
    {  
        for(int j=0;j<=y+1;j++)  
        {  
            if(i==0||j==0) {dp[i%2][j]=0;continue;}  
            if(str1[i-1]==str2[j-1])  
                dp[i%2][j]=dp[(i-1)%2][j-1]+1;  
            else  
                dp[i%2][j]=max(dp[(i-1)%2][j],dp[i%2][j-1]);  
        }  
    }  

}  

int main()  {  
    while(cin>>str1>>str2)  
    {  
        len1=str1.length();  
        len2=str2.length();  
        LCS(len1,len2);  
        printf("%d\n",dp[len1%2][len2]);  
    }  
    return 0;  
}  