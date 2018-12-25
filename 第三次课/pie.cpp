#include <stdio.h>
#include <math.h>
#include <algorithm>
#define PI acos(-1.0) //求较精确pi的方法
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
			scanf("%d",&r);// 半径
			area[i] = PI * r * r; // 每个面积
			sum += area[i]; // 总和
			r_max = max(r_max, area[i]); // 最大的那个
		}

		f++;
        double low = r_max/f; // 最小值
        double high = sum/f; // 最大值
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
