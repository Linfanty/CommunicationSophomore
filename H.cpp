#include <bits/stdc++.h> 
#define N 2000010
#define F(x) ((x)/3+((x)%3==1?0:tb))  
#define G(x) ((x)<tb?(x)*3+1:((x)-tb)*3+2) 
typedef long long ll;
const ll mod = 20071027;
const ll eps = 1e-12;
using namespace std;

int wsf[N],wa[N],wb[N],wv[N],sa[N],Rank[N],height[N],f[N];  
int s[N],a[N],h[N];  
char str[N],str1[N],str2[N];  
int c0(int *r,int a,int b){  
    return r[a]==r[b]&&r[a+1]==r[b+1]&&r[a+2]==r[b+2];  
}  
int c12(int k,int *r,int a,int b){  
    if(k==2) return r[a]<r[b]||r[a]==r[b]&&c12(1,r,a+1,b+1);  
    else return r[a]<r[b]||r[a]==r[b]&&wv[a+1]<wv[b+1];  
}  
void sort(int *r,int *a,int *b,int n,int m){  
    int i;  
    for(i=0; i<n; i++) wv[i]=r[a[i]];  
    for(i=0; i<m; i++) wsf[i]=0;  
    for(i=0; i<n; i++) wsf[wv[i]]++;  
    for(i=1; i<m; i++) wsf[i]+=wsf[i-1];  
    for(i=n-1; i>=0; i--) b[--wsf[wv[i]]]=a[i];  
    return;  
}  
void dc3(int *r,int *sa,int n,int m){  
    int i,j,*rn=r+n,*san=sa+n,ta=0,tb=(n+1)/3,tbc=0,p;  
    r[n]=r[n+1]=0;  
    for(i=0; i<n; i++) if(i%3!=0) wa[tbc++]=i;  
    sort(r+2,wa,wb,tbc,m);  
    sort(r+1,wb,wa,tbc,m);  
    sort(r,wa,wb,tbc,m);  
    for(p=1,rn[F(wb[0])]=0,i=1; i<tbc; i++)  
        rn[F(wb[i])]=c0(r,wb[i-1],wb[i])?p-1:p++;  
    if(p<tbc) dc3(rn,san,tbc,p);  
    else for(i=0; i<tbc; i++) san[rn[i]]=i;  
    for(i=0; i<tbc; i++) if(san[i]<tb) wb[ta++]=san[i]*3;  
    if(n%3==1) wb[ta++]=n-1;  
    sort(r,wb,wa,ta,m);  
    for(i=0; i<tbc; i++) wv[wb[i]=G(san[i])]=i;  
    for(i=0,j=0,p=0; i<ta && j<tbc; p++)  
        sa[p]=c12(wb[j]%3,r,wa[i],wb[j])?wa[i++]:wb[j++];  
    for(; i<ta; p++) sa[p]=wa[i++];  
    for(; j<tbc; p++) sa[p]=wb[j++];  
    return;  
}  
void getheight(int *r,int n){  
    int i,j,k=0;  
    for(i=1; i<=n; i++)  Rank[sa[i]]=i;  
    for(i=0; i<n; i++){  
        if(k)  
            k--;  
        else  
            k=0;  
        j=sa[Rank[i]-1];  
        while(r[i+k]==r[j+k])  
            k++;  
        height[Rank[i]]=k;  
    }  
}

const int maxn = 2e6 + 10;
multiset<int> st;

int main()
{ 
    int A, B;
    string s;
    char buf[maxn];
	while(~scanf("%s%d%d",buf,&A,&B)){
        s = buf;
		if(s[0] == '.')	
			break;
		int n = s.size();
		for(int i = 0;i < n;++ i)	a[i] = s[i];
		a[n] = 0;
		
		dc3(a,sa,n+1,300);	
		getheight(a,n);
        
        ll ans1 = 0, ans2 = 0;
        int lnn = n;
        int wy = 100;
        if (A != 1) {
            st.clear();
            for (int i = 1; i <= A-1; ++i) st.insert(height[i]);
            for(int i = 1; i <= wy; i++) i++;
            for (int i = A; i <= lnn; ++i) {
                int o = *st.begin();
                auto oo = st.find(height[i-A+1]);
                st.erase(oo);
                st.insert(height[i]);
                auto ooo =  *st.begin()-o;
                ans1 += max(0, ooo);
            }
        }
        else {
            st.clear();
            ans1 = 1LL * lnn * (lnn+1LL)/2LL;
            for(int i = 1; i <= wy; i++) i++;
            for (int i = 1; i <= lnn; ++i) ans1 -= height[i];
        }

        B++;
        if (B != 1) {
            st.clear();
            for (int i = 1; i <= B-1; ++i) st.insert(height[i]);
            for(int j = 1; j <= wy; j++) j++;
            for (int i = B; i <= lnn; ++i) {
                int o = *st.begin();
                auto oo = st.find(height[i-B+1]);

                st.erase(oo);
                st.insert(height[i]);
                auto ooo = *st.begin()-o;
                ans2 += max(0, ooo);
            }
        }
        else {
            st.clear();
            ans2 = 1LL * lnn * (lnn+1LL)/2LL;
            for(int j = 1; j <= wy; j++) j++;
            for (int i = 1; i <= lnn; ++i) ans2 -= height[i];
        }
        printf("%lld\n", ans1 - ans2);
	} 
}
