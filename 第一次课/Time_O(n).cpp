int aFunc(int n) {
   for(int i = 0; i < n; i++) {         // 需要执行 (n + 1) 次
       printf("Hello, World!\n");      // 需要执行 n 次
   }
   return 0;       // 需要执行 1 次
}
这个方法需要 (n + 1 + n  + 1) = 2n + 2 次运算。
时间复杂度的概念。


数学上定义： 存在常数 c，
使得当 N >= c 时 T(N) <= f(N)，表示为 T(n) = O(f(n)) 。
