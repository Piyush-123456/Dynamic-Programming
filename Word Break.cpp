class Solution {
public:
    bool check(string& word, vector<string>& wordDict) {
        for (auto i : wordDict) {
            if (i == word) {
                return true;
            }
        }
        return false;
    }
    bool solve(string& s, vector<string>& wordDict, int start) {
        if (start == s.size()) {
            return true;
        }
        string word = "";
        bool flag = false;
        for (int i = 0; i < s.size(); i++) {
            word += s[i];
            if (check(word, wordDict)) {
                flag = flag || solve(s, wordDict, i + 1);
            }
        }
        return flag;
    }
    bool solveusingMemo(string& s, vector<string>& wordDict, int start,
                        vector<int>& dp) {
        if (start == s.size()) {
            return true;
        }
        if (dp[start] != -1) {
            return dp[start];
        }
        string word = "";
        bool flag = false;
        for (int i = start; i < s.size(); i++) {
            word += s[i];
            if (check(word, wordDict)) {
                flag = flag || solveusingMemo(s, wordDict, i + 1, dp);
            }
        }
        dp[start] = flag;
        return dp[start];
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> dp(s.size() + 1, -1);
        return solveusingMemo(s, wordDict, 0, dp);
    }
};
