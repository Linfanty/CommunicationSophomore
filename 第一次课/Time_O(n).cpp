int aFunc(int n) {
   for(int i = 0; i < n; i++) {         // ��Ҫִ�� (n + 1) ��
       printf("Hello, World!\n");      // ��Ҫִ�� n ��
   }
   return 0;       // ��Ҫִ�� 1 ��
}
���������Ҫ (n + 1 + n  + 1) = 2n + 2 �����㡣
ʱ�临�Ӷȵĸ��


��ѧ�϶��壺 ���ڳ��� c��
ʹ�õ� N >= c ʱ T(N) <= f(N)����ʾΪ T(n) = O(f(n)) ��
