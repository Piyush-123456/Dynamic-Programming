class Solution {
public:
    int solve(int n) {
        if (n == 0) {
            return 1;
        }
        if (n < 0) {
            return 0;
        }

        int i = 1;
        int end = sqrt(n);
        int ans = INT_MAX;
        while (i <= end) {
            int perfectsq = i * i;
            int perfectsqrec = 1 + solve(n - perfectsq);
            if (ans > perfectsqrec) {
                ans = perfectsqrec;
            }
            i++;
        }
        return ans;
    }
    int solveusingMemo(int n, vector<int>& dp) {
        if (n == 0) {
            return 0;
        }
        if (dp[n] != -1) {
            return dp[n];
        }
        int i = 1;
        int end = sqrt(n);
        int ans = INT_MAX;
        while (i <= end) {
            int perfectsq = i * i;
            int perfectsqrec = 1 + solveusingMemo(n - perfectsq, dp);
            if (ans > perfectsqrec) {
                ans = perfectsqrec;
            }
            dp[n] = ans;
            i++;
        }
        return dp[n];
    }

    int solveusingTabulationMethod(int n) {
        vector<int> dp(n + 1, -1);
        dp[0] = 1;
        for (int i = 1; i <= n; i++) {
            int start = 1;
            int end = sqrt(i);
            int ans = INT_MAX;
            while (start <= end) {
                int perfectsq = start * start;
                int perfectsqrec = 1 + dp[i - perfectsq];
                if (ans > perfectsqrec) {
                    ans = perfectsqrec;
                }
                start++;
            }
            dp[i] = ans;
        }
        return dp[n];
    }
    int numSquares(int n) {
        vector<int> dp(n + 1, -1);
        return solveusingTabulationMethod(n)-1;
    }
};
