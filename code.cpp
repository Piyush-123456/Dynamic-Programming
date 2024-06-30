class Solution {
public:
    int solve(int start, int end) {
        if (start >= end) {
            return 0;
        }
        int ans = INT_MAX;
        for (int i = start; i <= end; i++) {
            ans = min(ans, i + max(solve(start, i - 1), solve(i + 1, end)));
        }
        return ans;
    }
    int solveusingMemo(int start, int end, vector<vector<int>>& dp) {
        if (start >= end) {
            return 0;
        }
        if (dp[start][end] != -1) {
            return dp[start][end];
        }
        int ans = INT_MAX;
        for (int i = start; i <= end; i++) {
            ans = min(ans, i + max(solveusingMemo(start, i - 1, dp), solveusingMemo(i + 1, end, dp)));
        }
        dp[start][end] = ans;
        return dp[start][end];
    }
    int solveusingTab(int n, int start, int end) {
        vector<vector<int>> dp(n + 2, vector<int>(n + 1, 0));

        for (int start = n; start >= 1; start--) {
            for (int end = 1; end <= n; end++) {
                if (start >= end) {
                    continue;
                }
                int ans = INT_MAX;
                for (int i = start; i <= end; i++) {
                    ans = min(ans, i + max(dp[start][i - 1], dp[i + 1][end]));
                }
                dp[start][end] = ans;
            }
        }
        return dp[1][n];
    }


    int getMoneyAmount(int n) {
        int start = 1;
        int end = n;
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return solveusingTab(n, start, end);
    }
};