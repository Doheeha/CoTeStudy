import java.io.*;
import java.util.*;

public class bj1563 {
    static int N;
    static int[][][] dp;

    static int dp(int n, int l, int a) {
        if (n == N) {
            return 1;
        } else if (l >= 2 || a >= 3) {
            return 0;
        } else if (dp[n][l][a] != 0) {
            return dp[n][l][a];
        } else {
            dp[n][l][a] = dp(n + 1, l, 0) + dp(n + 1, l + 1, 0) + dp(n + 1, l, a + 1);
            return dp[n][l][a];
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        dp = new int[1001][3][4];

        int result = dp(0, 0, 0);
        System.out.println(result % 1000000);
    }
}
