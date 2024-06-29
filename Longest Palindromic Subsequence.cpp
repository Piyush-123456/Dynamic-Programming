class Solution {
public:
    int solve(string a, string b, int i, int j) {
        if (i >= a.size()) {
            return 0;
        }
        if (j >= b.size()) {
            return 0;
        }
        int ans = 0;
        if (a[i] == b[j]) {
            ans = 1 + solve(a, b, i + 1, j + 1);
        } else {
            ans = max(solve(a, b, i + 1, j), solve(a, b, i, j + 1));
        }
        return ans;
    }

    int longestPalindromeSubseq(string s) {
        string s2 = s;
        reverse(s2.begin(), s2.end());
        return solve(s, s2, 0, 0);
    }
};
