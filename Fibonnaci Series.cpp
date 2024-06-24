class Solution {
public:
    int solveusingRecursion(int n) {
        if (n == 0) {
            return 0;
        }
        if (n == 1) {
            return 1;
        }
        int ans = solveusingRecursion(n - 1) + solveusingRecursion(n - 2);
        return ans;
    }
    int solveusingMemo(int n, vector<int>& dp) {
        if (n == 0) {
            return 0;
        }
        if (n == 1) {
            return 1;
        }
        if (dp[n] != -1) {
            return dp[n];
        }
        dp[n] = solveusingMemo(n - 1, dp) + solveusingMemo(n - 2, dp);
        return dp[n];
    }

    int solveusingTabulation(int n) {
        vector<int> dp(n+1, -1);
        dp[0] = 0;
        if(n==0){
            return dp[0];
        }
        dp[1] = 1;
        for(int i = 2;i<=n;i++){
            dp[i] = dp[i-1] + dp[i-2];
         }
         return dp[n];
    }
     int solveusingspaceoptimization(int n) {
            int ans = 0;
            int prev = 0;
            int curr = 1;
            if (n == 0 || n == 1) {
                return n;
            }
            for (int i = 2; i <= n; i++) {
                ans = prev + curr;
                prev = curr;
                curr = ans;
            }
            return ans;
        }
    int fib(int n) {
        vector<int> dp(n + 1, -1);
        // return solveusingRecursion(n);
        // return solveusingMemo(n, dp);
        return solveusingTabulation(n);
    }
};
