#include<stdio.h>
int main()
{
    int t,n,s,ans;
    int min, i, left,right,a[100005];
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&n,&s); // n������С��s
        for(i = 0; i < n; i++)
            scanf("%d",&a[i]);

        int left = 0, right = 0;
        int sum = 0, ans = n + 1;
        while(1){
            while(right < n && sum < s){
                sum += a[right];
                right++;
            }
            // printf("%d %d\n",left, right);
            if(sum < s) break;

            min = right - left;
            if(min > ans)
                min = ans;
            ans = min;
            sum -= a[left++];
        }

        if(ans == n+1) // �����ܵ����
            printf("0\n");
        else
            printf("%d\n",ans);
    }
}



/*
        int l = 0,right = 0,sum = 0,ans = n+1;
        while(1){
            while(right < n && sum<s){//��ǰ�濪ʼ
                sum+=a[right];
                right++;
            }

            if(sum < s){//�����������ˣ�
                break;
            }
            min = right-l;
            if(min > ans)
                min = ans;
            ans = min;//ans������С����
            sum -= a[l++];//��ȡ����ǰ����
        }
*/
