#include <stdio.h>
#include <math.h>
#include <algorithm>
#define PI acos(-1.0) //��Ͼ�ȷpi�ķ���
using namespace std;
double area[10005];
int n, f;

int main (){
	int t;
	scanf("%d",&t);
	while (t--){
		int r = 0;
		double r_max = 0;
		double sum = 0;

		scanf("%d%d",&n,&f);
		for(int i = 0;i < n; i++){
			scanf("%d",&r);// �뾶
			area[i] = PI * r * r; // ÿ�����
			sum += area[i]; // �ܺ�
			r_max = max(r_max, area[i]); // �����Ǹ�
		}

		f++;
        double low = r_max/f; // ��Сֵ
        double high = sum/f; // ���ֵ
        //cout << low << ' ' << high << endl;

        while(low + 1e-5 < high )
        {
            double mid = (low + high) / 2;
            int cnt = 0;

            for(int i = 0;i < n; i++)
              cnt += (int)floor(area[i]/mid);
            if(cnt < f) high = mid;
            else low = mid;
        }

		printf("%.4lf\n", low);
	}
	return 0;
}
