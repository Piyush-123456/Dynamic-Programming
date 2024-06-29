
class Solution {
public:
    // SOLVE USING RECURSION
    int solve(string text1, string text2, int i, int j) {
        if (i >= text1.size()) {
            return 0;
        }
        if (j >= text2.size()) {
            return 0;
        }
        int ans = 0;
        if (text1[i] == text2[j]) {
            ans = 1 + solve(text1, text2, i + 1, j + 1);
        } else {
            ans = max(solve(text1, text2, i + 1, j),
                      solve(text1, text2, i, j + 1));
        }
        return ans;
    }
    // SOLVE USING MEMOIZATION
    int solveusingMemo(string& a, string& b, int i, int j,
                       vector<vector<int>>& dp) {
        if (i >= a.size()) {
            return 0;
        }
        if (j >= b.size()) {
            return 0;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        int ans = 0;
        if (a[i] == b[j]) {
            ans = 1 + solve(a, b, i + 1, j + 1);
        } else {
            ans = max(solve(a, b, i + 1, j), solve(a, b, i, j + 1));
        }
        dp[i][j] = ans;
        return dp[i][j];
    }
    // SOLVE USING TABULATION METHOD
    int solveusingTabulationMethod(string a, string b) {
        vector<vector<int>> dp(a.size() + 1, vector<int>(b.size() + 1, 0));

        for (int i = a.size() - 1; i >= 0; i--) {
            int ans = 0;
            for (int j = b.size() - 1; j >= 0; j--) {
                if (a[i] == b[j]) {
                    ans = 1 + dp[i + 1][j + 1];
                } else {
                    ans = max(dp[i + 1][j], dp[i][j + 1]);
                }
                dp[i][j] = ans;
            }
        }
        return dp[0][0];
    }
    // SOLVE USING SPACE OPTIMIZATION
    int solveusingSpaceOpt(string a, string b) {
        vector<int> curr(a.size() + 1, 0);
        vector<int> next(a.size() + 1, 0);
        for (int j = b.size() - 1; j >= 0; j--) {
            for (int i = a.size() - 1; i >= 0; i--) {
                int ans = 0;
                if (a[i] == b[j]) {
                    ans = 1 + next[i + 1];
                } else {
                    ans = max(curr[i + 1], next[i]);
                }
                curr[i] = ans;
            }
            next = curr;
        }
        return curr[0];
    }
    int longestCommonSubsequence(string text1, string text2) {
        return solveusingSpaceOpt(text1, text2);
    }
};
