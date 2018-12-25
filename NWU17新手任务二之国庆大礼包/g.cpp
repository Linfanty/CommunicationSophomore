# include <stdio.h>
# include <string.h>
int main ()
{
	int n,i;
	char s[100];
	scanf("%d",&n);
		for( i=0;i<n;i++) {
			scanf("%s",s);
			int l=strlen(s);
			int j,sum=0,ci=0;
			for (j=0;j<l;j++) {
				if (s[j]=='O') {
					ci++;
					sum=sum+ci;
				}
				else ci=0;
			}
			printf("%d\n",sum);
		}

	return 0;
 }
