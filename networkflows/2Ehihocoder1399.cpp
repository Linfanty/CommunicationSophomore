import java.io.BufferedInputStream;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collection;
import java.util.Collections;
import java.util.HashMap;
import java.util.HashSet;
import java.util.PriorityQueue;
import java.util.Scanner;






public class Main {
    public static final int INF = 0x3f3f3f3f;
    public static Scanner in = new Scanner(new BufferedInputStream(System.in));
    public static void main(String[] args) {
        int n = in.nextInt();
        int[] a = new int[n];
        for(int i=0 ; i<n ; ++i)a[i] = ((in.nextInt()&1)==1?1:-1);
        System.out.println(new Solution(n, a).solve());
    }
}
class Solution {
    int N;
    int[] a;
    int[] dp;
    int[] last;
    public Solution(int n, int[] a) {
        super();
        N = n;
        this.a = a;
        this.dp = new int[N+1];
        last = new int[N+1];
    }
    public int solve() {
        int ret =0;
        for(int i=0 ; i<N; ++i)ret +=a[i];
        return Math.abs(ret);
    }
}