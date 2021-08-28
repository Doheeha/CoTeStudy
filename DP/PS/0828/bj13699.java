import java.io.*;

public class bj13699 {
    static long[] dp;

    static long dp(int n) {
        if (n == 0 || n == 1) {
            return 1;
        } else if (dp[n] != 0) {
            return dp[n];
        } else {
            // 점화식에 대한 풀이

            return dp[n];
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());

        dp = new long[n + 1];
        dp[0] = 1;
        dp[1] = 1;

        System.out.println(dp(n));
    }
}
