class Solution {
public:
    // SOLVE USING RECURSION
    int solve(string a, string b, int i, int j) {

        if (i == a.size()) {
            return b.size() - j;
        }
        if (j == b.size()) {
            return a.size() - i;
        }

        if (a[i] == b[j]) {
            return solve(a, b, i + 1, j + 1);
        } else {
            int insert = 1 + solve(a, b, i, j + 1);
            int del = 1 + solve(a, b, i + 1, j);
            int replace = 1 + solve(a, b, i + 1, j + 1);
            return min(insert, min(del, replace));
        }
    }

    // SOLVE USING MEMOIZATION
    int solveusingMemo(string a, string b, int i, int j,
                       vector<vector<int>>& dp) {
        if (i == a.size()) {
            return b.size() - j;
        }
        if (j == b.size()) {
            return a.size() - i;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        int ans = 0;
        if (a[i] == b[j]) {
            ans = solveusingMemo(a, b, i + 1, j + 1, dp);
        } else {
            int insert = 1 + solveusingMemo(a, b, i, j + 1, dp);
            int del = 1 + solveusingMemo(a, b, i + 1, j, dp);
            int replace = 1 + solveusingMemo(a, b, i + 1, j + 1, dp);
            ans = min(insert, min(del, replace));
        }
        dp[i][j] = ans;
        return dp[i][j];
    }

    // SOLVE USING TABULATION METHOD
    int solveusingTab(string a, string b) {
        vector<vector<int>> dp(a.size() + 1, vector<int>(b.size() + 1, -1));
        for (int col = 0; col <= b.size(); col++) {
            dp[a.size()][col] = b.size() - col;
        }
        for (int row = 0; row <= a.size(); row++) {
            dp[row][b.size()] = a.size() - row;
        }
        for (int i = a.size() - 1; i >= 0; i--) {
            for (int j = b.size() - 1; j >= 0; j--) {
                int ans = 0;
                if (a[i] == b[j]) {
                    ans = dp[i + 1][j + 1];
                } else {
                    int insert = 1 + dp[i][j + 1];
                    int del = 1 + dp[i + 1][j];
                    int replace = 1 + dp[i + 1][j + 1];
                    ans = min(insert, min(del, replace));
                }
                dp[i][j] = ans;
            }
        }
        return dp[0][0];
    }

    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size() + 1,
                               vector<int>(word2.size() + 1, -1));
        return solveusingTab(word1, word2);
    }
};
